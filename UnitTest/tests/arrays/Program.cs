using System;

namespace Demo
{
	public class Testing
	{
		public class OptimizedCRC
	    {
	        private const uint kCrcPoly = 0xEDB88320;
	        private const uint kInitial = 0xFFFFFFFF;
	        private static readonly uint[] Table;
	        private const uint CRC_NUM_TABLES = 8;

	        static OptimizedCRC()
	        {
	            unchecked
	            {
	                Table = new uint[256 * CRC_NUM_TABLES];
	                uint i;
	                for (i = 0; i < 256; i++)
	                {
	                    uint r = i;
	                    for (int j = 0; j < 8; j++)
	                        r = (r >> 1) ^ (kCrcPoly & ~((r & 1) - 1));
	                    Table[i] = r;
	                }
	                for (; i < 256 * CRC_NUM_TABLES; i++)
	                {
	                    uint r = Table[i - 256];
	                    Table[i] = Table[r & 0xFF] ^ (r >> 8);
	                }
	            }
	        }

	        private uint value;

	        public OptimizedCRC()
	        {
	            Init();
	        }

	        /// <summary>
	        /// Reset CRC
	        /// </summary>
	        public void Init()
	        {
	            value = kInitial;
	        }

	        public int Value
	        {
	            get { return (int)~value; }
	        }

	        public void UpdateByte(byte b)
	        {
	            value = (value >> 8) ^ Table[(byte)value ^ b];
	        }

	        public void Update(byte[] data, int offset, int count)
	        {
	            new ArraySegment<byte>(data, offset, count);     // check arguments
	            if (count == 0) return;

	            var table = OptimizedCRC.Table;        // important for performance!

	            uint crc = value;

	            for (; (offset & 7) != 0 && count != 0; count--)
	                crc = (crc >> 8) ^ table[(byte)crc ^ data[offset++]];

	            if (count >= 8)
	            {
	                /*
	                 * Idea from 7-zip project sources (http://7-zip.org/sdk.html)
	                 */

	                int to = (count - 8) & ~7;
	                count -= to;
	                to += offset;

	                while (offset != to)
	                {
	                    crc ^= (uint)(data[offset] + (data[offset + 1] << 8) + (data[offset + 2] << 16) + (data[offset + 3] << 24));
	                    uint high = (uint)(data[offset + 4] + (data[offset + 5] << 8) + (data[offset + 6] << 16) + (data[offset + 7] << 24));
	                    offset += 8;

	                    crc = table[(byte)crc + 0x700]
	                        ^ table[(byte)(crc >>= 8) + 0x600]
	                        ^ table[(byte)(crc >>= 8) + 0x500]
	                        ^ table[/*(byte)*/(crc >> 8) + 0x400]
	                        ^ table[(byte)(high) + 0x300]
	                        ^ table[(byte)(high >>= 8) + 0x200]
	                        ^ table[(byte)(high >>= 8) + 0x100]
	                        ^ table[/*(byte)*/(high >> 8) + 0x000];
	                }
	            }

	            while (count-- != 0)
	                crc = (crc >> 8) ^ table[(byte)crc ^ data[offset++]];

	            value = crc;
	        }

	        static public int Compute(byte[] data, int offset, int size)
	        {
	            var crc = new OptimizedCRC();
	            crc.Update(data, offset, size);
	            return crc.Value;
	        }

	        static public int Compute(byte[] data)
	        {
	            return Compute(data, 0, data.Length);
	        }

	        static public int Compute(ArraySegment<byte> block)
	        {
	            return Compute(block.Array, block.Offset, block.Count);
	        }

			static public void Run()
			{
				
				Console.WriteLine("Running CRC32 test...");
				int crc = Compute(new byte[1024*1024*128]);
				WriteCheck(crc, -2140847791);

				var bytes = new byte[1024*1024*128];
				for(int i = 0; i < bytes.Length; i++) bytes[i] = (byte)(i & 0xFF);
				crc = Compute(bytes);

				WriteCheck(crc, 2124873618);

				Console.WriteLine();
				
	            // 260 (win8 NET4, release), 240 (Debian Mono 2.10, release), 220 (Debian g++ 4.7, -O3)
			}
	    }

