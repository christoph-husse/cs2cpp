#include "stdafx_arrays_d4b6b5eeea339da.hpp"

namespace Demo {
    
    
    void _Run_c__AnonStorey40::constructor() {
    }
    
    int32_t _Run_c__AnonStorey40::__m__5D(int32_t x) {
        return (x * a);
    }
    
    int32_t _Run_c__AnonStorey40::__m__5E() {
        return (a * 3);
    }
    
    void _Run_c__AnonStorey40::__m__5F() {
         a = 13;
    }
    
    void _Run_c__AnonStorey40::__m__60(float x, int32_t y) {
         a = (int32_t)((2.f * x) + (float)(y));
    }
    
}
namespace Demo {
    // Automatically generated method stub
    void ClassA::methodA_2402d061b3119bd4() {
        return methodA();
    }
    
    // Automatically generated method stub
    void ClassA::methodA_fb48f75133248fd4() {
        return methodA2();
    }
    
}
namespace Demo {
    // Automatically generated method stub
    void ClassC::methodA_2402d061b3119bd4() {
        return methodA();
    }
    
    // Automatically generated method stub
    void ClassC::methodA_fb48f75133248fd4() {
        return methodA2();
    }
    
}
namespace Demo {
    // Automatically generated method stub
    void ClassD_Base::methodA_2402d061b3119bd4() {
        return methodA();
    }
    
    // Automatically generated method stub
    void ClassD_Base::methodA_fb48f75133248fd4() {
        return methodA_ca7f865b9a7ff5af();
    }
    
}
namespace Demo {
    // Automatically generated method stub
    void ClassE::methodA_2402d061b3119bd4() {
        return methodA();
    }
    
    // Automatically generated method stub
    void ClassE::methodA_fb48f75133248fd4() {
        return methodA();
    }
    
}
namespace Demo {
    
    
}
namespace Demo {
    
    
}
namespace Demo {
    
    
}
namespace Demo {
    
    cli::array<uint32_t>*  OptimizedCRC::Table;
    
    OptimizedCRC::OptimizedCRC()
    {
        static volatile bool initialized = false;
        static std::recursive_mutex mutex;
        if(!initialized)
        {
            std::lock_guard<std::recursive_mutex> lock(mutex);
            if(!initialized)
                static_constructor();
            initialized = true;
        }
        
    }
    
    void OptimizedCRC::static_constructor() {
        /*unchecked*/ {
            Table = (new cli::array<uint32_t>((int32_t)2048U));
            uint32_t i;
            for(i = 0U; (i < 256U); i++){
                uint32_t r = i;
                for(int32_t j = 0; (j < 8); j++) {
                    r = ((r >> 1) ^ (3988292384U & ~(((r & 1U) - 1U))));
                }
                Table->at((int32_t)i) = r;
            }
            for(; (i < 2048U); i++){
                uint32_t r = Table->at((int32_t)(i - 256U));
                Table->at((int32_t)i) = (Table->at((int32_t)(r & 255U)) ^ (r >> 8));
            }
        }
    }
    
    void OptimizedCRC::constructor() {
        Init();
    }
    
    void OptimizedCRC::Init() {
        this->value = 4294967295U;
    }
    
    void OptimizedCRC::UpdateByte(unsigned char b) {
        this->value = ((this->value >> 8) ^ Table->at(((int32_t)((unsigned char)this->value) ^ (int32_t)(b))));
    }
    
