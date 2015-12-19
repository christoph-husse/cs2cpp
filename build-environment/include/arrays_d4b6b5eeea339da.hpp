namespace Demo {
    struct MANAGED_API OptimizedCRC;
    struct MANAGED_API ArrayTest;
    struct MANAGED_API ClassA;
    struct MANAGED_API ClassC;
    struct MANAGED_API ClassD_Base;
    struct MANAGED_API ClassD;
    struct MANAGED_API ClassE;
    struct MANAGED_API PolymorphismTest;
    struct MANAGED_API DelegateTest;
    struct MANAGED_API CastTest;
    struct MANAGED_API Testing;
    struct MANAGED_API TestStruct;
    struct MANAGED_API TestStruct2;
    struct MANAGED_API TestClass;
    struct MANAGED_API IfaceA;
    struct MANAGED_API IfaceB;
    struct MANAGED_API ITestFace;
    struct MANAGED_API ITestFace2;
}
namespace cli {
}
namespace Demo {
    
    struct MANAGED_API IfaceA : public virtual System::Object{
        
        virtual void methodA_2402d061b3119bd4() = 0;
        
    };
    
    
    struct MANAGED_API IfaceB : public virtual System::Object{
        
        virtual void methodA_fb48f75133248fd4() = 0;
        
    };
    
    
    struct MANAGED_API ITestFace : public virtual System::Object{
        
        
    };
    
    
    struct MANAGED_API ITestFace2 : public virtual System::Object{
        
        
    };
    
}
namespace Demo {
    
    struct MANAGED_API TestStruct : public virtual System::ValueType, public virtual ITestFace{
        int32_t a;
        
        TestStruct* operator ->() { return this; }
        TestStruct() = default;
        TestStruct(const TestStruct* src);
        operator TestStruct*() { return ::cli::box<TestStruct*>(this); }
        
        
    };
    
    
    struct MANAGED_API TestStruct2 : public virtual System::ValueType, public virtual ITestFace2{
        int32_t a;
        
        TestStruct2* operator ->() { return this; }
        TestStruct2() = default;
        TestStruct2(const TestStruct2* src);
        operator TestStruct2*() { return ::cli::box<TestStruct2*>(this); }
        
        
    };
    
    
    struct MANAGED_API TestClass : public virtual System::ValueType, public virtual ITestFace{
        
        TestClass* operator ->() { return this; }
        TestClass() = default;
        TestClass(const TestClass* src);
        operator TestClass*() { return ::cli::box<TestClass*>(this); }
        
        
    };
    
}
namespace Demo {
    
    struct MANAGED_API ClassD_Base : public virtual System::Object, public virtual IfaceA, public virtual IfaceB{
        
        void constructor();
        void methodA();
        virtual void methodA_ca7f865b9a7ff5af() = 0;
        
        virtual void methodA_2402d061b3119bd4() override;
        virtual void methodA_fb48f75133248fd4() override;
    };
    
}
namespace Demo {
    
    struct MANAGED_API ClassD : public virtual ClassD_Base{
        
        void constructor();
        virtual void methodA_ca7f865b9a7ff5af() override;
        
    };
    
}
namespace Demo {
    
    struct MANAGED_API OptimizedCRC : public virtual System::Object{
        static constexpr uint32_t kCrcPoly = 3988292384U;
        static constexpr uint32_t kInitial = 4294967295U;
        static constexpr uint32_t CRC_NUM_TABLES = 8U;
        static cli::array<uint32_t>* Table;
        uint32_t value;
        
        OptimizedCRC();
        static void static_constructor();
        void constructor();
        void Init();
        void UpdateByte(unsigned char b);
        void Update(cli::array<unsigned char>* data, int32_t offset, int32_t count);
        static int32_t Compute(cli::array<unsigned char>* data, int32_t offset, int32_t size);
        static int32_t Compute2(cli::array<unsigned char>* data);
        static int32_t Compute3(System::ArraySegment<unsigned char> block);
        static void Run();
        int32_t get_Value();
        
    };
    
    
    struct MANAGED_API ArrayTest : public virtual System::Object{
        
        void constructor();
        static void assert(bool condition);
        static void Run();
        
    };
    
    
    struct MANAGED_API ClassA : public virtual System::Object, public virtual IfaceA, public virtual IfaceB{
        
        void constructor();
        void methodA();
        void methodA2();
        
        virtual void methodA_2402d061b3119bd4() override;
        virtual void methodA_fb48f75133248fd4() override;
    };
    
    
    struct MANAGED_API ClassC : public virtual System::Object, public virtual IfaceA, public virtual IfaceB{
        
        void constructor();
        void methodA();
        void methodA2();
        void methodA3();
        
        virtual void methodA_2402d061b3119bd4() override;
        virtual void methodA_fb48f75133248fd4() override;
    };
    
    
    struct MANAGED_API ClassE : public virtual ClassD{
        
        void constructor();
        void methodA() /*new*/;
        
        virtual void methodA_2402d061b3119bd4() override;
        virtual void methodA_fb48f75133248fd4() override;
    };
    
    
    struct MANAGED_API PolymorphismTest : public virtual System::Object{
        
        void constructor();
        static void Run();
        
    };
    
    
    struct MANAGED_API DelegateTest : public virtual System::Object{
        static System::Func2<int32_t, int32_t>* __f__am_cache0;
        
        void constructor();
        static int32_t delegateImplA(int32_t x);
        int32_t delegateImplB(int32_t x);
        static void Run();
        static int32_t _Run_m__5C(int32_t x);
        
    };
    
    
    struct MANAGED_API CastTest : public virtual System::Object{
        
        void constructor();
        template<class T>
        static void WriteCastCheck_1(System::Object* value, System::String* desc, bool expect);
        template<class T>
        static void WriteCastCheck_12(System::Object* value, T comp, System::String* desc, bool expect);
        static void Run();
        
    };
    
    
    struct MANAGED_API Testing : public virtual System::Object{
        
        void constructor();
        static void WriteCheck(int32_t a, int32_t expect);
        static void WriteCheck2(bool cond, System::String* desc, bool expect);
        static void Main(cli::array<System::String*>* args);
        
    };
    
}

#include "K:\projects\BachelorThesis.tar\build-environment/include/arrays_d4b6b5eeea339da.template.hpp"