		public class ArrayTest
		{
			public static void assert (bool condition)
			{
				if(!condition)
					throw new Exception("Assertion failed!");
			}

			public static void Run ()
			{
				Console.WriteLine("Running array test...");

				int[] arr = new int[10];
				int i = 0;
				for(i = 0; i < arr.Length; i++) arr[i] = i;
				for(i = 0; i < arr.Length; i++) assert(arr[i] == i);
				i = 0;
				foreach(var e in arr) assert(e == i++);
				i = 0;
				foreach(var e in arr) i += e;

				WriteCheck(i, 45);
			}
		}

		public class PolymorphismTest
		{
			public interface IfaceA
			{
				void methodA();
			}

			public interface IfaceB
			{
				void methodA();
			}

			public class ClassA : IfaceA, IfaceB
			{
				void IfaceA.methodA()
				{
					Console.Write("A");
				}

				public void methodA()
				{
					Console.Write("B");
				}
			}

			class ClassC : IfaceA, IfaceB
			{
				void IfaceA.methodA()
				{
					Console.Write("A");
				}

				void IfaceB.methodA()
				{
					Console.Write("B");
				}

				public void methodA()
				{
					Console.Write("C");
				}
			}

			abstract class ClassD_Base : IfaceA, IfaceB
			{
				void IfaceA.methodA()
				{
					Console.Write("A");
				}

				public abstract void methodA();
			}

			class ClassD : ClassD_Base
			{
				public override void methodA()
				{
					Console.Write("B");
				}
			}

			class ClassE : ClassD, IfaceA, IfaceB
			{
				public void methodA()
				{
					Console.Write("E");
				}
			}

			public static void Run()
			{
				Console.WriteLine();
				Console.WriteLine("Running polymorphism test...");


				ClassA a = new ClassA();
				((IfaceA)a).methodA();
				((IfaceB)a).methodA();
				a.methodA();
				Console.WriteLine();

				ClassC c = new ClassC();
				((IfaceA)c).methodA();
				((IfaceB)c).methodA();
				c.methodA();
				Console.WriteLine();

				ClassD d = new ClassD();
				((IfaceA)d).methodA();
				((IfaceB)d).methodA();
				d.methodA();
				Console.WriteLine();

				ClassE e = new ClassE();
				((IfaceA)e).methodA();
				((IfaceB)e).methodA();
				e.methodA();
				Console.WriteLine();
			}
		}

		static void WriteCheck(int a, int expect)
		{
			Console.Write ("a = " + a + " (expected " + expect + ")");

			if(a == expect)
				Console.WriteLine(" [OK]");
			else
				Console.WriteLine(" [ERROR]");
		}

	    static void WriteCheck(bool cond, string desc, bool expect)
	    {
	        Console.Write(desc + " = " + cond + " (expected " + expect + ")");

	        if (cond == expect)
	            Console.WriteLine(" [OK]");
	        else
	            Console.WriteLine(" [ERROR]");
	    }

		public class DelegateTest
		{
			private static int delegateImplA (int x)
			{
				return x * 13;
			}

			private int delegateImplB (int x)
			{
				return x * 7;
			}