    void OptimizedCRC::Update(cli::array<unsigned char>* data, int32_t offset, int32_t count) {
        cli::ctor<System::ArraySegment<unsigned char>>(data, offset, count);
        if((count ==  0)) 
        {
            return;
        }
        cli::array<uint32_t> *table = Table;
        uint32_t crc = this->value;
        for(; (((offset & 7) != 0) && (count != 0)); count--) {
            crc = ((crc >> 8) ^ table->at(((int32_t)((unsigned char)crc) ^ (int32_t)(data->at(offset++)))));
        }
        if((count >= 8)) 
        {
            int32_t to = ((count - 8) & -8);
            (count = count - to);
            (to = to + offset);
            while((offset != to)) {
                (crc = crc ^ (uint32_t)((((int32_t)(data->at(offset)) + ((int32_t)(data->at((offset + 1))) << 8)) + ((int32_t)(data->at((offset + 2))) << 16)) + ((int32_t)(data->at((offset + 3))) << 24)));
                uint32_t high = (uint32_t)((((int32_t)(data->at((offset + 4))) + ((int32_t)(data->at((offset + 5))) << 8)) + ((int32_t)(data->at((offset + 6))) << 16)) + ((int32_t)(data->at((offset + 7))) << 24));
                (offset = offset + 8);
                crc = (((((((table->at(((int32_t)((unsigned char)crc) + 1792)) ^ table->at(((int32_t)((unsigned char)(crc = crc >> 8)) + 1536))) ^ table->at(((int32_t)((unsigned char)(crc = crc >> 8)) + 1280))) ^ table->at((int32_t)((crc >> 8) + 1024U))) ^ table->at(((int32_t)((unsigned char)high) + 768))) ^ table->at(((int32_t)((unsigned char)(high = high >> 8)) + 512))) ^ table->at(((int32_t)((unsigned char)(high = high >> 8)) + 256))) ^ table->at((int32_t)(high >> 8)));
            }
        }
        while((count-- != 0)) crc = ((crc >> 8) ^ table->at(((int32_t)((unsigned char)crc) ^ (int32_t)(data->at(offset++)))));
        this->value = crc;
    }
    
    int32_t OptimizedCRC::Compute(cli::array<unsigned char>* data, int32_t offset, int32_t size) {
        OptimizedCRC *crc = cli::gcnew<OptimizedCRC>();
        crc->Update(data, offset, size);
        return crc->get_Value();
    }
    
    int32_t OptimizedCRC::Compute2(cli::array<unsigned char>* data) {
        return Compute(data, 0, data->get_Length());
    }
    
    int32_t OptimizedCRC::Compute3(System::ArraySegment<unsigned char> block) {
        return Compute(block->get_Array(), block->get_Offset(), block->get_Count());
    }
    
    void OptimizedCRC::Run() {
        System::Console::WriteLine11(_T("Running CRC32 test..."));
        int32_t crc = Compute2((new cli::array<unsigned char>(134217728)));
        Testing::WriteCheck(crc, -2140847791);
        cli::array<unsigned char> *bytes = (new cli::array<unsigned char>(134217728));
        for(int32_t i = 0; (i < bytes->get_Length()); i++) {
            bytes->at(i) = (unsigned char)(i & 255);
        }
        crc = Compute2(bytes);
        Testing::WriteCheck(crc, 2124873618);
        System::Console::WriteLine();
    }
    
    int32_t OptimizedCRC::get_Value() {
        return (int32_t)~(this->value);
    }
    
}
namespace Demo {
    
    
    void ArrayTest::constructor() {
    }
    
    void ArrayTest::assert(bool condition) {
        if(!(condition)) 
        {
            throw cli::gcnew<System::Exception>(_T("Assertion failed!"));
        }
    }
    
    void ArrayTest::Run() {
        System::Console::WriteLine11(_T("Running array test..."));
        cli::array<int32_t> *arr = (new cli::array<int32_t>(10));
        int32_t i = 0;
        for(i = 0; (i < arr->get_Length()); i++) {
            arr->at(i) = i;
        }
        for(i = 0; (i < arr->get_Length()); i++) {
            assert((arr->at(i) ==  i));
        }
        i = 0;
        for(auto tmp_0 : arr) {
            auto e = cli::cast<int32_t>(tmp_0);
            assert((e ==  i++));
        }
        i = 0;
        for(auto tmp_1 : arr) {
            auto e = cli::cast<int32_t>(tmp_1);
            (i = i + e);
        }
        Testing::WriteCheck(i, 45);
    }
    
}
namespace Demo {
    
    
    void ClassA::constructor() {
    }
    
    void ClassA::methodA() {
        System::Console::Write10(_T("A"));
    }
    
    void ClassA::methodA2() {
        System::Console::Write10(_T("B"));
    }
    
}
namespace Demo {
    
    
    void ClassC::constructor() {
    }
    
    void ClassC::methodA() {
        System::Console::Write10(_T("A"));
    }
    
    void ClassC::methodA2() {
        System::Console::Write10(_T("B"));
    }
    
    void ClassC::methodA3() {
        System::Console::Write10(_T("C"));
    }
    
}
namespace Demo {
    
    
    void ClassD_Base::constructor() {
    }
    
    void ClassD_Base::methodA() {
        System::Console::Write10(_T("A"));
    }
    
}
namespace Demo {
    
    
    void ClassD::constructor() {
    }
    
