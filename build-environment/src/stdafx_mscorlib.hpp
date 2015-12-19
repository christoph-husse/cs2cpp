#include "mscorlib.hpp"

namespace System { namespace Threading {
    
    struct MANAGED_API _Register_c__AnonStorey1B : public virtual System::Object{
        System::Action2<System::Object*>* callback;
        System::Object* state;
        
        void constructor();
        void __m__14();
        
    };
    
}}
namespace System { namespace Collections { namespace Concurrent { namespace Partitioners {
    
    struct MANAGED_API _GetOrderablePartitions_c__AnonStorey16 : public virtual System::Object{
        int32_t currentIndex;
        
        void constructor();
        int32_t __m__B();
        
    };
    
}}}}
namespace System { namespace Collections { namespace Concurrent { namespace Partitioners {
    
    struct MANAGED_API _GetOrderablePartitions_c__AnonStorey17 : public virtual System::Object{
        int64_t currentIndex;
        
        void constructor();
        int64_t __m__C();
        
    };
    
}}}}
namespace System { namespace IO {
    
    struct MANAGED_API _InternalGetFileSystemInfos_c__AnonStorey18 : public virtual System::Object{
        System::Collections::Generic::List<FileSystemInfo*>* infos;
        
        void constructor();
        void __m__D(System::String* dir);
        void __m__E(System::String* file);
        
    };
    
}}
namespace System { namespace Resources {
    
    struct MANAGED_API _ResourceValueAsStream_c__AnonStorey19 : public virtual System::Object{
        void* ptr;
        
        void constructor();
        void __m__F(System::Object* o, System::EventArgs* e);
        
    };
    
}}
namespace System { namespace Runtime { namespace Serialization {
    
    struct MANAGED_API _RegisterObject_c__AnonStorey1A : public virtual System::Object{
        SerializationCallbacks* sc;
        System::Object* obj;
        
        void constructor();
        void __m__13(StreamingContext ctx);
        
    };
    
}}}
namespace System { namespace Threading {
    
    struct MANAGED_API _Wait_c__AnonStorey1C : public virtual System::Object{
        int32_t millisecondsTimeout;
        Watch sw;
        
        void constructor();
        bool __m__15();
        
    };
    
}}
namespace System { namespace Threading { namespace Tasks {
    
    struct MANAGED_API _For_c__AnonStorey1D : public virtual System::Object{
        System::Action2<int32_t>* body;
        
        void constructor();
        void __m__16(int32_t index, ParallelLoopState* state);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    struct MANAGED_API _For_c__AnonStorey1E : public virtual System::Object{
        System::Action4<int32_t, ParallelLoopState*>* body;
        
        void constructor();
        System::Object* __m__18(int32_t i, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    struct MANAGED_API _For_c__AnonStorey20 : public virtual System::Object{
        System::Action2<int64_t>* body;
        
        void constructor();
        void __m__1B(int64_t index, ParallelLoopState* state);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    struct MANAGED_API _For_c__AnonStorey21 : public virtual System::Object{
        System::Action4<int64_t, ParallelLoopState*>* body;
        
        void constructor();
        System::Object* __m__1D(int64_t i, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    struct MANAGED_API _SpawnBestNumber_c__AnonStorey30 : public virtual System::Object{
        System::Action* action;
        System::Threading::CountdownEvent* evt;
        System::Action* callback;
        
        void constructor();
        void __m__45();
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    struct MANAGED_API _FromAsync_c__AnonStorey35 : public virtual System::Object{
        System::Action2<System::IAsyncResult*>* endMethod;
        System::IAsyncResult* asyncResult;
        
        void constructor();
        System::Object* __m__50(System::IAsyncResult* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    struct MANAGED_API _FromAsync_c__AnonStorey36 : public virtual System::Object{
        System::Action2<System::IAsyncResult*>* endMethod;
        
        void constructor();
        System::Object* __m__51(System::IAsyncResult* l);
        
    };
    
}}}