			public static void Run ()
			{
				Console.WriteLine ();
				Console.WriteLine ("Running delegate test...");

				// Lambda test
				Func<int, int> lambdaA = (x) => x * 4;
				int a = lambdaA(4);
				WriteCheck (a, 16);

				// Story test
				a = 1;
				Func<int, int> funcA = (x) => x * a;

				a = funcA (3);
				a = funcA (3);
				WriteCheck (a, 9);

				a = 1;
				for (int i = 1; i <= 3; i++) 
				{
					a += funcA(i);
				}
				WriteCheck (a, 24);

				Func<int> funcB = () => a * 3;
				a = 4;
				a = funcB();
				WriteCheck (a, 12);

				Action funcC = () => a = 13;
				funcC();
				WriteCheck (a, 13);

				Action<float, int> funcD = (x, y) => a = (int)(2 * x + y);
				funcD(3.5f, 2);
				WriteCheck (a, 9);

				// member test
				Func<int, int> memberA = delegateImplA;
				Func<int, int> memberB = new DelegateTest().delegateImplB;

				a = memberA(3);
				WriteCheck (a, 39);

				a = memberB(2);
				WriteCheck (a, 14);


				Console.WriteLine();
			}
		}

	    public class CastTest
	    {
	        interface ITestFace { }
	        interface ITestFace2 { }

	        private struct TestStruct : ITestFace { public int a; }
	        private struct TestStruct2 : ITestFace2 { public int a; }

	        private struct TestClass : ITestFace
	        {

	        }

			static void WriteCastCheck<T> (object value, string desc, bool expect) 
			{
				bool res1 = true;
				try {
					var test = (T)value;
				} catch (InvalidCastException) {
					res1 = false;
				}

				bool res2 = value is T;

				Console.Write (desc + " = " + res1 + " & " + res2 + " (expected " + expect + ")");

				if ((res1 == expect) && (res2 == expect))
					Console.WriteLine (" [OK]");
	            else
	                Console.WriteLine(" [ERROR]");
			}

	        static void WriteCastCheck<T> (object value, T comp, string desc, bool expect) 
			{
				bool res1 = true;
				try {
					var test = (T)value;
				} catch (InvalidCastException) {
					res1 = false;
				}

				bool res2 = value is T;

				Console.Write (desc + " = " + res1 + " & " + res2 + " (expected " + expect + ")");

				if ((res1 == expect) && (res2 == expect))
				{
					if(!expect || (value.Equals((Object)comp)))
						Console.WriteLine (" [OK]");
					else
						Console.WriteLine(" [ERROR]");
				}
	            else
	                Console.WriteLine(" [ERROR]");
	        }