    void ClassD::methodA_ca7f865b9a7ff5af() {
        System::Console::Write10(_T("B"));
    }
    
}
namespace Demo {
    
    
    void ClassE::constructor() {
    }
    
    void ClassE::methodA() {
        System::Console::Write10(_T("E"));
    }
    
}
namespace Demo {
    
    
    void PolymorphismTest::constructor() {
    }
    
    void PolymorphismTest::Run() {
        System::Console::WriteLine();
        System::Console::WriteLine11(_T("Running polymorphism test..."));
        ClassA *a = cli::gcnew<ClassA>();
        cli::cast<IfaceA*>(a)->methodA_2402d061b3119bd4();
        cli::cast<IfaceB*>(a)->methodA_fb48f75133248fd4();
        a->methodA2();
        System::Console::WriteLine();
        ClassC *c = cli::gcnew<ClassC>();
        cli::cast<IfaceA*>(c)->methodA_2402d061b3119bd4();
        cli::cast<IfaceB*>(c)->methodA_fb48f75133248fd4();
        c->methodA3();
        System::Console::WriteLine();
        ClassD *d = cli::gcnew<ClassD>();
        cli::cast<IfaceA*>(d)->methodA_2402d061b3119bd4();
        cli::cast<IfaceB*>(d)->methodA_fb48f75133248fd4();
        d->methodA_ca7f865b9a7ff5af();
        System::Console::WriteLine();
        ClassE *e = cli::gcnew<ClassE>();
        cli::cast<IfaceA*>(e)->methodA_2402d061b3119bd4();
        cli::cast<IfaceB*>(e)->methodA_fb48f75133248fd4();
        e->methodA();
        System::Console::WriteLine();
    }
    
}
namespace Demo {
    
    System::Func2<int32_t, int32_t>*  DelegateTest::__f__am_cache0;
    
    void DelegateTest::constructor() {
    }
    
    int32_t DelegateTest::delegateImplA(int32_t x) {
        return (x * 13);
    }
    
    int32_t DelegateTest::delegateImplB(int32_t x) {
        return (x * 7);
    }
    
    void DelegateTest::Run() {
        System::Console::WriteLine();
        System::Console::WriteLine11(_T("Running delegate test..."));
        System::Func2<int32_t, int32_t> *lambdaA = cli::bind([&] (int32_t x) -> int32_t {
            return (x * 4);
        }
        );
        auto storey_2 = cli::gcnew<_Run_c__AnonStorey40>();
        storey_2->a = lambdaA->Invoke(4);
        Testing::WriteCheck(storey_2->a, 16);
        storey_2->a = 1;
        System::Func2<int32_t, int32_t> *funcA = cli::bind(storey_2, &_Run_c__AnonStorey40::__m__5D);
        storey_2->a = funcA->Invoke(3);
        storey_2->a = funcA->Invoke(3);
        Testing::WriteCheck(storey_2->a, 9);
        storey_2->a = 1;
        for(int32_t i = 1; (i <= 3); i++){
            (storey_2->a = storey_2->a + funcA->Invoke(i));
        }
        Testing::WriteCheck(storey_2->a, 24);
        System::Func<int32_t> *funcB = cli::bind(storey_2, &_Run_c__AnonStorey40::__m__5E);
        storey_2->a = 4;
        storey_2->a = funcB->Invoke();
        Testing::WriteCheck(storey_2->a, 12);
        System::Action *funcC = cli::bind(storey_2, &_Run_c__AnonStorey40::__m__5F);
        funcC->Invoke();
        Testing::WriteCheck(storey_2->a, 13);
        System::Action4<float, int32_t> *funcD = cli::bind(storey_2, &_Run_c__AnonStorey40::__m__60);
        funcD->Invoke(3.5f, 2);
        Testing::WriteCheck(storey_2->a, 9);
        System::Func2<int32_t, int32_t> *memberA = cli::bind(&DelegateTest::delegateImplA);
        System::Func2<int32_t, int32_t> *memberB = cli::bind(cli::gcnew<DelegateTest>(), &DelegateTest::delegateImplB);
        storey_2->a = memberA->Invoke(3);
        Testing::WriteCheck(storey_2->a, 39);
        storey_2->a = memberB->Invoke(2);
        Testing::WriteCheck(storey_2->a, 14);
        System::Console::WriteLine();
    }
    
    int32_t DelegateTest::_Run_m__5C(int32_t x) {
        return (x * 4);
    }
    
}
namespace Demo {
    
    
    void CastTest::constructor() {
    }
    
