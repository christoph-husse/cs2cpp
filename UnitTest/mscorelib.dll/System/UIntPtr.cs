//
// System.UIntPtr.cs
//
// Author:
//   Michael Lambert (michaellambert@email.com)
//
// (C) 2001 Michael Lambert, All Rights Reserved
//
// Remarks:
// Requires '/unsafe' compiler option.  This class uses void*,
// ulong, and uint in overloaded constructors, conversion, and
// cast members in the public interface.  Using pointers is not
// valid CLS and the methods in question have been marked with
// the CLSCompliant attribute that avoid compiler warnings.

//
// Copyright (C) 2004 Novell, Inc (http://www.novell.com)
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

using System.Globalization;
using System.Runtime.Serialization;
using System.Runtime.InteropServices;
using System.Runtime.ConstrainedExecution;

namespace System
{
	[Serializable]
	[CLSCompliant (false)]
	[System.Runtime.InteropServices.ComVisible (true)]
	public unsafe struct UIntPtr : ISerializable
	{
		public static readonly UIntPtr Zero = new UIntPtr (0u);
        private void* m_value;
	
		public UIntPtr (ulong value)
		{
			if ((value > UInt32.MaxValue) && (UIntPtr.Size < 8)) {
				throw new OverflowException (
					Locale.GetText ("This isn't a 64bits machine."));
			}

			m_value = (void*) value;
		}
		
		public UIntPtr (uint value)
		{
			m_value = (void*)value;
		}
	
		[CLSCompliant (false)]
		public unsafe UIntPtr (void* value)
		{
			m_value = value;
		}
	
		public override bool Equals (object obj)
		{
			if( obj is UIntPtr ) {
				UIntPtr obj2 = (UIntPtr)obj;
				return this.m_value == obj2.m_value;
			}
			return false;
		}

		public override int GetHashCode ()
		{
			return (int)m_value;
		}

		public uint ToUInt32 ()
		{
			return (uint) m_value;
		}

		public ulong ToUInt64 ()
		{
			return (ulong) m_value;
		}

		[CLSCompliant (false)]
		public unsafe void* ToPointer ()
		{
			return m_value;
		}

		public override string ToString ()
		{
			return ((uint) m_value).ToString();
		}

		// Interface ISerializable
		void ISerializable.GetObjectData (SerializationInfo info, StreamingContext context)
		{
			if (info == null)
				throw new ArgumentNullException ("info");

			info.AddValue ("pointer", (ulong)m_value);
		}

		public static bool operator == (UIntPtr value1, UIntPtr value2)
		{
			return value1.m_value == value2.m_value;
		}

		public static bool operator != (UIntPtr value1, UIntPtr value2)
		{
			return value1.m_value != value2.m_value;
		}

		public static explicit operator ulong (UIntPtr value)
		{
			return (ulong)value.m_value;
		}

		public static explicit operator uint (UIntPtr value)
		{
			return (uint)value.m_value;
		}

		public static explicit operator UIntPtr (ulong value)
		{
			return new UIntPtr (value);
		}

		[CLSCompliant (false)]
		public unsafe static explicit operator UIntPtr (void* value)
		{
			return new UIntPtr (value);
		}

		[CLSCompliant (false)]
		public unsafe static explicit operator void* (UIntPtr value)
		{
			return value.ToPointer ();
		}

		public static explicit operator UIntPtr (uint value)
		{
			return new UIntPtr (value);
		}

		public static int Size {
			get { return sizeof (void*); }
		}

#if NET_4_0
		public static UIntPtr Add (UIntPtr pointer, int offset)
		{
			return (UIntPtr) (unchecked (((byte *) pointer) + offset));
		}

		public static UIntPtr Subtract (UIntPtr pointer, int offset)
		{
			return (UIntPtr) (unchecked (((byte *) pointer) - offset));
		}

		public static UIntPtr operator + (UIntPtr pointer, int offset)
		{
			return (UIntPtr) (unchecked (((byte *) pointer) + offset));
		}

		public static UIntPtr operator - (UIntPtr pointer, int offset)
		{
			return (UIntPtr) (unchecked (((byte *) pointer) - offset));
		}
#endif
	}
}