	        public static void Run()
	        {
	            // test struct boxing & casting
	            {
	                TestStruct a = new TestStruct();
	                a.a = 9;
	                ITestFace a_boxed = a;
	                a.a = 7;
	                Object a_boxed2 = a;
	                a.a = 13;
	                WriteCheck(a.a, 13);
	                a = (TestStruct) a_boxed;
	                WriteCheck(a.a, 9);
	                a = (TestStruct) a_boxed2;
	                WriteCheck(a.a, 7);

	                a_boxed = a as ITestFace;
	                a_boxed2 = a as Object;

	                WriteCheck(a_boxed is TestStruct, "a_boxed is TestStruct", true);
	                WriteCheck(a_boxed2 is TestStruct, "a_boxed2 is TestStruct", true);
	                WriteCheck(a_boxed2 is TestStruct2, "a_boxed2 is TestStruct2", false);
	                WriteCheck(a_boxed2 is ITestFace, "a_boxed2 is ITestFace", true);
	                WriteCheck(a_boxed2 is ITestFace2, "a_boxed2 is ITestFace2", false);
	                WriteCheck(a_boxed2 as ITestFace != null, "a_boxed2 is ITestFace", true);
	                WriteCheck(a_boxed2 as ITestFace2 != null, "a_boxed2 is ITestFace2", false);
	                WriteCastCheck<ITestFace>(a, "(ITestFace)a", true);
	                WriteCastCheck<ITestFace2>(a, "(ITestFace2)a", false);
	                WriteCastCheck<TestStruct2>(a, "(TestStruct2)a", false);
	                WriteCastCheck<TestStruct>(a, "(TestStruct)a", true);
	            }

	            // test integer boxing
				{
					object[] arr = {true, (byte)1, (sbyte)2, '3', (short)4, (ushort)5, (int)6, (uint)7,
						(long)8, (ulong)9, };

					WriteCastCheck<int>(arr[0], "boxed:bool -> int", false);
					WriteCastCheck<bool>(arr[0], true, "boxed:bool -> bool", true);

					WriteCastCheck<sbyte>(arr[1], "boxed:byte -> sbyte", false);
					WriteCastCheck<byte>(arr[1], 1, "boxed:byte -> byte", true);
					WriteCastCheck<uint>(arr[1], "boxed:byte -> uint", false);

					WriteCastCheck<byte>(arr[2], "boxed:sbyte -> byte", false);
					WriteCastCheck<sbyte>(arr[2], 2, "boxed:sbyte -> sbyte", true);
					WriteCastCheck<int>(arr[2], "boxed:sbyte -> int", false);

					WriteCastCheck<int>(arr[3], "boxed:char -> int", false);
					WriteCastCheck<char>(arr[3], '3', "boxed:char -> char", true);

					WriteCastCheck<ushort>(arr[4], "boxed:short -> ushort", false);
					WriteCastCheck<short>(arr[4], 4, "boxed:short -> short", true);
					WriteCastCheck<int>(arr[4], "boxed:short -> int", false);

					WriteCastCheck<short>(arr[5], "boxed:ushort -> short", false);
					WriteCastCheck<ushort>(arr[5], 5, "boxed:ushort -> ushort", true);
					WriteCastCheck<uint>(arr[5], "boxed:ushort -> uint", false);

					WriteCastCheck<uint>(arr[6], "boxed:int -> uint", false);
					WriteCastCheck<int>(arr[6], 6, "boxed:int -> int", true);
					WriteCastCheck<long>(arr[6], "boxed:int -> long", false);

					WriteCastCheck<int>(arr[7], "boxed:uint -> int", false);
					WriteCastCheck<uint>(arr[7], 7, "boxed:uint -> uint", true);
					WriteCastCheck<ulong>(arr[7], "boxed:uint -> ulong", false);

					WriteCastCheck<ulong>(arr[8], "boxed:long -> ulong", false);
					WriteCastCheck<long>(arr[8], 8, "boxed:long -> long", true);
					WriteCastCheck<int>(arr[8], "boxed:long -> int", false);

					WriteCastCheck<long>(arr[9], "boxed:ulong -> long", false);
					WriteCastCheck<ulong>(arr[9], 9, "boxed:ulong -> ulong", true);
					WriteCastCheck<uint>(arr[9], "boxed:ulong -> uint", false);
				}

	            // test arithmetic casts

	            // test object casts

	            // test imports
	            {
	                int[] arr = new int[5];
	                arr.Clone();

	                ((int)Int32.MaxValue).ToString();
	                ((long)Int64.MaxValue).ToString();
	                ((ulong)UInt64.MaxValue).ToString();
	                ((uint)UInt32.MaxValue).ToString();
	                ((double)Double.MaxValue).ToString();
	                ((float)Single.MaxValue).ToString();
	                ((short)Int16.MaxValue).ToString();
	                ((ushort)UInt16.MaxValue).ToString();
	                ((sbyte)SByte.MaxValue).ToString();
	                ((byte)Byte.MaxValue).ToString();
	                ((char)char.MaxValue).ToString();
	                ((bool)true).ToString();
	            }
	        }
	    }

	    public static void Main(string[] args)
	    {
            Console.WriteLine("\"Hello World!\" from program: " + args[0]);

            Console.WriteLine("> Passed Parameters (" + (args.Length - 1) + "):");
            for (int i = 1; i < args.Length; i++) Console.WriteLine("    " + args[i]);
            Console.WriteLine();

			ArrayTest.Run ();
			PolymorphismTest.Run();
			DelegateTest.Run();
			OptimizedCRC.Run();
	        CastTest.Run();
	    }

	}
}