    void CastTest::Run() {
        {
            TestStruct a = cli::ctor<TestStruct>();
            a->a = 9;
            ITestFace *a_boxed = cli::box<ITestFace*>(a);
            a->a = 7;
            System::Object *a_boxed2 = cli::box(a);
            a->a = 13;
            Testing::WriteCheck(a->a, 13);
            a = cli::unbox<TestStruct>(a_boxed);
            Testing::WriteCheck(a->a, 9);
            a = cli::unbox<TestStruct>(a_boxed2);
            Testing::WriteCheck(a->a, 7);
            a_boxed = cli::cast<ITestFace*>(cli::box<ITestFace*>(a));
            a_boxed2 = cli::cast<System::Object*>(cli::box(a));
            Testing::WriteCheck2(cli::is<TestStruct>(a_boxed), _T("a_boxed is TestStruct"), true);
            Testing::WriteCheck2(cli::is<TestStruct>(a_boxed2), _T("a_boxed2 is TestStruct"), true);
            Testing::WriteCheck2(cli::is<TestStruct2>(a_boxed2), _T("a_boxed2 is TestStruct2"), false);
            Testing::WriteCheck2(cli::is<ITestFace>(a_boxed2), _T("a_boxed2 is ITestFace"), true);
            Testing::WriteCheck2(cli::is<ITestFace2>(a_boxed2), _T("a_boxed2 is ITestFace2"), false);
            Testing::WriteCheck2((cli::as<ITestFace*>(a_boxed2) != nullptr), _T("a_boxed2 is ITestFace"), true);
            Testing::WriteCheck2((cli::as<ITestFace2*>(a_boxed2) != nullptr), _T("a_boxed2 is ITestFace2"), false);
            WriteCastCheck_1<ITestFace*>(cli::box(a), _T("(ITestFace)a"), true);
            WriteCastCheck_1<ITestFace2*>(cli::box(a), _T("(ITestFace2)a"), false);
            WriteCastCheck_1<TestStruct2>(cli::box(a), _T("(TestStruct2)a"), false);
            WriteCastCheck_1<TestStruct>(cli::box(a), _T("(TestStruct)a"), true);
        }
        {
            cli::array<System::Object*> *arr = (new cli::array<System::Object*>({cli::box(true), cli::box((System::Byte)1), cli::box((System::SByte)2), cli::box(u'3'), cli::box((System::Int16)4), cli::box((System::UInt16)5), cli::box((System::Int32)6), cli::box((System::UInt32)7), cli::box((System::Int64)8), cli::box((System::UInt64)9)}));
            WriteCastCheck_1<int32_t>(arr->at(0), _T("boxed:bool -> int"), false);
            WriteCastCheck_12<bool>(arr->at(0), true, _T("boxed:bool -> bool"), true);
            WriteCastCheck_1<signed char>(arr->at(1), _T("boxed:byte -> sbyte"), false);
            WriteCastCheck_12<unsigned char>(arr->at(1), 1, _T("boxed:byte -> byte"), true);
            WriteCastCheck_1<uint32_t>(arr->at(1), _T("boxed:byte -> uint"), false);
            WriteCastCheck_1<unsigned char>(arr->at(2), _T("boxed:sbyte -> byte"), false);
            WriteCastCheck_12<signed char>(arr->at(2), 2, _T("boxed:sbyte -> sbyte"), true);
            WriteCastCheck_1<int32_t>(arr->at(2), _T("boxed:sbyte -> int"), false);
            WriteCastCheck_1<int32_t>(arr->at(3), _T("boxed:char -> int"), false);
            WriteCastCheck_12<char16_t>(arr->at(3), u'3', _T("boxed:char -> char"), true);
            WriteCastCheck_1<uint16_t>(arr->at(4), _T("boxed:short -> ushort"), false);
            WriteCastCheck_12<int16_t>(arr->at(4), 4, _T("boxed:short -> short"), true);
            WriteCastCheck_1<int32_t>(arr->at(4), _T("boxed:short -> int"), false);
            WriteCastCheck_1<int16_t>(arr->at(5), _T("boxed:ushort -> short"), false);
            WriteCastCheck_12<uint16_t>(arr->at(5), 5, _T("boxed:ushort -> ushort"), true);
            WriteCastCheck_1<uint32_t>(arr->at(5), _T("boxed:ushort -> uint"), false);
            WriteCastCheck_1<uint32_t>(arr->at(6), _T("boxed:int -> uint"), false);
            WriteCastCheck_12<int32_t>(arr->at(6), 6, _T("boxed:int -> int"), true);
            WriteCastCheck_1<int64_t>(arr->at(6), _T("boxed:int -> long"), false);
            WriteCastCheck_1<int32_t>(arr->at(7), _T("boxed:uint -> int"), false);
            WriteCastCheck_12<uint32_t>(arr->at(7), 7U, _T("boxed:uint -> uint"), true);
            WriteCastCheck_1<uint64_t>(arr->at(7), _T("boxed:uint -> ulong"), false);
            WriteCastCheck_1<uint64_t>(arr->at(8), _T("boxed:long -> ulong"), false);
            WriteCastCheck_12<int64_t>(arr->at(8), 8L, _T("boxed:long -> long"), true);
            WriteCastCheck_1<int32_t>(arr->at(8), _T("boxed:long -> int"), false);
            WriteCastCheck_1<int64_t>(arr->at(9), _T("boxed:ulong -> long"), false);
            WriteCastCheck_12<uint64_t>(arr->at(9), 9UL, _T("boxed:ulong -> ulong"), true);
            WriteCastCheck_1<uint32_t>(arr->at(9), _T("boxed:ulong -> uint"), false);
        }
        {
            cli::array<int32_t> *arr = (new cli::array<int32_t>(5));
            cli::import(arr)->Clone();
            cli::import(2147483647)->ToString_1636a0751cb9ac11();
            cli::import(9223372036854775807L)->ToString_1636a0751cb9ac11();
            cli::import(18446744073709551615UL)->ToString_1636a0751cb9ac11();
            cli::import(4294967295U)->ToString_1636a0751cb9ac11();
            cli::import(std::numeric_limits<double>::max())->ToString_1636a0751cb9ac11();
            cli::import(std::numeric_limits<float>::max())->ToString_1636a0751cb9ac11();
            cli::import(32767)->ToString_1636a0751cb9ac11();
            cli::import(65535)->ToString_1636a0751cb9ac11();
            cli::import(127)->ToString_1636a0751cb9ac11();
            cli::import(255)->ToString_1636a0751cb9ac11();
            cli::import(u'\xffff')->ToString_1636a0751cb9ac11();
            cli::import(true)->ToString_1636a0751cb9ac11();
        }
    }
    
}
namespace Demo {
    
    
    void Testing::constructor() {
    }
    
    void Testing::WriteCheck(int32_t a, int32_t expect) {
        System::Console::Write10(cli::concat(_T("a = "), cli::box(a), _T(" (expected "), cli::box(expect), _T(")")));
        if((a ==  expect)) 
        {
            System::Console::WriteLine11(_T(" [OK]"));
        }
         else 
        {
            System::Console::WriteLine11(_T(" [ERROR]"));
        }
    }
    
    void Testing::WriteCheck2(bool cond, System::String* desc, bool expect) {
        System::Console::Write10(cli::concat(desc, _T(" = "), cli::box(cond), _T(" (expected "), cli::box(expect), _T(")")));
        if((cond ==  expect)) 
        {
            System::Console::WriteLine11(_T(" [OK]"));
        }
         else 
        {
            System::Console::WriteLine11(_T(" [ERROR]"));
        }
    }
    
    void Testing::Main(cli::array<System::String*>* args) {
        System::Console::WriteLine11(cli::concat(_T("\"Hello World!\" from program: "), args->at(0)));
        System::Console::WriteLine11(cli::concat(_T("> Passed Parameters ("), cli::box((args->get_Length() - 1))));
        for(int32_t i = 1; (i < args->get_Length()); i++) {
            System::Console::WriteLine11(cli::concat(_T("    "), args->at(i)));
        }
        System::Console::WriteLine();
        ArrayTest::Run();
        PolymorphismTest::Run();
        DelegateTest::Run();
        OptimizedCRC::Run();
        CastTest::Run();
    }
    
}


DEFINE_MAIN_ROUTINE(Demo::Testing::Main);

static void Constructor_Test() { 
    new Demo::TestStruct();
    new Demo::TestStruct2();
    new Demo::TestClass();
    new Demo::OptimizedCRC();
    new Demo::ArrayTest();
    new Demo::ClassA();
    new Demo::ClassC();
    new Demo::ClassD();
    new Demo::ClassE();
    new Demo::PolymorphismTest();
    new Demo::DelegateTest();
    new Demo::CastTest();
    new Demo::Testing();
}

