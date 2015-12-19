namespace System { namespace Collections { namespace Concurrent {
    
    template<class TKey, class TValue> struct MANAGED_API _AddOrUpdate_c__AnonStorey12 : public virtual System::Object{
        TKey key;
        System::Func2<TKey, TValue>* addValueFactory;
        System::Func4<TKey, TValue, TValue>* updateValueFactory;
        
        void constructor();
        System::Collections::Generic::KeyValuePair<TKey, TValue> __m__4();
        System::Collections::Generic::KeyValuePair<TKey, TValue> __m__5(System::Collections::Generic::KeyValuePair<TKey, TValue> e);
        
    };
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    
    template<class TKey, class TValue> struct MANAGED_API _AddOrUpdate_c__AnonStorey13 : public virtual System::Object{
        TValue addValue;
        
        void constructor();
        TValue __m__6(TKey _);
        
    };
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    
    template<class TKey, class TValue> struct MANAGED_API _TryUpdate_c__AnonStorey14 : public virtual System::Object{
        TValue comparisonValue;
        
        void constructor();
        bool __m__7(System::Collections::Generic::KeyValuePair<TKey, TValue> e);
        
    };
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    
    template<class TKey, class TValue> struct MANAGED_API _GetOrAdd_c__AnonStorey15 : public virtual System::Object{
        TKey key;
        System::Func2<TKey, TValue>* valueFactory;
        
        void constructor();
        System::Collections::Generic::KeyValuePair<TKey, TValue> __m__8();
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TLocal> struct MANAGED_API _For_c__AnonStorey1F : public virtual System::Object{
        int32_t currentIndex;
        cli::array<StealRange*>* ranges;
        int32_t num;
        int32_t toExclusive;
        int32_t step;
        System::Func<TLocal>* localInit;
        ExternalInfos* infos;
        ParallelOptions* parallelOptions;
        System::Func3<int32_t, ParallelLoopState*, TLocal, TLocal>* body;
        int32_t fromInclusive;
        System::Action2<TLocal>* localFinally;
        
        void constructor();
        void __m__1A();
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource, class TLocal> struct MANAGED_API _ForEach_c__AnonStorey22 : public virtual System::Object{
        System::Collections::Generic::IList2<System::Collections::Generic::IEnumerator2<TSource>*>* slices;
        int32_t sliceIndex;
        System::Func<TLocal>* init;
        ExternalInfos* infos;
        SimpleConcurrentBag<TSource>* bag;
        ParallelOptions* options;
        System::Func3<TSource, ParallelLoopState*, TLocal, TLocal>* action;
        System::Action2<TLocal>* destruct;
        
        void constructor();
        void __m__1F();
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey23 : public virtual System::Object{
        System::Action2<TSource>* body;
        
        void constructor();
        System::Object* __m__21(TSource e, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey24 : public virtual System::Object{
        System::Action4<TSource, ParallelLoopState*>* body;
        
        void constructor();
        System::Object* __m__24(TSource e, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey25 : public virtual System::Object{
        System::Action3<TSource, ParallelLoopState*, int64_t>* body;
        
        void constructor();
        System::Object* __m__27(TSource e, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey26 : public virtual System::Object{
        System::Action4<TSource, ParallelLoopState*>* body;
        
        void constructor();
        System::Object* __m__2A(TSource e, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey27 : public virtual System::Object{
        System::Action3<TSource, ParallelLoopState*, int64_t>* body;
        
        void constructor();
        System::Object* __m__2D(TSource e, ParallelLoopState* s, int64_t i, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey28 : public virtual System::Object{
        System::Action2<TSource>* body;
        
        void constructor();
        System::Object* __m__30(TSource e, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey29 : public virtual System::Object{
        System::Action2<TSource>* body;
        
        void constructor();
        System::Object* __m__33(TSource e, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey2A : public virtual System::Object{
        System::Action4<TSource, ParallelLoopState*>* body;
        
        void constructor();
        System::Object* __m__36(TSource e, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey2B : public virtual System::Object{
        System::Action3<TSource, ParallelLoopState*, int64_t>* body;
        
        void constructor();
        System::Object* __m__39(TSource e, ParallelLoopState* s, int64_t i, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey2C : public virtual System::Object{
        System::Action3<TSource, ParallelLoopState*, int64_t>* body;
        
        void constructor();
        System::Object* __m__3C(TSource e, ParallelLoopState* s, int64_t i, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey2D : public virtual System::Object{
        System::Action2<TSource>* body;
        
        void constructor();
        System::Object* __m__3F(TSource e, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource> struct MANAGED_API _ForEach_c__AnonStorey2E : public virtual System::Object{
        System::Action4<TSource, ParallelLoopState*>* body;
        
        void constructor();
        System::Object* __m__42(TSource e, ParallelLoopState* s, System::Object* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TSource, class TLocal> struct MANAGED_API _ForEach_c__AnonStorey2F : public virtual System::Object{
        System::Func5<TSource, ParallelLoopState*, int64_t, TLocal, TLocal>* body;
        
        void constructor();
        TLocal __m__44(System::Collections::Generic::KeyValuePair<int64_t, TSource> e, ParallelLoopState* s, TLocal l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TAntecedentResult> struct MANAGED_API _ContinueWhenAny_c__AnonStorey31 : public virtual System::Object{
        System::Action2<Task2<TAntecedentResult>*>* continuationAction;
        
        void constructor();
        void __m__49(Task* o);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TAntecedentResult, class TResult> struct MANAGED_API _ContinueWhenAny_c__AnonStorey32 : public virtual System::Object{
        System::Func2<Task2<TAntecedentResult>*, TResult>* continuationFunction;
        
        void constructor();
        TResult __m__4B(Task* t);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TAntecedentResult> struct MANAGED_API _ContinueWhenAll_c__AnonStorey33 : public virtual System::Object{
        System::Action2<cli::array<Task2<TAntecedentResult>*>*>* continuationAction;
        cli::array<Task2<TAntecedentResult>*>* tasks;
        
        void constructor();
        void __m__4D(cli::array<Task*>* o);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TAntecedentResult, class TResult> struct MANAGED_API _ContinueWhenAll_c__AnonStorey34 : public virtual System::Object{
        System::Func2<cli::array<Task2<TAntecedentResult>*>*, TResult>* continuationFunction;
        cli::array<Task2<TAntecedentResult>*>* tasks;
        
        void constructor();
        TResult __m__4F(cli::array<Task*>* o);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TArg1> struct MANAGED_API _FromAsync_c__AnonStorey37 : public virtual System::Object{
        System::Action2<System::IAsyncResult*>* endMethod;
        
        void constructor();
        System::Object* __m__52(System::IAsyncResult* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TArg1, class TArg2> struct MANAGED_API _FromAsync_c__AnonStorey38 : public virtual System::Object{
        System::Action2<System::IAsyncResult*>* endMethod;
        
        void constructor();
        System::Object* __m__53(System::IAsyncResult* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TArg1, class TArg2, class TArg3> struct MANAGED_API _FromAsync_c__AnonStorey39 : public virtual System::Object{
        System::Action2<System::IAsyncResult*>* endMethod;
        
        void constructor();
        System::Object* __m__54(System::IAsyncResult* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult> struct MANAGED_API _StartNew_c__AnonStorey3A : public virtual System::Object{
        System::Func<TResult>* function;
        
        void constructor();
        TResult __m__55(System::Object* o);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult> struct MANAGED_API _FromIAsyncResult_c__AnonStorey3B : public virtual System::Object{
        System::Func2<System::IAsyncResult*, TResult>* endMethod;
        System::IAsyncResult* asyncResult;
        System::Threading::CancellationTokenSource* source;
        Task2<TResult>* task;
        TaskScheduler* scheduler;
        
        void constructor();
        TResult __m__56(System::Object* l);
        void __m__57(System::Object* s, bool t);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult> struct MANAGED_API _FromAsyncBeginEnd_c__AnonStorey3C : public virtual System::Object{
        TaskCompletionSource<TResult>* tcs;
        System::Func2<System::IAsyncResult*, TResult>* endMethod;
        
        void constructor();
        void __m__58(System::IAsyncResult* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult, class TArg1> struct MANAGED_API _FromAsyncBeginEnd_c__AnonStorey3D : public virtual System::Object{
        TaskCompletionSource<TResult>* tcs;
        System::Func2<System::IAsyncResult*, TResult>* endMethod;
        
        void constructor();
        void __m__59(System::IAsyncResult* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult, class TArg1, class TArg2> struct MANAGED_API _FromAsyncBeginEnd_c__AnonStorey3E : public virtual System::Object{
        TaskCompletionSource<TResult>* tcs;
        System::Func2<System::IAsyncResult*, TResult>* endMethod;
        
        void constructor();
        void __m__5A(System::IAsyncResult* l);
        
    };
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult, class TArg1, class TArg2, class TArg3> struct MANAGED_API _FromAsyncBeginEnd_c__AnonStorey3F : public virtual System::Object{
        TaskCompletionSource<TResult>* tcs;
        System::Func2<System::IAsyncResult*, TResult>* endMethod;
        
        void constructor();
        void __m__5B(System::IAsyncResult* l);
        
    };
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    
    
    template<class TKey, class TValue>
    void _AddOrUpdate_c__AnonStorey12<TKey, TValue>::constructor() {
    }
    
    template<class TKey, class TValue>
    System::Collections::Generic::KeyValuePair<TKey, TValue> _AddOrUpdate_c__AnonStorey12<TKey, TValue>::__m__4() {
        return ConcurrentDictionary<TKey, TValue>::template Make_2<TKey, TValue>(key, addValueFactory->Invoke(key));
    }
    
    template<class TKey, class TValue>
    System::Collections::Generic::KeyValuePair<TKey, TValue> _AddOrUpdate_c__AnonStorey12<TKey, TValue>::__m__5(System::Collections::Generic::KeyValuePair<TKey, TValue> e) {
        return ConcurrentDictionary<TKey, TValue>::template Make_2<TKey, TValue>(key, updateValueFactory->Invoke(key, e->get_Value()));
    }
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    
    
    template<class TKey, class TValue>
    void _AddOrUpdate_c__AnonStorey13<TKey, TValue>::constructor() {
    }
    
    template<class TKey, class TValue>
    TValue _AddOrUpdate_c__AnonStorey13<TKey, TValue>::__m__6(TKey _) {
        return addValue;
    }
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    
    
    template<class TKey, class TValue>
    void _TryUpdate_c__AnonStorey14<TKey, TValue>::constructor() {
    }
    
    template<class TKey, class TValue>
    bool _TryUpdate_c__AnonStorey14<TKey, TValue>::__m__7(System::Collections::Generic::KeyValuePair<TKey, TValue> e) {
        return cli::import(e->get_Value())->Equals_ed975d2f4a7d193e(cli::box(comparisonValue));
    }
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    
    
    template<class TKey, class TValue>
    void _GetOrAdd_c__AnonStorey15<TKey, TValue>::constructor() {
    }
    
    template<class TKey, class TValue>
    System::Collections::Generic::KeyValuePair<TKey, TValue> _GetOrAdd_c__AnonStorey15<TKey, TValue>::__m__8() {
        return ConcurrentDictionary<TKey, TValue>::template Make_2<TKey, TValue>(key, valueFactory->Invoke(key));
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TLocal>
    void _For_c__AnonStorey1F<TLocal>::constructor() {
    }
    
    template<class TLocal>
    void _For_c__AnonStorey1F<TLocal>::__m__1A() {
        int32_t localWorker = System::Threading::Interlocked::Increment(currentIndex);
        StealRange *range = ranges->at(localWorker);
        int32_t index = range->V64->Actual;
        int32_t stopIndex = ((localWorker + 1) ==  num) ? toExclusive : System::Math::Min5(toExclusive, (index + step));
        TLocal local = localInit->Invoke();
        ParallelLoopState *state = cli::gcnew<ParallelLoopState>(infos);
        System::Threading::CancellationToken token = parallelOptions->get_CancellationToken();
        {
            cli::finally_guard([&]() {
                localFinally->Invoke(local);
            });
            for(int32_t i = index; (i < stopIndex); ){
                if(infos->IsStopped) 
                {
                    return;
                }
                token->ThrowIfCancellationRequested();
                if((i >= (stopIndex - range->V64->Stolen))) 
                {
                    break;
                }
                if((((System::Nullable2<int64_t>)(cli::unwrap_nullable(infos->LowestBreakIteration)) != nullptr) && (cli::unwrap_nullable(infos->LowestBreakIteration) > (int64_t)((System::Nullable2<int64_t>)(i))))) 
                {
                    return;
                }
                state->set_CurrentIteration(i);
                local = body->Invoke(i, state, local);
                if(((i + 1) >= (stopIndex - range->V64->Stolen))) 
                {
                    break;
                }
                range->V64->Actual = ++i;
            }
            int32_t len = (num + localWorker);
            for(int32_t sIndex = (localWorker + 1); (sIndex < len); ++sIndex){
                int32_t extWorker = (sIndex % num);
                range = ranges->at(extWorker);
                stopIndex = ((extWorker + 1) ==  num) ? toExclusive : System::Math::Min5(toExclusive, (fromInclusive + ((extWorker + 1) * step)));
                int32_t stolen = -1;
                do {
                    do {
                        int64_t old;
                        StealValue64 val = cli::ctor<StealValue64>();
                        old = Parallel::sixtyfour ? range->V64->Value : System::Threading::Interlocked::CompareExchange4(range->V64->Value, 0L, 0L);
                        val->Value = old;
                        if((val->Actual >= ((stopIndex - val->Stolen) - 2))) 
                        {
                            goto next;
                        }
                        stolen = (val->Stolen = val->Stolen + 1);
                        if((System::Threading::Interlocked::CompareExchange4(range->V64->Value, val->Value, old) ==  old)) 
                        {
                            break;
                        }
                    }
                    while(true);
                    stolen = (stopIndex - stolen);
                    if((stolen > range->V64->Actual)) 
                    {
                        local = body->Invoke(stolen, state, local);
                    }
                     else 
                    {
                        break;
                    }
                }
                while(true);
                next:
                continue;
            }
        }
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource, class TLocal>
    void _ForEach_c__AnonStorey22<TSource, TLocal>::constructor() {
    }
    
    template<class TSource, class TLocal>
    void _ForEach_c__AnonStorey22<TSource, TLocal>::__m__1F() {
        System::Collections::Generic::IEnumerator2<TSource> *slice = slices->get_Item_e6c1a54cb8f591e7(System::Threading::Interlocked::Increment(sliceIndex));
        TLocal local = init->Invoke();
        ParallelLoopState *state = cli::gcnew<ParallelLoopState>(infos);
        int32_t workIndex = bag->GetNextIndex();
        System::Threading::CancellationToken token = options->get_CancellationToken();
        {
            cli::finally_guard([&]() {
                destruct->Invoke(local);
            });
            bool cont = true;
            TSource element;
            while(cont) {
                if((infos->IsStopped || infos->IsBroken->get_Value())) 
                {
                    return;
                }
                token->ThrowIfCancellationRequested();
                for(int32_t i = 0; ((i < 5) && cont = slice->MoveNext_4e78e145935f5417()); i++){
                    bag->Add(workIndex, slice->get_Current_9be2a11682d08be8());
                }
                for(int32_t i = 0; ((i < 5) && bag->TryTake(workIndex, element)); i++){
                    if(infos->IsStopped) 
                    {
                        return;
                    }
                    token->ThrowIfCancellationRequested();
                    local = action->Invoke(element, state, local);
                }
            }
            while(bag->TrySteal(workIndex, element)) {
                token->ThrowIfCancellationRequested();
                local = action->Invoke(element, state, local);
                if((infos->IsStopped || infos->IsBroken->get_Value())) 
                {
                    return;
                }
            }
        }
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey23<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey23<TSource>::__m__21(TSource e, ParallelLoopState* s, System::Object* l) {
        body->Invoke(e);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey24<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey24<TSource>::__m__24(TSource e, ParallelLoopState* s, System::Object* l) {
        body->Invoke(e, s);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey25<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey25<TSource>::__m__27(TSource e, ParallelLoopState* s, System::Object* l) {
        body->Invoke(e, s, -1L);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey26<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey26<TSource>::__m__2A(TSource e, ParallelLoopState* s, System::Object* l) {
        body->Invoke(e, s);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey27<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey27<TSource>::__m__2D(TSource e, ParallelLoopState* s, int64_t i, System::Object* l) {
        body->Invoke(e, s, i);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey28<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey28<TSource>::__m__30(TSource e, ParallelLoopState* s, System::Object* l) {
        body->Invoke(e);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey29<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey29<TSource>::__m__33(TSource e, ParallelLoopState* s, System::Object* l) {
        body->Invoke(e);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey2A<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey2A<TSource>::__m__36(TSource e, ParallelLoopState* s, System::Object* l) {
        body->Invoke(e, s);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey2B<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey2B<TSource>::__m__39(TSource e, ParallelLoopState* s, int64_t i, System::Object* l) {
        body->Invoke(e, s, i);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey2C<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey2C<TSource>::__m__3C(TSource e, ParallelLoopState* s, int64_t i, System::Object* l) {
        body->Invoke(e, s, i);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey2D<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey2D<TSource>::__m__3F(TSource e, ParallelLoopState* s, System::Object* l) {
        body->Invoke(e);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource>
    void _ForEach_c__AnonStorey2E<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Object* _ForEach_c__AnonStorey2E<TSource>::__m__42(TSource e, ParallelLoopState* s, System::Object* l) {
        body->Invoke(e, s);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TSource, class TLocal>
    void _ForEach_c__AnonStorey2F<TSource, TLocal>::constructor() {
    }
    
    template<class TSource, class TLocal>
    TLocal _ForEach_c__AnonStorey2F<TSource, TLocal>::__m__44(System::Collections::Generic::KeyValuePair<int64_t, TSource> e, ParallelLoopState* s, TLocal l) {
        return body->Invoke(e->get_Value(), s, e->get_Key(), l);
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TAntecedentResult>
    void _ContinueWhenAny_c__AnonStorey31<TAntecedentResult>::constructor() {
    }
    
    template<class TAntecedentResult>
    void _ContinueWhenAny_c__AnonStorey31<TAntecedentResult>::__m__49(Task* o) {
         continuationAction->Invoke(cli::cast<Task2<TAntecedentResult>*>(o));
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TAntecedentResult, class TResult>
    void _ContinueWhenAny_c__AnonStorey32<TAntecedentResult, TResult>::constructor() {
    }
    
    template<class TAntecedentResult, class TResult>
    TResult _ContinueWhenAny_c__AnonStorey32<TAntecedentResult, TResult>::__m__4B(Task* t) {
        return continuationFunction->Invoke(cli::cast<Task2<TAntecedentResult>*>(t));
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TAntecedentResult>
    void _ContinueWhenAll_c__AnonStorey33<TAntecedentResult>::constructor() {
    }
    
    template<class TAntecedentResult>
    void _ContinueWhenAll_c__AnonStorey33<TAntecedentResult>::__m__4D(cli::array<Task*>* o) {
         continuationAction->Invoke(tasks);
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TAntecedentResult, class TResult>
    void _ContinueWhenAll_c__AnonStorey34<TAntecedentResult, TResult>::constructor() {
    }
    
    template<class TAntecedentResult, class TResult>
    TResult _ContinueWhenAll_c__AnonStorey34<TAntecedentResult, TResult>::__m__4F(cli::array<Task*>* o) {
        return continuationFunction->Invoke(tasks);
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TArg1>
    void _FromAsync_c__AnonStorey37<TArg1>::constructor() {
    }
    
    template<class TArg1>
    System::Object* _FromAsync_c__AnonStorey37<TArg1>::__m__52(System::IAsyncResult* l) {
        endMethod->Invoke(l);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TArg1, class TArg2>
    void _FromAsync_c__AnonStorey38<TArg1, TArg2>::constructor() {
    }
    
    template<class TArg1, class TArg2>
    System::Object* _FromAsync_c__AnonStorey38<TArg1, TArg2>::__m__53(System::IAsyncResult* l) {
        endMethod->Invoke(l);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TArg1, class TArg2, class TArg3>
    void _FromAsync_c__AnonStorey39<TArg1, TArg2, TArg3>::constructor() {
    }
    
    template<class TArg1, class TArg2, class TArg3>
    System::Object* _FromAsync_c__AnonStorey39<TArg1, TArg2, TArg3>::__m__54(System::IAsyncResult* l) {
        endMethod->Invoke(l);
        return nullptr;
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TResult>
    void _StartNew_c__AnonStorey3A<TResult>::constructor() {
    }
    
    template<class TResult>
    TResult _StartNew_c__AnonStorey3A<TResult>::__m__55(System::Object* o) {
        return function->Invoke();
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TResult>
    void _FromIAsyncResult_c__AnonStorey3B<TResult>::constructor() {
    }
    
    template<class TResult>
    TResult _FromIAsyncResult_c__AnonStorey3B<TResult>::__m__56(System::Object* l) {
        try {
            return endMethod->Invoke(asyncResult);
        }
        catch(System::OperationCanceledException*) {
            source->Cancel();
            source->get_Token()->ThrowIfCancellationRequested();
        }
        return TResult();
    }
    
    template<class TResult>
    void _FromIAsyncResult_c__AnonStorey3B<TResult>::__m__57(System::Object* s, bool t) {
         task->RunSynchronously2(scheduler);
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TResult>
    void _FromAsyncBeginEnd_c__AnonStorey3C<TResult>::constructor() {
    }
    
    template<class TResult>
    void _FromAsyncBeginEnd_c__AnonStorey3C<TResult>::__m__58(System::IAsyncResult* l) {
         TaskFactory2<TResult>::InnerInvoke(tcs, endMethod, l);
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TResult, class TArg1>
    void _FromAsyncBeginEnd_c__AnonStorey3D<TResult, TArg1>::constructor() {
    }
    
    template<class TResult, class TArg1>
    void _FromAsyncBeginEnd_c__AnonStorey3D<TResult, TArg1>::__m__59(System::IAsyncResult* l) {
         TaskFactory2<TResult>::InnerInvoke(tcs, endMethod, l);
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TResult, class TArg1, class TArg2>
    void _FromAsyncBeginEnd_c__AnonStorey3E<TResult, TArg1, TArg2>::constructor() {
    }
    
    template<class TResult, class TArg1, class TArg2>
    void _FromAsyncBeginEnd_c__AnonStorey3E<TResult, TArg1, TArg2>::__m__5A(System::IAsyncResult* l) {
         TaskFactory2<TResult>::InnerInvoke(tcs, endMethod, l);
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
    
    
    template<class TResult, class TArg1, class TArg2, class TArg3>
    void _FromAsyncBeginEnd_c__AnonStorey3F<TResult, TArg1, TArg2, TArg3>::constructor() {
    }
    
    template<class TResult, class TArg1, class TArg2, class TArg3>
    void _FromAsyncBeginEnd_c__AnonStorey3F<TResult, TArg1, TArg2, TArg3>::__m__5B(System::IAsyncResult* l) {
         TaskFactory2<TResult>::InnerInvoke(tcs, endMethod, l);
    }
    
}}}
namespace System {
    // Automatically generated method stub
    template<class T>
    void InternalEnumerator<T>::Dispose_95cb2516542c2f97() {
        return Dispose();
    }
    
    // Automatically generated method stub
    template<class T>
    bool InternalEnumerator<T>::MoveNext_4e78e145935f5417() {
        return MoveNext();
    }
    
    // Automatically generated method stub
    template<class T>
    void InternalEnumerator<T>::Reset_bcd82381eed41868() {
        return Reset();
    }
    
    // Automatically generated method stub
    template<class T>
    T InternalEnumerator<T>::get_Current_9be2a11682d08be8() {
        return get_Current();
    }
    
    // Automatically generated method stub
    template<class T>
    Object* InternalEnumerator<T>::get_Current_8eca9b3da02b123a() {
        return get_Current2();
    }
    
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Enumerator4<TKey, TValue>::MoveNext_4e78e145935f5417() {
        return MoveNext();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Enumerator4<TKey, TValue>::Reset_bcd82381eed41868() {
        return Reset();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Enumerator4<TKey, TValue>::Dispose_95cb2516542c2f97() {
        return Dispose();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    KeyValuePair<TKey, TValue> Enumerator4<TKey, TValue>::get_Current_9be2a11682d08be8() {
        return get_Current();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* Enumerator4<TKey, TValue>::get_Current_8eca9b3da02b123a() {
        return get_Current2();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::DictionaryEntry Enumerator4<TKey, TValue>::get_Entry_7d036eca1ef8d5f4() {
        return get_Entry();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* Enumerator4<TKey, TValue>::get_Key_ed7954531cb20258() {
        return get_Key();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* Enumerator4<TKey, TValue>::get_Value_889e0f410f0d67ef() {
        return get_Value();
    }
    
}}}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Enumerator5<TKey, TValue>::Dispose_95cb2516542c2f97() {
        return Dispose();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Enumerator5<TKey, TValue>::MoveNext_4e78e145935f5417() {
        return MoveNext();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Enumerator5<TKey, TValue>::Reset_bcd82381eed41868() {
        return Reset();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    TKey Enumerator5<TKey, TValue>::get_Current_9be2a11682d08be8() {
        return get_Current();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* Enumerator5<TKey, TValue>::get_Current_8eca9b3da02b123a() {
        return get_Current2();
    }
    
}}}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Enumerator6<TKey, TValue>::Dispose_95cb2516542c2f97() {
        return Dispose();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Enumerator6<TKey, TValue>::MoveNext_4e78e145935f5417() {
        return MoveNext();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Enumerator6<TKey, TValue>::Reset_bcd82381eed41868() {
        return Reset();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    TValue Enumerator6<TKey, TValue>::get_Current_9be2a11682d08be8() {
        return get_Current();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* Enumerator6<TKey, TValue>::get_Current_8eca9b3da02b123a() {
        return get_Current2();
    }
    
}}}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class T>
    void Enumerator7<T>::Dispose_95cb2516542c2f97() {
        return Dispose();
    }
    
    // Automatically generated method stub
    template<class T>
    bool Enumerator7<T>::MoveNext_4e78e145935f5417() {
        return MoveNext();
    }
    
    // Automatically generated method stub
    template<class T>
    void Enumerator7<T>::Reset_bcd82381eed41868() {
        return Reset();
    }
    
    // Automatically generated method stub
    template<class T>
    T Enumerator7<T>::get_Current_9be2a11682d08be8() {
        return get_Current();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* Enumerator7<T>::get_Current_8eca9b3da02b123a() {
        return get_Current2();
    }
    
}}}
namespace System { namespace Configuration { namespace Assemblies {
}}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace Microsoft { namespace Win32 {
}}
namespace Microsoft { namespace Win32 {
}}
namespace Microsoft { namespace Win32 {
}}
namespace Mono { namespace Globalization { namespace Unicode {
}}}
namespace Mono { namespace Globalization { namespace Unicode {
}}}
namespace Mono { namespace Interop {
}}
namespace Mono { namespace Security { namespace Cryptography {
}}}
namespace Mono { namespace Security { namespace X509 {
}}}
namespace Mono { namespace Security { namespace X509 {
}}}
namespace Mono { namespace Security { namespace X509 {
}}}
namespace Mono { namespace Security { namespace X509 {
}}}
namespace Mono { namespace Security { namespace X509 {
}}}
namespace Mono { namespace Security { namespace X509 {
}}}
namespace Mono { namespace Xml {
}}
namespace Mono { namespace Xml {
}}
namespace Mono { namespace Xml {
}}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    int32_t Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::CompareTo_ed9d39205b7812f0(Object* obj) {
        return CompareTo(obj);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    int32_t Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::CompareTo_6a6cfba1da2bec3b(Object* other, Collections::IComparer* comparer) {
        return CompareTo2(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    bool Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::Equals_2f89738462b0fb33(Object* other, Collections::IEqualityComparer* comparer) {
        return Equals4(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    int32_t Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::GetHashCode_94e84ad7bccbc132(Collections::IEqualityComparer* comparer) {
        return GetHashCode3(comparer);
    }
    
}
namespace System {
    // Automatically generated method stub
    template<class T1>
    int32_t Tuple3<T1>::CompareTo_ed9d39205b7812f0(Object* obj) {
        return CompareTo(obj);
    }
    
    // Automatically generated method stub
    template<class T1>
    int32_t Tuple3<T1>::CompareTo_6a6cfba1da2bec3b(Object* other, Collections::IComparer* comparer) {
        return CompareTo2(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1>
    bool Tuple3<T1>::Equals_2f89738462b0fb33(Object* other, Collections::IEqualityComparer* comparer) {
        return Equals4(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1>
    int32_t Tuple3<T1>::GetHashCode_94e84ad7bccbc132(Collections::IEqualityComparer* comparer) {
        return GetHashCode3(comparer);
    }
    
}
namespace System {
    // Automatically generated method stub
    template<class T1, class T2>
    int32_t Tuple4<T1, T2>::CompareTo_ed9d39205b7812f0(Object* obj) {
        return CompareTo(obj);
    }
    
    // Automatically generated method stub
    template<class T1, class T2>
    int32_t Tuple4<T1, T2>::CompareTo_6a6cfba1da2bec3b(Object* other, Collections::IComparer* comparer) {
        return CompareTo2(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2>
    bool Tuple4<T1, T2>::Equals_2f89738462b0fb33(Object* other, Collections::IEqualityComparer* comparer) {
        return Equals4(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2>
    int32_t Tuple4<T1, T2>::GetHashCode_94e84ad7bccbc132(Collections::IEqualityComparer* comparer) {
        return GetHashCode3(comparer);
    }
    
}
namespace System {
    // Automatically generated method stub
    template<class T1, class T2, class T3>
    int32_t Tuple5<T1, T2, T3>::CompareTo_ed9d39205b7812f0(Object* obj) {
        return CompareTo(obj);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3>
    int32_t Tuple5<T1, T2, T3>::CompareTo_6a6cfba1da2bec3b(Object* other, Collections::IComparer* comparer) {
        return CompareTo2(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3>
    bool Tuple5<T1, T2, T3>::Equals_2f89738462b0fb33(Object* other, Collections::IEqualityComparer* comparer) {
        return Equals4(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3>
    int32_t Tuple5<T1, T2, T3>::GetHashCode_94e84ad7bccbc132(Collections::IEqualityComparer* comparer) {
        return GetHashCode3(comparer);
    }
    
}
namespace System {
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4>
    int32_t Tuple6<T1, T2, T3, T4>::CompareTo_ed9d39205b7812f0(Object* obj) {
        return CompareTo(obj);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4>
    int32_t Tuple6<T1, T2, T3, T4>::CompareTo_6a6cfba1da2bec3b(Object* other, Collections::IComparer* comparer) {
        return CompareTo2(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4>
    bool Tuple6<T1, T2, T3, T4>::Equals_2f89738462b0fb33(Object* other, Collections::IEqualityComparer* comparer) {
        return Equals4(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4>
    int32_t Tuple6<T1, T2, T3, T4>::GetHashCode_94e84ad7bccbc132(Collections::IEqualityComparer* comparer) {
        return GetHashCode3(comparer);
    }
    
}
namespace System {
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5>
    int32_t Tuple7<T1, T2, T3, T4, T5>::CompareTo_ed9d39205b7812f0(Object* obj) {
        return CompareTo(obj);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5>
    int32_t Tuple7<T1, T2, T3, T4, T5>::CompareTo_6a6cfba1da2bec3b(Object* other, Collections::IComparer* comparer) {
        return CompareTo2(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5>
    bool Tuple7<T1, T2, T3, T4, T5>::Equals_2f89738462b0fb33(Object* other, Collections::IEqualityComparer* comparer) {
        return Equals4(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5>
    int32_t Tuple7<T1, T2, T3, T4, T5>::GetHashCode_94e84ad7bccbc132(Collections::IEqualityComparer* comparer) {
        return GetHashCode3(comparer);
    }
    
}
namespace System {
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    int32_t Tuple8<T1, T2, T3, T4, T5, T6>::CompareTo_ed9d39205b7812f0(Object* obj) {
        return CompareTo(obj);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    int32_t Tuple8<T1, T2, T3, T4, T5, T6>::CompareTo_6a6cfba1da2bec3b(Object* other, Collections::IComparer* comparer) {
        return CompareTo2(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    bool Tuple8<T1, T2, T3, T4, T5, T6>::Equals_2f89738462b0fb33(Object* other, Collections::IEqualityComparer* comparer) {
        return Equals4(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    int32_t Tuple8<T1, T2, T3, T4, T5, T6>::GetHashCode_94e84ad7bccbc132(Collections::IEqualityComparer* comparer) {
        return GetHashCode3(comparer);
    }
    
}
namespace System {
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    int32_t Tuple9<T1, T2, T3, T4, T5, T6, T7>::CompareTo_ed9d39205b7812f0(Object* obj) {
        return CompareTo(obj);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    int32_t Tuple9<T1, T2, T3, T4, T5, T6, T7>::CompareTo_6a6cfba1da2bec3b(Object* other, Collections::IComparer* comparer) {
        return CompareTo2(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    bool Tuple9<T1, T2, T3, T4, T5, T6, T7>::Equals_2f89738462b0fb33(Object* other, Collections::IEqualityComparer* comparer) {
        return Equals4(other, comparer);
    }
    
    // Automatically generated method stub
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    int32_t Tuple9<T1, T2, T3, T4, T5, T6, T7>::GetHashCode_94e84ad7bccbc132(Collections::IEqualityComparer* comparer) {
        return GetHashCode3(comparer);
    }
    
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System {
}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections {
}}
namespace System { namespace Collections { namespace Concurrent {
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionaryEnumerator<TKey, TValue>::MoveNext_4e78e145935f5417() {
        return MoveNext();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ConcurrentDictionaryEnumerator<TKey, TValue>::Reset_bcd82381eed41868() {
        return Reset();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionaryEnumerator<TKey, TValue>::get_Current_8eca9b3da02b123a() {
        return get_Current();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::DictionaryEntry ConcurrentDictionaryEnumerator<TKey, TValue>::get_Entry_7d036eca1ef8d5f4() {
        return get_Entry();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionaryEnumerator<TKey, TValue>::get_Key_ed7954531cb20258() {
        return get_Key();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionaryEnumerator<TKey, TValue>::get_Value_889e0f410f0d67ef() {
        return get_Value();
    }
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Add_98fd6232ab01b789(TKey key, TValue value) {
        return Add2(key, value);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Add_a6fc54bc2aa3c029(System::Collections::Generic::KeyValuePair<TKey, TValue> pair) {
        return Add3(pair);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::TryGetValue_ce9f0a16d22fc3a7(TKey key, TValue value) {
        return TryGetValue(key, value);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::Remove_6b6ef63eca7c3783(TKey key) {
        return Remove2(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::Remove_67948971902d0cce(System::Collections::Generic::KeyValuePair<TKey, TValue> pair) {
        return Remove3(pair);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::ContainsKey_6b27cc7fbf3d0673(TKey key) {
        return ContainsKey(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::Contains_32eba6643fe7ee4b(System::Object* key) {
        return Contains(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Remove_f212b96e00d6aaed(System::Object* key) {
        return Remove4(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Add_642542cf7a4cae38(System::Object* key, System::Object* value) {
        return Add4(key, value);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::Contains_ca946a648e63e62e(System::Collections::Generic::KeyValuePair<TKey, TValue> pair) {
        return Contains2(pair);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Clear_16ef3c35b14f77a2() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Clear_23091c63869f817f() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::CopyTo_7065a6e3cf6a140(System::Array* array, int32_t startIndex) {
        return CopyTo(array, startIndex);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::CopyTo_e6884c04285bc976(cli::array<System::Collections::Generic::KeyValuePair<TKey, TValue>>* array, int32_t startIndex) {
        return CopyTo3(array, startIndex);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<TKey, TValue>>* ConcurrentDictionary<TKey, TValue>::GetEnumerator_ad4887f30f9e4c5() {
        return GetEnumerator();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::IEnumerator* ConcurrentDictionary<TKey, TValue>::GetEnumerator_674ad93a972a4d67() {
        return GetEnumerator2();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::IDictionaryEnumerator* ConcurrentDictionary<TKey, TValue>::GetEnumerator_40657fcb15842551() {
        return GetEnumerator3();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::get_Item_6184d8d494c06347(TKey key) {
        return get_Item(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::set_Item_9efe7d5d7f862add(TKey key, TValue value) {
        return set_Item(key, value);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionary<TKey, TValue>::get_Item_95688dd349c069c0(System::Object* key) {
        return get_Item2(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionary<TKey, TValue>::set_Item_a0c4aaef01cc13c2(System::Object* key, System::Object* value) {
        return set_Item2(key, value);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    int32_t ConcurrentDictionary<TKey, TValue>::get_Count_a9c25d5c244affb9() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    int32_t ConcurrentDictionary<TKey, TValue>::get_Count_8f254f3dd8e2403() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::get_IsReadOnly_9569eb0bb1daa9b5() {
        return get_IsReadOnly();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::get_IsReadOnly_faaa94fe854aaa5f() {
        return get_IsReadOnly2();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::Generic::ICollection2<TKey>* ConcurrentDictionary<TKey, TValue>::get_Keys_2b6b38d6f5ec99fa() {
        return get_Keys();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::Generic::ICollection2<TValue>* ConcurrentDictionary<TKey, TValue>::get_Values_9c050b7765e02952() {
        return get_Values();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::ICollection* ConcurrentDictionary<TKey, TValue>::get_Keys_d809cadac60b140a() {
        return get_Keys2();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::ICollection* ConcurrentDictionary<TKey, TValue>::get_Values_ef6ae5cda2bdcf40() {
        return get_Values2();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionary<TKey, TValue>::get_SyncRoot_257108f45cc89e19() {
        return get_SyncRoot();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::get_IsFixedSize_9b77ca904d42a211() {
        return get_IsFixedSize();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::get_IsSynchronized_20926e7dabc53dbf() {
        return get_IsSynchronized();
    }
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    // Automatically generated method stub
    template<class T>
    bool ConcurrentOrderedList<T>::Contains_ca946a648e63e62e(T data) {
        return Contains(data);
    }
    
    // Automatically generated method stub
    template<class T>
    void ConcurrentOrderedList<T>::Clear_16ef3c35b14f77a2() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class T>
    void ConcurrentOrderedList<T>::CopyTo_e6884c04285bc976(cli::array<T>* array, int32_t startIndex) {
        return CopyTo(array, startIndex);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ConcurrentOrderedList<T>::GetEnumerator_ad4887f30f9e4c5() {
        return GetEnumerator();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::IEnumerator* ConcurrentOrderedList<T>::GetEnumerator_674ad93a972a4d67() {
        return GetEnumerator2();
    }
    
    // Automatically generated method stub
    template<class T>
    void ConcurrentOrderedList<T>::Add_a6fc54bc2aa3c029(T item) {
        return Add(item);
    }
    
    // Automatically generated method stub
    template<class T>
    bool ConcurrentOrderedList<T>::Remove_67948971902d0cce(T item) {
        return Remove(item);
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t ConcurrentOrderedList<T>::get_Count_a9c25d5c244affb9() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class T>
    bool ConcurrentOrderedList<T>::get_IsReadOnly_9569eb0bb1daa9b5() {
        return get_IsReadOnly();
    }
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    // Automatically generated method stub
    template<class T>
    bool ConcurrentQueue<T>::TryAdd_c8c99cf8ee0a136a(T item) {
        return TryAdd(item);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::IEnumerator* ConcurrentQueue<T>::GetEnumerator_674ad93a972a4d67() {
        return GetEnumerator();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ConcurrentQueue<T>::GetEnumerator_ad4887f30f9e4c5() {
        return GetEnumerator2();
    }
    
    // Automatically generated method stub
    template<class T>
    void ConcurrentQueue<T>::CopyTo_7065a6e3cf6a140(System::Array* array, int32_t index) {
        return CopyTo(array, index);
    }
    
    // Automatically generated method stub
    template<class T>
    void ConcurrentQueue<T>::CopyTo_c08b50ac29c8b1c8(cli::array<T>* array, int32_t index) {
        return CopyTo2(array, index);
    }
    
    // Automatically generated method stub
    template<class T>
    cli::array<T>* ConcurrentQueue<T>::ToArray_8ccf9eabf7c0f83c() {
        return ToArray();
    }
    
    // Automatically generated method stub
    template<class T>
    bool ConcurrentQueue<T>::TryTake_847d302d2cfeb97(T item) {
        return TryTake(item);
    }
    
    // Automatically generated method stub
    template<class T>
    bool ConcurrentQueue<T>::get_IsSynchronized_20926e7dabc53dbf() {
        return get_IsSynchronized();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* ConcurrentQueue<T>::get_SyncRoot_257108f45cc89e19() {
        return get_SyncRoot();
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t ConcurrentQueue<T>::get_Count_8f254f3dd8e2403() {
        return get_Count();
    }
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    // Automatically generated method stub
    template<class T>
    bool ConcurrentStack<T>::TryAdd_c8c99cf8ee0a136a(T elem) {
        return TryAdd(elem);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::IEnumerator* ConcurrentStack<T>::GetEnumerator_674ad93a972a4d67() {
        return GetEnumerator();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ConcurrentStack<T>::GetEnumerator_ad4887f30f9e4c5() {
        return GetEnumerator2();
    }
    
    // Automatically generated method stub
    template<class T>
    void ConcurrentStack<T>::CopyTo_7065a6e3cf6a140(System::Array* array, int32_t index) {
        return CopyTo(array, index);
    }
    
    // Automatically generated method stub
    template<class T>
    void ConcurrentStack<T>::CopyTo_c08b50ac29c8b1c8(cli::array<T>* array, int32_t index) {
        return CopyTo2(array, index);
    }
    
    // Automatically generated method stub
    template<class T>
    bool ConcurrentStack<T>::TryTake_847d302d2cfeb97(T item) {
        return TryTake(item);
    }
    
    // Automatically generated method stub
    template<class T>
    cli::array<T>* ConcurrentStack<T>::ToArray_8ccf9eabf7c0f83c() {
        return ToArray();
    }
    
    // Automatically generated method stub
    template<class T>
    bool ConcurrentStack<T>::get_IsSynchronized_20926e7dabc53dbf() {
        return get_IsSynchronized();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* ConcurrentStack<T>::get_SyncRoot_257108f45cc89e19() {
        return get_SyncRoot();
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t ConcurrentStack<T>::get_Count_8f254f3dd8e2403() {
        return get_Count();
    }
    
}}}
namespace System { namespace Collections { namespace Concurrent {
    // Automatically generated method stub
    template<class TSource>
    void ProxyEnumerator<TSource>::Dispose_95cb2516542c2f97() {
        return Dispose();
    }
    
    // Automatically generated method stub
    template<class TSource>
    bool ProxyEnumerator<TSource>::MoveNext_4e78e145935f5417() {
        return MoveNext();
    }
    
    // Automatically generated method stub
    template<class TSource>
    void ProxyEnumerator<TSource>::Reset_bcd82381eed41868() {
        return Reset();
    }
    
    // Automatically generated method stub
    template<class TSource>
    System::Object* ProxyEnumerator<TSource>::get_Current_8eca9b3da02b123a() {
        return get_Current();
    }
    
    // Automatically generated method stub
    template<class TSource>
    TSource ProxyEnumerator<TSource>::get_Current_9be2a11682d08be8() {
        return get_Current2();
    }
    
}}}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class T>
    int32_t Comparer2<T>::Compare_5902559f67a8cefa(T x, T y) {
        return Compare_1b044eff3abea0d9(x, y);
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t Comparer2<T>::Compare_451fd276747b629d(System::Object* x, System::Object* y) {
        return Compare2(x, y);
    }
    
}}}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ShimEnumerator<TKey, TValue>::MoveNext_4e78e145935f5417() {
        return MoveNext();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ShimEnumerator<TKey, TValue>::Reset_bcd82381eed41868() {
        return Reset();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::DictionaryEntry ShimEnumerator<TKey, TValue>::get_Entry_7d036eca1ef8d5f4() {
        return get_Entry();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* ShimEnumerator<TKey, TValue>::get_Key_ed7954531cb20258() {
        return get_Key();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* ShimEnumerator<TKey, TValue>::get_Value_889e0f410f0d67ef() {
        return get_Value();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* ShimEnumerator<TKey, TValue>::get_Current_8eca9b3da02b123a() {
        return get_Current();
    }
    
}}}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class TKey, class TValue>
    void KeyCollection<TKey, TValue>::CopyTo_e6884c04285bc976(cli::array<TKey>* array, int32_t index) {
        return CopyTo(array, index);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void KeyCollection<TKey, TValue>::Add_a6fc54bc2aa3c029(TKey item) {
        return Add(item);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void KeyCollection<TKey, TValue>::Clear_16ef3c35b14f77a2() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool KeyCollection<TKey, TValue>::Contains_ca946a648e63e62e(TKey item) {
        return Contains(item);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool KeyCollection<TKey, TValue>::Remove_67948971902d0cce(TKey item) {
        return Remove(item);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    IEnumerator2<TKey>* KeyCollection<TKey, TValue>::GetEnumerator_ad4887f30f9e4c5() {
        return GetEnumerator2();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void KeyCollection<TKey, TValue>::CopyTo_7065a6e3cf6a140(System::Array* array, int32_t index) {
        return CopyTo2(array, index);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::IEnumerator* KeyCollection<TKey, TValue>::GetEnumerator_674ad93a972a4d67() {
        return GetEnumerator3();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    int32_t KeyCollection<TKey, TValue>::get_Count_a9c25d5c244affb9() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    int32_t KeyCollection<TKey, TValue>::get_Count_8f254f3dd8e2403() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool KeyCollection<TKey, TValue>::get_IsReadOnly_9569eb0bb1daa9b5() {
        return get_IsReadOnly();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool KeyCollection<TKey, TValue>::get_IsSynchronized_20926e7dabc53dbf() {
        return get_IsSynchronized();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* KeyCollection<TKey, TValue>::get_SyncRoot_257108f45cc89e19() {
        return get_SyncRoot();
    }
    
}}}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ValueCollection<TKey, TValue>::CopyTo_e6884c04285bc976(cli::array<TValue>* array, int32_t index) {
        return CopyTo(array, index);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ValueCollection<TKey, TValue>::Add_a6fc54bc2aa3c029(TValue item) {
        return Add(item);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ValueCollection<TKey, TValue>::Clear_16ef3c35b14f77a2() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ValueCollection<TKey, TValue>::Contains_ca946a648e63e62e(TValue item) {
        return Contains(item);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ValueCollection<TKey, TValue>::Remove_67948971902d0cce(TValue item) {
        return Remove(item);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    IEnumerator2<TValue>* ValueCollection<TKey, TValue>::GetEnumerator_ad4887f30f9e4c5() {
        return GetEnumerator2();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void ValueCollection<TKey, TValue>::CopyTo_7065a6e3cf6a140(System::Array* array, int32_t index) {
        return CopyTo2(array, index);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::IEnumerator* ValueCollection<TKey, TValue>::GetEnumerator_674ad93a972a4d67() {
        return GetEnumerator3();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    int32_t ValueCollection<TKey, TValue>::get_Count_a9c25d5c244affb9() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    int32_t ValueCollection<TKey, TValue>::get_Count_8f254f3dd8e2403() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ValueCollection<TKey, TValue>::get_IsReadOnly_9569eb0bb1daa9b5() {
        return get_IsReadOnly();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool ValueCollection<TKey, TValue>::get_IsSynchronized_20926e7dabc53dbf() {
        return get_IsSynchronized();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* ValueCollection<TKey, TValue>::get_SyncRoot_257108f45cc89e19() {
        return get_SyncRoot();
    }
    
}}}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Add_98fd6232ab01b789(TKey key, TValue value) {
        return Add(key, value);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Clear_16ef3c35b14f77a2() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Clear_23091c63869f817f() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::ContainsKey_6b27cc7fbf3d0673(TKey key) {
        return ContainsKey(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::GetObjectData_11b895a112e04409(System::Runtime::Serialization::SerializationInfo* info, System::Runtime::Serialization::StreamingContext context) {
        return GetObjectData_15c552da9e393b6(info, context);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::OnDeserialization_e9ecfecba8df9754(System::Object* sender) {
        return OnDeserialization_b298596fbc47c46f(sender);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::Remove_6b6ef63eca7c3783(TKey key) {
        return Remove(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::TryGetValue_ce9f0a16d22fc3a7(TKey key, TValue value) {
        return TryGetValue(key, value);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Add_642542cf7a4cae38(System::Object* key, System::Object* value) {
        return Add2(key, value);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::Contains_32eba6643fe7ee4b(System::Object* key) {
        return Contains(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Remove_f212b96e00d6aaed(System::Object* key) {
        return Remove2(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Add_a6fc54bc2aa3c029(KeyValuePair<TKey, TValue> keyValuePair) {
        return Add3(keyValuePair);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::Contains_ca946a648e63e62e(KeyValuePair<TKey, TValue> keyValuePair) {
        return Contains2(keyValuePair);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::CopyTo_e6884c04285bc976(cli::array<KeyValuePair<TKey, TValue>>* array, int32_t index) {
        return CopyTo2(array, index);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::Remove_67948971902d0cce(KeyValuePair<TKey, TValue> keyValuePair) {
        return Remove3(keyValuePair);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::CopyTo_7065a6e3cf6a140(System::Array* array, int32_t index) {
        return CopyTo3(array, index);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::IEnumerator* Dictionary<TKey, TValue>::GetEnumerator_674ad93a972a4d67() {
        return GetEnumerator();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    IEnumerator2<KeyValuePair<TKey, TValue>>* Dictionary<TKey, TValue>::GetEnumerator_ad4887f30f9e4c5() {
        return GetEnumerator2();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::IDictionaryEnumerator* Dictionary<TKey, TValue>::GetEnumerator_40657fcb15842551() {
        return GetEnumerator3();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    int32_t Dictionary<TKey, TValue>::get_Count_a9c25d5c244affb9() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    int32_t Dictionary<TKey, TValue>::get_Count_8f254f3dd8e2403() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    TValue Dictionary<TKey, TValue>::get_Item_6184d8d494c06347(TKey key) {
        return get_Item(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    TValue Dictionary<TKey, TValue>::set_Item_9efe7d5d7f862add(TKey key, TValue value) {
        return set_Item(key, value);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    ICollection2<TKey>* Dictionary<TKey, TValue>::get_Keys_2b6b38d6f5ec99fa() {
        return get_Keys();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    ICollection2<TValue>* Dictionary<TKey, TValue>::get_Values_9c050b7765e02952() {
        return get_Values();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::ICollection* Dictionary<TKey, TValue>::get_Keys_d809cadac60b140a() {
        return get_Keys3();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Collections::ICollection* Dictionary<TKey, TValue>::get_Values_ef6ae5cda2bdcf40() {
        return get_Values3();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::get_IsFixedSize_9b77ca904d42a211() {
        return get_IsFixedSize();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::get_IsReadOnly_faaa94fe854aaa5f() {
        return get_IsReadOnly();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* Dictionary<TKey, TValue>::get_Item_95688dd349c069c0(System::Object* key) {
        return get_Item2(key);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* Dictionary<TKey, TValue>::set_Item_a0c4aaef01cc13c2(System::Object* key, System::Object* value) {
        return set_Item2(key, value);
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::get_IsSynchronized_20926e7dabc53dbf() {
        return get_IsSynchronized();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    System::Object* Dictionary<TKey, TValue>::get_SyncRoot_257108f45cc89e19() {
        return get_SyncRoot();
    }
    
    // Automatically generated method stub
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::get_IsReadOnly_9569eb0bb1daa9b5() {
        return get_IsReadOnly2();
    }
    
}}}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class T>
    int32_t EqualityComparer<T>::GetHashCode_74f46a6b01295dbe(T obj) {
        return GetHashCode_f61694b39bec824d(obj);
    }
    
    // Automatically generated method stub
    template<class T>
    bool EqualityComparer<T>::Equals_f783e5e22b72a1c0(T x, T y) {
        return Equals_e786aaeef5b10ff2(x, y);
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t EqualityComparer<T>::GetHashCode_f8793dfb2b096a5a(System::Object* obj) {
        return GetHashCode3(obj);
    }
    
    // Automatically generated method stub
    template<class T>
    bool EqualityComparer<T>::Equals_ad190887ea91ded(System::Object* x, System::Object* y) {
        return Equals4(x, y);
    }
    
}}}
namespace System { namespace Collections { namespace Generic {
    // Automatically generated method stub
    template<class T>
    void List<T>::Add_a6fc54bc2aa3c029(T item) {
        return Add(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void List<T>::Clear_16ef3c35b14f77a2() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class T>
    void List<T>::Clear_e0ee496065507a2f() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class T>
    bool List<T>::Contains_ca946a648e63e62e(T item) {
        return Contains(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void List<T>::CopyTo_e6884c04285bc976(cli::array<T>* array, int32_t arrayIndex) {
        return CopyTo2(array, arrayIndex);
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t List<T>::IndexOf_9e82d7c34bb82d25(T item) {
        return IndexOf(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void List<T>::Insert_d9ae15974e481e9e(int32_t index, T item) {
        return Insert(index, item);
    }
    
    // Automatically generated method stub
    template<class T>
    bool List<T>::Remove_67948971902d0cce(T item) {
        return Remove(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void List<T>::RemoveAt_92d07238fa433d4a(int32_t index) {
        return RemoveAt(index);
    }
    
    // Automatically generated method stub
    template<class T>
    void List<T>::RemoveAt_dce190584913328b(int32_t index) {
        return RemoveAt(index);
    }
    
    // Automatically generated method stub
    template<class T>
    IEnumerator2<T>* List<T>::GetEnumerator_ad4887f30f9e4c5() {
        return GetEnumerator2();
    }
    
    // Automatically generated method stub
    template<class T>
    void List<T>::CopyTo_7065a6e3cf6a140(System::Array* array, int32_t arrayIndex) {
        return CopyTo4(array, arrayIndex);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::IEnumerator* List<T>::GetEnumerator_674ad93a972a4d67() {
        return GetEnumerator3();
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t List<T>::Add_985508e3bf9b7a73(System::Object* item) {
        return Add2(item);
    }
    
    // Automatically generated method stub
    template<class T>
    bool List<T>::Contains_2a2192a595869f4e(System::Object* item) {
        return Contains2(item);
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t List<T>::IndexOf_7f6d78d7aa6d53e5(System::Object* item) {
        return IndexOf4(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void List<T>::Insert_16e8bd69dfc603f4(int32_t index, System::Object* item) {
        return Insert2(index, item);
    }
    
    // Automatically generated method stub
    template<class T>
    void List<T>::Remove_69f1b1e57bb34112(System::Object* item) {
        return Remove2(item);
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t List<T>::get_Count_a9c25d5c244affb9() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t List<T>::get_Count_8f254f3dd8e2403() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class T>
    T List<T>::get_Item_e6c1a54cb8f591e7(int32_t index) {
        return get_Item(index);
    }
    
    // Automatically generated method stub
    template<class T>
    T List<T>::set_Item_13ad50de181a1c01(int32_t index, T value) {
        return set_Item(index, value);
    }
    
    // Automatically generated method stub
    template<class T>
    bool List<T>::get_IsReadOnly_9569eb0bb1daa9b5() {
        return get_IsReadOnly();
    }
    
    // Automatically generated method stub
    template<class T>
    bool List<T>::get_IsSynchronized_20926e7dabc53dbf() {
        return get_IsSynchronized();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* List<T>::get_SyncRoot_257108f45cc89e19() {
        return get_SyncRoot();
    }
    
    // Automatically generated method stub
    template<class T>
    bool List<T>::get_IsFixedSize_4d3eaee3435ee591() {
        return get_IsFixedSize();
    }
    
    // Automatically generated method stub
    template<class T>
    bool List<T>::get_IsReadOnly_53b6e02d46187790() {
        return get_IsReadOnly2();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* List<T>::get_Item_8550d21996ef9dc5(int32_t index) {
        return get_Item2(index);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* List<T>::set_Item_d57705373e0668e7(int32_t index, System::Object* value) {
        return set_Item2(index, value);
    }
    
}}}
namespace System { namespace Collections { namespace ObjectModel {
    // Automatically generated method stub
    template<class T>
    void Collection<T>::Add_a6fc54bc2aa3c029(T item) {
        return Add(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void Collection<T>::Clear_16ef3c35b14f77a2() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class T>
    void Collection<T>::Clear_e0ee496065507a2f() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class T>
    bool Collection<T>::Contains_ca946a648e63e62e(T item) {
        return Contains(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void Collection<T>::CopyTo_e6884c04285bc976(cli::array<T>* array, int32_t index) {
        return CopyTo(array, index);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* Collection<T>::GetEnumerator_ad4887f30f9e4c5() {
        return GetEnumerator();
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t Collection<T>::IndexOf_9e82d7c34bb82d25(T item) {
        return IndexOf(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void Collection<T>::Insert_d9ae15974e481e9e(int32_t index, T item) {
        return Insert(index, item);
    }
    
    // Automatically generated method stub
    template<class T>
    bool Collection<T>::Remove_67948971902d0cce(T item) {
        return Remove(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void Collection<T>::RemoveAt_92d07238fa433d4a(int32_t index) {
        return RemoveAt(index);
    }
    
    // Automatically generated method stub
    template<class T>
    void Collection<T>::RemoveAt_dce190584913328b(int32_t index) {
        return RemoveAt(index);
    }
    
    // Automatically generated method stub
    template<class T>
    void Collection<T>::CopyTo_7065a6e3cf6a140(System::Array* array, int32_t index) {
        return CopyTo2(array, index);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::IEnumerator* Collection<T>::GetEnumerator_674ad93a972a4d67() {
        return GetEnumerator2();
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t Collection<T>::Add_985508e3bf9b7a73(System::Object* value) {
        return Add2(value);
    }
    
    // Automatically generated method stub
    template<class T>
    bool Collection<T>::Contains_2a2192a595869f4e(System::Object* value) {
        return Contains2(value);
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t Collection<T>::IndexOf_7f6d78d7aa6d53e5(System::Object* value) {
        return IndexOf2(value);
    }
    
    // Automatically generated method stub
    template<class T>
    void Collection<T>::Insert_16e8bd69dfc603f4(int32_t index, System::Object* value) {
        return Insert2(index, value);
    }
    
    // Automatically generated method stub
    template<class T>
    void Collection<T>::Remove_69f1b1e57bb34112(System::Object* value) {
        return Remove2(value);
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t Collection<T>::get_Count_a9c25d5c244affb9() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t Collection<T>::get_Count_8f254f3dd8e2403() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class T>
    T Collection<T>::get_Item_e6c1a54cb8f591e7(int32_t index) {
        return get_Item(index);
    }
    
    // Automatically generated method stub
    template<class T>
    T Collection<T>::set_Item_13ad50de181a1c01(int32_t index, T value) {
        return set_Item(index, value);
    }
    
    // Automatically generated method stub
    template<class T>
    bool Collection<T>::get_IsReadOnly_9569eb0bb1daa9b5() {
        return get_IsReadOnly();
    }
    
    // Automatically generated method stub
    template<class T>
    bool Collection<T>::get_IsSynchronized_20926e7dabc53dbf() {
        return get_IsSynchronized();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* Collection<T>::get_SyncRoot_257108f45cc89e19() {
        return get_SyncRoot();
    }
    
    // Automatically generated method stub
    template<class T>
    bool Collection<T>::get_IsFixedSize_4d3eaee3435ee591() {
        return get_IsFixedSize();
    }
    
    // Automatically generated method stub
    template<class T>
    bool Collection<T>::get_IsReadOnly_53b6e02d46187790() {
        return get_IsReadOnly2();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* Collection<T>::get_Item_8550d21996ef9dc5(int32_t index) {
        return get_Item2(index);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* Collection<T>::set_Item_d57705373e0668e7(int32_t index, System::Object* value) {
        return set_Item2(index, value);
    }
    
}}}
namespace System { namespace Collections { namespace ObjectModel {
    // Automatically generated method stub
    template<class T>
    void ReadOnlyCollection<T>::Add_a6fc54bc2aa3c029(T item) {
        return Add(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void ReadOnlyCollection<T>::Clear_16ef3c35b14f77a2() {
        return Clear();
    }
    
    // Automatically generated method stub
    template<class T>
    bool ReadOnlyCollection<T>::Contains_ca946a648e63e62e(T value) {
        return Contains(value);
    }
    
    // Automatically generated method stub
    template<class T>
    void ReadOnlyCollection<T>::CopyTo_e6884c04285bc976(cli::array<T>* array, int32_t index) {
        return CopyTo(array, index);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ReadOnlyCollection<T>::GetEnumerator_ad4887f30f9e4c5() {
        return GetEnumerator();
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t ReadOnlyCollection<T>::IndexOf_9e82d7c34bb82d25(T value) {
        return IndexOf(value);
    }
    
    // Automatically generated method stub
    template<class T>
    void ReadOnlyCollection<T>::Insert_d9ae15974e481e9e(int32_t index, T item) {
        return Insert(index, item);
    }
    
    // Automatically generated method stub
    template<class T>
    bool ReadOnlyCollection<T>::Remove_67948971902d0cce(T item) {
        return Remove(item);
    }
    
    // Automatically generated method stub
    template<class T>
    void ReadOnlyCollection<T>::RemoveAt_92d07238fa433d4a(int32_t index) {
        return RemoveAt(index);
    }
    
    // Automatically generated method stub
    template<class T>
    void ReadOnlyCollection<T>::CopyTo_7065a6e3cf6a140(System::Array* array, int32_t index) {
        return CopyTo2(array, index);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::IEnumerator* ReadOnlyCollection<T>::GetEnumerator_674ad93a972a4d67() {
        return GetEnumerator2();
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t ReadOnlyCollection<T>::Add_985508e3bf9b7a73(System::Object* value) {
        return Add2(value);
    }
    
    // Automatically generated method stub
    template<class T>
    void ReadOnlyCollection<T>::Clear_e0ee496065507a2f() {
        return Clear2();
    }
    
    // Automatically generated method stub
    template<class T>
    bool ReadOnlyCollection<T>::Contains_2a2192a595869f4e(System::Object* value) {
        return Contains2(value);
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t ReadOnlyCollection<T>::IndexOf_7f6d78d7aa6d53e5(System::Object* value) {
        return IndexOf2(value);
    }
    
    // Automatically generated method stub
    template<class T>
    void ReadOnlyCollection<T>::Insert_16e8bd69dfc603f4(int32_t index, System::Object* value) {
        return Insert2(index, value);
    }
    
    // Automatically generated method stub
    template<class T>
    void ReadOnlyCollection<T>::Remove_69f1b1e57bb34112(System::Object* value) {
        return Remove2(value);
    }
    
    // Automatically generated method stub
    template<class T>
    void ReadOnlyCollection<T>::RemoveAt_dce190584913328b(int32_t index) {
        return RemoveAt2(index);
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t ReadOnlyCollection<T>::get_Count_a9c25d5c244affb9() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class T>
    int32_t ReadOnlyCollection<T>::get_Count_8f254f3dd8e2403() {
        return get_Count();
    }
    
    // Automatically generated method stub
    template<class T>
    T ReadOnlyCollection<T>::get_Item_e6c1a54cb8f591e7(int32_t index) {
        return get_Item2(index);
    }
    
    // Automatically generated method stub
    template<class T>
    T ReadOnlyCollection<T>::set_Item_13ad50de181a1c01(int32_t index, T value) {
        return set_Item(index, value);
    }
    
    // Automatically generated method stub
    template<class T>
    bool ReadOnlyCollection<T>::get_IsReadOnly_9569eb0bb1daa9b5() {
        return get_IsReadOnly();
    }
    
    // Automatically generated method stub
    template<class T>
    bool ReadOnlyCollection<T>::get_IsSynchronized_20926e7dabc53dbf() {
        return get_IsSynchronized();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* ReadOnlyCollection<T>::get_SyncRoot_257108f45cc89e19() {
        return get_SyncRoot();
    }
    
    // Automatically generated method stub
    template<class T>
    bool ReadOnlyCollection<T>::get_IsFixedSize_4d3eaee3435ee591() {
        return get_IsFixedSize();
    }
    
    // Automatically generated method stub
    template<class T>
    bool ReadOnlyCollection<T>::get_IsReadOnly_53b6e02d46187790() {
        return get_IsReadOnly2();
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* ReadOnlyCollection<T>::get_Item_8550d21996ef9dc5(int32_t index) {
        return get_Item3(index);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Object* ReadOnlyCollection<T>::set_Item_d57705373e0668e7(int32_t index, System::Object* value) {
        return set_Item2(index, value);
    }
    
}}}
namespace System { namespace Globalization {
}}
namespace System { namespace Globalization {
}}
namespace System { namespace Globalization {
}}
namespace System { namespace Globalization {
}}
namespace System { namespace Globalization {
}}
namespace System { namespace Globalization {
}}
namespace System { namespace Globalization {
}}
namespace System { namespace Globalization {
}}
namespace System { namespace IO {
}}
namespace System { namespace IO {
}}
namespace System { namespace IO {
}}
namespace System { namespace IO {
}}
namespace System { namespace IO {
}}
namespace System { namespace IO {
}}
namespace System { namespace IO {
}}
namespace System { namespace IO {
}}
namespace System { namespace IO {
}}
namespace System { namespace IO { namespace IsolatedStorage {
}}}
namespace System { namespace IO { namespace IsolatedStorage {
}}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection {
}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Reflection { namespace Emit {
}}}
namespace System { namespace Resources {
}}
namespace System { namespace Resources {
}}
namespace System { namespace Resources {
}}
namespace System { namespace Resources {
}}
namespace System { namespace Runtime {
}}
namespace System { namespace Runtime { namespace InteropServices {
}}}
namespace System { namespace Runtime { namespace InteropServices {
}}}
namespace System { namespace Runtime { namespace InteropServices {
}}}
namespace System { namespace Runtime { namespace InteropServices {
}}}
namespace System { namespace Runtime { namespace Remoting {
}}}
namespace System { namespace Runtime { namespace Remoting {
}}}
namespace System { namespace Runtime { namespace Remoting {
}}}
namespace System { namespace Runtime { namespace Remoting {
}}}
namespace System { namespace Runtime { namespace Remoting {
}}}
namespace System { namespace Runtime { namespace Remoting {
}}}
namespace System { namespace Runtime { namespace Remoting { namespace Activation {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Activation {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Activation {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Activation {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Activation {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting {
}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Channels {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Lifetime {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Lifetime {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Lifetime {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
}}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Proxies {
}}}}
namespace System { namespace Runtime { namespace Remoting { namespace Proxies {
}}}}
namespace System { namespace Runtime { namespace Serialization {
}}}
namespace System { namespace Runtime { namespace Serialization {
}}}
namespace System { namespace Runtime { namespace Serialization {
}}}
namespace System { namespace Runtime { namespace Serialization {
}}}
namespace System { namespace Runtime { namespace Serialization {
}}}
namespace System { namespace Runtime { namespace Serialization {
}}}
namespace System { namespace Runtime { namespace Serialization { namespace Formatters {
}}}}
namespace System { namespace Runtime { namespace Serialization { namespace Formatters {
}}}}
namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
}}}}}
namespace System { namespace Security {
}}
namespace System { namespace Security {
}}
namespace System { namespace Security {
}}
namespace System { namespace Security {
}}
namespace System { namespace Security {
}}
namespace System { namespace Security { namespace AccessControl {
}}}
namespace System { namespace Security { namespace AccessControl {
}}}
namespace System { namespace Security { namespace AccessControl {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Cryptography { namespace X509Certificates {
}}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Permissions {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace System { namespace Security { namespace Principal {
}}}
namespace System { namespace Security { namespace Principal {
}}}
namespace System { namespace Security { namespace Principal {
}}}
namespace System { namespace Security { namespace Principal {
}}}
namespace System { namespace Security { namespace Principal {
}}}
namespace System { namespace Security { namespace Principal {
}}}
namespace System { namespace Security { namespace Principal {
}}}
namespace System { namespace Text {
}}
namespace System { namespace Text {
}}
namespace System { namespace Text {
}}
namespace System { namespace Text {
}}
namespace System { namespace Text {
}}
namespace System { namespace Text {
}}
namespace System { namespace Text {
}}
namespace System { namespace Text {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
    // Automatically generated method stub
    template<class T>
    void ThreadLocal<T>::Dispose_95cb2516542c2f97() {
        return Dispose();
    }
    
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading {
}}
namespace System { namespace Threading { namespace Tasks {
    // Automatically generated method stub
    template<class T>
    void CyclicDeque<T>::PushBottom_67d204615af76330(T obj) {
        return PushBottom(obj);
    }
    
    // Automatically generated method stub
    template<class T>
    PopResult CyclicDeque<T>::PopBottom_550cfc022701ac6c(T obj) {
        return PopBottom(obj);
    }
    
    // Automatically generated method stub
    template<class T>
    PopResult CyclicDeque<T>::PopTop_6ebc020e341f5b55(T obj) {
        return PopTop(obj);
    }
    
    // Automatically generated method stub
    template<class T>
    System::Collections::Generic::IEnumerable2<T>* CyclicDeque<T>::GetEnumerable_8d3bea811daa044d() {
        return GetEnumerable();
    }
    
}}}
namespace System { namespace Threading { namespace Tasks {
}}}
namespace System { namespace Threading { namespace Tasks {
}}}
namespace System { namespace Threading { namespace Tasks {
}}}
namespace System { namespace Threading { namespace Tasks {
}}}
namespace System { namespace Threading { namespace Tasks {
}}}
namespace System { namespace Threading { namespace Tasks {
}}}
namespace Microsoft { namespace Win32 { namespace SafeHandles {
}}}
namespace Microsoft { namespace Win32 { namespace SafeHandles {
}}}
namespace Microsoft { namespace Win32 { namespace SafeHandles {
}}}
namespace Microsoft { namespace Win32 { namespace SafeHandles {
}}}
namespace Microsoft { namespace Win32 { namespace SafeHandles {
}}}
namespace System { namespace Collections { namespace Generic {
}}}
namespace System { namespace Runtime { namespace InteropServices {
}}}
namespace System { namespace Security { namespace Cryptography {
}}}
namespace System { namespace Security { namespace Policy {
}}}
namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Security {
    
}}
 namespace System {
    
}
 namespace System {
    
    template<class T>
    void InternalEnumerator<T>::constructor(Array* array) {
        (*this)->array = array;
        (*this)->idx = -2;
    }
    
    template<class T>
    void InternalEnumerator<T>::Dispose() {
        (*this)->idx = -2;
    }
    
    template<class T>
    bool InternalEnumerator<T>::MoveNext() {
        if(((*this)->idx ==  -2)) 
        {
            (*this)->idx = (*this)->array->get_Length();
        }
        return (((*this)->idx != -1) && (--(*this)->idx != -1));
    }
    
    template<class T>
    void InternalEnumerator<T>::Reset() {
        (*this)->idx = -2;
    }
    
    template<class T>
    T InternalEnumerator<T>::get_Current() {
        if(((*this)->idx ==  -2)) 
        {
            throw cli::gcnew<InvalidOperationException>(_T("Enumeration has not started. Call MoveNext"));
        }
        if(((*this)->idx ==  -1)) 
        {
            throw cli::gcnew<InvalidOperationException>(_T("Enumeration already finished"));
        }
        return (*this)->array->template InternalArray__get_Item_1<T>((((*this)->array->get_Length() - 1) - (*this)->idx));
    }
    
    template<class T>
    Object* InternalEnumerator<T>::get_Current2() {
        return cli::box((*this)->get_Current());
    }
    
}
 namespace System {
    
    template<class T>
    void ArraySegment<T>::constructor(cli::array<T>* array, int32_t offset, int32_t count) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((offset < 0)) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("offset"), _T("Non-negative number required."));
        }
        if((count < 0)) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("count"), _T("Non-negative number required."));
        }
        if((offset > array->get_Length())) 
        {
            throw cli::gcnew<ArgumentException>(_T("out of bounds"));
        }
        if(((array->get_Length() - offset) < count)) 
        {
            throw cli::gcnew<ArgumentException>(_T("out of bounds"), _T("offset"));
        }
        (*this)->array = array;
        (*this)->offset = offset;
        (*this)->count = count;
    }
    
    template<class T>
    void ArraySegment<T>::constructor(cli::array<T>* array) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        (*this)->array = array;
        (*this)->offset = 0;
        (*this)->count = array->get_Length();
    }
    
    template<class T>
    bool ArraySegment<T>::Equals_ed975d2f4a7d193e(Object* obj) {
        if(cli::is<ArraySegment<T>>(obj)) 
        {
            return (*this)->Equals2(cli::unbox<ArraySegment<T>>(obj));
        }
        return false;
    }
    
    template<class T>
    bool ArraySegment<T>::Equals2(ArraySegment<T> obj) {
        if(((((*this)->array ==  obj->get_Array()) && ((*this)->offset ==  obj->get_Offset())) && ((*this)->count ==  obj->get_Count()))) 
        {
            return true;
        }
        return false;
    }
    
    template<class T>
    int32_t ArraySegment<T>::GetHashCode_6648aef0f235ee6c() {
        return ((cli::import((*this)->array)->GetHashCode_6648aef0f235ee6c() ^ (*this)->offset) ^ (*this)->count);
    }
    
    template<class T>
    bool ArraySegment<T>::op_Equality(ArraySegment<T> a, ArraySegment<T> b) {
        return a->Equals2(b);
    }
    
    template<class T>
    bool ArraySegment<T>::op_Inequality(ArraySegment<T> a, ArraySegment<T> b) {
        return !(a->Equals2(b));
    }
    
    template<class T>
    cli::array<T>* ArraySegment<T>::get_Array() {
        return (*this)->array;
    }
    
    template<class T>
    int32_t ArraySegment<T>::get_Offset() {
        return (*this)->offset;
    }
    
    template<class T>
    int32_t ArraySegment<T>::get_Count() {
        return (*this)->count;
    }
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
    template<class T>
    void Nullable2<T>::constructor(T value) {
        (*this)->has_value = true;
        (*this)->value = value;
    }
    
    template<class T>
    bool Nullable2<T>::Equals_ed975d2f4a7d193e(Object* other) {
        if((other ==  nullptr)) 
        {
            return ((*this)->has_value ==  false);
        }
        if(!(cli::is<Nullable2<T>>(other))) 
        {
            return false;
        }
        return Equals2(cli::unbox<Nullable2<T>>(other));
    }
    
    template<class T>
    bool Nullable2<T>::Equals2(Nullable2<T> other) {
        if((other->has_value != (*this)->has_value)) 
        {
            return false;
        }
        if(((*this)->has_value ==  false)) 
        {
            return true;
        }
        return cli::import(other->value)->Equals_ed975d2f4a7d193e(cli::box((*this)->value));
    }
    
    template<class T>
    int32_t Nullable2<T>::GetHashCode_6648aef0f235ee6c() {
        if(!((*this)->has_value)) 
        {
            return 0;
        }
        return cli::import((*this)->value)->GetHashCode_6648aef0f235ee6c();
    }
    
    template<class T>
    T Nullable2<T>::GetValueOrDefault() {
        return (*this)->has_value ? (*this)->value : T();
    }
    
    template<class T>
    T Nullable2<T>::GetValueOrDefault2(T defaultValue) {
        return (*this)->has_value ? (*this)->value : defaultValue;
    }
    
    template<class T>
    String* Nullable2<T>::ToString_1636a0751cb9ac11() {
        if((*this)->has_value) 
        {
            return cli::import((*this)->value)->ToString_1636a0751cb9ac11();
        }
         else 
        {
            return String::Empty;
        }
    }
    
    template<class T>
    Object* Nullable2<T>::Box(Nullable2<T> o) {
        if(!(o->has_value)) 
        {
            return nullptr;
        }
        return cli::box(o->value);
    }
    
    template<class T>
    Nullable2<T> Nullable2<T>::Unbox(Object* o) {
        if((o ==  nullptr)) 
        {
            return nullptr;
        }
        return cli::wrap_nullable(cli::unbox<T>(o));
    }
    
    template<class T>
    Nullable2<T> Nullable2<T>::op_Implicit(T value) {
        return cli::ctor<Nullable2<T>>(value);
    }
    
    template<class T>
    T Nullable2<T>::op_Explicit(Nullable2<T> value) {
        return value->get_Value();
    }
    
    template<class T>
    bool Nullable2<T>::get_HasValue() {
        return (*this)->has_value;
    }
    
    template<class T>
    T Nullable2<T>::get_Value() {
        if(!((*this)->has_value)) 
        {
            throw cli::gcnew<InvalidOperationException>(_T("Nullable object must have a value."));
        }
        return (*this)->value;
    }
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class TKey, class T>
    void SimpleRwLock<TKey, T>::EnterReadLock() {
        System::Threading::SpinWait sw = cli::ctor<System::Threading::SpinWait>();
        do {
            while((((*this)->rwlock & 3) > 0)) sw->SpinOnce();
            if(((System::Threading::Interlocked::Add((*this)->rwlock, 4) & 1) ==  0)) 
            {
                return;
            }
            System::Threading::Interlocked::Add((*this)->rwlock, -4);
        }
        while(true);
    }
    
    template<class TKey, class T>
    void SimpleRwLock<TKey, T>::ExitReadLock() {
        System::Threading::Interlocked::Add((*this)->rwlock, -4);
    }
    
    template<class TKey, class T>
    void SimpleRwLock<TKey, T>::EnterWriteLock() {
        System::Threading::SpinWait sw = cli::ctor<System::Threading::SpinWait>();
        do {
            int32_t state = (*this)->rwlock;
            if((state < 2)) 
            {
                if((System::Threading::Interlocked::CompareExchange((*this)->rwlock, 2, state) ==  state)) 
                {
                    return;
                }
                state = (*this)->rwlock;
            }
            while((((state & 1) ==  0) && (System::Threading::Interlocked::CompareExchange((*this)->rwlock, (state | 1), state) != state))) state = (*this)->rwlock;
            while(((*this)->rwlock > 1)) sw->SpinOnce();
        }
        while(true);
    }
    
    template<class TKey, class T>
    void SimpleRwLock<TKey, T>::ExitWriteLock() {
        System::Threading::Interlocked::Add((*this)->rwlock, -2);
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class TKey, class TValue>
    void Enumerator4<TKey, TValue>::constructor(Dictionary<TKey, TValue>* dictionary) {
        (*this)->dictionary = dictionary;
        (*this)->stamp = dictionary->generation;
    }
    
    template<class TKey, class TValue>
    bool Enumerator4<TKey, TValue>::MoveNext() {
        VerifyState();
        if(((*this)->next < 0)) 
        {
            return false;
        }
        while(((*this)->next < (*this)->dictionary->touchedSlots)) {
            int32_t cur = (*this)->next++;
            if((((*this)->dictionary->linkSlots->at(cur)->HashCode & -2147483648) != 0)) 
            {
                (*this)->current = cli::ctor<KeyValuePair<TKey, TValue>>((*this)->dictionary->keySlots->at(cur), (*this)->dictionary->valueSlots->at(cur));
                return true;
            }
        }
        (*this)->next = -1;
        return false;
    }
    
    template<class TKey, class TValue>
    void Enumerator4<TKey, TValue>::Reset() {
        Reset2();
    }
    
    template<class TKey, class TValue>
    void Enumerator4<TKey, TValue>::Reset2() {
        VerifyState();
        (*this)->next = 0;
    }
    
    template<class TKey, class TValue>
    void Enumerator4<TKey, TValue>::VerifyState() {
        if(((*this)->dictionary ==  nullptr)) 
        {
            throw cli::gcnew<System::ObjectDisposedException>(nullptr);
        }
        if(((*this)->dictionary->generation != (*this)->stamp)) 
        {
            throw cli::gcnew<System::InvalidOperationException>(_T("out of sync"));
        }
    }
    
    template<class TKey, class TValue>
    void Enumerator4<TKey, TValue>::VerifyCurrent() {
        VerifyState();
        if(((*this)->next <= 0)) 
        {
            throw cli::gcnew<System::InvalidOperationException>(_T("Current is not valid"));
        }
    }
    
    template<class TKey, class TValue>
    void Enumerator4<TKey, TValue>::Dispose() {
        (*this)->dictionary = nullptr;
    }
    
    template<class TKey, class TValue>
    KeyValuePair<TKey, TValue> Enumerator4<TKey, TValue>::get_Current() {
        return (*this)->current;
    }
    
    template<class TKey, class TValue>
    TKey Enumerator4<TKey, TValue>::get_CurrentKey() {
        VerifyCurrent();
        return (*this)->current->get_Key();
    }
    
    template<class TKey, class TValue>
    TValue Enumerator4<TKey, TValue>::get_CurrentValue() {
        VerifyCurrent();
        return (*this)->current->get_Value();
    }
    
    template<class TKey, class TValue>
    System::Object* Enumerator4<TKey, TValue>::get_Current2() {
        VerifyCurrent();
        return cli::box((*this)->current);
    }
    
    template<class TKey, class TValue>
    System::Collections::DictionaryEntry Enumerator4<TKey, TValue>::get_Entry() {
        VerifyCurrent();
        return cli::ctor<System::Collections::DictionaryEntry>(cli::box((*this)->current->get_Key()), cli::box((*this)->current->get_Value()));
    }
    
    template<class TKey, class TValue>
    System::Object* Enumerator4<TKey, TValue>::get_Key() {
        return cli::box((*this)->get_CurrentKey());
    }
    
    template<class TKey, class TValue>
    System::Object* Enumerator4<TKey, TValue>::get_Value() {
        return cli::box((*this)->get_CurrentValue());
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class TKey, class TValue>
    void Enumerator5<TKey, TValue>::constructor(Dictionary<TKey, TValue>* host) {
        (*this)->host_enumerator = host->GetEnumerator4();
    }
    
    template<class TKey, class TValue>
    void Enumerator5<TKey, TValue>::Dispose() {
        (*this)->host_enumerator->Dispose();
    }
    
    template<class TKey, class TValue>
    bool Enumerator5<TKey, TValue>::MoveNext() {
        return (*this)->host_enumerator->MoveNext();
    }
    
    template<class TKey, class TValue>
    void Enumerator5<TKey, TValue>::Reset() {
        (*this)->host_enumerator->Reset2();
    }
    
    template<class TKey, class TValue>
    TKey Enumerator5<TKey, TValue>::get_Current() {
        return (*this)->host_enumerator->current->get_Key();
    }
    
    template<class TKey, class TValue>
    System::Object* Enumerator5<TKey, TValue>::get_Current2() {
        return cli::box((*this)->host_enumerator->get_CurrentKey());
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class TKey, class TValue>
    void Enumerator6<TKey, TValue>::constructor(Dictionary<TKey, TValue>* host) {
        (*this)->host_enumerator = host->GetEnumerator4();
    }
    
    template<class TKey, class TValue>
    void Enumerator6<TKey, TValue>::Dispose() {
        (*this)->host_enumerator->Dispose();
    }
    
    template<class TKey, class TValue>
    bool Enumerator6<TKey, TValue>::MoveNext() {
        return (*this)->host_enumerator->MoveNext();
    }
    
    template<class TKey, class TValue>
    void Enumerator6<TKey, TValue>::Reset() {
        (*this)->host_enumerator->Reset2();
    }
    
    template<class TKey, class TValue>
    TValue Enumerator6<TKey, TValue>::get_Current() {
        return (*this)->host_enumerator->current->get_Value();
    }
    
    template<class TKey, class TValue>
    System::Object* Enumerator6<TKey, TValue>::get_Current2() {
        return cli::box((*this)->host_enumerator->get_CurrentValue());
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class TKey, class TValue>
    void KeyValuePair<TKey, TValue>::constructor(TKey key, TValue value) {
        (*this)->key = key;
        (*this)->value = value;
    }
    
    template<class TKey, class TValue>
    System::String* KeyValuePair<TKey, TValue>::ToString_1636a0751cb9ac11() {
        return cli::concat(_T("["), (cli::box((*this)->get_Key()) != nullptr) ? cli::import((*this)->get_Key())->ToString_1636a0751cb9ac11() : System::String::Empty, _T(", "), (cli::box((*this)->get_Value()) != nullptr) ? cli::import((*this)->get_Value())->ToString_1636a0751cb9ac11() : System::String::Empty, _T("]"));
    }
    
    template<class TKey, class TValue>
    TKey KeyValuePair<TKey, TValue>::get_Key() {
        return (*this)->key;
    }
    
    template<class TKey, class TValue>
    TKey KeyValuePair<TKey, TValue>::set_Key(TKey value) {
        (*this)->key = value;
        return get_Key();
    }
    
    template<class TKey, class TValue>
    TValue KeyValuePair<TKey, TValue>::get_Value() {
        return (*this)->value;
    }
    
    template<class TKey, class TValue>
    TValue KeyValuePair<TKey, TValue>::set_Value(TValue value) {
        (*this)->value = value;
        return get_Value();
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class T>
    void Enumerator7<T>::constructor(List<T>* l) {
        (*this)->l = l;
        (*this)->ver = l->_version;
    }
    
    template<class T>
    void Enumerator7<T>::Dispose() {
    }
    
    template<class T>
    void Enumerator7<T>::VerifyState() {
        if(((*this)->ver != (*this)->l->_version)) 
        {
            throw cli::gcnew<System::InvalidOperationException>(_T("Collection was modified; enumeration operation may not execute."));
        }
    }
    
    template<class T>
    bool Enumerator7<T>::MoveNext() {
        VerifyState();
        if(((*this)->next < 0)) 
        {
            return false;
        }
        if(((*this)->next < (*this)->l->_size)) 
        {
            (*this)->current = (*this)->l->_items->at((*this)->next++);
            return true;
        }
        (*this)->next = -1;
        return false;
    }
    
    template<class T>
    void Enumerator7<T>::Reset() {
        VerifyState();
        (*this)->next = 0;
    }
    
    template<class T>
    T Enumerator7<T>::get_Current() {
        return (*this)->current;
    }
    
    template<class T>
    System::Object* Enumerator7<T>::get_Current2() {
        VerifyState();
        if(((*this)->next <= 0)) 
        {
            throw cli::gcnew<System::InvalidOperationException>();
        }
        return cli::box((*this)->current);
    }
    
}}}
 namespace System { namespace Configuration { namespace Assemblies {
    
}}}
 namespace System { namespace Diagnostics { namespace SymbolStore {
    
}}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO { namespace IsolatedStorage {
    
}}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace InteropServices { namespace ComTypes {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography { namespace X509Certificates {
    
}}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TCompletion>
    void TaskCompletionQueue<TCompletion>::Add(TCompletion continuation) {
        if(((cli::box((*this)->single) ==  nullptr) && (cli::box(System::Threading::Interlocked::template CompareExchange_1<TCompletion>((*this)->single, continuation, nullptr)) ==  nullptr))) 
        {
            return;
        }
        if(((*this)->completed ==  nullptr)) 
        {
            System::Threading::Interlocked::template CompareExchange_1<System::Collections::Concurrent::ConcurrentOrderedList<TCompletion>*>((*this)->completed, cli::gcnew<System::Collections::Concurrent::ConcurrentOrderedList<TCompletion>>(), nullptr);
        }
        (*this)->completed->TryAdd(continuation);
    }
    
    template<class TCompletion>
    bool TaskCompletionQueue<TCompletion>::Remove(TCompletion continuation) {
        TCompletion temp = (*this)->single;
        if((((cli::box(temp) != nullptr) && (cli::box(temp) ==  cli::box(continuation))) && (cli::box(System::Threading::Interlocked::template CompareExchange_1<TCompletion>((*this)->single, nullptr, continuation)) ==  cli::box(continuation)))) 
        {
            return true;
        }
        if(((*this)->completed != nullptr)) 
        {
            return (*this)->completed->TryRemove(continuation);
        }
        return false;
    }
    
    template<class TCompletion>
    bool TaskCompletionQueue<TCompletion>::TryGetNextCompletion(TCompletion continuation) {
        continuation = nullptr;
        if(((cli::box((*this)->single) != nullptr) && (cli::box(continuation = System::Threading::Interlocked::template Exchange_1<TCompletion>((*this)->single, nullptr)) != nullptr))) 
        {
            return true;
        }
        return (((*this)->completed != nullptr) && (*this)->completed->TryPop(continuation));
    }
    
    template<class TCompletion>
    bool TaskCompletionQueue<TCompletion>::get_HasElements() {
        return ((cli::box((*this)->single) != nullptr) || (((*this)->completed != nullptr) && ((*this)->completed->get_Count() != 0)));
    }
    
}}}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 
 
 namespace Microsoft { namespace Win32 {
    
}}
 namespace Microsoft { namespace Win32 {
    
}}
 namespace Microsoft { namespace Win32 {
    
}}
 namespace Microsoft { namespace Win32 {
    
}}
 namespace Microsoft { namespace Win32 {
    
}}
 namespace Microsoft { namespace Win32 {
    
}}
 namespace Microsoft { namespace Win32 {
    
}}
 namespace Microsoft { namespace Win32 { namespace SafeHandles {
    
}}}
 namespace Microsoft { namespace Win32 { namespace SafeHandles {
    
}}}
 namespace Microsoft { namespace Win32 { namespace SafeHandles {
    
}}}
 namespace Microsoft { namespace Win32 { namespace SafeHandles {
    
}}}
 namespace Microsoft { namespace Win32 { namespace SafeHandles {
    
}}}
 namespace Microsoft { namespace Win32 { namespace SafeHandles {
    
}}}
 namespace Microsoft { namespace Win32 { namespace SafeHandles {
    
}}}
 namespace Mono {
    
}
 namespace Mono {
    
}
 namespace Mono {
    
}
 namespace Mono {
    
}
 namespace Mono {
    
}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace System { namespace Globalization {
    
}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Globalization { namespace Unicode {
    
}}}
 namespace Mono { namespace Interop {
    
}}
 namespace Mono { namespace Math {
    
}}
 namespace Mono { namespace Math {
    
}}
 namespace Mono { namespace Math {
    
}}
 namespace Mono { namespace Math { namespace Prime {
    
}}}
 namespace Mono { namespace Math { namespace Prime { namespace Generator {
    
}}}}
 namespace Mono { namespace Math { namespace Prime { namespace Generator {
    
}}}}
 namespace Mono { namespace Math { namespace Prime { namespace Generator {
    
}}}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security {
    
}}
 namespace Mono { namespace Security { namespace Authenticode {
    
}}}
 namespace Mono { namespace Security { namespace Authenticode {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace Cryptography {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 {
    
}}}
 namespace Mono { namespace Security { namespace X509 { namespace Extensions {
    
}}}}
 namespace Mono { namespace Security { namespace X509 { namespace Extensions {
    
}}}}
 namespace Mono { namespace Security { namespace X509 { namespace Extensions {
    
}}}}
 namespace Mono { namespace Xml {
    
}}
 namespace Mono { namespace Xml {
    
}}
 namespace Mono { namespace Xml {
    
}}
 namespace Mono { namespace Xml {
    
}}
 namespace Mono { namespace Xml {
    
}}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
    template<class T>
    T Activator::CreateInstance_1() {
        return cli::unbox<T>(CreateInstance8(cli::typeof<Type>::info));
    }
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
    template<class T>
    Collections::Generic::IEnumerator2<T>* Array::InternalArray__IEnumerable_GetEnumerator_1() {
        return cli::box<Collections::Generic::IEnumerator2<T>*>(cli::ctor<InternalEnumerator<T>>(this));
    }
    
    template<class T>
    void Array::InternalArray__ICollection_Add_1(T item) {
        throw cli::gcnew<NotSupportedException>(_T("Collection is of a fixed size"));
    }
    
    template<class T>
    bool Array::InternalArray__ICollection_Remove_1(T item) {
        throw cli::gcnew<NotSupportedException>(_T("Collection is of a fixed size"));
    }
    
    template<class T>
    bool Array::InternalArray__ICollection_Contains_1(T item) {
        if((this->get_Rank() > 1)) 
        {
            throw cli::gcnew<RankException>(Locale::GetText(_T("Only single dimension arrays are supported.")));
        }
        int32_t length = this->get_Length();
        for(int32_t i = 0; (i < length); i++){
            T value;
            GetGenericValueImpl_1<T>(i, value);
            if((cli::box(item) ==  nullptr)) 
            {
                if((cli::box(value) ==  nullptr)) 
                {
                    return true;
                }
                continue;
            }
            if(cli::import(item)->Equals_ed975d2f4a7d193e(cli::box(value))) 
            {
                return true;
            }
        }
        return false;
    }
    
    template<class T>
    void Array::InternalArray__ICollection_CopyTo_1(cli::array<T>* array, int32_t index) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((this->get_Rank() > 1)) 
        {
            throw cli::gcnew<RankException>(Locale::GetText(_T("Only single dimension arrays are supported.")));
        }
        if(((index + this->GetLength(0)) > (cli::import(array)->GetLowerBound(0) + cli::import(array)->GetLength(0)))) 
        {
            throw cli::gcnew<ArgumentException>(_T("Destination array was not long enough. Check destIndex and length, and the array\'s lower bounds."));
        }
        if((array->get_Rank() > 1)) 
        {
            throw cli::gcnew<RankException>(Locale::GetText(_T("Only single dimension arrays are supported.")));
        }
        if((index < 0)) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("index"), Locale::GetText(_T("Value has to be >= 0.")));
        }
        Copy2(this, this->GetLowerBound(0), array, index, this->GetLength(0));
    }
    
    template<class T>
    void Array::InternalArray__Insert_1(int32_t index, T item) {
        throw cli::gcnew<NotSupportedException>(_T("Collection is of a fixed size"));
    }
    
    template<class T>
    int32_t Array::InternalArray__IndexOf_1(T item) {
        if((this->get_Rank() > 1)) 
        {
            throw cli::gcnew<RankException>(Locale::GetText(_T("Only single dimension arrays are supported.")));
        }
        int32_t length = this->get_Length();
        for(int32_t i = 0; (i < length); i++){
            T value;
            GetGenericValueImpl_1<T>(i, value);
            if((cli::box(item) ==  nullptr)) 
            {
                if((cli::box(value) ==  nullptr)) 
                {
                    return (i + this->GetLowerBound(0));
                }
                continue;
            }
            if(cli::import(value)->Equals_ed975d2f4a7d193e(cli::box(item))) 
            {
                return (i + this->GetLowerBound(0));
            }
        }
        /*unchecked*/ {
            return (this->GetLowerBound(0) - 1);
        }
    }
    
    template<class T>
    T Array::InternalArray__get_Item_1(int32_t index) {
        if((cli::unchecked((uint32_t)index) >= cli::unchecked((uint32_t)this->get_Length()))) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("index"));
        }
        T value;
        GetGenericValueImpl_1<T>(index, value);
        return value;
    }
    
    template<class T>
    void Array::InternalArray__set_Item_1(int32_t index, T item) {
        if((cli::unchecked((uint32_t)index) >= cli::unchecked((uint32_t)this->get_Length()))) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("index"));
        }
        cli::array<Object*> *oarray = cli::as<cli::array<Object*>*>(this);
        if((oarray != nullptr)) 
        {
            oarray->at(index) = cli::box(item);
            return;
        }
        SetGenericValueImpl_1<T>(index, item);
    }
    
    template<class T>
    void Array::GetGenericValueImpl_1(int32_t pos, T value) {
      // TODO: "Unimplemented external method!"
      throw cli::gcnew<System::NotImplementedException>();
    }
    
    template<class T>
    void Array::SetGenericValueImpl_1(int32_t pos, T value) {
      // TODO: "Unimplemented external method!"
      throw cli::gcnew<System::NotImplementedException>();
    }
    
    template<class T>
    void Array::Sort_1(cli::array<T>* array) {
        Sort_12<T>(array, nullptr);
    }
    
    template<class TKey, class TValue>
    void Array::Sort_2(cli::array<TKey>* keys, cli::array<TValue>* items) {
        Sort_22<TKey, TValue>(keys, items, nullptr);
    }
    
    template<class T>
    void Array::Sort_12(cli::array<T>* array, Collections::Generic::IComparer2<T>* comparer) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        SortImpl_1<T>(array, 0, array->get_Length(), comparer);
    }
    
    template<class TKey, class TValue>
    void Array::Sort_22(cli::array<TKey>* keys, cli::array<TValue>* items, Collections::Generic::IComparer2<TKey>* comparer) {
        if((items ==  nullptr)) 
        {
            Sort_12<TKey>(keys, comparer);
            return;
        }
        if((keys ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("keys"));
        }
        if((keys->get_Length() != items->get_Length())) 
        {
            throw cli::gcnew<ArgumentException>(_T("Length of keys and items does not match."));
        }
        SortImpl_2<TKey, TValue>(keys, items, 0, keys->get_Length(), comparer);
    }
    
    template<class T>
    void Array::Sort_13(cli::array<T>* array, int32_t index, int32_t length) {
        Sort_14<T>(array, index, length, nullptr);
    }
    
    template<class TKey, class TValue>
    void Array::Sort_23(cli::array<TKey>* keys, cli::array<TValue>* items, int32_t index, int32_t length) {
        Sort_24<TKey, TValue>(keys, items, index, length, nullptr);
    }
    
    template<class T>
    void Array::Sort_14(cli::array<T>* array, int32_t index, int32_t length, Collections::Generic::IComparer2<T>* comparer) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((index < 0)) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("index"));
        }
        if((length < 0)) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("length"), Locale::GetText(_T("Value has to be >= 0.")));
        }
        if(((index + length) > array->get_Length())) 
        {
            throw cli::gcnew<ArgumentException>();
        }
        SortImpl_2<T, T>(array, nullptr, index, length, comparer);
    }
    
    template<class TKey, class TValue>
    void Array::Sort_24(cli::array<TKey>* keys, cli::array<TValue>* items, int32_t index, int32_t length, Collections::Generic::IComparer2<TKey>* comparer) {
        if((items ==  nullptr)) 
        {
            Sort_14<TKey>(keys, index, length, comparer);
            return;
        }
        if((keys ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("keys"));
        }
        if((index < 0)) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("index"));
        }
        if((length < 0)) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("length"));
        }
        if((((items->get_Length() - index) < length) || ((keys->get_Length() - index) < length))) 
        {
            throw cli::gcnew<ArgumentException>();
        }
        SortImpl_2<TKey, TValue>(keys, items, index, length, comparer);
    }
    
    template<class TKey, class TValue>
    void Array::SortImpl_2(cli::array<TKey>* keys, cli::array<TValue>* items, int32_t index, int32_t length, Collections::Generic::IComparer2<TKey>* comparer) {
        if((keys->get_Length() <= 1)) 
        {
            return;
        }
        int32_t low = index;
        int32_t high = ((index + length) - 1);
        if((comparer ==  nullptr)) 
        {
            switch(Type::GetTypeCode(cli::typeof<Type>::info)) {
                case TypeCode::Int322: case_1: {
                    qsort_2<int32_t, TValue>(cli::as<cli::array<int32_t>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::Int642: case_2: {
                    qsort_2<int64_t, TValue>(cli::as<cli::array<int64_t>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::Byte2: case_3: {
                    qsort_2<unsigned char, TValue>(cli::as<cli::array<unsigned char>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::Char2: case_4: {
                    qsort_2<char16_t, TValue>(cli::as<cli::array<char16_t>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::DateTime2: case_5: {
                    qsort_2<DateTime, TValue>(cli::as<cli::array<DateTime>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::Decimal2: case_6: {
                    qsort_2<Decimal, TValue>(cli::as<cli::array<Decimal>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::Double2: case_7: {
                    qsort_2<double, TValue>(cli::as<cli::array<double>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::Int162: case_8: {
                    qsort_2<int16_t, TValue>(cli::as<cli::array<int16_t>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::SByte2: case_9: {
                    qsort_2<signed char, TValue>(cli::as<cli::array<signed char>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::Single2: case_10: {
                    qsort_2<float, TValue>(cli::as<cli::array<float>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::UInt162: case_11: {
                    qsort_2<uint16_t, TValue>(cli::as<cli::array<uint16_t>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::UInt322: case_12: {
                    qsort_2<uint32_t, TValue>(cli::as<cli::array<uint32_t>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
                case TypeCode::UInt642: case_13: {
                    qsort_2<uint64_t, TValue>(cli::as<cli::array<uint64_t>*>(cli::box<cli::array<TKey>*>(keys)), items, low, high);
                    return;
                }
            }
            if((cli::typeof<Type>::info->IsAssignableFrom_e3aa32d778e63a90(cli::typeof<Type>::info) && cli::typeof<Type>::info->get_IsValueType())) 
            {
                comparer = Collections::Generic::Comparer2<TKey>::get_Default();
            }
        }
        if((comparer ==  nullptr)) 
        {
            CheckComparerAvailable_1<TKey>(keys, low, high);
        }
        qsort_22<TKey, TValue>(keys, items, low, high, comparer);
    }
    
    template<class TKey>
    void Array::SortImpl_1(cli::array<TKey>* keys, int32_t index, int32_t length, Collections::Generic::IComparer2<TKey>* comparer) {
        if((keys->get_Length() <= 1)) 
        {
            return;
        }
        int32_t low = index;
        int32_t high = ((index + length) - 1);
        if((comparer ==  nullptr)) 
        {
            switch(Type::GetTypeCode(cli::typeof<Type>::info)) {
                case TypeCode::Int322: case_14: {
                    qsort_1<int32_t>(cli::as<cli::array<int32_t>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::Int642: case_15: {
                    qsort_1<int64_t>(cli::as<cli::array<int64_t>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::Byte2: case_16: {
                    qsort_1<unsigned char>(cli::as<cli::array<unsigned char>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::Char2: case_17: {
                    qsort_1<char16_t>(cli::as<cli::array<char16_t>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::DateTime2: case_18: {
                    qsort_1<DateTime>(cli::as<cli::array<DateTime>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::Decimal2: case_19: {
                    qsort_1<Decimal>(cli::as<cli::array<Decimal>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::Double2: case_20: {
                    qsort_1<double>(cli::as<cli::array<double>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::Int162: case_21: {
                    qsort_1<int16_t>(cli::as<cli::array<int16_t>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::SByte2: case_22: {
                    qsort_1<signed char>(cli::as<cli::array<signed char>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::Single2: case_23: {
                    qsort_1<float>(cli::as<cli::array<float>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::UInt162: case_24: {
                    qsort_1<uint16_t>(cli::as<cli::array<uint16_t>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::UInt322: case_25: {
                    qsort_1<uint32_t>(cli::as<cli::array<uint32_t>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
                case TypeCode::UInt642: case_26: {
                    qsort_1<uint64_t>(cli::as<cli::array<uint64_t>*>(cli::box<cli::array<TKey>*>(keys)), low, high);
                    return;
                }
            }
            if((cli::typeof<Type>::info->IsAssignableFrom_e3aa32d778e63a90(cli::typeof<Type>::info) && cli::typeof<Type>::info->get_IsValueType())) 
            {
                comparer = Collections::Generic::Comparer2<TKey>::get_Default();
            }
        }
        if((comparer ==  nullptr)) 
        {
            CheckComparerAvailable_1<TKey>(keys, low, high);
        }
        qsort_12<TKey>(keys, low, high, comparer);
    }
    
    template<class T>
    void Array::Sort_15(cli::array<T>* array, Comparison<T>* comparison) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((comparison ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("comparison"));
        }
        SortImpl_12<T>(array, array->get_Length(), comparison);
    }
    
    template<class T>
    void Array::SortImpl_12(cli::array<T>* array, int32_t length, Comparison<T>* comparison) {
        if((length <= 1)) 
        {
            return;
        }
        try {
            int32_t low0 = 0;
            int32_t high0 = (length - 1);
            qsort_13<T>(array, low0, high0, comparison);
        }
        catch(InvalidOperationException*) {
            throw ;
        }
        catch(Exception* e) {
            throw cli::gcnew<InvalidOperationException>(Locale::GetText(_T("Comparison threw an exception.")), e);
        }
    }
    
    template<class T, class U>
    bool Array::QSortArrange_2(cli::array<T>* keys, cli::array<U>* items, int32_t lo, int32_t hi) {
        if((cli::box(keys->at(lo)) != nullptr)) 
        {
            if(((cli::box(keys->at(hi)) ==  nullptr) || (cli::import(keys->at(hi))->CompareTo_8a8b7d6c83beb422(keys->at(lo)) < 0))) 
            {
                swap_2<T, U>(keys, items, lo, hi);
                return true;
            }
        }
        return false;
    }
    
    template<class T>
    bool Array::QSortArrange_1(cli::array<T>* keys, int32_t lo, int32_t hi) {
        if((cli::box(keys->at(lo)) != nullptr)) 
        {
            if(((cli::box(keys->at(hi)) ==  nullptr) || (cli::import(keys->at(hi))->CompareTo_8a8b7d6c83beb422(keys->at(lo)) < 0))) 
            {
                swap_1<T>(keys, lo, hi);
                return true;
            }
        }
        return false;
    }
    
    template<class T, class U>
    void Array::qsort_2(cli::array<T>* keys, cli::array<U>* items, int32_t low, int32_t high) {
        const int32_t QSORT_THRESHOLD = 7;
        int32_t mid, i, k;
        T key;
        if(((low + 7) > high)) 
        {
            for(i = (low + 1); (i <= high); i++){
                for(k = i; (k > low); k--){
                    if((cli::box(keys->at((k - 1))) ==  nullptr)) 
                    {
                        break;
                    }
                    if(((cli::box(keys->at(k)) != nullptr) && (cli::import(keys->at(k))->CompareTo_8a8b7d6c83beb422(keys->at((k - 1))) >= 0))) 
                    {
                        break;
                    }
                    swap_2<T, U>(keys, items, (k - 1), k);
                }
            }
            return;
        }
        mid = (low + ((high - low) / 2));
        QSortArrange_2<T, U>(keys, items, low, mid);
        if(QSortArrange_2<T, U>(keys, items, mid, high)) 
        {
            QSortArrange_2<T, U>(keys, items, low, mid);
        }
        key = keys->at(mid);
        k = (high - 1);
        i = (low + 1);
        do {
            if((cli::box(key) != nullptr)) 
            {
                while(((i < k) && (cli::import(key)->CompareTo_8a8b7d6c83beb422(keys->at(i)) >= 0))) i++;
                while(((k >= i) && (cli::import(key)->CompareTo_8a8b7d6c83beb422(keys->at(k)) < 0))) k--;
            }
             else 
            {
                while(((i < k) && (cli::box(keys->at(i)) ==  nullptr))) i++;
                while(((k >= i) && (cli::box(keys->at(k)) != nullptr))) k--;
            }
            if((k <= i)) 
            {
                break;
            }
            swap_2<T, U>(keys, items, i, k);
            if((mid ==  i)) 
            {
                mid = k;
            }
             else 
            {
                if((mid ==  k)) 
                {
                    mid = i;
                }
            }
            i++;
            k--;
        }
        while(true);
        if((k != mid)) 
        {
            swap_2<T, U>(keys, items, mid, k);
        }
        if(((k + 1) < high)) 
        {
            qsort_2<T, U>(keys, items, (k + 1), high);
        }
        if(((k - 1) > low)) 
        {
            qsort_2<T, U>(keys, items, low, (k - 1));
        }
    }
    
    template<class T>
    void Array::qsort_1(cli::array<T>* keys, int32_t low, int32_t high) {
        const int32_t QSORT_THRESHOLD = 7;
        int32_t mid, i, k;
        T key;
        if(((low + 7) > high)) 
        {
            for(i = (low + 1); (i <= high); i++){
                for(k = i; (k > low); k--){
                    if((cli::box(keys->at((k - 1))) ==  nullptr)) 
                    {
                        break;
                    }
                    if(((cli::box(keys->at(k)) != nullptr) && (cli::import(keys->at(k))->CompareTo_8a8b7d6c83beb422(keys->at((k - 1))) >= 0))) 
                    {
                        break;
                    }
                    swap_1<T>(keys, (k - 1), k);
                }
            }
            return;
        }
        mid = (low + ((high - low) / 2));
        QSortArrange_1<T>(keys, low, mid);
        if(QSortArrange_1<T>(keys, mid, high)) 
        {
            QSortArrange_1<T>(keys, low, mid);
        }
        key = keys->at(mid);
        k = (high - 1);
        i = (low + 1);
        do {
            if((cli::box(key) != nullptr)) 
            {
                while(((i < k) && (cli::import(key)->CompareTo_8a8b7d6c83beb422(keys->at(i)) >= 0))) i++;
                while(((k >= i) && (cli::import(key)->CompareTo_8a8b7d6c83beb422(keys->at(k)) < 0))) k--;
            }
             else 
            {
                while(((i < k) && (cli::box(keys->at(i)) ==  nullptr))) i++;
                while(((k >= i) && (cli::box(keys->at(k)) != nullptr))) k--;
            }
            if((k <= i)) 
            {
                break;
            }
            swap_1<T>(keys, i, k);
            if((mid ==  i)) 
            {
                mid = k;
            }
             else 
            {
                if((mid ==  k)) 
                {
                    mid = i;
                }
            }
            i++;
            k--;
        }
        while(true);
        if((k != mid)) 
        {
            swap_1<T>(keys, mid, k);
        }
        if(((k + 1) < high)) 
        {
            qsort_1<T>(keys, (k + 1), high);
        }
        if(((k - 1) > low)) 
        {
            qsort_1<T>(keys, low, (k - 1));
        }
    }
    
    template<class K, class V>
    bool Array::QSortArrange_22(cli::array<K>* keys, cli::array<V>* items, int32_t lo, int32_t hi, Collections::Generic::IComparer2<K>* comparer) {
        IComparable2<K> *gcmp;
        IComparable *cmp;
        if((comparer != nullptr)) 
        {
            if((comparer->Compare_5902559f67a8cefa(keys->at(hi), keys->at(lo)) < 0)) 
            {
                swap_2<K, V>(keys, items, lo, hi);
                return true;
            }
        }
         else 
        {
            if((cli::box(keys->at(lo)) != nullptr)) 
            {
                if((cli::box(keys->at(hi)) ==  nullptr)) 
                {
                    swap_2<K, V>(keys, items, lo, hi);
                    return true;
                }
                gcmp = cli::as<IComparable2<K>*>(cli::box<K>(keys->at(hi)));
                if((gcmp != nullptr)) 
                {
                    if((gcmp->CompareTo_8a8b7d6c83beb422(keys->at(lo)) < 0)) 
                    {
                        swap_2<K, V>(keys, items, lo, hi);
                        return true;
                    }
                    return false;
                }
                cmp = cli::as<IComparable*>(cli::box<K>(keys->at(hi)));
                if((cmp != nullptr)) 
                {
                    if((cmp->CompareTo_ed9d39205b7812f0(cli::box(keys->at(lo))) < 0)) 
                    {
                        swap_2<K, V>(keys, items, lo, hi);
                        return true;
                    }
                    return false;
                }
            }
        }
        return false;
    }
    
    template<class K>
    bool Array::QSortArrange_12(cli::array<K>* keys, int32_t lo, int32_t hi, Collections::Generic::IComparer2<K>* comparer) {
        IComparable2<K> *gcmp;
        IComparable *cmp;
        if((comparer != nullptr)) 
        {
            if((comparer->Compare_5902559f67a8cefa(keys->at(hi), keys->at(lo)) < 0)) 
            {
                swap_1<K>(keys, lo, hi);
                return true;
            }
        }
         else 
        {
            if((cli::box(keys->at(lo)) != nullptr)) 
            {
                if((cli::box(keys->at(hi)) ==  nullptr)) 
                {
                    swap_1<K>(keys, lo, hi);
                    return true;
                }
                gcmp = cli::as<IComparable2<K>*>(cli::box<K>(keys->at(hi)));
                if((gcmp != nullptr)) 
                {
                    if((gcmp->CompareTo_8a8b7d6c83beb422(keys->at(lo)) < 0)) 
                    {
                        swap_1<K>(keys, lo, hi);
                        return true;
                    }
                    return false;
                }
                cmp = cli::as<IComparable*>(cli::box<K>(keys->at(hi)));
                if((cmp != nullptr)) 
                {
                    if((cmp->CompareTo_ed9d39205b7812f0(cli::box(keys->at(lo))) < 0)) 
                    {
                        swap_1<K>(keys, lo, hi);
                        return true;
                    }
                    return false;
                }
            }
        }
        return false;
    }
    
    template<class K, class V>
    void Array::qsort_22(cli::array<K>* keys, cli::array<V>* items, int32_t low, int32_t high, Collections::Generic::IComparer2<K>* comparer) {
        const int32_t QSORT_THRESHOLD = 7;
        IComparable2<K> *gcmp;
        IComparable *cmp;
        int32_t mid, i, k;
        K key;
        if(((low + 7) > high)) 
        {
            for(i = (low + 1); (i <= high); i++){
                for(k = i; (k > low); k--){
                    if((comparer != nullptr)) 
                    {
                        if((comparer->Compare_5902559f67a8cefa(keys->at(k), keys->at((k - 1))) >= 0)) 
                        {
                            break;
                        }
                    }
                     else 
                    {
                        if((cli::box(keys->at((k - 1))) ==  nullptr)) 
                        {
                            break;
                        }
                        if((cli::box(keys->at(k)) != nullptr)) 
                        {
                            gcmp = cli::as<IComparable2<K>*>(cli::box<K>(keys->at(k)));
                            cmp = cli::as<IComparable*>(cli::box<K>(keys->at(k)));
                            if((gcmp != nullptr)) 
                            {
                                if((gcmp->CompareTo_8a8b7d6c83beb422(keys->at((k - 1))) >= 0)) 
                                {
                                    break;
                                }
                            }
                             else 
                            {
                                if((cmp->CompareTo_ed9d39205b7812f0(cli::box(keys->at((k - 1)))) >= 0)) 
                                {
                                    break;
                                }
                            }
                        }
                    }
                    swap_2<K, V>(keys, items, (k - 1), k);
                }
            }
            return;
        }
        mid = (low + ((high - low) / 2));
        QSortArrange_22<K, V>(keys, items, low, mid, comparer);
        if(QSortArrange_22<K, V>(keys, items, mid, high, comparer)) 
        {
            QSortArrange_22<K, V>(keys, items, low, mid, comparer);
        }
        key = keys->at(mid);
        gcmp = cli::as<IComparable2<K>*>(cli::box<K>(key));
        cmp = cli::as<IComparable*>(cli::box<K>(key));
        k = (high - 1);
        i = (low + 1);
        do {
            if((comparer != nullptr)) 
            {
                while(((i < k) && (comparer->Compare_5902559f67a8cefa(key, keys->at(i)) >= 0))) i++;
                while(((k >= i) && (comparer->Compare_5902559f67a8cefa(key, keys->at(k)) < 0))) k--;
            }
             else 
            {
                if((gcmp != nullptr)) 
                {
                    while(((i < k) && (gcmp->CompareTo_8a8b7d6c83beb422(keys->at(i)) >= 0))) i++;
                    while(((k >= i) && (gcmp->CompareTo_8a8b7d6c83beb422(keys->at(k)) < 0))) k--;
                }
                 else 
                {
                    if((cmp != nullptr)) 
                    {
                        while(((i < k) && (cmp->CompareTo_ed9d39205b7812f0(cli::box(keys->at(i))) >= 0))) i++;
                        while(((k >= i) && (cmp->CompareTo_ed9d39205b7812f0(cli::box(keys->at(k))) < 0))) k--;
                    }
                     else 
                    {
                        while(((i < k) && (cli::box(keys->at(i)) ==  nullptr))) i++;
                        while(((k >= i) && (cli::box(keys->at(k)) != nullptr))) k--;
                    }
                }
            }
            if((k <= i)) 
            {
                break;
            }
            swap_2<K, V>(keys, items, i, k);
            if((mid ==  i)) 
            {
                mid = k;
            }
             else 
            {
                if((mid ==  k)) 
                {
                    mid = i;
                }
            }
            i++;
            k--;
        }
        while(true);
        if((k != mid)) 
        {
            swap_2<K, V>(keys, items, mid, k);
        }
        if(((k + 1) < high)) 
        {
            qsort_22<K, V>(keys, items, (k + 1), high, comparer);
        }
        if(((k - 1) > low)) 
        {
            qsort_22<K, V>(keys, items, low, (k - 1), comparer);
        }
    }
    
    template<class K>
    void Array::qsort_12(cli::array<K>* keys, int32_t low, int32_t high, Collections::Generic::IComparer2<K>* comparer) {
        const int32_t QSORT_THRESHOLD = 7;
        IComparable2<K> *gcmp;
        IComparable *cmp;
        int32_t mid, i, k;
        K key;
        if(((low + 7) > high)) 
        {
            for(i = (low + 1); (i <= high); i++){
                for(k = i; (k > low); k--){
                    if((comparer != nullptr)) 
                    {
                        if((comparer->Compare_5902559f67a8cefa(keys->at(k), keys->at((k - 1))) >= 0)) 
                        {
                            break;
                        }
                    }
                     else 
                    {
                        if((cli::box(keys->at((k - 1))) ==  nullptr)) 
                        {
                            break;
                        }
                        if((cli::box(keys->at(k)) != nullptr)) 
                        {
                            gcmp = cli::as<IComparable2<K>*>(cli::box<K>(keys->at(k)));
                            cmp = cli::as<IComparable*>(cli::box<K>(keys->at(k)));
                            if((gcmp != nullptr)) 
                            {
                                if((gcmp->CompareTo_8a8b7d6c83beb422(keys->at((k - 1))) >= 0)) 
                                {
                                    break;
                                }
                            }
                             else 
                            {
                                if((cmp->CompareTo_ed9d39205b7812f0(cli::box(keys->at((k - 1)))) >= 0)) 
                                {
                                    break;
                                }
                            }
                        }
                    }
                    swap_1<K>(keys, (k - 1), k);
                }
            }
            return;
        }
        mid = (low + ((high - low) / 2));
        QSortArrange_12<K>(keys, low, mid, comparer);
        if(QSortArrange_12<K>(keys, mid, high, comparer)) 
        {
            QSortArrange_12<K>(keys, low, mid, comparer);
        }
        key = keys->at(mid);
        gcmp = cli::as<IComparable2<K>*>(cli::box<K>(key));
        cmp = cli::as<IComparable*>(cli::box<K>(key));
        k = (high - 1);
        i = (low + 1);
        do {
            if((comparer != nullptr)) 
            {
                while(((i < k) && (comparer->Compare_5902559f67a8cefa(key, keys->at(i)) >= 0))) i++;
                while(((k >= i) && (comparer->Compare_5902559f67a8cefa(key, keys->at(k)) < 0))) k--;
            }
             else 
            {
                if((gcmp != nullptr)) 
                {
                    while(((i < k) && (gcmp->CompareTo_8a8b7d6c83beb422(keys->at(i)) >= 0))) i++;
                    while(((k >= i) && (gcmp->CompareTo_8a8b7d6c83beb422(keys->at(k)) < 0))) k--;
                }
                 else 
                {
                    if((cmp != nullptr)) 
                    {
                        while(((i < k) && (cmp->CompareTo_ed9d39205b7812f0(cli::box(keys->at(i))) >= 0))) i++;
                        while(((k >= i) && (cmp->CompareTo_ed9d39205b7812f0(cli::box(keys->at(k))) < 0))) k--;
                    }
                     else 
                    {
                        while(((i < k) && (cli::box(keys->at(i)) ==  nullptr))) i++;
                        while(((k >= i) && (cli::box(keys->at(k)) != nullptr))) k--;
                    }
                }
            }
            if((k <= i)) 
            {
                break;
            }
            swap_1<K>(keys, i, k);
            if((mid ==  i)) 
            {
                mid = k;
            }
             else 
            {
                if((mid ==  k)) 
                {
                    mid = i;
                }
            }
            i++;
            k--;
        }
        while(true);
        if((k != mid)) 
        {
            swap_1<K>(keys, mid, k);
        }
        if(((k + 1) < high)) 
        {
            qsort_12<K>(keys, (k + 1), high, comparer);
        }
        if(((k - 1) > low)) 
        {
            qsort_12<K>(keys, low, (k - 1), comparer);
        }
    }
    
    template<class T>
    bool Array::QSortArrange_13(cli::array<T>* array, int32_t lo, int32_t hi, Comparison<T>* compare) {
        if((cli::box(array->at(lo)) != nullptr)) 
        {
            if(((cli::box(array->at(hi)) ==  nullptr) || (compare->Invoke(array->at(hi), array->at(lo)) < 0))) 
            {
                swap_1<T>(array, lo, hi);
                return true;
            }
        }
        return false;
    }
    
    template<class T>
    void Array::qsort_13(cli::array<T>* array, int32_t low, int32_t high, Comparison<T>* compare) {
        const int32_t QSORT_THRESHOLD = 7;
        int32_t mid, i, k;
        T key;
        if(((low + 7) > high)) 
        {
            for(i = (low + 1); (i <= high); i++){
                for(k = i; (k > low); k--){
                    if((cli::box(array->at((k - 1))) ==  nullptr)) 
                    {
                        break;
                    }
                    if(((cli::box(array->at(k)) != nullptr) && (compare->Invoke(array->at(k), array->at((k - 1))) >= 0))) 
                    {
                        break;
                    }
                    swap_1<T>(array, (k - 1), k);
                }
            }
            return;
        }
        mid = (low + ((high - low) / 2));
        QSortArrange_13<T>(array, low, mid, compare);
        if(QSortArrange_13<T>(array, mid, high, compare)) 
        {
            QSortArrange_13<T>(array, low, mid, compare);
        }
        key = array->at(mid);
        k = (high - 1);
        i = (low + 1);
        do {
            if((cli::box(key) != nullptr)) 
            {
                while(((i < k) && (compare->Invoke(key, array->at(i)) >= 0))) i++;
                while(((k >= i) && (compare->Invoke(key, array->at(k)) < 0))) k--;
            }
             else 
            {
                while(((i < k) && (cli::box(array->at(i)) ==  nullptr))) i++;
                while(((k >= i) && (cli::box(array->at(k)) != nullptr))) k--;
            }
            if((k <= i)) 
            {
                break;
            }
            swap_1<T>(array, i, k);
            if((mid ==  i)) 
            {
                mid = k;
            }
             else 
            {
                if((mid ==  k)) 
                {
                    mid = i;
                }
            }
            i++;
            k--;
        }
        while(true);
        if((k != mid)) 
        {
            swap_1<T>(array, mid, k);
        }
        if(((k + 1) < high)) 
        {
            qsort_13<T>(array, (k + 1), high, compare);
        }
        if(((k - 1) > low)) 
        {
            qsort_13<T>(array, low, (k - 1), compare);
        }
    }
    
    template<class K>
    void Array::CheckComparerAvailable_1(cli::array<K>* keys, int32_t low, int32_t high) {
        for(int32_t i = low; (i < high); i++){
            K key = keys->at(i);
            if((cli::box(key) != nullptr)) 
            {
                if((!(cli::is<IComparable2<K>>(cli::box<IComparable2<K>*>(key))) && !(cli::is<IComparable>(cli::box<IComparable*>(key))))) 
                {
                    String *msg = Locale::GetText(_T("No IComparable<T> or IComparable interface found for type \'{0}\'."));
                    throw cli::gcnew<InvalidOperationException>(String::Format2(msg, cli::import(key)->GetType()));
                }
            }
        }
    }
    
    template<class K, class V>
    void Array::swap_2(cli::array<K>* keys, cli::array<V>* items, int32_t i, int32_t j) {
        K tmp;
        tmp = keys->at(i);
        keys->at(i) = keys->at(j);
        keys->at(j) = tmp;
        if((items != nullptr)) 
        {
            V itmp;
            itmp = items->at(i);
            items->at(i) = items->at(j);
            items->at(j) = itmp;
        }
    }
    
    template<class T>
    void Array::swap_1(cli::array<T>* array, int32_t i, int32_t j) {
        T tmp = array->at(i);
        array->at(i) = array->at(j);
        array->at(j) = tmp;
    }
    
    template<class T>
    void Array::Resize_1(cli::array<T>* array, int32_t newSize) {
        if((newSize < 0)) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>();
        }
        if((array ==  nullptr)) 
        {
            array = (new cli::array<T>(newSize));
            return;
        }
        int32_t length = array->get_Length();
        if((length ==  newSize)) 
        {
            return;
        }
        cli::array<T> *a = (new cli::array<T>(newSize));
        if((length != 0)) 
        {
            FastCopy(array, 0, a, 0, Math::Min5(newSize, length));
        }
        array = a;
    }
    
    template<class T>
    bool Array::TrueForAll_1(cli::array<T>* array, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((match ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("match"));
        }
        for(auto tmp_0 : array) {
            auto t = cli::cast<T>(tmp_0);
            if(!(match->Invoke(t))) 
            {
                return false;
            }
        }
        return true;
    }
    
    template<class T>
    void Array::ForEach_1(cli::array<T>* array, Action2<T>* action) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((action ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("action"));
        }
        for(auto tmp_1 : array) {
            auto t = cli::cast<T>(tmp_1);
            action->Invoke(t);
        }
    }
    
    template<class TInput, class TOutput>
    cli::array<TOutput>* Array::ConvertAll_2(cli::array<TInput>* array, Converter<TInput, TOutput>* converter) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((converter ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("converter"));
        }
        cli::array<TOutput> *output = (new cli::array<TOutput>(array->get_Length()));
        for(int32_t i = 0; (i < array->get_Length()); i++) {
            output->at(i) = converter->Invoke(array->at(i));
        }
        return output;
    }
    
    template<class T>
    int32_t Array::FindLastIndex_1(cli::array<T>* array, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        return FindLastIndex_13<T>(array, 0, array->get_Length(), match);
    }
    
    template<class T>
    int32_t Array::FindLastIndex_12(cli::array<T>* array, int32_t startIndex, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>();
        }
        return FindLastIndex_13<T>(array, startIndex, (array->get_Length() - startIndex), match);
    }
    
    template<class T>
    int32_t Array::FindLastIndex_13(cli::array<T>* array, int32_t startIndex, int32_t count, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((match ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("match"));
        }
        if(((startIndex > array->get_Length()) || ((startIndex + count) > array->get_Length()))) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>();
        }
        for(int32_t i = ((startIndex + count) - 1); (i >= startIndex); i--) {
            if(match->Invoke(array->at(i))) 
            {
                return i;
            }
        }
        return -1;
    }
    
    template<class T>
    int32_t Array::FindIndex_1(cli::array<T>* array, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        return FindIndex_13<T>(array, 0, array->get_Length(), match);
    }
    
    template<class T>
    int32_t Array::FindIndex_12(cli::array<T>* array, int32_t startIndex, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        return FindIndex_13<T>(array, startIndex, (array->get_Length() - startIndex), match);
    }
    
    template<class T>
    int32_t Array::FindIndex_13(cli::array<T>* array, int32_t startIndex, int32_t count, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((match ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("match"));
        }
        if(((startIndex > array->get_Length()) || ((startIndex + count) > array->get_Length()))) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>();
        }
        for(int32_t i = startIndex; (i < (startIndex + count)); i++) {
            if(match->Invoke(array->at(i))) 
            {
                return i;
            }
        }
        return -1;
    }
    
    template<class T>
    int32_t Array::BinarySearch_1(cli::array<T>* array, T value) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        return BinarySearch_14<T>(array, 0, array->get_Length(), value, nullptr);
    }
    
    template<class T>
    int32_t Array::BinarySearch_12(cli::array<T>* array, T value, Collections::Generic::IComparer2<T>* comparer) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        return BinarySearch_14<T>(array, 0, array->get_Length(), value, comparer);
    }
    
    template<class T>
    int32_t Array::BinarySearch_13(cli::array<T>* array, int32_t index, int32_t length, T value) {
        return BinarySearch_14<T>(array, index, length, value, nullptr);
    }
    
    template<class T>
    int32_t Array::BinarySearch_14(cli::array<T>* array, int32_t index, int32_t length, T value, Collections::Generic::IComparer2<T>* comparer) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((index < 0)) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("index"), Locale::GetText(_T("index is less than the lower bound of array.")));
        }
        if((length < 0)) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>(_T("length"), Locale::GetText(_T("Value has to be >= 0.")));
        }
        if((index > (array->get_Length() - length))) 
        {
            throw cli::gcnew<ArgumentException>(Locale::GetText(_T("index and length do not specify a valid range in array.")));
        }
        if((comparer ==  nullptr)) 
        {
            comparer = Collections::Generic::Comparer2<T>::get_Default();
        }
        int32_t iMin = index;
        int32_t iMax = ((index + length) - 1);
        int32_t iCmp = 0;
        try {
            while((iMin <= iMax)) {
                int32_t iMid = (iMin + ((iMax - iMin) / 2));
                iCmp = comparer->Compare_5902559f67a8cefa(value, array->at(iMid));
                if((iCmp ==  0)) 
                {
                    return iMid;
                }
                 else 
                {
                    if((iCmp < 0)) 
                    {
                        iMax = (iMid - 1);
                    }
                     else 
                    {
                        iMin = (iMid + 1);
                    }
                }
            }
        }
        catch(Exception* e) {
            throw cli::gcnew<InvalidOperationException>(Locale::GetText(_T("Comparer threw an exception.")), e);
        }
        return ~(iMin);
    }
    
    template<class T>
    int32_t Array::IndexOf_1(cli::array<T>* array, T value) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        return IndexOf_13<T>(array, value, 0, array->get_Length());
    }
    
    template<class T>
    int32_t Array::IndexOf_12(cli::array<T>* array, T value, int32_t startIndex) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        return IndexOf_13<T>(array, value, startIndex, (array->get_Length() - startIndex));
    }
    
    template<class T>
    int32_t Array::IndexOf_13(cli::array<T>* array, T value, int32_t startIndex, int32_t count) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((((count < 0) || (startIndex < cli::import(array)->GetLowerBound(0))) || ((startIndex - 1) > (cli::import(array)->GetUpperBound(0) - count)))) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>();
        }
        int32_t max = (startIndex + count);
        Collections::Generic::EqualityComparer<T> *equalityComparer = Collections::Generic::EqualityComparer<T>::get_Default();
        for(int32_t i = startIndex; (i < max); i++){
            if(equalityComparer->Equals_e786aaeef5b10ff2(array->at(i), value)) 
            {
                return i;
            }
        }
        return -1;
    }
    
    template<class T>
    int32_t Array::LastIndexOf_1(cli::array<T>* array, T value) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((array->get_Length() ==  0)) 
        {
            return -1;
        }
        return LastIndexOf_12<T>(array, value, (array->get_Length() - 1));
    }
    
    template<class T>
    int32_t Array::LastIndexOf_12(cli::array<T>* array, T value, int32_t startIndex) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        return LastIndexOf_13<T>(array, value, startIndex, (startIndex + 1));
    }
    
    template<class T>
    int32_t Array::LastIndexOf_13(cli::array<T>* array, T value, int32_t startIndex, int32_t count) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if(((((count < 0) || (startIndex < cli::import(array)->GetLowerBound(0))) || (startIndex > cli::import(array)->GetUpperBound(0))) || (((startIndex - count) + 1) < cli::import(array)->GetLowerBound(0)))) 
        {
            throw cli::gcnew<ArgumentOutOfRangeException>();
        }
        Collections::Generic::EqualityComparer<T> *equalityComparer = Collections::Generic::EqualityComparer<T>::get_Default();
        for(int32_t i = startIndex; (i >= ((startIndex - count) + 1)); i--){
            if(equalityComparer->Equals_e786aaeef5b10ff2(array->at(i), value)) 
            {
                return i;
            }
        }
        return -1;
    }
    
    template<class T>
    cli::array<T>* Array::FindAll_1(cli::array<T>* array, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((match ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("match"));
        }
        int32_t pos = 0;
        cli::array<T> *d = (new cli::array<T>(array->get_Length()));
        for(auto tmp_2 : array) {
            auto t = cli::cast<T>(tmp_2);
            if(match->Invoke(t)) 
            {
                d->at(pos++) = t;
            }
        }
        Resize_1<T>(d, pos);
        return d;
    }
    
    template<class T>
    bool Array::Exists_1(cli::array<T>* array, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((match ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("match"));
        }
        for(auto tmp_3 : array) {
            auto t = cli::cast<T>(tmp_3);
            if(match->Invoke(t)) 
            {
                return true;
            }
        }
        return false;
    }
    
    template<class T>
    Collections::ObjectModel::ReadOnlyCollection<T>* Array::AsReadOnly_1(cli::array<T>* array) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        return cli::gcnew<Collections::ObjectModel::ReadOnlyCollection<T>>(array);
    }
    
    template<class T>
    T Array::Find_1(cli::array<T>* array, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((match ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("match"));
        }
        for(auto tmp_4 : array) {
            auto t = cli::cast<T>(tmp_4);
            if(match->Invoke(t)) 
            {
                return t;
            }
        }
        return T();
    }
    
    template<class T>
    T Array::FindLast_1(cli::array<T>* array, Predicate<T>* match) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("array"));
        }
        if((match ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("match"));
        }
        for(int32_t i = (array->get_Length() - 1); (i >= 0); i--) {
            if(match->Invoke(array->at(i))) 
            {
                return array->at(i);
            }
        }
        return T();
    }
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
    template<class TEnum>
    bool Enum::Parse_1(Type* enumType, String* value, bool ignoreCase, TEnum result) {
        result = TEnum();
        MonoEnumInfo info;
        MonoEnumInfo::GetInfo(enumType, info);
        int32_t loc = FindName(info->name_hash, info->names, value, ignoreCase);
        if((loc >= 0)) 
        {
            result = cli::unbox<TEnum>(info->values->GetValue2(loc));
            return true;
        }
        TypeCode typeCode = cli::cast<Enum*>(info->values->GetValue2(0))->GetTypeCode();
        if((value->IndexOf4(u',') != -1)) 
        {
            cli::array<String*> *names = value->Split(split_char);
            uint64_t retVal = 0UL;
            for(int32_t i = 0; (i < names->get_Length()); ++i){
                loc = FindName(info->name_hash, info->names, names->at(i)->Trim(), ignoreCase);
                if((loc < 0)) 
                {
                    return false;
                }
                (retVal = retVal | GetValue(info->values->GetValue2(loc), typeCode));
            }
            result = cli::unbox<TEnum>(ToObject9(enumType, retVal));
            return true;
        }
        switch(typeCode) {
            case TypeCode::SByte2: case_27: {
                signed char sb;
                if(!(SByte::TryParse(value, sb))) 
                {
                    return false;
                }
                result = cli::unbox<TEnum>(ToObject6(enumType, sb));
                break;
            }
            case TypeCode::Byte2: case_28: {
                unsigned char b;
                if(!(Byte::TryParse(value, b))) 
                {
                    return false;
                }
                result = cli::unbox<TEnum>(ToObject(enumType, b));
                break;
            }
            case TypeCode::Int162: case_29: {
                int16_t i16;
                if(!(Int16::TryParse(value, i16))) 
                {
                    return false;
                }
                result = cli::unbox<TEnum>(ToObject2(enumType, i16));
                break;
            }
            case TypeCode::UInt162: case_30: {
                uint16_t u16;
                if(!(UInt16::TryParse(value, u16))) 
                {
                    return false;
                }
                result = cli::unbox<TEnum>(ToObject7(enumType, u16));
                break;
            }
            case TypeCode::Int322: case_31: {
                int32_t i32;
                if(!(Int32::TryParse(value, i32))) 
                {
                    return false;
                }
                result = cli::unbox<TEnum>(ToObject3(enumType, i32));
                break;
            }
            case TypeCode::UInt322: case_32: {
                uint32_t u32;
                if(!(UInt32::TryParse(value, u32))) 
                {
                    return false;
                }
                result = cli::unbox<TEnum>(ToObject8(enumType, u32));
                break;
            }
            case TypeCode::Int642: case_33: {
                int64_t i64;
                if(!(Int64::TryParse(value, i64))) 
                {
                    return false;
                }
                result = cli::unbox<TEnum>(ToObject4(enumType, i64));
                break;
            }
            case TypeCode::UInt642: case_34: {
                uint64_t u64;
                if(!(UInt64::TryParse(value, u64))) 
                {
                    return false;
                }
                result = cli::unbox<TEnum>(ToObject9(enumType, u64));
                break;
            }
            default: case_35: {
                break;
            }
        }
        return true;
    }
    
    template<class TEnum>
    bool Enum::TryParse_1(String* value, TEnum result) {
        return TryParse_12<TEnum>(value, false, result);
    }
    
    template<class TEnum>
    bool Enum::TryParse_12(String* value, bool ignoreCase, TEnum result) {
        Type *tenum_type = cli::typeof<Type>::info;
        if(!(tenum_type->get_IsEnum_bc85ea7b0a749db())) 
        {
            throw cli::gcnew<ArgumentException>(_T("TEnum is not an Enum type."), _T("enumType"));
        }
        result = TEnum();
        if(((value ==  nullptr) || (value->Trim()->get_Length() ==  0))) 
        {
            return false;
        }
        return Parse_1<TEnum>(tenum_type, value, ignoreCase, result);
    }
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
    template<class T>
    void Lazy<T>::constructor() {
    }
    
    template<class T>
    void Lazy<T>::constructor(Func<T>* valueFactory) {
    }
    
    template<class T>
    void Lazy<T>::constructor(bool isThreadSafe) {
    }
    
    template<class T>
    void Lazy<T>::constructor(Func<T>* valueFactory, bool isThreadSafe) {
    }
    
    template<class T>
    void Lazy<T>::constructor(Threading::LazyThreadSafetyMode mode) {
    }
    
    template<class T>
    void Lazy<T>::constructor(Func<T>* valueFactory, Threading::LazyThreadSafetyMode mode) {
        if((valueFactory ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("valueFactory"));
        }
        this->factory = valueFactory;
        if(((int32_t)(mode) != 0)) 
        {
            this->monitor = cli::gcnew<Object>();
        }
        this->mode = mode;
    }
    
    template<class T>
    T Lazy<T>::InitValue() {
        Func<T> *init_factory;
        T v;
        switch(this->mode) {
            case Threading::LazyThreadSafetyMode::None: case_36: {
                init_factory = this->factory;
                if((init_factory ==  nullptr)) 
                {
                    throw this->exception = cli::gcnew<InvalidOperationException>(_T("The initialization function tries to access Value on this instance"));
                }
                try {
                    this->factory = nullptr;
                    v = init_factory->Invoke();
                    this->value = v;
                    Threading::Thread::MemoryBarrier();
                    this->inited = true;
                }
                catch(Exception* ex) {
                    this->exception = ex;
                    throw ;
                }
                break;
            }
            case Threading::LazyThreadSafetyMode::PublicationOnly: case_37: {
                init_factory = this->factory;
                if((init_factory != nullptr)) 
                {
                    v = init_factory->Invoke();
                }
                 else 
                {
                    v = T();
                }
                {
                    cli::lock_guard{this->monitor};
                    if(this->inited) 
                    {
                        return this->value;
                    }
                    this->value = v;
                    Threading::Thread::MemoryBarrier();
                    this->inited = true;
                    this->factory = nullptr;
                }
                break;
            }
            case Threading::LazyThreadSafetyMode::ExecutionAndPublication: case_38: {
                {
                    cli::lock_guard{this->monitor};
                    if(this->inited) 
                    {
                        return this->value;
                    }
                    if((this->factory ==  nullptr)) 
                    {
                        throw this->exception = cli::gcnew<InvalidOperationException>(_T("The initialization function tries to access Value on this instance"));
                    }
                    init_factory = this->factory;
                    try {
                        this->factory = nullptr;
                        v = init_factory->Invoke();
                        this->value = v;
                        Threading::Thread::MemoryBarrier();
                        this->inited = true;
                    }
                    catch(Exception* ex) {
                        this->exception = ex;
                        throw ;
                    }
                }
                break;
            }
            default: case_39: {
                throw cli::gcnew<InvalidOperationException>(cli::concat(_T("Invalid LazyThreadSafetyMode "), cli::box(this->mode)));
            }
        }
        return this->value;
    }
    
    template<class T>
    String* Lazy<T>::ToString_1636a0751cb9ac11() {
        if(this->inited) 
        {
            return cli::import(this->value)->ToString_1636a0751cb9ac11();
        }
         else 
        {
            return _T("Value is not created");
        }
    }
    
    template<class T>
    T Lazy<T>::_Lazy_m__1() {
        return Activator::template CreateInstance_1<T>();
    }
    
    template<class T>
    T Lazy<T>::_Lazy_m__2() {
        return Activator::template CreateInstance_1<T>();
    }
    
    template<class T>
    T Lazy<T>::get_Value() {
        if(this->inited) 
        {
            return this->value;
        }
        if((this->exception != nullptr)) 
        {
            throw this->exception;
        }
        return InitValue();
    }
    
    template<class T>
    bool Lazy<T>::get_IsValueCreated() {
        return this->inited;
    }
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
    template<class T>
    int32_t Nullable::Compare_1(Nullable2<T> n1, Nullable2<T> n2) {
        if(n1->has_value) 
        {
            if(!(n2->has_value)) 
            {
                return 1;
            }
            return Collections::Generic::Comparer2<T>::get_Default()->Compare_1b044eff3abea0d9(n1->value, n2->value);
        }
        return n2->has_value ? -1 : 0;
    }
    
    template<class T>
    bool Nullable::Equals_1(Nullable2<T> n1, Nullable2<T> n2) {
        if((n1->has_value != n2->has_value)) 
        {
            return false;
        }
        if(!(n1->has_value)) 
        {
            return true;
        }
        return Collections::Generic::EqualityComparer<T>::get_Default()->Equals_e786aaeef5b10ff2(n1->value, n2->value);
    }
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
    template<class T>
    String* String::Concat_1(Collections::Generic::IEnumerable2<T>* values) {
        if((values ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("values"));
        }
        Collections::Generic::List<String*> *stringList = cli::gcnew<Collections::Generic::List<String*>>();
        int32_t len = 0;
        for(auto tmp_5 : values) {
            auto v = cli::cast<T>(tmp_5);
            {
                String *sr = cli::import(v)->ToString_1636a0751cb9ac11();
                (len = len + sr->get_Length());
                stringList->Add(sr);
            }
        }
        return ConcatInternal(stringList->ToArray(), len);
    }
    
    template<class T>
    String* String::Join_1(String* separator, Collections::Generic::IEnumerable2<T>* values) {
        if((separator ==  nullptr)) 
        {
            return Concat_1<T>(values);
        }
        if((values ==  nullptr)) 
        {
            throw cli::gcnew<ArgumentNullException>(_T("values"));
        }
        Collections::Generic::List<String*> *stringList = cli::gcnew<Collections::Generic::List<String*>>();
        for(auto tmp_6 : values) {
            auto v = cli::cast<T>(tmp_6);
            stringList->Add(cli::import(v)->ToString_1636a0751cb9ac11());
        }
        return JoinUnchecked(separator, stringList->ToArray(), 0, stringList->get_Count());
    }
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
    Tuple2<T1, T2, T3, T4, T5, T6, T7, Tuple3<T8>*>* Tuple::Create_8(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, T8 item8) {
        return cli::gcnew<Tuple2<T1, T2, T3, T4, T5, T6, T7, Tuple3<T8>*>>(item1, item2, item3, item4, item5, item6, item7, cli::gcnew<Tuple3<T8>>(item8));
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    Tuple9<T1, T2, T3, T4, T5, T6, T7>* Tuple::Create_7(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7) {
        return cli::gcnew<Tuple9<T1, T2, T3, T4, T5, T6, T7>>(item1, item2, item3, item4, item5, item6, item7);
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    Tuple8<T1, T2, T3, T4, T5, T6>* Tuple::Create_6(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6) {
        return cli::gcnew<Tuple8<T1, T2, T3, T4, T5, T6>>(item1, item2, item3, item4, item5, item6);
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    Tuple7<T1, T2, T3, T4, T5>* Tuple::Create_5(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5) {
        return cli::gcnew<Tuple7<T1, T2, T3, T4, T5>>(item1, item2, item3, item4, item5);
    }
    
    template<class T1, class T2, class T3, class T4>
    Tuple6<T1, T2, T3, T4>* Tuple::Create_4(T1 item1, T2 item2, T3 item3, T4 item4) {
        return cli::gcnew<Tuple6<T1, T2, T3, T4>>(item1, item2, item3, item4);
    }
    
    template<class T1, class T2, class T3>
    Tuple5<T1, T2, T3>* Tuple::Create_3(T1 item1, T2 item2, T3 item3) {
        return cli::gcnew<Tuple5<T1, T2, T3>>(item1, item2, item3);
    }
    
    template<class T1, class T2>
    Tuple4<T1, T2>* Tuple::Create_2(T1 item1, T2 item2) {
        return cli::gcnew<Tuple4<T1, T2>>(item1, item2);
    }
    
    template<class T1>
    Tuple3<T1>* Tuple::Create_1(T1 item1) {
        return cli::gcnew<Tuple3<T1>>(item1);
    }
    
}
 namespace System {
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    void Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::constructor(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, TRest rest) {
        this->item1 = item1;
        this->item2 = item2;
        this->item3 = item3;
        this->item4 = item4;
        this->item5 = item5;
        this->item6 = item6;
        this->item7 = item7;
        this->rest = rest;
        bool ok = true;
        if(!(cli::typeof<Type>::info->get_IsGenericType_4db8ddd5b97f3c14())) 
        {
            ok = false;
        }
        if(ok) 
        {
            Type *t = cli::typeof<Type>::info->GetGenericTypeDefinition_15f8fc7813e8e8bf();
            if(!((((((((Type::op_Equality2(t, cli::typeof<Type>::info) || Type::op_Equality2(t, cli::typeof<Type>::info)) || Type::op_Equality2(t, cli::typeof<Type>::info)) || Type::op_Equality2(t, cli::typeof<Type>::info)) || Type::op_Equality2(t, cli::typeof<Type>::info)) || Type::op_Equality2(t, cli::typeof<Type>::info)) || Type::op_Equality2(t, cli::typeof<Type>::info)) || Type::op_Equality2(t, cli::typeof<Type>::info)))) 
            {
                ok = false;
            }
        }
        if(!(ok)) 
        {
            throw cli::gcnew<ArgumentException>(_T("rest"), _T("The last element of an eight element tuple must be a Tuple."));
        }
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    int32_t Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::CompareTo(Object* obj) {
        return cli::cast<Collections::IStructuralComparable*>(this)->CompareTo_6a6cfba1da2bec3b(obj, Collections::Generic::Comparer2<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    int32_t Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::CompareTo2(Object* other, Collections::IComparer* comparer) {
        Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest> *t = cli::as<Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>*>(other);
        if((t ==  nullptr)) 
        {
            if((other ==  nullptr)) 
            {
                return 1;
            }
            throw cli::gcnew<ArgumentException>(_T("other"));
        }
        int32_t res = comparer->Compare_451fd276747b629d(cli::box(this->item1), cli::box(t->item1));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item2), cli::box(t->item2));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item3), cli::box(t->item3));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item4), cli::box(t->item4));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item5), cli::box(t->item5));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item6), cli::box(t->item6));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item7), cli::box(t->item7));
        if((res != 0)) 
        {
            return res;
        }
        return comparer->Compare_451fd276747b629d(cli::box(this->rest), cli::box(t->rest));
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    bool Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::Equals_ed975d2f4a7d193e(Object* obj) {
        return cli::cast<Collections::IStructuralEquatable*>(this)->Equals_2f89738462b0fb33(obj, Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    bool Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::Equals4(Object* other, Collections::IEqualityComparer* comparer) {
        Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest> *t = cli::as<Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>*>(other);
        if((t ==  nullptr)) 
        {
            return false;
        }
        return (((((((comparer->Equals_ad190887ea91ded(cli::box(this->item1), cli::box(t->item1)) && comparer->Equals_ad190887ea91ded(cli::box(this->item2), cli::box(t->item2))) && comparer->Equals_ad190887ea91ded(cli::box(this->item3), cli::box(t->item3))) && comparer->Equals_ad190887ea91ded(cli::box(this->item4), cli::box(t->item4))) && comparer->Equals_ad190887ea91ded(cli::box(this->item5), cli::box(t->item5))) && comparer->Equals_ad190887ea91ded(cli::box(this->item6), cli::box(t->item6))) && comparer->Equals_ad190887ea91ded(cli::box(this->item7), cli::box(t->item7))) && comparer->Equals_ad190887ea91ded(cli::box(this->rest), cli::box(t->rest)));
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    int32_t Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::GetHashCode_6648aef0f235ee6c() {
        return cli::cast<Collections::IStructuralEquatable*>(this)->GetHashCode_94e84ad7bccbc132(Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    int32_t Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::GetHashCode3(Collections::IEqualityComparer* comparer) {
        int32_t h = comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item1));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item2)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item3)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item4)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item5)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item6)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item7)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->rest)));
        return h;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    String* Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::ToString_1636a0751cb9ac11() {
        return String::Format5(_T("({0}, {1}, {2}, {3}, {4}, {5}, {6}, {7})"), (new cli::array<Object*>({cli::box(this->item1), cli::box(this->item2), cli::box(this->item3), cli::box(this->item4), cli::box(this->item5), cli::box(this->item6), cli::box(this->item7), cli::box(this->rest)})));
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    T1 Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::get_Item1() {
        return this->item1;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    T2 Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::get_Item2() {
        return this->item2;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    T3 Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::get_Item3() {
        return this->item3;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    T4 Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::get_Item4() {
        return this->item4;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    T5 Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::get_Item5() {
        return this->item5;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    T6 Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::get_Item6() {
        return this->item6;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    T7 Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::get_Item7() {
        return this->item7;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
    TRest Tuple2<T1, T2, T3, T4, T5, T6, T7, TRest>::get_Rest() {
        return this->rest;
    }
    
}
 namespace System {
    
    template<class T1>
    void Tuple3<T1>::constructor(T1 item1) {
        this->item1 = item1;
    }
    
    template<class T1>
    int32_t Tuple3<T1>::CompareTo(Object* obj) {
        return cli::cast<Collections::IStructuralComparable*>(this)->CompareTo_6a6cfba1da2bec3b(obj, Collections::Generic::Comparer2<Object*>::get_Default());
    }
    
    template<class T1>
    int32_t Tuple3<T1>::CompareTo2(Object* other, Collections::IComparer* comparer) {
        Tuple3<T1> *t = cli::as<Tuple3<T1>*>(other);
        if((t ==  nullptr)) 
        {
            if((other ==  nullptr)) 
            {
                return 1;
            }
            throw cli::gcnew<ArgumentException>(_T("other"));
        }
        return comparer->Compare_451fd276747b629d(cli::box(this->item1), cli::box(t->item1));
    }
    
    template<class T1>
    bool Tuple3<T1>::Equals_ed975d2f4a7d193e(Object* obj) {
        return cli::cast<Collections::IStructuralEquatable*>(this)->Equals_2f89738462b0fb33(obj, Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1>
    bool Tuple3<T1>::Equals4(Object* other, Collections::IEqualityComparer* comparer) {
        Tuple3<T1> *t = cli::as<Tuple3<T1>*>(other);
        if((t ==  nullptr)) 
        {
            return false;
        }
        return comparer->Equals_ad190887ea91ded(cli::box(this->item1), cli::box(t->item1));
    }
    
    template<class T1>
    int32_t Tuple3<T1>::GetHashCode_6648aef0f235ee6c() {
        return cli::cast<Collections::IStructuralEquatable*>(this)->GetHashCode_94e84ad7bccbc132(Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1>
    int32_t Tuple3<T1>::GetHashCode3(Collections::IEqualityComparer* comparer) {
        return comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item1));
    }
    
    template<class T1>
    String* Tuple3<T1>::ToString_1636a0751cb9ac11() {
        return String::Format2(_T("({0})"), cli::box(this->item1));
    }
    
    template<class T1>
    T1 Tuple3<T1>::get_Item1() {
        return this->item1;
    }
    
}
 namespace System {
    
    template<class T1, class T2>
    void Tuple4<T1, T2>::constructor(T1 item1, T2 item2) {
        this->item1 = item1;
        this->item2 = item2;
    }
    
    template<class T1, class T2>
    int32_t Tuple4<T1, T2>::CompareTo(Object* obj) {
        return cli::cast<Collections::IStructuralComparable*>(this)->CompareTo_6a6cfba1da2bec3b(obj, Collections::Generic::Comparer2<Object*>::get_Default());
    }
    
    template<class T1, class T2>
    int32_t Tuple4<T1, T2>::CompareTo2(Object* other, Collections::IComparer* comparer) {
        Tuple4<T1, T2> *t = cli::as<Tuple4<T1, T2>*>(other);
        if((t ==  nullptr)) 
        {
            if((other ==  nullptr)) 
            {
                return 1;
            }
            throw cli::gcnew<ArgumentException>(_T("other"));
        }
        int32_t res = comparer->Compare_451fd276747b629d(cli::box(this->item1), cli::box(t->item1));
        if((res != 0)) 
        {
            return res;
        }
        return comparer->Compare_451fd276747b629d(cli::box(this->item2), cli::box(t->item2));
    }
    
    template<class T1, class T2>
    bool Tuple4<T1, T2>::Equals_ed975d2f4a7d193e(Object* obj) {
        return cli::cast<Collections::IStructuralEquatable*>(this)->Equals_2f89738462b0fb33(obj, Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2>
    bool Tuple4<T1, T2>::Equals4(Object* other, Collections::IEqualityComparer* comparer) {
        Tuple4<T1, T2> *t = cli::as<Tuple4<T1, T2>*>(other);
        if((t ==  nullptr)) 
        {
            return false;
        }
        return (comparer->Equals_ad190887ea91ded(cli::box(this->item1), cli::box(t->item1)) && comparer->Equals_ad190887ea91ded(cli::box(this->item2), cli::box(t->item2)));
    }
    
    template<class T1, class T2>
    int32_t Tuple4<T1, T2>::GetHashCode_6648aef0f235ee6c() {
        return cli::cast<Collections::IStructuralEquatable*>(this)->GetHashCode_94e84ad7bccbc132(Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2>
    int32_t Tuple4<T1, T2>::GetHashCode3(Collections::IEqualityComparer* comparer) {
        int32_t h = comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item1));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item2)));
        return h;
    }
    
    template<class T1, class T2>
    String* Tuple4<T1, T2>::ToString_1636a0751cb9ac11() {
        return String::Format3(_T("({0}, {1})"), cli::box(this->item1), cli::box(this->item2));
    }
    
    template<class T1, class T2>
    T1 Tuple4<T1, T2>::get_Item1() {
        return this->item1;
    }
    
    template<class T1, class T2>
    T2 Tuple4<T1, T2>::get_Item2() {
        return this->item2;
    }
    
}
 namespace System {
    
    template<class T1, class T2, class T3>
    void Tuple5<T1, T2, T3>::constructor(T1 item1, T2 item2, T3 item3) {
        this->item1 = item1;
        this->item2 = item2;
        this->item3 = item3;
    }
    
    template<class T1, class T2, class T3>
    int32_t Tuple5<T1, T2, T3>::CompareTo(Object* obj) {
        return cli::cast<Collections::IStructuralComparable*>(this)->CompareTo_6a6cfba1da2bec3b(obj, Collections::Generic::Comparer2<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3>
    int32_t Tuple5<T1, T2, T3>::CompareTo2(Object* other, Collections::IComparer* comparer) {
        Tuple5<T1, T2, T3> *t = cli::as<Tuple5<T1, T2, T3>*>(other);
        if((t ==  nullptr)) 
        {
            if((other ==  nullptr)) 
            {
                return 1;
            }
            throw cli::gcnew<ArgumentException>(_T("other"));
        }
        int32_t res = comparer->Compare_451fd276747b629d(cli::box(this->item1), cli::box(t->item1));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item2), cli::box(t->item2));
        if((res != 0)) 
        {
            return res;
        }
        return comparer->Compare_451fd276747b629d(cli::box(this->item3), cli::box(t->item3));
    }
    
    template<class T1, class T2, class T3>
    bool Tuple5<T1, T2, T3>::Equals_ed975d2f4a7d193e(Object* obj) {
        return cli::cast<Collections::IStructuralEquatable*>(this)->Equals_2f89738462b0fb33(obj, Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3>
    bool Tuple5<T1, T2, T3>::Equals4(Object* other, Collections::IEqualityComparer* comparer) {
        Tuple5<T1, T2, T3> *t = cli::as<Tuple5<T1, T2, T3>*>(other);
        if((t ==  nullptr)) 
        {
            return false;
        }
        return ((comparer->Equals_ad190887ea91ded(cli::box(this->item1), cli::box(t->item1)) && comparer->Equals_ad190887ea91ded(cli::box(this->item2), cli::box(t->item2))) && comparer->Equals_ad190887ea91ded(cli::box(this->item3), cli::box(t->item3)));
    }
    
    template<class T1, class T2, class T3>
    int32_t Tuple5<T1, T2, T3>::GetHashCode_6648aef0f235ee6c() {
        return cli::cast<Collections::IStructuralEquatable*>(this)->GetHashCode_94e84ad7bccbc132(Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3>
    int32_t Tuple5<T1, T2, T3>::GetHashCode3(Collections::IEqualityComparer* comparer) {
        int32_t h = comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item1));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item2)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item3)));
        return h;
    }
    
    template<class T1, class T2, class T3>
    String* Tuple5<T1, T2, T3>::ToString_1636a0751cb9ac11() {
        return String::Format4(_T("({0}, {1}, {2})"), cli::box(this->item1), cli::box(this->item2), cli::box(this->item3));
    }
    
    template<class T1, class T2, class T3>
    T1 Tuple5<T1, T2, T3>::get_Item1() {
        return this->item1;
    }
    
    template<class T1, class T2, class T3>
    T2 Tuple5<T1, T2, T3>::get_Item2() {
        return this->item2;
    }
    
    template<class T1, class T2, class T3>
    T3 Tuple5<T1, T2, T3>::get_Item3() {
        return this->item3;
    }
    
}
 namespace System {
    
    template<class T1, class T2, class T3, class T4>
    void Tuple6<T1, T2, T3, T4>::constructor(T1 item1, T2 item2, T3 item3, T4 item4) {
        this->item1 = item1;
        this->item2 = item2;
        this->item3 = item3;
        this->item4 = item4;
    }
    
    template<class T1, class T2, class T3, class T4>
    int32_t Tuple6<T1, T2, T3, T4>::CompareTo(Object* obj) {
        return cli::cast<Collections::IStructuralComparable*>(this)->CompareTo_6a6cfba1da2bec3b(obj, Collections::Generic::Comparer2<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4>
    int32_t Tuple6<T1, T2, T3, T4>::CompareTo2(Object* other, Collections::IComparer* comparer) {
        Tuple6<T1, T2, T3, T4> *t = cli::as<Tuple6<T1, T2, T3, T4>*>(other);
        if((t ==  nullptr)) 
        {
            if((other ==  nullptr)) 
            {
                return 1;
            }
            throw cli::gcnew<ArgumentException>(_T("other"));
        }
        int32_t res = comparer->Compare_451fd276747b629d(cli::box(this->item1), cli::box(t->item1));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item2), cli::box(t->item2));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item3), cli::box(t->item3));
        if((res != 0)) 
        {
            return res;
        }
        return comparer->Compare_451fd276747b629d(cli::box(this->item4), cli::box(t->item4));
    }
    
    template<class T1, class T2, class T3, class T4>
    bool Tuple6<T1, T2, T3, T4>::Equals_ed975d2f4a7d193e(Object* obj) {
        return cli::cast<Collections::IStructuralEquatable*>(this)->Equals_2f89738462b0fb33(obj, Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4>
    bool Tuple6<T1, T2, T3, T4>::Equals4(Object* other, Collections::IEqualityComparer* comparer) {
        Tuple6<T1, T2, T3, T4> *t = cli::as<Tuple6<T1, T2, T3, T4>*>(other);
        if((t ==  nullptr)) 
        {
            return false;
        }
        return (((comparer->Equals_ad190887ea91ded(cli::box(this->item1), cli::box(t->item1)) && comparer->Equals_ad190887ea91ded(cli::box(this->item2), cli::box(t->item2))) && comparer->Equals_ad190887ea91ded(cli::box(this->item3), cli::box(t->item3))) && comparer->Equals_ad190887ea91ded(cli::box(this->item4), cli::box(t->item4)));
    }
    
    template<class T1, class T2, class T3, class T4>
    int32_t Tuple6<T1, T2, T3, T4>::GetHashCode_6648aef0f235ee6c() {
        return cli::cast<Collections::IStructuralEquatable*>(this)->GetHashCode_94e84ad7bccbc132(Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4>
    int32_t Tuple6<T1, T2, T3, T4>::GetHashCode3(Collections::IEqualityComparer* comparer) {
        int32_t h = comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item1));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item2)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item3)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item4)));
        return h;
    }
    
    template<class T1, class T2, class T3, class T4>
    String* Tuple6<T1, T2, T3, T4>::ToString_1636a0751cb9ac11() {
        return String::Format5(_T("({0}, {1}, {2}, {3})"), (new cli::array<Object*>({cli::box(this->item1), cli::box(this->item2), cli::box(this->item3), cli::box(this->item4)})));
    }
    
    template<class T1, class T2, class T3, class T4>
    T1 Tuple6<T1, T2, T3, T4>::get_Item1() {
        return this->item1;
    }
    
    template<class T1, class T2, class T3, class T4>
    T2 Tuple6<T1, T2, T3, T4>::get_Item2() {
        return this->item2;
    }
    
    template<class T1, class T2, class T3, class T4>
    T3 Tuple6<T1, T2, T3, T4>::get_Item3() {
        return this->item3;
    }
    
    template<class T1, class T2, class T3, class T4>
    T4 Tuple6<T1, T2, T3, T4>::get_Item4() {
        return this->item4;
    }
    
}
 namespace System {
    
    template<class T1, class T2, class T3, class T4, class T5>
    void Tuple7<T1, T2, T3, T4, T5>::constructor(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5) {
        this->item1 = item1;
        this->item2 = item2;
        this->item3 = item3;
        this->item4 = item4;
        this->item5 = item5;
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    int32_t Tuple7<T1, T2, T3, T4, T5>::CompareTo(Object* obj) {
        return cli::cast<Collections::IStructuralComparable*>(this)->CompareTo_6a6cfba1da2bec3b(obj, Collections::Generic::Comparer2<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    int32_t Tuple7<T1, T2, T3, T4, T5>::CompareTo2(Object* other, Collections::IComparer* comparer) {
        Tuple7<T1, T2, T3, T4, T5> *t = cli::as<Tuple7<T1, T2, T3, T4, T5>*>(other);
        if((t ==  nullptr)) 
        {
            if((other ==  nullptr)) 
            {
                return 1;
            }
            throw cli::gcnew<ArgumentException>(_T("other"));
        }
        int32_t res = comparer->Compare_451fd276747b629d(cli::box(this->item1), cli::box(t->item1));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item2), cli::box(t->item2));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item3), cli::box(t->item3));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item4), cli::box(t->item4));
        if((res != 0)) 
        {
            return res;
        }
        return comparer->Compare_451fd276747b629d(cli::box(this->item5), cli::box(t->item5));
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    bool Tuple7<T1, T2, T3, T4, T5>::Equals_ed975d2f4a7d193e(Object* obj) {
        return cli::cast<Collections::IStructuralEquatable*>(this)->Equals_2f89738462b0fb33(obj, Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    bool Tuple7<T1, T2, T3, T4, T5>::Equals4(Object* other, Collections::IEqualityComparer* comparer) {
        Tuple7<T1, T2, T3, T4, T5> *t = cli::as<Tuple7<T1, T2, T3, T4, T5>*>(other);
        if((t ==  nullptr)) 
        {
            return false;
        }
        return ((((comparer->Equals_ad190887ea91ded(cli::box(this->item1), cli::box(t->item1)) && comparer->Equals_ad190887ea91ded(cli::box(this->item2), cli::box(t->item2))) && comparer->Equals_ad190887ea91ded(cli::box(this->item3), cli::box(t->item3))) && comparer->Equals_ad190887ea91ded(cli::box(this->item4), cli::box(t->item4))) && comparer->Equals_ad190887ea91ded(cli::box(this->item5), cli::box(t->item5)));
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    int32_t Tuple7<T1, T2, T3, T4, T5>::GetHashCode_6648aef0f235ee6c() {
        return cli::cast<Collections::IStructuralEquatable*>(this)->GetHashCode_94e84ad7bccbc132(Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    int32_t Tuple7<T1, T2, T3, T4, T5>::GetHashCode3(Collections::IEqualityComparer* comparer) {
        int32_t h = comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item1));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item2)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item3)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item4)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item5)));
        return h;
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    String* Tuple7<T1, T2, T3, T4, T5>::ToString_1636a0751cb9ac11() {
        return String::Format5(_T("({0}, {1}, {2}, {3}, {4})"), (new cli::array<Object*>({cli::box(this->item1), cli::box(this->item2), cli::box(this->item3), cli::box(this->item4), cli::box(this->item5)})));
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    T1 Tuple7<T1, T2, T3, T4, T5>::get_Item1() {
        return this->item1;
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    T2 Tuple7<T1, T2, T3, T4, T5>::get_Item2() {
        return this->item2;
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    T3 Tuple7<T1, T2, T3, T4, T5>::get_Item3() {
        return this->item3;
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    T4 Tuple7<T1, T2, T3, T4, T5>::get_Item4() {
        return this->item4;
    }
    
    template<class T1, class T2, class T3, class T4, class T5>
    T5 Tuple7<T1, T2, T3, T4, T5>::get_Item5() {
        return this->item5;
    }
    
}
 namespace System {
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    void Tuple8<T1, T2, T3, T4, T5, T6>::constructor(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6) {
        this->item1 = item1;
        this->item2 = item2;
        this->item3 = item3;
        this->item4 = item4;
        this->item5 = item5;
        this->item6 = item6;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    int32_t Tuple8<T1, T2, T3, T4, T5, T6>::CompareTo(Object* obj) {
        return cli::cast<Collections::IStructuralComparable*>(this)->CompareTo_6a6cfba1da2bec3b(obj, Collections::Generic::Comparer2<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    int32_t Tuple8<T1, T2, T3, T4, T5, T6>::CompareTo2(Object* other, Collections::IComparer* comparer) {
        Tuple8<T1, T2, T3, T4, T5, T6> *t = cli::as<Tuple8<T1, T2, T3, T4, T5, T6>*>(other);
        if((t ==  nullptr)) 
        {
            if((other ==  nullptr)) 
            {
                return 1;
            }
            throw cli::gcnew<ArgumentException>(_T("other"));
        }
        int32_t res = comparer->Compare_451fd276747b629d(cli::box(this->item1), cli::box(t->item1));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item2), cli::box(t->item2));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item3), cli::box(t->item3));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item4), cli::box(t->item4));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item5), cli::box(t->item5));
        if((res != 0)) 
        {
            return res;
        }
        return comparer->Compare_451fd276747b629d(cli::box(this->item6), cli::box(t->item6));
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    bool Tuple8<T1, T2, T3, T4, T5, T6>::Equals_ed975d2f4a7d193e(Object* obj) {
        return cli::cast<Collections::IStructuralEquatable*>(this)->Equals_2f89738462b0fb33(obj, Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    bool Tuple8<T1, T2, T3, T4, T5, T6>::Equals4(Object* other, Collections::IEqualityComparer* comparer) {
        Tuple8<T1, T2, T3, T4, T5, T6> *t = cli::as<Tuple8<T1, T2, T3, T4, T5, T6>*>(other);
        if((t ==  nullptr)) 
        {
            return false;
        }
        return (((((comparer->Equals_ad190887ea91ded(cli::box(this->item1), cli::box(t->item1)) && comparer->Equals_ad190887ea91ded(cli::box(this->item2), cli::box(t->item2))) && comparer->Equals_ad190887ea91ded(cli::box(this->item3), cli::box(t->item3))) && comparer->Equals_ad190887ea91ded(cli::box(this->item4), cli::box(t->item4))) && comparer->Equals_ad190887ea91ded(cli::box(this->item5), cli::box(t->item5))) && comparer->Equals_ad190887ea91ded(cli::box(this->item6), cli::box(t->item6)));
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    int32_t Tuple8<T1, T2, T3, T4, T5, T6>::GetHashCode_6648aef0f235ee6c() {
        return cli::cast<Collections::IStructuralEquatable*>(this)->GetHashCode_94e84ad7bccbc132(Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    int32_t Tuple8<T1, T2, T3, T4, T5, T6>::GetHashCode3(Collections::IEqualityComparer* comparer) {
        int32_t h = comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item1));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item2)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item3)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item4)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item5)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item6)));
        return h;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    String* Tuple8<T1, T2, T3, T4, T5, T6>::ToString_1636a0751cb9ac11() {
        return String::Format5(_T("({0}, {1}, {2}, {3}, {4}, {5})"), (new cli::array<Object*>({cli::box(this->item1), cli::box(this->item2), cli::box(this->item3), cli::box(this->item4), cli::box(this->item5), cli::box(this->item6)})));
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    T1 Tuple8<T1, T2, T3, T4, T5, T6>::get_Item1() {
        return this->item1;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    T2 Tuple8<T1, T2, T3, T4, T5, T6>::get_Item2() {
        return this->item2;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    T3 Tuple8<T1, T2, T3, T4, T5, T6>::get_Item3() {
        return this->item3;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    T4 Tuple8<T1, T2, T3, T4, T5, T6>::get_Item4() {
        return this->item4;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    T5 Tuple8<T1, T2, T3, T4, T5, T6>::get_Item5() {
        return this->item5;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6>
    T6 Tuple8<T1, T2, T3, T4, T5, T6>::get_Item6() {
        return this->item6;
    }
    
}
 namespace System {
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    void Tuple9<T1, T2, T3, T4, T5, T6, T7>::constructor(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7) {
        this->item1 = item1;
        this->item2 = item2;
        this->item3 = item3;
        this->item4 = item4;
        this->item5 = item5;
        this->item6 = item6;
        this->item7 = item7;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    int32_t Tuple9<T1, T2, T3, T4, T5, T6, T7>::CompareTo(Object* obj) {
        return cli::cast<Collections::IStructuralComparable*>(this)->CompareTo_6a6cfba1da2bec3b(obj, Collections::Generic::Comparer2<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    int32_t Tuple9<T1, T2, T3, T4, T5, T6, T7>::CompareTo2(Object* other, Collections::IComparer* comparer) {
        Tuple9<T1, T2, T3, T4, T5, T6, T7> *t = cli::as<Tuple9<T1, T2, T3, T4, T5, T6, T7>*>(other);
        if((t ==  nullptr)) 
        {
            if((other ==  nullptr)) 
            {
                return 1;
            }
            throw cli::gcnew<ArgumentException>(_T("other"));
        }
        int32_t res = comparer->Compare_451fd276747b629d(cli::box(this->item1), cli::box(t->item1));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item2), cli::box(t->item2));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item3), cli::box(t->item3));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item4), cli::box(t->item4));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item5), cli::box(t->item5));
        if((res != 0)) 
        {
            return res;
        }
        res = comparer->Compare_451fd276747b629d(cli::box(this->item6), cli::box(t->item6));
        if((res != 0)) 
        {
            return res;
        }
        return comparer->Compare_451fd276747b629d(cli::box(this->item7), cli::box(t->item7));
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    bool Tuple9<T1, T2, T3, T4, T5, T6, T7>::Equals_ed975d2f4a7d193e(Object* obj) {
        return cli::cast<Collections::IStructuralEquatable*>(this)->Equals_2f89738462b0fb33(obj, Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    bool Tuple9<T1, T2, T3, T4, T5, T6, T7>::Equals4(Object* other, Collections::IEqualityComparer* comparer) {
        Tuple9<T1, T2, T3, T4, T5, T6, T7> *t = cli::as<Tuple9<T1, T2, T3, T4, T5, T6, T7>*>(other);
        if((t ==  nullptr)) 
        {
            return false;
        }
        return ((((((comparer->Equals_ad190887ea91ded(cli::box(this->item1), cli::box(t->item1)) && comparer->Equals_ad190887ea91ded(cli::box(this->item2), cli::box(t->item2))) && comparer->Equals_ad190887ea91ded(cli::box(this->item3), cli::box(t->item3))) && comparer->Equals_ad190887ea91ded(cli::box(this->item4), cli::box(t->item4))) && comparer->Equals_ad190887ea91ded(cli::box(this->item5), cli::box(t->item5))) && comparer->Equals_ad190887ea91ded(cli::box(this->item6), cli::box(t->item6))) && comparer->Equals_ad190887ea91ded(cli::box(this->item7), cli::box(t->item7)));
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    int32_t Tuple9<T1, T2, T3, T4, T5, T6, T7>::GetHashCode_6648aef0f235ee6c() {
        return cli::cast<Collections::IStructuralEquatable*>(this)->GetHashCode_94e84ad7bccbc132(Collections::Generic::EqualityComparer<Object*>::get_Default());
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    int32_t Tuple9<T1, T2, T3, T4, T5, T6, T7>::GetHashCode3(Collections::IEqualityComparer* comparer) {
        int32_t h = comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item1));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item2)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item3)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item4)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item5)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item6)));
        h = (((h << 5) - h) + comparer->GetHashCode_f8793dfb2b096a5a(cli::box(this->item7)));
        return h;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    String* Tuple9<T1, T2, T3, T4, T5, T6, T7>::ToString_1636a0751cb9ac11() {
        return String::Format5(_T("({0}, {1}, {2}, {3}, {4}, {5}, {6})"), (new cli::array<Object*>({cli::box(this->item1), cli::box(this->item2), cli::box(this->item3), cli::box(this->item4), cli::box(this->item5), cli::box(this->item6), cli::box(this->item7)})));
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    T1 Tuple9<T1, T2, T3, T4, T5, T6, T7>::get_Item1() {
        return this->item1;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    T2 Tuple9<T1, T2, T3, T4, T5, T6, T7>::get_Item2() {
        return this->item2;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    T3 Tuple9<T1, T2, T3, T4, T5, T6, T7>::get_Item3() {
        return this->item3;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    T4 Tuple9<T1, T2, T3, T4, T5, T6, T7>::get_Item4() {
        return this->item4;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    T5 Tuple9<T1, T2, T3, T4, T5, T6, T7>::get_Item5() {
        return this->item5;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    T6 Tuple9<T1, T2, T3, T4, T5, T6, T7>::get_Item6() {
        return this->item6;
    }
    
    template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
    T7 Tuple9<T1, T2, T3, T4, T5, T6, T7>::get_Item7() {
        return this->item7;
    }
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System {
    
}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections {
    
}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class TKey, class TValue>
    void ConcurrentDictionaryEnumerator<TKey, TValue>::constructor(System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<TKey, TValue>>* internalEnum) {
        this->internalEnum = internalEnum;
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionaryEnumerator<TKey, TValue>::MoveNext() {
        return this->internalEnum->MoveNext_4e78e145935f5417();
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionaryEnumerator<TKey, TValue>::Reset() {
        this->internalEnum->Reset_bcd82381eed41868();
    }
    
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionaryEnumerator<TKey, TValue>::get_Current() {
        return cli::box(this->get_Entry());
    }
    
    template<class TKey, class TValue>
    System::Collections::DictionaryEntry ConcurrentDictionaryEnumerator<TKey, TValue>::get_Entry() {
        System::Collections::Generic::KeyValuePair<TKey, TValue> current = this->internalEnum->get_Current_9be2a11682d08be8();
        return cli::ctor<System::Collections::DictionaryEntry>(cli::box(current->get_Key()), cli::box(current->get_Value()));
    }
    
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionaryEnumerator<TKey, TValue>::get_Key() {
        return cli::box(this->internalEnum->get_Current_9be2a11682d08be8()->get_Key());
    }
    
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionaryEnumerator<TKey, TValue>::get_Value() {
        return cli::box(this->internalEnum->get_Current_9be2a11682d08be8()->get_Value());
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::constructor() {
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::constructor(System::Collections::Generic::IEnumerable2<System::Collections::Generic::KeyValuePair<TKey, TValue>>* collection) {
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::constructor(System::Collections::Generic::IEqualityComparer2<TKey>* comparer) {
        this->comparer = comparer;
        this->internalDictionary = cli::gcnew<SplitOrderedList<TKey, System::Collections::Generic::KeyValuePair<TKey, TValue>>>(comparer);
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::constructor(System::Collections::Generic::IEnumerable2<System::Collections::Generic::KeyValuePair<TKey, TValue>>* collection, System::Collections::Generic::IEqualityComparer2<TKey>* comparer) {
        for(auto tmp_7 : collection) {
            auto pair = cli::cast<System::Collections::Generic::KeyValuePair<TKey, TValue>>(tmp_7);
            Add(pair->get_Key(), pair->get_Value());
        }
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::constructor(int32_t concurrencyLevel, int32_t capacity) {
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::constructor(int32_t concurrencyLevel, System::Collections::Generic::IEnumerable2<System::Collections::Generic::KeyValuePair<TKey, TValue>>* collection, System::Collections::Generic::IEqualityComparer2<TKey>* comparer) {
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::constructor(int32_t concurrencyLevel, int32_t capacity, System::Collections::Generic::IEqualityComparer2<TKey>* comparer) {
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Add(TKey key, TValue value) {
        while(!(TryAdd(key, value))) ;
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Add2(TKey key, TValue value) {
        Add(key, value);
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::TryAdd(TKey key, TValue value) {
        return this->internalDictionary->Insert(Hash2(key), key, Make_2<TKey, TValue>(key, value));
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Add3(System::Collections::Generic::KeyValuePair<TKey, TValue> pair) {
        Add(pair->get_Key(), pair->get_Value());
    }
    
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::AddOrUpdate(TKey key, System::Func2<TKey, TValue>* addValueFactory, System::Func4<TKey, TValue, TValue>* updateValueFactory) {
        auto storey_8 = cli::gcnew<_AddOrUpdate_c__AnonStorey12<TKey, TValue>>();
        storey_8->key = key;
        storey_8->addValueFactory = addValueFactory;
        storey_8->updateValueFactory = updateValueFactory;
        return this->internalDictionary->InsertOrUpdate(Hash2(storey_8->key), storey_8->key, cli::bind(storey_8, &_AddOrUpdate_c__AnonStorey12<TKey, TValue>::__m__4), cli::bind(storey_8, &_AddOrUpdate_c__AnonStorey12<TKey, TValue>::__m__5))->get_Value();
    }
    
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::AddOrUpdate2(TKey key, TValue addValue, System::Func4<TKey, TValue, TValue>* updateValueFactory) {
        auto storey_9 = cli::gcnew<_AddOrUpdate_c__AnonStorey13<TKey, TValue>>();
        storey_9->addValue = addValue;
        return AddOrUpdate(key, cli::bind(storey_9, &_AddOrUpdate_c__AnonStorey13<TKey, TValue>::__m__6), updateValueFactory);
    }
    
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::AddOrUpdate3(TKey key, TValue addValue, TValue updateValue) {
        return this->internalDictionary->InsertOrUpdate2(Hash2(key), key, Make_2<TKey, TValue>(key, addValue), Make_2<TKey, TValue>(key, updateValue))->get_Value();
    }
    
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::GetValue(TKey key) {
        TValue temp;
        if(!(TryGetValue(key, temp))) 
        {
            throw cli::gcnew<System::Collections::Generic::KeyNotFoundException>(cli::import(key)->ToString_1636a0751cb9ac11());
        }
        return temp;
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::TryGetValue(TKey key, TValue value) {
        System::Collections::Generic::KeyValuePair<TKey, TValue> pair;
        bool result = this->internalDictionary->Find(Hash2(key), key, pair);
        value = pair->get_Value();
        return result;
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::TryUpdate(TKey key, TValue newValue, TValue comparisonValue) {
        auto storey_10 = cli::gcnew<_TryUpdate_c__AnonStorey14<TKey, TValue>>();
        storey_10->comparisonValue = comparisonValue;
        return this->internalDictionary->CompareExchange(Hash2(key), key, Make_2<TKey, TValue>(key, newValue), cli::bind(storey_10, &_TryUpdate_c__AnonStorey14<TKey, TValue>::__m__7));
    }
    
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::GetOrAdd(TKey key, System::Func2<TKey, TValue>* valueFactory) {
        auto storey_11 = cli::gcnew<_GetOrAdd_c__AnonStorey15<TKey, TValue>>();
        storey_11->key = key;
        storey_11->valueFactory = valueFactory;
        return this->internalDictionary->InsertOrGet(Hash2(storey_11->key), storey_11->key, Make_2<TKey, TValue>(storey_11->key, TValue()), cli::bind(storey_11, &_GetOrAdd_c__AnonStorey15<TKey, TValue>::__m__8))->get_Value();
    }
    
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::GetOrAdd2(TKey key, TValue value) {
        return this->internalDictionary->InsertOrGet(Hash2(key), key, Make_2<TKey, TValue>(key, value), nullptr)->get_Value();
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::TryRemove(TKey key, TValue value) {
        System::Collections::Generic::KeyValuePair<TKey, TValue> data;
        bool result = this->internalDictionary->Delete(Hash2(key), key, data);
        value = data->get_Value();
        return result;
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::Remove(TKey key) {
        TValue dummy;
        return TryRemove(key, dummy);
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::Remove2(TKey key) {
        return Remove(key);
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::Remove3(System::Collections::Generic::KeyValuePair<TKey, TValue> pair) {
        return Remove(pair->get_Key());
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::ContainsKey(TKey key) {
        System::Collections::Generic::KeyValuePair<TKey, TValue> dummy;
        return this->internalDictionary->Find(Hash2(key), key, dummy);
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::Contains(System::Object* key) {
        if(!(cli::is<TKey>(key))) 
        {
            return false;
        }
        return ContainsKey(cli::unbox<TKey>(key));
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Remove4(System::Object* key) {
        if(!(cli::is<TKey>(key))) 
        {
            return;
        }
        Remove(cli::unbox<TKey>(key));
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Add4(System::Object* key, System::Object* value) {
        if((!(cli::is<TKey>(key)) || !(cli::is<TValue>(value)))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("key or value aren\'t of correct type"));
        }
        Add(cli::unbox<TKey>(key), cli::unbox<TValue>(value));
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::Contains2(System::Collections::Generic::KeyValuePair<TKey, TValue> pair) {
        return ContainsKey(pair->get_Key());
    }
    
    template<class TKey, class TValue>
    cli::array<System::Collections::Generic::KeyValuePair<TKey, TValue>>* ConcurrentDictionary<TKey, TValue>::ToArray() {
        return cli::gcnew<System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<TKey, TValue>>>(this)->ToArray();
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::Clear() {
        this->internalDictionary = cli::gcnew<SplitOrderedList<TKey, System::Collections::Generic::KeyValuePair<TKey, TValue>>>(this->comparer);
    }
    
    template<class TKey, class TValue>
    template<class T>
    System::Collections::Generic::ICollection2<T>* ConcurrentDictionary<TKey, TValue>::GetPart_1(System::Func2<System::Collections::Generic::KeyValuePair<TKey, TValue>, T>* extractor) {
        System::Collections::Generic::List<T> *temp = cli::gcnew<System::Collections::Generic::List<T>>();
        for(auto tmp_12 : this) {
            auto kvp = cli::cast<System::Collections::Generic::KeyValuePair<TKey, TValue>>(tmp_12);
            temp->Add(extractor->Invoke(kvp));
        }
        return temp->AsReadOnly();
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::CopyTo(System::Array* array, int32_t startIndex) {
        cli::array<System::Collections::Generic::KeyValuePair<TKey, TValue>> *arr = cli::as<cli::array<System::Collections::Generic::KeyValuePair<TKey, TValue>>*>(array);
        if((arr ==  nullptr)) 
        {
            return;
        }
        CopyTo4(arr, startIndex, this->get_Count());
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::CopyTo2(cli::array<System::Collections::Generic::KeyValuePair<TKey, TValue>>* array, int32_t startIndex) {
        CopyTo4(array, startIndex, this->get_Count());
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::CopyTo3(cli::array<System::Collections::Generic::KeyValuePair<TKey, TValue>>* array, int32_t startIndex) {
        CopyTo2(array, startIndex);
    }
    
    template<class TKey, class TValue>
    void ConcurrentDictionary<TKey, TValue>::CopyTo4(cli::array<System::Collections::Generic::KeyValuePair<TKey, TValue>>* array, int32_t startIndex, int32_t num) {
        for(auto tmp_13 : this) {
            auto kvp = cli::cast<System::Collections::Generic::KeyValuePair<TKey, TValue>>(tmp_13);
            {
                array->at(startIndex++) = kvp;
                if((--num <= 0)) 
                {
                    return;
                }
            }
        }
    }
    
    template<class TKey, class TValue>
    System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<TKey, TValue>>* ConcurrentDictionary<TKey, TValue>::GetEnumerator() {
        return GetEnumeratorInternal();
    }
    
    template<class TKey, class TValue>
    System::Collections::IEnumerator* ConcurrentDictionary<TKey, TValue>::GetEnumerator2() {
        return cli::cast<System::Collections::IEnumerator*>(GetEnumeratorInternal());
    }
    
    template<class TKey, class TValue>
    System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<TKey, TValue>>* ConcurrentDictionary<TKey, TValue>::GetEnumeratorInternal() {
        return this->internalDictionary->GetEnumerator();
    }
    
    template<class TKey, class TValue>
    System::Collections::IDictionaryEnumerator* ConcurrentDictionary<TKey, TValue>::GetEnumerator3() {
        return cli::gcnew<ConcurrentDictionaryEnumerator<TKey, TValue>>(GetEnumeratorInternal());
    }
    
    template<class TKey, class TValue>
    template<class U, class V>
    System::Collections::Generic::KeyValuePair<U, V> ConcurrentDictionary<TKey, TValue>::Make_2(U key, V value) {
        return cli::ctor<System::Collections::Generic::KeyValuePair<U, V>>(key, value);
    }
    
    template<class TKey, class TValue>
    uint32_t ConcurrentDictionary<TKey, TValue>::Hash2(TKey key) {
        return (uint32_t)this->comparer->GetHashCode_74f46a6b01295dbe(key);
    }
    
    template<class TKey, class TValue>
    TKey ConcurrentDictionary<TKey, TValue>::_get_Keys_m__9(System::Collections::Generic::KeyValuePair<TKey, TValue> kvp) {
        return kvp->get_Key();
    }
    
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::_get_Values_m__A(System::Collections::Generic::KeyValuePair<TKey, TValue> kvp) {
        return kvp->get_Value();
    }
    
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::get_Item(TKey key) {
        return GetValue(key);
    }
    
    template<class TKey, class TValue>
    TValue ConcurrentDictionary<TKey, TValue>::set_Item(TKey key, TValue value) {
        AddOrUpdate3(key, value, value);
        return get_Item(key);
    }
    
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionary<TKey, TValue>::get_Item2(System::Object* key) {
        if(!(cli::is<TKey>(key))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("key isn\'t of correct type"), _T("key"));
        }
        return cli::box(this->get_Item(cli::unbox<TKey>(key)));
    }
    
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionary<TKey, TValue>::set_Item2(System::Object* key, System::Object* value) {
        if((!(cli::is<TKey>(key)) || !(cli::is<TValue>(value)))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("key or value aren\'t of correct type"));
        }
        this->set_Item(cli::unbox<TKey>(key), cli::unbox<TValue>(value));
        return get_Item2(key);
    }
    
    template<class TKey, class TValue>
    int32_t ConcurrentDictionary<TKey, TValue>::get_Count() {
        return this->internalDictionary->get_Count();
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::get_IsEmpty() {
        return (this->get_Count() ==  0);
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::get_IsReadOnly() {
        return false;
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::get_IsReadOnly2() {
        return false;
    }
    
    template<class TKey, class TValue>
    System::Collections::Generic::ICollection2<TKey>* ConcurrentDictionary<TKey, TValue>::get_Keys() {
        return GetPart_1<TKey>(cli::bind([&] (System::Collections::Generic::KeyValuePair<TKey, TValue> kvp) -> TKey {
            return kvp->get_Key();
        }
        ));
    }
    
    template<class TKey, class TValue>
    System::Collections::Generic::ICollection2<TValue>* ConcurrentDictionary<TKey, TValue>::get_Values() {
        return GetPart_1<TValue>(cli::bind([&] (System::Collections::Generic::KeyValuePair<TKey, TValue> kvp) -> TValue {
            return kvp->get_Value();
        }
        ));
    }
    
    template<class TKey, class TValue>
    System::Collections::ICollection* ConcurrentDictionary<TKey, TValue>::get_Keys2() {
        return cli::cast<System::Collections::ICollection*>(this->get_Keys());
    }
    
    template<class TKey, class TValue>
    System::Collections::ICollection* ConcurrentDictionary<TKey, TValue>::get_Values2() {
        return cli::cast<System::Collections::ICollection*>(this->get_Values());
    }
    
    template<class TKey, class TValue>
    System::Object* ConcurrentDictionary<TKey, TValue>::get_SyncRoot() {
        return this;
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::get_IsFixedSize() {
        return false;
    }
    
    template<class TKey, class TValue>
    bool ConcurrentDictionary<TKey, TValue>::get_IsSynchronized() {
        return true;
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class T>
    void Node<T>::constructor() {
    }
    
    template<class T>
    void Node<T>::constructor(Node<T>* wrapped) {
        this->Marked = true;
        this->Next = wrapped;
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class T>
    void ConcurrentOrderedList<T>::constructor() {
    }
    
    template<class T>
    void ConcurrentOrderedList<T>::constructor(System::Collections::Generic::IEqualityComparer2<T>* comparer) {
        if((comparer ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("comparer"));
        }
        this->comparer = comparer;
        this->head = cli::gcnew<Node<T>>();
        this->tail = cli::gcnew<Node<T>>();
        this->head->Next = this->tail;
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::TryAdd(T data) {
        Node<T> *node = cli::gcnew<Node<T>>();
        node->Data2 = data;
        node->Key2 = this->comparer->GetHashCode_74f46a6b01295dbe(data);
        if(ListInsert(node)) 
        {
            System::Threading::Interlocked::Increment(this->count);
            return true;
        }
        return false;
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::TryRemove(T data) {
        T dummy;
        return TryRemoveHash(this->comparer->GetHashCode_74f46a6b01295dbe(data), dummy);
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::TryRemoveHash(int32_t key, T data) {
        if(ListDelete(key, data)) 
        {
            System::Threading::Interlocked::Decrement(this->count);
            return true;
        }
        return false;
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::TryPop(T data) {
        return ListPop(data);
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::Contains(T data) {
        return ContainsHash(this->comparer->GetHashCode_74f46a6b01295dbe(data));
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::ContainsHash(int32_t key) {
        Node<T> *node;
        if(!(ListFind(key, node))) 
        {
            return false;
        }
        return true;
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::TryGetFromHash(int32_t key, T data) {
        data = T();
        Node<T> *node;
        if(!(ListFind(key, node))) 
        {
            return false;
        }
        data = node->Data2;
        return true;
    }
    
    template<class T>
    void ConcurrentOrderedList<T>::Clear() {
        this->head->Next = this->tail;
    }
    
    template<class T>
    void ConcurrentOrderedList<T>::CopyTo(cli::array<T>* array, int32_t startIndex) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("array"));
        }
        if((startIndex < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("startIndex"));
        }
        if((this->count > (array->get_Length() - startIndex))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("array"), _T("The number of elements is greater than the available space from startIndex to the end of the destination array."));
        }
        for(auto tmp_14 : this) {
            auto item = cli::cast<T>(tmp_14);
            {
                if((startIndex >= array->get_Length())) 
                {
                    break;
                }
                array->at(startIndex++) = item;
            }
        }
    }
    
    template<class T>
    Node<T>* ConcurrentOrderedList<T>::ListSearch(int32_t key, Node<T>* left) {
        Node<T> *leftNodeNext = nullptr, *rightNode = nullptr;
        do {
            Node<T> *t = this->head;
            Node<T> *tNext = t->Next;
            do {
                if(!(tNext->Marked)) 
                {
                    left = t;
                    leftNodeNext = tNext;
                }
                t = tNext->Marked ? tNext->Next : tNext;
                if((t ==  this->tail)) 
                {
                    break;
                }
                tNext = t->Next;
            }
            while((tNext->Marked || (t->Key2 < key)));
            rightNode = t;
            if((leftNodeNext ==  rightNode)) 
            {
                if(((rightNode != this->tail) && rightNode->Next->Marked)) 
                {
                    continue;
                }
                 else 
                {
                    return rightNode;
                }
            }
            if((System::Threading::Interlocked::template CompareExchange_1<Node<T>*>(left->Next, rightNode, leftNodeNext) ==  leftNodeNext)) 
            {
                if(((rightNode != this->tail) && rightNode->Next->Marked)) 
                {
                    continue;
                }
                 else 
                {
                    return rightNode;
                }
            }
        }
        while(true);
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::ListDelete(int32_t key, T data) {
        Node<T> *rightNode = nullptr, *rightNodeNext = nullptr, *leftNode = nullptr;
        data = T();
        do {
            rightNode = ListSearch(key, leftNode);
            if(((rightNode ==  this->tail) || (rightNode->Key2 != key))) 
            {
                return false;
            }
            data = rightNode->Data2;
            rightNodeNext = rightNode->Next;
            if(!(rightNodeNext->Marked)) 
            {
                if((System::Threading::Interlocked::template CompareExchange_1<Node<T>*>(rightNode->Next, cli::gcnew<Node<T>>(rightNodeNext), rightNodeNext) ==  rightNodeNext)) 
                {
                    break;
                }
            }
        }
        while(true);
        if((System::Threading::Interlocked::template CompareExchange_1<Node<T>*>(leftNode->Next, rightNodeNext, rightNode) != rightNodeNext)) 
        {
            ListSearch(rightNode->Key2, leftNode);
        }
        return true;
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::ListPop(T data) {
        Node<T> *rightNode = nullptr, *rightNodeNext = nullptr, *leftNode = this->head;
        data = T();
        do {
            rightNode = this->head->Next;
            if((rightNode ==  this->tail)) 
            {
                return false;
            }
            data = rightNode->Data2;
            rightNodeNext = rightNode->Next;
            if(!(rightNodeNext->Marked)) 
            {
                if((System::Threading::Interlocked::template CompareExchange_1<Node<T>*>(rightNode->Next, cli::gcnew<Node<T>>(rightNodeNext), rightNodeNext) ==  rightNodeNext)) 
                {
                    break;
                }
            }
        }
        while(true);
        if((System::Threading::Interlocked::template CompareExchange_1<Node<T>*>(leftNode->Next, rightNodeNext, rightNode) != rightNodeNext)) 
        {
            ListSearch(rightNode->Key2, leftNode);
        }
        return true;
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::ListInsert(Node<T>* newNode) {
        int32_t key = newNode->Key2;
        Node<T> *rightNode = nullptr, *leftNode = nullptr;
        do {
            rightNode = ListSearch(key, leftNode);
            if(((rightNode != this->tail) && (rightNode->Key2 ==  key))) 
            {
                return false;
            }
            newNode->Next = rightNode;
            if((System::Threading::Interlocked::template CompareExchange_1<Node<T>*>(leftNode->Next, newNode, rightNode) ==  rightNode)) 
            {
                return true;
            }
        }
        while(true);
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::ListFind(int32_t key, Node<T>* data) {
        Node<T> *rightNode = nullptr, *leftNode = nullptr;
        data = nullptr;
        data = rightNode = ListSearch(key, leftNode);
        return ((rightNode != this->tail) && (rightNode->Key2 ==  key));
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ConcurrentOrderedList<T>::GetEnumerator() {
        return GetEnumeratorInternal();
    }
    
    template<class T>
    System::Collections::IEnumerator* ConcurrentOrderedList<T>::GetEnumerator2() {
        return GetEnumeratorInternal();
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ConcurrentOrderedList<T>::GetEnumeratorInternal() {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
    template<class T>
    void ConcurrentOrderedList<T>::Add(T item) {
        TryAdd(item);
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::Remove(T item) {
        return TryRemove(item);
    }
    
    template<class T>
    System::Collections::Generic::IEqualityComparer2<T>* ConcurrentOrderedList<T>::get_Comparer() {
        return this->comparer;
    }
    
    template<class T>
    int32_t ConcurrentOrderedList<T>::get_Count() {
        return this->count;
    }
    
    template<class T>
    bool ConcurrentOrderedList<T>::get_IsReadOnly() {
        return false;
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class T>
    void Node2<T>::constructor() {
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class T>
    void NodeObjectPool<T>::constructor() {
    }
    
    template<class T>
    Node2<T>* NodeObjectPool<T>::Creator_c074cf904cf11d1e() {
        return cli::gcnew<Node2<T>>();
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class T>
    ConcurrentQueue<T>::ConcurrentQueue()
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
    
    template<class T>
    void ConcurrentQueue<T>::constructor() {
        this->tail = this->head;
    }
    
    template<class T>
    void ConcurrentQueue<T>::constructor(System::Collections::Generic::IEnumerable2<T>* collection) {
        for(auto tmp_15 : collection) {
            auto item = cli::cast<T>(tmp_15);
            Enqueue(item);
        }
    }
    
    template<class T>
    void ConcurrentQueue<T>::static_constructor() {
    }
    
    template<class T>
    Node2<T>* ConcurrentQueue<T>::ZeroOut(Node2<T>* node) {
        node->Value = T();
        node->Next = nullptr;
        return node;
    }
    
    template<class T>
    void ConcurrentQueue<T>::Enqueue(T item) {
        Node2<T> *node = ConcurrentQueue<T>::pool->Take();
        node->Value = item;
        Node2<T> *oldTail = nullptr;
        Node2<T> *oldNext = nullptr;
        bool update = false;
        while(!(update)) {
            oldTail = this->tail;
            oldNext = oldTail->Next;
            if((this->tail ==  oldTail)) 
            {
                if((oldNext ==  nullptr)) 
                {
                    update = (System::Threading::Interlocked::template CompareExchange_1<Node2<T>*>(this->tail->Next, node, nullptr) ==  nullptr);
                }
                 else 
                {
                    System::Threading::Interlocked::template CompareExchange_1<Node2<T>*>(this->tail, oldNext, oldTail);
                }
            }
        }
        System::Threading::Interlocked::template CompareExchange_1<Node2<T>*>(this->tail, node, oldTail);
        System::Threading::Interlocked::Increment(this->count);
    }
    
    template<class T>
    bool ConcurrentQueue<T>::TryAdd(T item) {
        Enqueue(item);
        return true;
    }
    
    template<class T>
    bool ConcurrentQueue<T>::TryDequeue(T result) {
        result = T();
        bool advanced = false;
        while(!(advanced)) {
            Node2<T> *oldHead = this->head;
            Node2<T> *oldTail = this->tail;
            Node2<T> *oldNext = oldHead->Next;
            if((oldHead ==  this->head)) 
            {
                if((oldHead ==  oldTail)) 
                {
                    if((oldNext != nullptr)) 
                    {
                        System::Threading::Interlocked::template CompareExchange_1<Node2<T>*>(this->tail, oldNext, oldTail);
                    }
                    result = T();
                    return false;
                }
                 else 
                {
                    result = oldNext->Value;
                    advanced = (System::Threading::Interlocked::template CompareExchange_1<Node2<T>*>(this->head, oldNext, oldHead) ==  oldHead);
                    if(advanced) 
                    {
                        ConcurrentQueue<T>::pool->Release(ZeroOut(oldHead));
                    }
                }
            }
        }
        System::Threading::Interlocked::Decrement(this->count);
        return true;
    }
    
    template<class T>
    bool ConcurrentQueue<T>::TryPeek(T result) {
        if(this->get_IsEmpty()) 
        {
            result = T();
            return false;
        }
        Node2<T> *first = this->head->Next;
        result = first->Value;
        return true;
    }
    
    template<class T>
    void ConcurrentQueue<T>::Clear() {
        this->count = 0;
        this->tail = this->head = cli::gcnew<Node2<T>>();
    }
    
    template<class T>
    System::Collections::IEnumerator* ConcurrentQueue<T>::GetEnumerator() {
        return cli::cast<System::Collections::IEnumerator*>(InternalGetEnumerator());
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ConcurrentQueue<T>::GetEnumerator2() {
        return InternalGetEnumerator();
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ConcurrentQueue<T>::InternalGetEnumerator() {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
    template<class T>
    void ConcurrentQueue<T>::CopyTo(System::Array* array, int32_t index) {
        cli::array<T> *dest = cli::as<cli::array<T>*>(array);
        if((dest ==  nullptr)) 
        {
            return;
        }
        CopyTo2(dest, index);
    }
    
    template<class T>
    void ConcurrentQueue<T>::CopyTo2(cli::array<T>* array, int32_t index) {
        System::Collections::Generic::IEnumerator2<T> *e = InternalGetEnumerator();
        int32_t i = index;
        while(e->MoveNext_4e78e145935f5417()) {
            array->at(i++) = e->get_Current_9be2a11682d08be8();
        }
    }
    
    template<class T>
    cli::array<T>* ConcurrentQueue<T>::ToArray() {
        cli::array<T> *dest = (new cli::array<T>(this->count));
        CopyTo2(dest, 0);
        return dest;
    }
    
    template<class T>
    bool ConcurrentQueue<T>::TryTake(T item) {
        return TryDequeue(item);
    }
    
    template<class T>
    bool ConcurrentQueue<T>::get_IsSynchronized() {
        return true;
    }
    
    template<class T>
    System::Object* ConcurrentQueue<T>::get_SyncRoot() {
        return this->syncRoot;
    }
    
    template<class T>
    int32_t ConcurrentQueue<T>::get_Count() {
        return this->count;
    }
    
    template<class T>
    bool ConcurrentQueue<T>::get_IsEmpty() {
        return (this->count ==  0);
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class T>
    void Node3<T>::constructor() {
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class T>
    void NodeObjectPool2<T>::constructor() {
    }
    
    template<class T>
    Node3<T>* NodeObjectPool2<T>::Creator_c074cf904cf11d1e() {
        return cli::gcnew<Node3<T>>();
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class T>
    ConcurrentStack<T>::ConcurrentStack()
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
    
    template<class T>
    void ConcurrentStack<T>::constructor() {
    }
    
    template<class T>
    void ConcurrentStack<T>::constructor(System::Collections::Generic::IEnumerable2<T>* collection) {
        for(auto tmp_16 : collection) {
            auto item = cli::cast<T>(tmp_16);
            Push(item);
        }
    }
    
    template<class T>
    void ConcurrentStack<T>::static_constructor() {
    }
    
    template<class T>
    Node3<T>* ConcurrentStack<T>::ZeroOut(Node3<T>* node) {
        node->Value = T();
        node->Next = nullptr;
        return node;
    }
    
    template<class T>
    bool ConcurrentStack<T>::TryAdd(T elem) {
        Push(elem);
        return true;
    }
    
    template<class T>
    void ConcurrentStack<T>::Push(T item) {
        Node3<T> *temp = ConcurrentStack<T>::pool->Take();
        temp->Value = item;
        do {
            temp->Next = this->head;
        }
        while((System::Threading::Interlocked::template CompareExchange_1<Node3<T>*>(this->head, temp, temp->Next) != temp->Next));
        System::Threading::Interlocked::Increment(this->count);
    }
    
    template<class T>
    void ConcurrentStack<T>::PushRange(cli::array<T>* items) {
        PushRange2(items, 0, items->get_Length());
    }
    
    template<class T>
    void ConcurrentStack<T>::PushRange2(cli::array<T>* items, int32_t startIndex, int32_t count) {
        Node3<T> *insert = nullptr;
        Node3<T> *first = nullptr;
        for(int32_t i = startIndex; (i < count); i++){
            Node3<T> *temp = ConcurrentStack<T>::pool->Take();
            temp->Value = items->at(i);
            temp->Next = insert;
            insert = temp;
            if((first ==  nullptr)) 
            {
                first = temp;
            }
        }
        do {
            first->Next = this->head;
        }
        while((System::Threading::Interlocked::template CompareExchange_1<Node3<T>*>(this->head, insert, first->Next) != first->Next));
        System::Threading::Interlocked::Add(count, count);
    }
    
    template<class T>
    bool ConcurrentStack<T>::TryPop(T result) {
        Node3<T> *temp;
        do {
            temp = this->head;
            if((temp ==  nullptr)) 
            {
                result = T();
                return false;
            }
        }
        while((System::Threading::Interlocked::template CompareExchange_1<Node3<T>*>(this->head, temp->Next, temp) != temp));
        System::Threading::Interlocked::Decrement(this->count);
        result = temp->Value;
        ConcurrentStack<T>::pool->Release(ZeroOut(temp));
        return true;
    }
    
    template<class T>
    int32_t ConcurrentStack<T>::TryPopRange(cli::array<T>* items) {
        return TryPopRange2(items, 0, items->get_Length());
    }
    
    template<class T>
    int32_t ConcurrentStack<T>::TryPopRange2(cli::array<T>* items, int32_t startIndex, int32_t count) {
        Node3<T> *temp;
        Node3<T> *end;
        do {
            temp = this->head;
            if((temp ==  nullptr)) 
            {
                return -1;
            }
            end = temp;
            for(int32_t j = 0; (j < (count - 1)); j++){
                end = end->Next;
                if((end ==  nullptr)) 
                {
                    break;
                }
            }
        }
        while((System::Threading::Interlocked::template CompareExchange_1<Node3<T>*>(this->head, end, temp) != temp));
        int32_t i;
        for(i = startIndex; ((i < count) && (temp != nullptr)); i++){
            items->at(i) = temp->Value;
            end = temp;
            temp = temp->Next;
            ConcurrentStack<T>::pool->Release(ZeroOut(end));
        }
        return (i - 1);
    }
    
    template<class T>
    bool ConcurrentStack<T>::TryPeek(T result) {
        Node3<T> *myHead = this->head;
        if((myHead ==  nullptr)) 
        {
            result = T();
            return false;
        }
        result = myHead->Value;
        return true;
    }
    
    template<class T>
    void ConcurrentStack<T>::Clear() {
        this->count = 0;
        this->head = nullptr;
    }
    
    template<class T>
    System::Collections::IEnumerator* ConcurrentStack<T>::GetEnumerator() {
        return cli::cast<System::Collections::IEnumerator*>(InternalGetEnumerator());
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ConcurrentStack<T>::GetEnumerator2() {
        return InternalGetEnumerator();
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ConcurrentStack<T>::InternalGetEnumerator() {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
    template<class T>
    void ConcurrentStack<T>::CopyTo(System::Array* array, int32_t index) {
        cli::array<T> *dest = cli::as<cli::array<T>*>(array);
        if((dest ==  nullptr)) 
        {
            return;
        }
        CopyTo2(dest, index);
    }
    
    template<class T>
    void ConcurrentStack<T>::CopyTo2(cli::array<T>* array, int32_t index) {
        System::Collections::Generic::IEnumerator2<T> *e = InternalGetEnumerator();
        int32_t i = index;
        while(e->MoveNext_4e78e145935f5417()) {
            array->at(i++) = e->get_Current_9be2a11682d08be8();
        }
    }
    
    template<class T>
    bool ConcurrentStack<T>::TryTake(T item) {
        return TryPop(item);
    }
    
    template<class T>
    cli::array<T>* ConcurrentStack<T>::ToArray() {
        cli::array<T> *dest = (new cli::array<T>(this->count));
        CopyTo2(dest, 0);
        return dest;
    }
    
    template<class T>
    bool ConcurrentStack<T>::get_IsSynchronized() {
        return true;
    }
    
    template<class T>
    System::Object* ConcurrentStack<T>::get_SyncRoot() {
        return this->syncRoot;
    }
    
    template<class T>
    int32_t ConcurrentStack<T>::get_Count() {
        return this->count;
    }
    
    template<class T>
    bool ConcurrentStack<T>::get_IsEmpty() {
        return (this->count ==  0);
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class T>
    void ObjectPool<T>::constructor() {
        this->buffer = (new cli::array<T>(20));
        for(int32_t i = 0; (i < 20); i++) {
            this->buffer->at(i) = Creator_c074cf904cf11d1e();
        }
        this->addIndex = 19;
    }
    
    template<class T>
    T ObjectPool<T>::Take() {
        if((((this->addIndex & -134217729) - 1) ==  this->removeIndex)) 
        {
            return Creator_c074cf904cf11d1e();
        }
        int32_t i;
        T result;
        int32_t tries = 3;
        do {
            i = this->removeIndex;
            if(((((this->addIndex & -134217729) - 1) ==  i) || (tries ==  0))) 
            {
                return Creator_c074cf904cf11d1e();
            }
            result = this->buffer->at((i % 20));
        }
        while(((System::Threading::Interlocked::CompareExchange(this->removeIndex, (i + 1), i) != i) && (--tries > -1)));
        return result;
    }
    
    template<class T>
    void ObjectPool<T>::Release(T obj) {
        if(((cli::box(obj) ==  nullptr) || ((this->addIndex - this->removeIndex) >= 19))) 
        {
            return;
        }
        int32_t i;
        int32_t tries = 3;
        do {
            do {
                i = this->addIndex;
            }
            while(((i & 134217728) > 0));
            if(((i - this->removeIndex) >= 19)) 
            {
                return;
            }
        }
        while(((System::Threading::Interlocked::CompareExchange(this->addIndex, ((i + 1) + 134217728), i) != i) && (--tries > 0)));
        this->buffer->at((i % 20)) = obj;
        this->addIndex = (this->addIndex - 134217728);
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class TSource>
    void ProxyEnumerator<TSource>::constructor(System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, TSource>>* enumerator) {
        this->internalEnumerator = enumerator;
    }
    
    template<class TSource>
    void ProxyEnumerator<TSource>::Dispose() {
        this->internalEnumerator->Dispose_95cb2516542c2f97();
    }
    
    template<class TSource>
    bool ProxyEnumerator<TSource>::MoveNext() {
        if(!(this->internalEnumerator->MoveNext_4e78e145935f5417())) 
        {
            return false;
        }
        this->set_Current(this->internalEnumerator->get_Current_9be2a11682d08be8()->get_Value());
        return true;
    }
    
    template<class TSource>
    void ProxyEnumerator<TSource>::Reset() {
        this->internalEnumerator->Reset_bcd82381eed41868();
    }
    
    template<class TSource>
    System::Object* ProxyEnumerator<TSource>::get_Current() {
        return cli::box(this->get_Current2());
    }
    
    template<class TSource>
    TSource ProxyEnumerator<TSource>::get_Current2() {
        return this->_Current_k__BackingField;
    }
    
    template<class TSource>
    TSource ProxyEnumerator<TSource>::set_Current(TSource value) {
        this->_Current_k__BackingField = value;
        return get_Current2();
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class TSource>
    void OrderablePartitioner<TSource>::constructor(bool keysOrderedInEachPartition, bool keysOrderedAcrossPartitions, bool keysNormalized) {
        this->keysOrderedInEachPartition = keysOrderedInEachPartition;
        this->keysOrderedAcrossPartitions = keysOrderedAcrossPartitions;
        this->keysNormalized = keysNormalized;
    }
    
    template<class TSource>
    System::Collections::Generic::IEnumerable2<TSource>* OrderablePartitioner<TSource>::GetDynamicPartitions_9e06f5d55ec2b8be() {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
    template<class TSource>
    System::Collections::Generic::IList2<System::Collections::Generic::IEnumerator2<TSource>*>* OrderablePartitioner<TSource>::GetPartitions_388b8792e0ab2501(int32_t partitionCount) {
        cli::array<System::Collections::Generic::IEnumerator2<TSource>*> *temp = (new cli::array<System::Collections::Generic::IEnumerator2<TSource>*>(partitionCount));
        System::Collections::Generic::IList2<System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, TSource>>*> *enumerators = GetOrderablePartitions_abc13b50067e2c56(partitionCount);
        for(int32_t i = 0; (i < enumerators->get_Count_a9c25d5c244affb9()); i++) {
            temp->at(i) = cli::gcnew<ProxyEnumerator<TSource>>(enumerators->get_Item_e6c1a54cb8f591e7(i));
        }
        return temp;
    }
    
    template<class TSource>
    System::Collections::Generic::IEnumerator2<TSource>* OrderablePartitioner<TSource>::GetProxyEnumerator(System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, TSource>>* enumerator) {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
    template<class TSource>
    System::Collections::Generic::IEnumerable2<System::Collections::Generic::KeyValuePair<int64_t, TSource>>* OrderablePartitioner<TSource>::GetOrderableDynamicPartitions_f7c19bb268c93fb3() {
        if(!(this->get_SupportsDynamicPartitions_5600fc5184df900())) 
        {
            throw cli::gcnew<System::NotSupportedException>();
        }
        return nullptr;
    }
    
    template<class TSource>
    bool OrderablePartitioner<TSource>::get_KeysOrderedInEachPartition() {
        return this->keysOrderedInEachPartition;
    }
    
    template<class TSource>
    bool OrderablePartitioner<TSource>::get_KeysOrderedAcrossPartitions() {
        return this->keysOrderedAcrossPartitions;
    }
    
    template<class TSource>
    bool OrderablePartitioner<TSource>::get_KeysNormalized() {
        return this->keysNormalized;
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class TSource>
    OrderablePartitioner<TSource>* Partitioner2::Create_1(System::Collections::Generic::IEnumerable2<TSource>* source) {
        System::Collections::Generic::IList2<TSource> *tempIList = cli::as<System::Collections::Generic::IList2<TSource>*>(source);
        if((tempIList != nullptr)) 
        {
            return Create_13<TSource>(tempIList, true);
        }
        return cli::gcnew<Partitioners::EnumerablePartitioner<TSource>>(source);
    }
    
    template<class TSource>
    OrderablePartitioner<TSource>* Partitioner2::Create_12(cli::array<TSource>* array, bool loadBalance) {
        return Create_13<TSource>(cli::cast<System::Collections::Generic::IList2<TSource>*>(array), loadBalance);
    }
    
    template<class TSource>
    OrderablePartitioner<TSource>* Partitioner2::Create_13(System::Collections::Generic::IList2<TSource>* list, bool loadBalance) {
        return cli::gcnew<Partitioners::ListPartitioner<TSource>>(list);
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class TSource>
    void Partitioner<TSource>::constructor() {
    }
    
    template<class TSource>
    System::Collections::Generic::IEnumerable2<TSource>* Partitioner<TSource>::GetDynamicPartitions_9e06f5d55ec2b8be() {
        if(!(this->get_SupportsDynamicPartitions_5600fc5184df900())) 
        {
            throw cli::gcnew<System::NotSupportedException>();
        }
        return nullptr;
    }
    
    template<class TSource>
    bool Partitioner<TSource>::get_SupportsDynamicPartitions_5600fc5184df900() {
        return false;
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class TKey, class T>
    void Node4<TKey, T>::constructor() {
    }
    
    template<class TKey, class T>
    Node4<TKey, T>* Node4<TKey, T>::Init(uint64_t key, TKey subKey, T data) {
        this->Key2 = key;
        this->SubKey = subKey;
        this->Data2 = data;
        this->Marked = false;
        this->Next = nullptr;
        return this;
    }
    
    template<class TKey, class T>
    Node4<TKey, T>* Node4<TKey, T>::Init2(uint64_t key) {
        this->Key2 = key;
        this->Data2 = T();
        this->Next = nullptr;
        this->Marked = false;
        this->SubKey = TKey();
        return this;
    }
    
    template<class TKey, class T>
    Node4<TKey, T>* Node4<TKey, T>::Init3(Node4<TKey, T>* wrapped) {
        this->Marked = true;
        this->Next = wrapped;
        this->Key2 = 0UL;
        this->Data2 = T();
        this->SubKey = TKey();
        return this;
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class TKey, class T>
    void NodeObjectPool3<TKey, T>::constructor() {
    }
    
    template<class TKey, class T>
    Node4<TKey, T>* NodeObjectPool3<TKey, T>::Creator_c074cf904cf11d1e() {
        return cli::gcnew<Node4<TKey, T>>();
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent {
    
    template<class TKey, class T>
    SplitOrderedList<TKey, T>::SplitOrderedList()
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
    
    template<class TKey, class T>
    void SplitOrderedList<TKey, T>::constructor(System::Collections::Generic::IEqualityComparer2<TKey>* comparer) {
        this->comparer = comparer;
        this->head = cli::gcnew<Node4<TKey, T>>()->Init2(0UL);
        this->tail = cli::gcnew<Node4<TKey, T>>()->Init2(18446744073709551615UL);
        this->head->Next = this->tail;
        SetBucket(0U, this->head);
    }
    
    template<class TKey, class T>
    void SplitOrderedList<TKey, T>::static_constructor() {
    }
    
    template<class TKey, class T>
    T SplitOrderedList<TKey, T>::InsertOrUpdate(uint32_t key, TKey subKey, System::Func<T>* addGetter, System::Func2<T, T>* updateGetter) {
        Node4<TKey, T> *current;
        bool result = InsertInternal(key, subKey, T(), addGetter, current);
        if(result) 
        {
            return current->Data2;
        }
        return current->Data2 = updateGetter->Invoke(current->Data2);
    }
    
    template<class TKey, class T>
    T SplitOrderedList<TKey, T>::InsertOrUpdate2(uint32_t key, TKey subKey, T addValue, T updateValue) {
        Node4<TKey, T> *current;
        if(InsertInternal(key, subKey, addValue, nullptr, current)) 
        {
            return current->Data2;
        }
        return current->Data2 = updateValue;
    }
    
    template<class TKey, class T>
    bool SplitOrderedList<TKey, T>::Insert(uint32_t key, TKey subKey, T data) {
        Node4<TKey, T> *current;
        return InsertInternal(key, subKey, data, nullptr, current);
    }
    
    template<class TKey, class T>
    T SplitOrderedList<TKey, T>::InsertOrGet(uint32_t key, TKey subKey, T data, System::Func<T>* dataCreator) {
        Node4<TKey, T> *current;
        InsertInternal(key, subKey, data, dataCreator, current);
        return current->Data2;
    }
    
    template<class TKey, class T>
    bool SplitOrderedList<TKey, T>::InsertInternal(uint32_t key, TKey subKey, T data, System::Func<T>* dataCreator, Node4<TKey, T>* current) {
        Node4<TKey, T> *node = SplitOrderedList<TKey, T>::pool->Take()->Init(ComputeRegularKey(key), subKey, data);
        uint32_t b = (key % (uint32_t)this->size);
        Node4<TKey, T> *bucket;
        if(((bucket = GetBucket(b)) ==  (nullptr))) 
        {
            bucket = InitializeBucket(b);
        }
        if(!(ListInsert(node, bucket, current, dataCreator))) 
        {
            return false;
        }
        int32_t csize = this->size;
        if((((System::Threading::Interlocked::Increment(this->count) / csize) > 5) && ((csize & 1073741824) ==  0))) 
        {
            System::Threading::Interlocked::CompareExchange(this->size, (2 * csize), csize);
        }
        current = node;
        return true;
    }
    
    template<class TKey, class T>
    bool SplitOrderedList<TKey, T>::Find(uint32_t key, TKey subKey, T data) {
        Node4<TKey, T> *node;
        uint32_t b = (key % (uint32_t)this->size);
        data = T();
        Node4<TKey, T> *bucket;
        if(((bucket = GetBucket(b)) ==  (nullptr))) 
        {
            bucket = InitializeBucket(b);
        }
        if(!(ListFind(ComputeRegularKey(key), subKey, bucket, node))) 
        {
            return false;
        }
        data = node->Data2;
        return !(node->Marked);
    }
    
    template<class TKey, class T>
    bool SplitOrderedList<TKey, T>::CompareExchange(uint32_t key, TKey subKey, T data, System::Func2<T, bool>* check) {
        Node4<TKey, T> *node;
        uint32_t b = (key % (uint32_t)this->size);
        Node4<TKey, T> *bucket;
        if(((bucket = GetBucket(b)) ==  (nullptr))) 
        {
            bucket = InitializeBucket(b);
        }
        if(!(ListFind(ComputeRegularKey(key), subKey, bucket, node))) 
        {
            return false;
        }
        if(!(check->Invoke(node->Data2))) 
        {
            return false;
        }
        node->Data2 = data;
        return true;
    }
    
    template<class TKey, class T>
    bool SplitOrderedList<TKey, T>::Delete(uint32_t key, TKey subKey, T data) {
        uint32_t b = (key % (uint32_t)this->size);
        Node4<TKey, T> *bucket;
        if(((bucket = GetBucket(b)) ==  (nullptr))) 
        {
            bucket = InitializeBucket(b);
        }
        if(!(ListDelete(bucket, ComputeRegularKey(key), subKey, data))) 
        {
            return false;
        }
        System::Threading::Interlocked::Decrement(this->count);
        return true;
    }
    
    template<class TKey, class T>
    System::Collections::Generic::IEnumerator2<T>* SplitOrderedList<TKey, T>::GetEnumerator() {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
    template<class TKey, class T>
    Node4<TKey, T>* SplitOrderedList<TKey, T>::InitializeBucket(uint32_t b) {
        Node4<TKey, T> *current;
        uint32_t parent = GetParent(b);
        Node4<TKey, T> *bucket;
        if(((bucket = GetBucket(parent)) ==  (nullptr))) 
        {
            bucket = InitializeBucket(parent);
        }
        Node4<TKey, T> *dummy = SplitOrderedList<TKey, T>::pool->Take()->Init2(ComputeDummyKey(b));
        if(!(ListInsert(dummy, bucket, current, nullptr))) 
        {
            return current;
        }
        return SetBucket(b, dummy);
    }
    
    template<class TKey, class T>
    uint32_t SplitOrderedList<TKey, T>::GetParent(uint32_t v) {
        uint32_t t, tt;
        int32_t pos = ((tt = (v >> 16)) > (0U)) ? ((t = (tt >> 8)) > (0U)) ? (24 + (int32_t)(SplitOrderedList<TKey, T>::logTable->at((int32_t)t))) : (16 + (int32_t)(SplitOrderedList<TKey, T>::logTable->at((int32_t)tt))) : ((t = (v >> 8)) > (0U)) ? (8 + (int32_t)(SplitOrderedList<TKey, T>::logTable->at((int32_t)t))) : (int32_t)(SplitOrderedList<TKey, T>::logTable->at((int32_t)v));
        return (uint32_t)((int64_t)(v) & (int64_t)(~((1 << (pos & 31)))));
    }
    
    template<class TKey, class T>
    uint64_t SplitOrderedList<TKey, T>::ComputeRegularKey(uint32_t key) {
        return (ComputeDummyKey(key) | 1UL);
    }
    
    template<class TKey, class T>
    uint64_t SplitOrderedList<TKey, T>::ComputeDummyKey(uint32_t key) {
        return ((uint64_t)((((((uint32_t)(SplitOrderedList<TKey, T>::reverseTable->at((int32_t)(key & 255U))) << 24) | ((uint32_t)(SplitOrderedList<TKey, T>::reverseTable->at((int32_t)((key >> 8) & 255U))) << 16)) | ((uint32_t)(SplitOrderedList<TKey, T>::reverseTable->at((int32_t)((key >> 16) & 255U))) << 8)) | (uint32_t)(SplitOrderedList<TKey, T>::reverseTable->at((int32_t)((key >> 24) & 255U))))) << 1);
    }
    
    template<class TKey, class T>
    Node4<TKey, T>* SplitOrderedList<TKey, T>::GetBucket(uint32_t index) {
        if(((int64_t)(index) >= (int64_t)(this->buckets->get_Length()))) 
        {
            return nullptr;
        }
        return this->buckets->at((int32_t)index);
    }
    
    template<class TKey, class T>
    Node4<TKey, T>* SplitOrderedList<TKey, T>::SetBucket(uint32_t index, Node4<TKey, T>* node) {
        {
            cli::finally_guard([&]() {
                this->slim->ExitReadLock();
            });
            this->slim->EnterReadLock();
            CheckSegment(index, true);
            System::Threading::Interlocked::template CompareExchange_1<Node4<TKey, T>*>(this->buckets->at((int32_t)index), node, nullptr);
            return this->buckets->at((int32_t)index);
        }
    }
    
    template<class TKey, class T>
    void SplitOrderedList<TKey, T>::CheckSegment(uint32_t segment, bool readLockTaken) {
        if(((int64_t)(segment) < (int64_t)(this->buckets->get_Length()))) 
        {
            return;
        }
        if(readLockTaken) 
        {
            this->slim->ExitReadLock();
        }
        {
            cli::finally_guard([&]() {
                this->slim->ExitWriteLock();
            });
            this->slim->EnterWriteLock();
            while(((int64_t)(segment) >= (int64_t)(this->buckets->get_Length()))) System::Array::template Resize_1<Node4<TKey, T>*>(this->buckets, (this->buckets->get_Length() * 2));
        }
        if(readLockTaken) 
        {
            this->slim->EnterReadLock();
        }
    }
    
    template<class TKey, class T>
    Node4<TKey, T>* SplitOrderedList<TKey, T>::ListSearch(uint64_t key, TKey subKey, Node4<TKey, T>* left, Node4<TKey, T>* h) {
        Node4<TKey, T> *leftNodeNext = nullptr, *rightNode = nullptr;
        do {
            Node4<TKey, T> *t = h;
            Node4<TKey, T> *tNext = t->Next;
            do {
                if(!(tNext->Marked)) 
                {
                    left = t;
                    leftNodeNext = tNext;
                }
                t = tNext->Marked ? tNext->Next : tNext;
                if((t ==  this->tail)) 
                {
                    break;
                }
                tNext = t->Next;
            }
            while(((tNext->Marked || (t->Key2 < key)) || ((tNext->Key2 ==  key) && !(this->comparer->Equals_f783e5e22b72a1c0(subKey, t->SubKey)))));
            rightNode = t;
            if((leftNodeNext ==  rightNode)) 
            {
                if(((rightNode != this->tail) && rightNode->Next->Marked)) 
                {
                    continue;
                }
                 else 
                {
                    return rightNode;
                }
            }
            if((System::Threading::Interlocked::template CompareExchange_1<Node4<TKey, T>*>(left->Next, rightNode, leftNodeNext) ==  leftNodeNext)) 
            {
                SplitOrderedList<TKey, T>::pool->Release(leftNodeNext);
                if(((rightNode != this->tail) && rightNode->Next->Marked)) 
                {
                    continue;
                }
                 else 
                {
                    return rightNode;
                }
            }
        }
        while(true);
    }
    
    template<class TKey, class T>
    bool SplitOrderedList<TKey, T>::ListDelete(Node4<TKey, T>* startPoint, uint64_t key, TKey subKey, T data) {
        Node4<TKey, T> *rightNode = nullptr, *rightNodeNext = nullptr, *leftNode = nullptr;
        data = T();
        Node4<TKey, T> *markedNode = nullptr;
        do {
            rightNode = ListSearch(key, subKey, leftNode, startPoint);
            if((((rightNode ==  this->tail) || (rightNode->Key2 != key)) || !(this->comparer->Equals_f783e5e22b72a1c0(subKey, rightNode->SubKey)))) 
            {
                return false;
            }
            data = rightNode->Data2;
            rightNodeNext = rightNode->Next;
            if(!(rightNodeNext->Marked)) 
            {
                if((markedNode ==  nullptr)) 
                {
                    markedNode = SplitOrderedList<TKey, T>::pool->Take();
                }
                markedNode->Init3(rightNodeNext);
                if((System::Threading::Interlocked::template CompareExchange_1<Node4<TKey, T>*>(rightNode->Next, markedNode, rightNodeNext) ==  rightNodeNext)) 
                {
                    break;
                }
            }
        }
        while(true);
        if((System::Threading::Interlocked::template CompareExchange_1<Node4<TKey, T>*>(leftNode->Next, rightNodeNext, rightNode) != rightNode)) 
        {
            ListSearch(rightNode->Key2, subKey, leftNode, startPoint);
        }
         else 
        {
            SplitOrderedList<TKey, T>::pool->Release(rightNode);
        }
        return true;
    }
    
    template<class TKey, class T>
    bool SplitOrderedList<TKey, T>::ListInsert(Node4<TKey, T>* newNode, Node4<TKey, T>* startPoint, Node4<TKey, T>* current, System::Func<T>* dataCreator) {
        uint64_t key = newNode->Key2;
        Node4<TKey, T> *rightNode = nullptr, *leftNode = nullptr;
        do {
            rightNode = current = ListSearch(key, newNode->SubKey, leftNode, startPoint);
            if((((rightNode != this->tail) && (rightNode->Key2 ==  key)) && this->comparer->Equals_f783e5e22b72a1c0(newNode->SubKey, rightNode->SubKey))) 
            {
                return false;
            }
            newNode->Next = rightNode;
            if((dataCreator != nullptr)) 
            {
                newNode->Data2 = dataCreator->Invoke();
            }
            if((System::Threading::Interlocked::template CompareExchange_1<Node4<TKey, T>*>(leftNode->Next, newNode, rightNode) ==  rightNode)) 
            {
                return true;
            }
        }
        while(true);
    }
    
    template<class TKey, class T>
    bool SplitOrderedList<TKey, T>::ListFind(uint64_t key, TKey subKey, Node4<TKey, T>* startPoint, Node4<TKey, T>* data) {
        Node4<TKey, T> *rightNode = nullptr, *leftNode = nullptr;
        data = nullptr;
        rightNode = ListSearch(key, subKey, leftNode, startPoint);
        data = rightNode;
        return (((rightNode != this->tail) && (rightNode->Key2 ==  key)) && this->comparer->Equals_f783e5e22b72a1c0(subKey, rightNode->SubKey));
    }
    
    template<class TKey, class T>
    int32_t SplitOrderedList<TKey, T>::get_Count() {
        return this->count;
    }
    
}}}
 namespace System { namespace Collections { namespace Concurrent { namespace Partitioners {
    
    template<class T>
    void PartitionerState<T>::constructor() {
    }
    
}}}}
 namespace System { namespace Collections { namespace Concurrent { namespace Partitioners {
    
    template<class T>
    void EnumerablePartitioner<T>::constructor(System::Collections::Generic::IEnumerable2<T>* source) {
    }
    
    template<class T>
    void EnumerablePartitioner<T>::constructor(System::Collections::Generic::IEnumerable2<T>* source, int32_t initialPartitionSize, int32_t partitionMultiplier) {
        this->source = source;
        this->initialPartitionSize = initialPartitionSize;
        this->partitionMultiplier = partitionMultiplier;
    }
    
    template<class T>
    System::Collections::Generic::IList2<System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>*>* EnumerablePartitioner<T>::GetOrderablePartitions_abc13b50067e2c56(int32_t partitionCount) {
        if((partitionCount <= 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("partitionCount"));
        }
        cli::array<System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>*> *enumerators = (new cli::array<System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>*>(partitionCount));
        PartitionerState<T> *state = cli::gcnew<PartitionerState<T>>();
        System::Collections::Generic::IEnumerator2<T> *src = this->source->GetEnumerator_ad4887f30f9e4c5();
        bool isSimple = ((this->initialPartitionSize ==  1) && (this->partitionMultiplier ==  1));
        for(int32_t i = 0; (i < enumerators->get_Length()); i++){
            enumerators->at(i) = isSimple ? GetPartitionEnumeratorSimple(src, state, (i ==  (enumerators->get_Length() - 1))) : GetPartitionEnumerator(src, state);
        }
        return enumerators;
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>* EnumerablePartitioner<T>::GetPartitionEnumeratorSimple(System::Collections::Generic::IEnumerator2<T>* src, PartitionerState<T>* state, bool last) {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>* EnumerablePartitioner<T>::GetPartitionEnumerator(System::Collections::Generic::IEnumerator2<T>* src, PartitionerState<T>* state) {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
}}}}
 namespace System { namespace Collections { namespace Concurrent { namespace Partitioners {
    
    template<class T>
    void Range<T>::constructor(int32_t frm, int32_t lastIndex) {
        this->Actual = frm;
        this->LastIndex = lastIndex;
    }
    
}}}}
 namespace System { namespace Collections { namespace Concurrent { namespace Partitioners {
    
    template<class T>
    void ListPartitioner<T>::constructor(System::Collections::Generic::IList2<T>* source) {
        this->source = source;
    }
    
    template<class T>
    System::Collections::Generic::IList2<System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>*>* ListPartitioner<T>::GetOrderablePartitions_abc13b50067e2c56(int32_t partitionCount) {
        if((partitionCount <= 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("partitionCount"));
        }
        cli::array<System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>*> *enumerators = (new cli::array<System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>*>(partitionCount));
        int32_t count = (this->source->get_Count_a9c25d5c244affb9() / partitionCount);
        int32_t extra = 0;
        if((this->source->get_Count_a9c25d5c244affb9() < partitionCount)) 
        {
            count = 1;
        }
         else 
        {
            extra = (this->source->get_Count_a9c25d5c244affb9() % partitionCount);
            if((extra > 0)) 
            {
                ++count;
            }
        }
        int32_t currentIndex = 0;
        cli::array<Range<T>*> *ranges = (new cli::array<Range<T>*>(enumerators->get_Length()));
        for(int32_t i = 0; (i < ranges->get_Length()); i++){
            ranges->at(i) = cli::gcnew<Range<T>>(currentIndex, (currentIndex + count));
            (currentIndex = currentIndex + count);
            if((--extra ==  0)) 
            {
                --count;
            }
        }
        for(int32_t i = 0; (i < enumerators->get_Length()); i++){
            enumerators->at(i) = GetEnumeratorForRange(ranges, i);
        }
        return enumerators;
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>* ListPartitioner<T>::GetEnumeratorForRange(cli::array<Range<T>*>* ranges, int32_t workerIndex) {
        if((ranges->at(workerIndex)->Actual >= this->source->get_Count_a9c25d5c244affb9())) 
        {
            return GetEmpty();
        }
        return GetEnumeratorForRangeInternal(ranges, workerIndex);
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>* ListPartitioner<T>::GetEmpty() {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<System::Collections::Generic::KeyValuePair<int64_t, T>>* ListPartitioner<T>::GetEnumeratorForRangeInternal(cli::array<Range<T>*>* ranges, int32_t workerIndex) {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
}}}}
 namespace System { namespace Collections { namespace Concurrent { namespace Partitioners {
    
}}}}
 namespace System { namespace Collections { namespace Concurrent { namespace Partitioners {
    
}}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class T>
    void CollectionDebuggerView2<T>::constructor(ICollection2<T>* col) {
        this->c = col;
    }
    
    template<class T>
    cli::array<T>* CollectionDebuggerView2<T>::get_Items() {
        cli::array<T> *o = (new cli::array<T>(this->c->get_Count_a9c25d5c244affb9()));
        this->c->CopyTo_e6884c04285bc976(o, 0);
        return o;
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class T, class U>
    void CollectionDebuggerView3<T, U>::constructor(ICollection2<KeyValuePair<T, U>>* col) {
        this->c = col;
    }
    
    template<class T, class U>
    cli::array<KeyValuePair<T, U>>* CollectionDebuggerView3<T, U>::get_Items() {
        cli::array<KeyValuePair<T, U>> *o = (new cli::array<KeyValuePair<T, U>>(this->c->get_Count_a9c25d5c244affb9()));
        this->c->CopyTo_e6884c04285bc976(o, 0);
        return o;
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class T>
    void DefaultComparer<T>::constructor() {
    }
    
    template<class T>
    int32_t DefaultComparer<T>::Compare_1b044eff3abea0d9(T x, T y) {
        if((cli::box(x) ==  nullptr)) 
        {
            return (cli::box(y) ==  nullptr) ? 0 : -1;
        }
         else 
        {
            if((cli::box(y) ==  nullptr)) 
            {
                return 1;
            }
        }
        if(cli::is<System::IComparable2<T>>(cli::box<System::IComparable2<T>*>(x))) 
        {
            return cli::cast<System::IComparable2<T>*>(x)->CompareTo_8a8b7d6c83beb422(y);
        }
         else 
        {
            if(cli::is<System::IComparable>(cli::box<System::IComparable*>(x))) 
            {
                return cli::cast<System::IComparable*>(x)->CompareTo_ed9d39205b7812f0(cli::box(y));
            }
             else 
            {
                throw cli::gcnew<System::ArgumentException>(_T("does not implement right interface"));
            }
        }
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class T>
    Comparer2<T>::Comparer2()
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
    
    template<class T>
    void Comparer2<T>::constructor() {
    }
    
    template<class T>
    void Comparer2<T>::static_constructor() {
    }
    
    template<class T>
    int32_t Comparer2<T>::Compare2(System::Object* x, System::Object* y) {
        if((x ==  nullptr)) 
        {
            return (y ==  nullptr) ? 0 : -1;
        }
        if((y ==  nullptr)) 
        {
            return 1;
        }
        if((cli::is<T>(x) && cli::is<T>(y))) 
        {
            return Compare_1b044eff3abea0d9(cli::unbox<T>(x), cli::unbox<T>(y));
        }
        throw cli::gcnew<System::ArgumentException>();
    }
    
    template<class T>
    Comparer2<T>* Comparer2<T>::get_Default() {
        return Comparer2<T>::_default;
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class T>
    void GenericComparer<T>::constructor() {
    }
    
    template<class T>
    int32_t GenericComparer<T>::Compare_1b044eff3abea0d9(T x, T y) {
        if((cli::box(x) ==  nullptr)) 
        {
            return (cli::box(y) ==  nullptr) ? 0 : -1;
        }
         else 
        {
            if((cli::box(y) ==  nullptr)) 
            {
                return 1;
            }
        }
        return cli::import(x)->CompareTo_8a8b7d6c83beb422(y);
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class TKey, class TValue>
    void ShimEnumerator<TKey, TValue>::constructor(Dictionary<TKey, TValue>* host) {
        this->host_enumerator = host->GetEnumerator4();
    }
    
    template<class TKey, class TValue>
    void ShimEnumerator<TKey, TValue>::Dispose() {
        this->host_enumerator->Dispose();
    }
    
    template<class TKey, class TValue>
    bool ShimEnumerator<TKey, TValue>::MoveNext() {
        return this->host_enumerator->MoveNext();
    }
    
    template<class TKey, class TValue>
    void ShimEnumerator<TKey, TValue>::Reset() {
        this->host_enumerator->Reset2();
    }
    
    template<class TKey, class TValue>
    System::Collections::DictionaryEntry ShimEnumerator<TKey, TValue>::get_Entry() {
        return cli::box<System::Collections::IDictionaryEnumerator*>(this->host_enumerator)->get_Entry_7d036eca1ef8d5f4();
    }
    
    template<class TKey, class TValue>
    System::Object* ShimEnumerator<TKey, TValue>::get_Key() {
        return cli::box(this->host_enumerator->get_Current()->get_Key());
    }
    
    template<class TKey, class TValue>
    System::Object* ShimEnumerator<TKey, TValue>::get_Value() {
        return cli::box(this->host_enumerator->get_Current()->get_Value());
    }
    
    template<class TKey, class TValue>
    System::Object* ShimEnumerator<TKey, TValue>::get_Current() {
        return cli::box(this->get_Entry());
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class TKey, class TValue>
    void KeyCollection<TKey, TValue>::constructor(Dictionary<TKey, TValue>* dictionary) {
        if((dictionary ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("dictionary"));
        }
        this->dictionary = dictionary;
    }
    
    template<class TKey, class TValue>
    void KeyCollection<TKey, TValue>::CopyTo(cli::array<TKey>* array, int32_t index) {
        this->dictionary->CopyToCheck(array, index);
        this->dictionary->CopyKeys(array, index);
    }
    
    template<class TKey, class TValue>
    Enumerator5<TKey, TValue> KeyCollection<TKey, TValue>::GetEnumerator() {
        return cli::ctor<Enumerator5<TKey, TValue>>(this->dictionary);
    }
    
    template<class TKey, class TValue>
    void KeyCollection<TKey, TValue>::Add(TKey item) {
        throw cli::gcnew<System::NotSupportedException>(_T("this is a read-only collection"));
    }
    
    template<class TKey, class TValue>
    void KeyCollection<TKey, TValue>::Clear() {
        throw cli::gcnew<System::NotSupportedException>(_T("this is a read-only collection"));
    }
    
    template<class TKey, class TValue>
    bool KeyCollection<TKey, TValue>::Contains(TKey item) {
        return this->dictionary->ContainsKey(item);
    }
    
    template<class TKey, class TValue>
    bool KeyCollection<TKey, TValue>::Remove(TKey item) {
        throw cli::gcnew<System::NotSupportedException>(_T("this is a read-only collection"));
    }
    
    template<class TKey, class TValue>
    IEnumerator2<TKey>* KeyCollection<TKey, TValue>::GetEnumerator2() {
        return cli::box<IEnumerator2<TKey>*>(this->GetEnumerator());
    }
    
    template<class TKey, class TValue>
    void KeyCollection<TKey, TValue>::CopyTo2(System::Array* array, int32_t index) {
        cli::array<TKey> *target = cli::as<cli::array<TKey>*>(array);
        if((target != nullptr)) 
        {
            CopyTo(target, index);
            return;
        }
        this->dictionary->CopyToCheck(array, index);
        this->dictionary->template Do_ICollectionCopyTo_1<TKey>(array, index, cli::bind(&Dictionary<TKey, TValue>::pick_key));
    }
    
    template<class TKey, class TValue>
    System::Collections::IEnumerator* KeyCollection<TKey, TValue>::GetEnumerator3() {
        return cli::box<System::Collections::IEnumerator*>(this->GetEnumerator());
    }
    
    template<class TKey, class TValue>
    int32_t KeyCollection<TKey, TValue>::get_Count() {
        return this->dictionary->get_Count();
    }
    
    template<class TKey, class TValue>
    bool KeyCollection<TKey, TValue>::get_IsReadOnly() {
        return true;
    }
    
    template<class TKey, class TValue>
    bool KeyCollection<TKey, TValue>::get_IsSynchronized() {
        return false;
    }
    
    template<class TKey, class TValue>
    System::Object* KeyCollection<TKey, TValue>::get_SyncRoot() {
        return cli::cast<System::Collections::ICollection*>(this->dictionary)->get_SyncRoot_257108f45cc89e19();
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class TKey, class TValue>
    void ValueCollection<TKey, TValue>::constructor(Dictionary<TKey, TValue>* dictionary) {
        if((dictionary ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("dictionary"));
        }
        this->dictionary = dictionary;
    }
    
    template<class TKey, class TValue>
    void ValueCollection<TKey, TValue>::CopyTo(cli::array<TValue>* array, int32_t index) {
        this->dictionary->CopyToCheck(array, index);
        this->dictionary->CopyValues(array, index);
    }
    
    template<class TKey, class TValue>
    Enumerator6<TKey, TValue> ValueCollection<TKey, TValue>::GetEnumerator() {
        return cli::ctor<Enumerator6<TKey, TValue>>(this->dictionary);
    }
    
    template<class TKey, class TValue>
    void ValueCollection<TKey, TValue>::Add(TValue item) {
        throw cli::gcnew<System::NotSupportedException>(_T("this is a read-only collection"));
    }
    
    template<class TKey, class TValue>
    void ValueCollection<TKey, TValue>::Clear() {
        throw cli::gcnew<System::NotSupportedException>(_T("this is a read-only collection"));
    }
    
    template<class TKey, class TValue>
    bool ValueCollection<TKey, TValue>::Contains(TValue item) {
        return this->dictionary->ContainsValue(item);
    }
    
    template<class TKey, class TValue>
    bool ValueCollection<TKey, TValue>::Remove(TValue item) {
        throw cli::gcnew<System::NotSupportedException>(_T("this is a read-only collection"));
    }
    
    template<class TKey, class TValue>
    IEnumerator2<TValue>* ValueCollection<TKey, TValue>::GetEnumerator2() {
        return cli::box<IEnumerator2<TValue>*>(this->GetEnumerator());
    }
    
    template<class TKey, class TValue>
    void ValueCollection<TKey, TValue>::CopyTo2(System::Array* array, int32_t index) {
        cli::array<TValue> *target = cli::as<cli::array<TValue>*>(array);
        if((target != nullptr)) 
        {
            CopyTo(target, index);
            return;
        }
        this->dictionary->CopyToCheck(array, index);
        this->dictionary->template Do_ICollectionCopyTo_1<TValue>(array, index, cli::bind(&Dictionary<TKey, TValue>::pick_value));
    }
    
    template<class TKey, class TValue>
    System::Collections::IEnumerator* ValueCollection<TKey, TValue>::GetEnumerator3() {
        return cli::box<System::Collections::IEnumerator*>(this->GetEnumerator());
    }
    
    template<class TKey, class TValue>
    int32_t ValueCollection<TKey, TValue>::get_Count() {
        return this->dictionary->get_Count();
    }
    
    template<class TKey, class TValue>
    bool ValueCollection<TKey, TValue>::get_IsReadOnly() {
        return true;
    }
    
    template<class TKey, class TValue>
    bool ValueCollection<TKey, TValue>::get_IsSynchronized() {
        return false;
    }
    
    template<class TKey, class TValue>
    System::Object* ValueCollection<TKey, TValue>::get_SyncRoot() {
        return cli::cast<System::Collections::ICollection*>(this->dictionary)->get_SyncRoot_257108f45cc89e19();
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::constructor() {
        Init(10, nullptr);
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::constructor(IEqualityComparer2<TKey>* comparer) {
        Init(10, comparer);
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::constructor(IDictionary2<TKey, TValue>* dictionary) {
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::constructor(int32_t capacity) {
        Init(capacity, nullptr);
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::constructor(IDictionary2<TKey, TValue>* dictionary, IEqualityComparer2<TKey>* comparer) {
        if((dictionary ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("dictionary"));
        }
        int32_t capacity = dictionary->get_Count_a9c25d5c244affb9();
        Init(capacity, comparer);
        for(auto tmp_17 : dictionary) {
            auto entry = cli::cast<KeyValuePair<TKey, TValue>>(tmp_17);
            this->Add(entry->get_Key(), entry->get_Value());
        }
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::constructor(int32_t capacity, IEqualityComparer2<TKey>* comparer) {
        Init(capacity, comparer);
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::constructor(System::Runtime::Serialization::SerializationInfo* info, System::Runtime::Serialization::StreamingContext context) {
        this->serialization_info = info;
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Init(int32_t capacity, IEqualityComparer2<TKey>* hcp) {
        if((capacity < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("capacity"));
        }
        this->hcp = (hcp != nullptr) ? hcp : EqualityComparer<TKey>::get_Default();
        if((capacity ==  0)) 
        {
            capacity = 10;
        }
        capacity = ((int32_t)((float)(capacity) / 0.9f) + 1);
        InitArrays(capacity);
        this->generation = 0;
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::InitArrays(int32_t size) {
        this->table = (new cli::array<int32_t>(size));
        this->linkSlots = (new cli::array<Link>(size));
        this->emptySlot = -1;
        this->keySlots = (new cli::array<TKey>(size));
        this->valueSlots = (new cli::array<TValue>(size));
        this->touchedSlots = 0;
        this->threshold = (int32_t)((float)(this->table->get_Length()) * 0.9f);
        if(((this->threshold ==  0) && (this->table->get_Length() > 0))) 
        {
            this->threshold = 1;
        }
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::CopyToCheck(System::Array* array, int32_t index) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("array"));
        }
        if((index < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("index"));
        }
        if((index > array->get_Length())) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("index larger than largest valid index of array"));
        }
        if(((array->get_Length() - index) < this->get_Count())) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("Destination array cannot hold the requested elements!"));
        }
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::CopyKeys(cli::array<TKey>* array, int32_t index) {
        for(int32_t i = 0; (i < this->touchedSlots); i++){
            if(((this->linkSlots->at(i)->HashCode & -2147483648) != 0)) 
            {
                array->at(index++) = this->keySlots->at(i);
            }
        }
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::CopyValues(cli::array<TValue>* array, int32_t index) {
        for(int32_t i = 0; (i < this->touchedSlots); i++){
            if(((this->linkSlots->at(i)->HashCode & -2147483648) != 0)) 
            {
                array->at(index++) = this->valueSlots->at(i);
            }
        }
    }
    
    template<class TKey, class TValue>
    KeyValuePair<TKey, TValue> Dictionary<TKey, TValue>::make_pair(TKey key, TValue value) {
        return cli::ctor<KeyValuePair<TKey, TValue>>(key, value);
    }
    
    template<class TKey, class TValue>
    TKey Dictionary<TKey, TValue>::pick_key(TKey key, TValue value) {
        return key;
    }
    
    template<class TKey, class TValue>
    TValue Dictionary<TKey, TValue>::pick_value(TKey key, TValue value) {
        return value;
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::CopyTo(cli::array<KeyValuePair<TKey, TValue>>* array, int32_t index) {
        CopyToCheck(array, index);
        for(int32_t i = 0; (i < this->touchedSlots); i++){
            if(((this->linkSlots->at(i)->HashCode & -2147483648) != 0)) 
            {
                array->at(index++) = cli::ctor<KeyValuePair<TKey, TValue>>(this->keySlots->at(i), this->valueSlots->at(i));
            }
        }
    }
    
    template<class TKey, class TValue>
    template<class TRet>
    void Dictionary<TKey, TValue>::Do_ICollectionCopyTo_1(System::Array* array, int32_t index, Transform<TKey, TValue, TRet>* transform) {
        System::Type *src = cli::typeof<System::Type>::info;
        System::Type *tgt = array->GetType()->GetElementType_ab5070dbbfe66f5f();
        try {
            if(((src->get_IsPrimitive() || tgt->get_IsPrimitive()) && !(tgt->IsAssignableFrom_e3aa32d778e63a90(src)))) 
            {
                throw cli::gcnew<System::Exception>();
            }
            cli::array<System::Object*> *dest = cli::cast<cli::array<System::Object*>*>(array);
            for(int32_t i = 0; (i < this->touchedSlots); i++){
                if(((this->linkSlots->at(i)->HashCode & -2147483648) != 0)) 
                {
                    dest->at(index++) = cli::box(transform->Invoke(this->keySlots->at(i), this->valueSlots->at(i)));
                }
            }
        }
        catch(System::Exception* e) {
            throw cli::gcnew<System::ArgumentException>(_T("Cannot copy source collection elements to destination array"), _T("array"), e);
        }
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Resize() {
        int32_t newSize = System::Collections::Hashtable::ToPrime(((this->table->get_Length() << 1) | 1));
        cli::array<int32_t> *newTable = (new cli::array<int32_t>(newSize));
        cli::array<Link> *newLinkSlots = (new cli::array<Link>(newSize));
        for(int32_t i = 0; (i < this->table->get_Length()); i++){
            int32_t cur = (this->table->at(i) - 1);
            while((cur != -1)) {
                int32_t hashCode = newLinkSlots->at(cur)->HashCode = (this->hcp->GetHashCode_74f46a6b01295dbe(this->keySlots->at(cur)) | -2147483648);
                int32_t index = ((hashCode & 2147483647) % newSize);
                newLinkSlots->at(cur)->Next = (newTable->at(index) - 1);
                newTable->at(index) = (cur + 1);
                cur = this->linkSlots->at(cur)->Next;
            }
        }
        this->table = newTable;
        this->linkSlots = newLinkSlots;
        cli::array<TKey> *newKeySlots = (new cli::array<TKey>(newSize));
        cli::array<TValue> *newValueSlots = (new cli::array<TValue>(newSize));
        System::Array::Copy2(this->keySlots, 0, newKeySlots, 0, this->touchedSlots);
        System::Array::Copy2(this->valueSlots, 0, newValueSlots, 0, this->touchedSlots);
        this->keySlots = newKeySlots;
        this->valueSlots = newValueSlots;
        this->threshold = (int32_t)((float)(newSize) * 0.9f);
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Add(TKey key, TValue value) {
        if((cli::box(key) ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("key"));
        }
        int32_t hashCode = (this->hcp->GetHashCode_74f46a6b01295dbe(key) | -2147483648);
        int32_t index = ((hashCode & 2147483647) % this->table->get_Length());
        int32_t cur = (this->table->at(index) - 1);
        while((cur != -1)) {
            if(((this->linkSlots->at(cur)->HashCode ==  hashCode) && this->hcp->Equals_f783e5e22b72a1c0(this->keySlots->at(cur), key))) 
            {
                throw cli::gcnew<System::ArgumentException>(_T("An element with the same key already exists in the dictionary."));
            }
            cur = this->linkSlots->at(cur)->Next;
        }
        if((++this->count > this->threshold)) 
        {
            Resize();
            index = ((hashCode & 2147483647) % this->table->get_Length());
        }
        cur = this->emptySlot;
        if((cur ==  -1)) 
        {
            cur = this->touchedSlots++;
        }
         else 
        {
            this->emptySlot = this->linkSlots->at(cur)->Next;
        }
        this->linkSlots->at(cur)->HashCode = hashCode;
        this->linkSlots->at(cur)->Next = (this->table->at(index) - 1);
        this->table->at(index) = (cur + 1);
        this->keySlots->at(cur) = key;
        this->valueSlots->at(cur) = value;
        this->generation++;
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Clear() {
        this->count = 0;
        System::Array::Clear2(this->table, 0, this->table->get_Length());
        System::Array::Clear2(this->keySlots, 0, this->keySlots->get_Length());
        System::Array::Clear2(this->valueSlots, 0, this->valueSlots->get_Length());
        System::Array::Clear2(this->linkSlots, 0, this->linkSlots->get_Length());
        this->emptySlot = -1;
        this->touchedSlots = 0;
        this->generation++;
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::ContainsKey(TKey key) {
        if((cli::box(key) ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("key"));
        }
        int32_t hashCode = (this->hcp->GetHashCode_74f46a6b01295dbe(key) | -2147483648);
        int32_t cur = (this->table->at(((hashCode & 2147483647) % this->table->get_Length())) - 1);
        while((cur != -1)) {
            if(((this->linkSlots->at(cur)->HashCode ==  hashCode) && this->hcp->Equals_f783e5e22b72a1c0(this->keySlots->at(cur), key))) 
            {
                return true;
            }
            cur = this->linkSlots->at(cur)->Next;
        }
        return false;
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::ContainsValue(TValue value) {
        IEqualityComparer2<TValue> *cmp = EqualityComparer<TValue>::get_Default();
        for(int32_t i = 0; (i < this->table->get_Length()); i++){
            int32_t cur = (this->table->at(i) - 1);
            while((cur != -1)) {
                if(cmp->Equals_f783e5e22b72a1c0(this->valueSlots->at(cur), value)) 
                {
                    return true;
                }
                cur = this->linkSlots->at(cur)->Next;
            }
        }
        return false;
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::GetObjectData_15c552da9e393b6(System::Runtime::Serialization::SerializationInfo* info, System::Runtime::Serialization::StreamingContext context) {
        if((info ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("info"));
        }
        info->AddValue4(_T("Version"), this->generation);
        info->AddValue16(_T("Comparer"), this->hcp);
        cli::array<KeyValuePair<TKey, TValue>> *data = (new cli::array<KeyValuePair<TKey, TValue>>(this->count));
        if((this->count > 0)) 
        {
            CopyTo(data, 0);
        }
        info->AddValue4(_T("HashSize"), this->table->get_Length());
        info->AddValue16(_T("KeyValuePairs"), data);
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::OnDeserialization_b298596fbc47c46f(System::Object* sender) {
        if((this->serialization_info ==  nullptr)) 
        {
            return;
        }
        int32_t hashSize = 0;
        cli::array<KeyValuePair<TKey, TValue>> *data = nullptr;
        System::Runtime::Serialization::SerializationInfoEnumerator *e = this->serialization_info->GetEnumerator();
        while(e->MoveNext()) {
            System::String* tmp_18 = e->get_Name();
            ::System::Int32 tmp_19 = -1;
            if(::System::String::Equals3(tmp_18, _T("Version"))) tmp_19 = 0;
            if(::System::String::Equals3(tmp_18, _T("Comparer"))) tmp_19 = 1;
            if(::System::String::Equals3(tmp_18, _T("HashSize"))) tmp_19 = 2;
            if(::System::String::Equals3(tmp_18, _T("KeyValuePairs"))) tmp_19 = 3;
            switch(tmp_19)
            {
                case 0: case_40: 
                {
                    this->generation = cli::unbox<int32_t>(e->get_Value());
                    break;
                }
                case 1: case_41: 
                {
                    this->hcp = cli::cast<IEqualityComparer2<TKey>*>(e->get_Value());
                    break;
                }
                case 2: case_42: 
                {
                    hashSize = cli::unbox<int32_t>(e->get_Value());
                    break;
                }
                case 3: case_43: 
                {
                    data = cli::cast<cli::array<KeyValuePair<TKey, TValue>>*>(e->get_Value());
                    break;
                }
            }
        }
        if((this->hcp ==  nullptr)) 
        {
            this->hcp = EqualityComparer<TKey>::get_Default();
        }
        if((hashSize < 10)) 
        {
            hashSize = 10;
        }
        InitArrays(hashSize);
        this->count = 0;
        if((data != nullptr)) 
        {
            for(int32_t i = 0; (i < data->get_Length()); ++i) {
                Add(data->at(i)->get_Key(), data->at(i)->get_Value());
            }
        }
        this->generation++;
        this->serialization_info = nullptr;
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::Remove(TKey key) {
        if((cli::box(key) ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("key"));
        }
        int32_t hashCode = (this->hcp->GetHashCode_74f46a6b01295dbe(key) | -2147483648);
        int32_t index = ((hashCode & 2147483647) % this->table->get_Length());
        int32_t cur = (this->table->at(index) - 1);
        if((cur ==  -1)) 
        {
            return false;
        }
        int32_t prev = -1;
        do {
            if(((this->linkSlots->at(cur)->HashCode ==  hashCode) && this->hcp->Equals_f783e5e22b72a1c0(this->keySlots->at(cur), key))) 
            {
                break;
            }
            prev = cur;
            cur = this->linkSlots->at(cur)->Next;
        }
        while((cur != -1));
        if((cur ==  -1)) 
        {
            return false;
        }
        this->count--;
        if((prev ==  -1)) 
        {
            this->table->at(index) = (this->linkSlots->at(cur)->Next + 1);
        }
         else 
        {
            this->linkSlots->at(prev)->Next = this->linkSlots->at(cur)->Next;
        }
        this->linkSlots->at(cur)->Next = this->emptySlot;
        this->emptySlot = cur;
        this->linkSlots->at(cur)->HashCode = 0;
        this->keySlots->at(cur) = TKey();
        this->valueSlots->at(cur) = TValue();
        this->generation++;
        return true;
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::TryGetValue(TKey key, TValue value) {
        if((cli::box(key) ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("key"));
        }
        int32_t hashCode = (this->hcp->GetHashCode_74f46a6b01295dbe(key) | -2147483648);
        int32_t cur = (this->table->at(((hashCode & 2147483647) % this->table->get_Length())) - 1);
        while((cur != -1)) {
            if(((this->linkSlots->at(cur)->HashCode ==  hashCode) && this->hcp->Equals_f783e5e22b72a1c0(this->keySlots->at(cur), key))) 
            {
                value = this->valueSlots->at(cur);
                return true;
            }
            cur = this->linkSlots->at(cur)->Next;
        }
        value = TValue();
        return false;
    }
    
    template<class TKey, class TValue>
    TKey Dictionary<TKey, TValue>::ToTKey(System::Object* key) {
        if((key ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("key"));
        }
        if(!(cli::is<TKey>(key))) 
        {
            throw cli::gcnew<System::ArgumentException>(cli::concat(_T("not of type: "), cli::typeof<System::Type>::info->ToString_1636a0751cb9ac11()), _T("key"));
        }
        return cli::unbox<TKey>(key);
    }
    
    template<class TKey, class TValue>
    TValue Dictionary<TKey, TValue>::ToTValue(System::Object* value) {
        if(((value ==  nullptr) && !(cli::typeof<System::Type>::info->get_IsValueType()))) 
        {
            return TValue();
        }
        if(!(cli::is<TValue>(value))) 
        {
            throw cli::gcnew<System::ArgumentException>(cli::concat(_T("not of type: "), cli::typeof<System::Type>::info->ToString_1636a0751cb9ac11()), _T("value"));
        }
        return cli::unbox<TValue>(value);
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Add2(System::Object* key, System::Object* value) {
        this->Add(ToTKey(key), ToTValue(value));
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::Contains(System::Object* key) {
        if((key ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("key"));
        }
        if(cli::is<TKey>(key)) 
        {
            return ContainsKey(cli::unbox<TKey>(key));
        }
        return false;
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Remove2(System::Object* key) {
        if((key ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("key"));
        }
        if(cli::is<TKey>(key)) 
        {
            Remove(cli::unbox<TKey>(key));
        }
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::Add3(KeyValuePair<TKey, TValue> keyValuePair) {
        Add(keyValuePair->get_Key(), keyValuePair->get_Value());
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::Contains2(KeyValuePair<TKey, TValue> keyValuePair) {
        return ContainsKeyValuePair(keyValuePair);
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::CopyTo2(cli::array<KeyValuePair<TKey, TValue>>* array, int32_t index) {
        this->CopyTo(array, index);
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::Remove3(KeyValuePair<TKey, TValue> keyValuePair) {
        if(!(ContainsKeyValuePair(keyValuePair))) 
        {
            return false;
        }
        return Remove(keyValuePair->get_Key());
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::ContainsKeyValuePair(KeyValuePair<TKey, TValue> pair) {
        TValue value;
        if(!(TryGetValue(pair->get_Key(), value))) 
        {
            return false;
        }
        return EqualityComparer<TValue>::get_Default()->Equals_e786aaeef5b10ff2(pair->get_Value(), value);
    }
    
    template<class TKey, class TValue>
    void Dictionary<TKey, TValue>::CopyTo3(System::Array* array, int32_t index) {
        cli::array<KeyValuePair<TKey, TValue>> *pairs = cli::as<cli::array<KeyValuePair<TKey, TValue>>*>(array);
        if((pairs != nullptr)) 
        {
            this->CopyTo(pairs, index);
            return;
        }
        CopyToCheck(array, index);
        cli::array<System::Collections::DictionaryEntry> *entries = cli::as<cli::array<System::Collections::DictionaryEntry>*>(array);
        if((entries != nullptr)) 
        {
            for(int32_t i = 0; (i < this->touchedSlots); i++){
                if(((this->linkSlots->at(i)->HashCode & -2147483648) != 0)) 
                {
                    entries->at(index++) = cli::ctor<System::Collections::DictionaryEntry>(cli::box(this->keySlots->at(i)), cli::box(this->valueSlots->at(i)));
                }
            }
            return;
        }
        Do_ICollectionCopyTo_1<KeyValuePair<TKey, TValue>>(array, index, cli::bind(&Dictionary<TKey, TValue>::make_pair));
    }
    
    template<class TKey, class TValue>
    System::Collections::IEnumerator* Dictionary<TKey, TValue>::GetEnumerator() {
        return cli::box<System::Collections::IEnumerator*>(cli::ctor<Enumerator4<TKey, TValue>>(this));
    }
    
    template<class TKey, class TValue>
    IEnumerator2<KeyValuePair<TKey, TValue>>* Dictionary<TKey, TValue>::GetEnumerator2() {
        return cli::box<IEnumerator2<KeyValuePair<TKey, TValue>>*>(cli::ctor<Enumerator4<TKey, TValue>>(this));
    }
    
    template<class TKey, class TValue>
    System::Collections::IDictionaryEnumerator* Dictionary<TKey, TValue>::GetEnumerator3() {
        return cli::gcnew<ShimEnumerator<TKey, TValue>>(this);
    }
    
    template<class TKey, class TValue>
    Enumerator4<TKey, TValue> Dictionary<TKey, TValue>::GetEnumerator4() {
        return cli::ctor<Enumerator4<TKey, TValue>>(this);
    }
    
    template<class TKey, class TValue>
    int32_t Dictionary<TKey, TValue>::get_Count() {
        return this->count;
    }
    
    template<class TKey, class TValue>
    TValue Dictionary<TKey, TValue>::get_Item(TKey key) {
        if((cli::box(key) ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("key"));
        }
        int32_t hashCode = (this->hcp->GetHashCode_74f46a6b01295dbe(key) | -2147483648);
        int32_t cur = (this->table->at(((hashCode & 2147483647) % this->table->get_Length())) - 1);
        while((cur != -1)) {
            if(((this->linkSlots->at(cur)->HashCode ==  hashCode) && this->hcp->Equals_f783e5e22b72a1c0(this->keySlots->at(cur), key))) 
            {
                return this->valueSlots->at(cur);
            }
            cur = this->linkSlots->at(cur)->Next;
        }
        throw cli::gcnew<KeyNotFoundException>();
    }
    
    template<class TKey, class TValue>
    TValue Dictionary<TKey, TValue>::set_Item(TKey key, TValue value) {
        if((cli::box(key) ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("key"));
        }
        int32_t hashCode = (this->hcp->GetHashCode_74f46a6b01295dbe(key) | -2147483648);
        int32_t index = ((hashCode & 2147483647) % this->table->get_Length());
        int32_t cur = (this->table->at(index) - 1);
        int32_t prev = -1;
        if((cur != -1)) 
        {
            do {
                if(((this->linkSlots->at(cur)->HashCode ==  hashCode) && this->hcp->Equals_f783e5e22b72a1c0(this->keySlots->at(cur), key))) 
                {
                    break;
                }
                prev = cur;
                cur = this->linkSlots->at(cur)->Next;
            }
            while((cur != -1));
        }
        if((cur ==  -1)) 
        {
            if((++this->count > this->threshold)) 
            {
                Resize();
                index = ((hashCode & 2147483647) % this->table->get_Length());
            }
            cur = this->emptySlot;
            if((cur ==  -1)) 
            {
                cur = this->touchedSlots++;
            }
             else 
            {
                this->emptySlot = this->linkSlots->at(cur)->Next;
            }
            this->linkSlots->at(cur)->Next = (this->table->at(index) - 1);
            this->table->at(index) = (cur + 1);
            this->linkSlots->at(cur)->HashCode = hashCode;
            this->keySlots->at(cur) = key;
        }
         else 
        {
            if((prev != -1)) 
            {
                this->linkSlots->at(prev)->Next = this->linkSlots->at(cur)->Next;
                this->linkSlots->at(cur)->Next = (this->table->at(index) - 1);
                this->table->at(index) = (cur + 1);
            }
        }
        this->valueSlots->at(cur) = value;
        this->generation++;
        return get_Item(key);
    }
    
    template<class TKey, class TValue>
    IEqualityComparer2<TKey>* Dictionary<TKey, TValue>::get_Comparer() {
        return this->hcp;
    }
    
    template<class TKey, class TValue>
    ICollection2<TKey>* Dictionary<TKey, TValue>::get_Keys() {
        return this->get_Keys2();
    }
    
    template<class TKey, class TValue>
    ICollection2<TValue>* Dictionary<TKey, TValue>::get_Values() {
        return this->get_Values2();
    }
    
    template<class TKey, class TValue>
    KeyCollection<TKey, TValue>* Dictionary<TKey, TValue>::get_Keys2() {
        return cli::gcnew<KeyCollection<TKey, TValue>>(this);
    }
    
    template<class TKey, class TValue>
    ValueCollection<TKey, TValue>* Dictionary<TKey, TValue>::get_Values2() {
        return cli::gcnew<ValueCollection<TKey, TValue>>(this);
    }
    
    template<class TKey, class TValue>
    System::Collections::ICollection* Dictionary<TKey, TValue>::get_Keys3() {
        return this->get_Keys2();
    }
    
    template<class TKey, class TValue>
    System::Collections::ICollection* Dictionary<TKey, TValue>::get_Values3() {
        return this->get_Values2();
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::get_IsFixedSize() {
        return false;
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::get_IsReadOnly() {
        return false;
    }
    
    template<class TKey, class TValue>
    System::Object* Dictionary<TKey, TValue>::get_Item2(System::Object* key) {
        if((cli::is<TKey>(key) && ContainsKey(cli::unbox<TKey>(key)))) 
        {
            return cli::box(this->get_Item(ToTKey(key)));
        }
        return nullptr;
    }
    
    template<class TKey, class TValue>
    System::Object* Dictionary<TKey, TValue>::set_Item2(System::Object* key, System::Object* value) {
        this->set_Item(ToTKey(key), ToTValue(value));
        return get_Item2(key);
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::get_IsSynchronized() {
        return false;
    }
    
    template<class TKey, class TValue>
    System::Object* Dictionary<TKey, TValue>::get_SyncRoot() {
        return this;
    }
    
    template<class TKey, class TValue>
    bool Dictionary<TKey, TValue>::get_IsReadOnly2() {
        return false;
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class T>
    void DefaultComparer2<T>::constructor() {
    }
    
    template<class T>
    int32_t DefaultComparer2<T>::GetHashCode_f61694b39bec824d(T obj) {
        if((cli::box(obj) ==  nullptr)) 
        {
            return 0;
        }
        return cli::import(obj)->GetHashCode_6648aef0f235ee6c();
    }
    
    template<class T>
    bool DefaultComparer2<T>::Equals_e786aaeef5b10ff2(T x, T y) {
        if((cli::box(x) ==  nullptr)) 
        {
            return (cli::box(y) ==  nullptr);
        }
        return cli::import(x)->Equals_ed975d2f4a7d193e(cli::box(y));
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class T>
    EqualityComparer<T>::EqualityComparer()
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
    
    template<class T>
    void EqualityComparer<T>::static_constructor() {
        if(System::Type::op_Equality2(cli::typeof<System::Type>::info, cli::typeof<System::Type>::info)) 
        {
            EqualityComparer<T>::_default = cli::cast<EqualityComparer<T>*>(cli::cast<System::Object*>(cli::gcnew<InternalStringComparer>()));
            return;
        }
        if(cli::typeof<System::Type>::info->IsAssignableFrom_e3aa32d778e63a90(cli::typeof<System::Type>::info)) 
        {
            EqualityComparer<T>::_default = cli::cast<EqualityComparer<T>*>(System::Activator::CreateInstance8(cli::typeof<System::Type>::info->MakeGenericType_da11ef776ac96678((new cli::array<System::Type*>({cli::typeof<System::Type>::info})))));
        }
         else 
        {
            EqualityComparer<T>::_default = cli::gcnew<DefaultComparer2<T>>();
        }
    }
    
    template<class T>
    void EqualityComparer<T>::constructor() {
    }
    
    template<class T>
    int32_t EqualityComparer<T>::GetHashCode3(System::Object* obj) {
        if((obj ==  nullptr)) 
        {
            return 0;
        }
        if(!(cli::is<T>(obj))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("Argument is not compatible"), _T("obj"));
        }
        return GetHashCode_f61694b39bec824d(cli::unbox<T>(obj));
    }
    
    template<class T>
    bool EqualityComparer<T>::Equals4(System::Object* x, System::Object* y) {
        if((x ==  y)) 
        {
            return true;
        }
        if(((x ==  nullptr) || (y ==  nullptr))) 
        {
            return false;
        }
        if(!(cli::is<T>(x))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("Argument is not compatible"), _T("x"));
        }
        if(!(cli::is<T>(y))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("Argument is not compatible"), _T("y"));
        }
        return Equals_e786aaeef5b10ff2(cli::unbox<T>(x), cli::unbox<T>(y));
    }
    
    template<class T>
    EqualityComparer<T>* EqualityComparer<T>::get_Default() {
        return EqualityComparer<T>::_default;
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class T>
    void GenericEqualityComparer<T>::constructor() {
    }
    
    template<class T>
    int32_t GenericEqualityComparer<T>::GetHashCode_f61694b39bec824d(T obj) {
        if((cli::box(obj) ==  nullptr)) 
        {
            return 0;
        }
        return cli::import(obj)->GetHashCode_6648aef0f235ee6c();
    }
    
    template<class T>
    bool GenericEqualityComparer<T>::Equals_e786aaeef5b10ff2(T x, T y) {
        if((cli::box(x) ==  nullptr)) 
        {
            return (cli::box(y) ==  nullptr);
        }
        return cli::import(x)->Equals_ea48fd0c13a733fe(y);
    }
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
}}}
 namespace System { namespace Collections { namespace Generic {
    
    template<class T>
    List<T>::List()
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
    
    template<class T>
    void List<T>::constructor() {
        this->_items = List<T>::EmptyArray;
    }
    
    template<class T>
    void List<T>::constructor(IEnumerable2<T>* collection) {
        if((collection ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("collection"));
        }
        ICollection2<T> *c = cli::as<ICollection2<T>*>(collection);
        if((c ==  nullptr)) 
        {
            this->_items = List<T>::EmptyArray;
            AddEnumerable(collection);
        }
         else 
        {
            this->_size = c->get_Count_a9c25d5c244affb9();
            this->_items = (new cli::array<T>(System::Math::Max5(this->_size, 4)));
            c->CopyTo_e6884c04285bc976(this->_items, 0);
        }
    }
    
    template<class T>
    void List<T>::constructor(int32_t capacity) {
        if((capacity < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("capacity"));
        }
        this->_items = (new cli::array<T>(capacity));
    }
    
    template<class T>
    void List<T>::constructor(cli::array<T>* data, int32_t size) {
        this->_items = data;
        this->_size = size;
    }
    
    template<class T>
    void List<T>::static_constructor() {
    }
    
    template<class T>
    void List<T>::Add(T item) {
        if((this->_size ==  this->_items->get_Length())) 
        {
            GrowIfNeeded(1);
        }
        this->_items->at(this->_size++) = item;
        this->_version++;
    }
    
    template<class T>
    void List<T>::GrowIfNeeded(int32_t newCount) {
        int32_t minimumSize = (this->_size + newCount);
        if((minimumSize > this->_items->get_Length())) 
        {
            this->set_Capacity(System::Math::Max5(System::Math::Max5((this->get_Capacity() * 2), 4), minimumSize));
        }
    }
    
    template<class T>
    void List<T>::CheckRange(int32_t idx, int32_t count) {
        if((idx < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("index"));
        }
        if((count < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("count"));
        }
        if((((uint32_t)idx + (uint32_t)count) > (uint32_t)this->_size)) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("index and count exceed length of list"));
        }
    }
    
    template<class T>
    void List<T>::AddCollection(ICollection2<T>* collection) {
        int32_t collectionCount = collection->get_Count_a9c25d5c244affb9();
        if((collectionCount ==  0)) 
        {
            return;
        }
        GrowIfNeeded(collectionCount);
        collection->CopyTo_e6884c04285bc976(this->_items, this->_size);
        (this->_size = this->_size + collectionCount);
    }
    
    template<class T>
    void List<T>::AddEnumerable(IEnumerable2<T>* enumerable) {
        for(auto tmp_20 : enumerable) {
            auto t = cli::cast<T>(tmp_20);
            {
                Add(t);
            }
        }
    }
    
    template<class T>
    void List<T>::AddRange(IEnumerable2<T>* collection) {
        if((collection ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("collection"));
        }
        ICollection2<T> *c = cli::as<ICollection2<T>*>(collection);
        if((c != nullptr)) 
        {
            AddCollection(c);
        }
         else 
        {
            AddEnumerable(collection);
        }
        this->_version++;
    }
    
    template<class T>
    System::Collections::ObjectModel::ReadOnlyCollection<T>* List<T>::AsReadOnly() {
        return cli::gcnew<System::Collections::ObjectModel::ReadOnlyCollection<T>>(this);
    }
    
    template<class T>
    int32_t List<T>::BinarySearch(T item) {
        return System::Array::template BinarySearch_13<T>(this->_items, 0, this->_size, item);
    }
    
    template<class T>
    int32_t List<T>::BinarySearch2(T item, IComparer2<T>* comparer) {
        return System::Array::template BinarySearch_14<T>(this->_items, 0, this->_size, item, comparer);
    }
    
    template<class T>
    int32_t List<T>::BinarySearch3(int32_t index, int32_t count, T item, IComparer2<T>* comparer) {
        CheckRange(index, count);
        return System::Array::template BinarySearch_14<T>(this->_items, index, count, item, comparer);
    }
    
    template<class T>
    void List<T>::Clear() {
        System::Array::Clear2(this->_items, 0, this->_items->get_Length());
        this->_size = 0;
        this->_version++;
    }
    
    template<class T>
    bool List<T>::Contains(T item) {
        return (System::Array::template IndexOf_13<T>(this->_items, item, 0, this->_size) != -1);
    }
    
    template<class T>
    template<class TOutput>
    List<TOutput>* List<T>::ConvertAll_1(System::Converter<T, TOutput>* converter) {
        if((converter ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("converter"));
        }
        List<TOutput> *u = cli::gcnew<List<TOutput>>(this->_size);
        for(int32_t i = 0; (i < this->_size); i++) {
            u->_items->at(i) = converter->Invoke(this->_items->at(i));
        }
        u->_size = this->_size;
        return u;
    }
    
    template<class T>
    void List<T>::CopyTo(cli::array<T>* array) {
        System::Array::Copy2(this->_items, 0, array, 0, this->_size);
    }
    
    template<class T>
    void List<T>::CopyTo2(cli::array<T>* array, int32_t arrayIndex) {
        System::Array::Copy2(this->_items, 0, array, arrayIndex, this->_size);
    }
    
    template<class T>
    void List<T>::CopyTo3(int32_t index, cli::array<T>* array, int32_t arrayIndex, int32_t count) {
        CheckRange(index, count);
        System::Array::Copy2(this->_items, index, array, arrayIndex, count);
    }
    
    template<class T>
    bool List<T>::Exists(System::Predicate<T>* match) {
        CheckMatch(match);
        return (GetIndex(0, this->_size, match) != -1);
    }
    
    template<class T>
    T List<T>::Find(System::Predicate<T>* match) {
        CheckMatch(match);
        int32_t i = GetIndex(0, this->_size, match);
        return (i != -1) ? this->_items->at(i) : T();
    }
    
    template<class T>
    void List<T>::CheckMatch(System::Predicate<T>* match) {
        if((match ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("match"));
        }
    }
    
    template<class T>
    List<T>* List<T>::FindAll(System::Predicate<T>* match) {
        CheckMatch(match);
        if((this->_size <= 65536)) 
        {
            return this->FindAllStackBits(match);
        }
         else 
        {
            return this->FindAllList(match);
        }
    }
    
    template<class T>
    List<T>* List<T>::FindAllStackBits(System::Predicate<T>* match) {
        uint32_t bits[((this->_size / 32) + 1)];
        uint32_t *ptr = bits;
        int32_t found = 0;
        uint32_t bitmask = 2147483648U;
        for(int32_t i = 0; (i < this->_size); i++){
            if(match->Invoke(this->_items->at(i))) 
            {
                (*ptr) = ((*ptr) | bitmask);
                found++;
            }
            bitmask = (bitmask >> 1);
            if((bitmask ==  0U)) 
            {
                ptr++;
                bitmask = 2147483648U;
            }
        }
        cli::array<T> *results = (new cli::array<T>(found));
        bitmask = 2147483648U;
        ptr = bits;
        int32_t j = 0;
        for(int32_t i = 0; ((i < this->_size) && (j < found)); i++){
            if((((*ptr) & bitmask) ==  bitmask)) 
            {
                results->at(j++) = this->_items->at(i);
            }
            bitmask = (bitmask >> 1);
            if((bitmask ==  0U)) 
            {
                ptr++;
                bitmask = 2147483648U;
            }
        }
        return cli::gcnew<List<T>>(results, found);
    }
    
    template<class T>
    List<T>* List<T>::FindAllList(System::Predicate<T>* match) {
        List<T> *results = cli::gcnew<List<T>>();
        for(int32_t i = 0; (i < this->_size); i++) {
            if(match->Invoke(this->_items->at(i))) 
            {
                results->Add(this->_items->at(i));
            }
        }
        return results;
    }
    
    template<class T>
    int32_t List<T>::FindIndex(System::Predicate<T>* match) {
        CheckMatch(match);
        return GetIndex(0, this->_size, match);
    }
    
    template<class T>
    int32_t List<T>::FindIndex2(int32_t startIndex, System::Predicate<T>* match) {
        CheckMatch(match);
        CheckIndex(startIndex);
        return GetIndex(startIndex, (this->_size - startIndex), match);
    }
    
    template<class T>
    int32_t List<T>::FindIndex3(int32_t startIndex, int32_t count, System::Predicate<T>* match) {
        CheckMatch(match);
        CheckRange(startIndex, count);
        return GetIndex(startIndex, count, match);
    }
    
    template<class T>
    int32_t List<T>::GetIndex(int32_t startIndex, int32_t count, System::Predicate<T>* match) {
        int32_t end = (startIndex + count);
        for(int32_t i = startIndex; (i < end); i++) {
            if(match->Invoke(this->_items->at(i))) 
            {
                return i;
            }
        }
        return -1;
    }
    
    template<class T>
    T List<T>::FindLast(System::Predicate<T>* match) {
        CheckMatch(match);
        int32_t i = GetLastIndex(0, this->_size, match);
        return (i ==  -1) ? T() : this->get_Item(i);
    }
    
    template<class T>
    int32_t List<T>::FindLastIndex(System::Predicate<T>* match) {
        CheckMatch(match);
        return GetLastIndex(0, this->_size, match);
    }
    
    template<class T>
    int32_t List<T>::FindLastIndex2(int32_t startIndex, System::Predicate<T>* match) {
        CheckMatch(match);
        CheckIndex(startIndex);
        return GetLastIndex(0, (startIndex + 1), match);
    }
    
    template<class T>
    int32_t List<T>::FindLastIndex3(int32_t startIndex, int32_t count, System::Predicate<T>* match) {
        CheckMatch(match);
        int32_t start = ((startIndex - count) + 1);
        CheckRange(start, count);
        return GetLastIndex(start, count, match);
    }
    
    template<class T>
    int32_t List<T>::GetLastIndex(int32_t startIndex, int32_t count, System::Predicate<T>* match) {
        for(int32_t i = (startIndex + count); (i != startIndex); ) {
            if(match->Invoke(this->_items->at(--i))) 
            {
                return i;
            }
        }
        return -1;
    }
    
    template<class T>
    void List<T>::ForEach(System::Action2<T>* action) {
        if((action ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("action"));
        }
        for(int32_t i = 0; (i < this->_size); i++) {
            action->Invoke(this->_items->at(i));
        }
    }
    
    template<class T>
    Enumerator7<T> List<T>::GetEnumerator() {
        return cli::ctor<Enumerator7<T>>(this);
    }
    
    template<class T>
    List<T>* List<T>::GetRange(int32_t index, int32_t count) {
        CheckRange(index, count);
        cli::array<T> *tmpArray = (new cli::array<T>(count));
        System::Array::Copy2(this->_items, index, tmpArray, 0, count);
        return cli::gcnew<List<T>>(tmpArray, count);
    }
    
    template<class T>
    int32_t List<T>::IndexOf(T item) {
        return System::Array::template IndexOf_13<T>(this->_items, item, 0, this->_size);
    }
    
    template<class T>
    int32_t List<T>::IndexOf2(T item, int32_t index) {
        CheckIndex(index);
        return System::Array::template IndexOf_13<T>(this->_items, item, index, (this->_size - index));
    }
    
    template<class T>
    int32_t List<T>::IndexOf3(T item, int32_t index, int32_t count) {
        if((index < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("index"));
        }
        if((count < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("count"));
        }
        if((((uint32_t)index + (uint32_t)count) > (uint32_t)this->_size)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("index and count exceed length of list"));
        }
        return System::Array::template IndexOf_13<T>(this->_items, item, index, count);
    }
    
    template<class T>
    void List<T>::Shift(int32_t start, int32_t delta) {
        if((delta < 0)) 
        {
            (start = start - delta);
        }
        if((start < this->_size)) 
        {
            System::Array::Copy2(this->_items, start, this->_items, (start + delta), (this->_size - start));
        }
        (this->_size = this->_size + delta);
        if((delta < 0)) 
        {
            System::Array::Clear2(this->_items, this->_size, -(delta));
        }
    }
    
    template<class T>
    void List<T>::CheckIndex(int32_t index) {
        if(((index < 0) || ((uint32_t)index > (uint32_t)this->_size))) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("index"));
        }
    }
    
    template<class T>
    void List<T>::Insert(int32_t index, T item) {
        CheckIndex(index);
        if((this->_size ==  this->_items->get_Length())) 
        {
            GrowIfNeeded(1);
        }
        Shift(index, 1);
        this->_items->at(index) = item;
        this->_version++;
    }
    
    template<class T>
    void List<T>::InsertRange(int32_t index, IEnumerable2<T>* collection) {
        if((collection ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("collection"));
        }
        CheckIndex(index);
        if((collection ==  this)) 
        {
            cli::array<T> *buffer = (new cli::array<T>(this->_size));
            CopyTo2(buffer, 0);
            GrowIfNeeded(this->_size);
            Shift(index, buffer->get_Length());
            System::Array::Copy2(buffer, 0, this->_items, index, buffer->get_Length());
        }
         else 
        {
            ICollection2<T> *c = cli::as<ICollection2<T>*>(collection);
            if((c != nullptr)) 
            {
                InsertCollection(index, c);
            }
             else 
            {
                InsertEnumeration(index, collection);
            }
        }
        this->_version++;
    }
    
    template<class T>
    void List<T>::InsertCollection(int32_t index, ICollection2<T>* collection) {
        int32_t collectionCount = collection->get_Count_a9c25d5c244affb9();
        GrowIfNeeded(collectionCount);
        Shift(index, collectionCount);
        collection->CopyTo_e6884c04285bc976(this->_items, index);
    }
    
    template<class T>
    void List<T>::InsertEnumeration(int32_t index, IEnumerable2<T>* enumerable) {
        for(auto tmp_21 : enumerable) {
            auto t = cli::cast<T>(tmp_21);
            Insert(index++, t);
        }
    }
    
    template<class T>
    int32_t List<T>::LastIndexOf(T item) {
        if((this->_size ==  0)) 
        {
            return -1;
        }
        return System::Array::template LastIndexOf_13<T>(this->_items, item, (this->_size - 1), this->_size);
    }
    
    template<class T>
    int32_t List<T>::LastIndexOf2(T item, int32_t index) {
        CheckIndex(index);
        return System::Array::template LastIndexOf_13<T>(this->_items, item, index, (index + 1));
    }
    
    template<class T>
    int32_t List<T>::LastIndexOf3(T item, int32_t index, int32_t count) {
        if((index < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("index"), cli::box(index), _T("index is negative"));
        }
        if((count < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("count"), cli::box(count), _T("count is negative"));
        }
        if((((index - count) + 1) < 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("cound"), cli::box(count), _T("count is too large"));
        }
        return System::Array::template LastIndexOf_13<T>(this->_items, item, index, count);
    }
    
    template<class T>
    bool List<T>::Remove(T item) {
        int32_t loc = IndexOf(item);
        if((loc != -1)) 
        {
            RemoveAt(loc);
        }
        return (loc != -1);
    }
    
    template<class T>
    int32_t List<T>::RemoveAll(System::Predicate<T>* match) {
        CheckMatch(match);
        int32_t i = 0;
        int32_t j = 0;
        for(i = 0; (i < this->_size); i++) {
            if(match->Invoke(this->_items->at(i))) 
            {
                break;
            }
        }
        if((i ==  this->_size)) 
        {
            return 0;
        }
        this->_version++;
        for(j = (i + 1); (j < this->_size); j++){
            if(!(match->Invoke(this->_items->at(j)))) 
            {
                this->_items->at(i++) = this->_items->at(j);
            }
        }
        if(((j - i) > 0)) 
        {
            System::Array::Clear2(this->_items, i, (j - i));
        }
        this->_size = i;
        return (j - i);
    }
    
    template<class T>
    void List<T>::RemoveAt(int32_t index) {
        if(((index < 0) || ((uint32_t)index >= (uint32_t)this->_size))) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("index"));
        }
        Shift(index, -1);
        System::Array::Clear2(this->_items, this->_size, 1);
        this->_version++;
    }
    
    template<class T>
    void List<T>::RemoveRange(int32_t index, int32_t count) {
        CheckRange(index, count);
        if((count > 0)) 
        {
            Shift(index, -(count));
            System::Array::Clear2(this->_items, this->_size, count);
            this->_version++;
        }
    }
    
    template<class T>
    void List<T>::Reverse() {
        System::Array::Reverse2(this->_items, 0, this->_size);
        this->_version++;
    }
    
    template<class T>
    void List<T>::Reverse2(int32_t index, int32_t count) {
        CheckRange(index, count);
        System::Array::Reverse2(this->_items, index, count);
        this->_version++;
    }
    
    template<class T>
    void List<T>::Sort() {
        System::Array::template Sort_13<T>(this->_items, 0, this->_size);
        this->_version++;
    }
    
    template<class T>
    void List<T>::Sort2(IComparer2<T>* comparer) {
        System::Array::template Sort_14<T>(this->_items, 0, this->_size, comparer);
        this->_version++;
    }
    
    template<class T>
    void List<T>::Sort3(System::Comparison<T>* comparison) {
        if((comparison ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("comparison"));
        }
        System::Array::template SortImpl_12<T>(this->_items, this->_size, comparison);
        this->_version++;
    }
    
    template<class T>
    void List<T>::Sort4(int32_t index, int32_t count, IComparer2<T>* comparer) {
        CheckRange(index, count);
        System::Array::template Sort_14<T>(this->_items, index, count, comparer);
        this->_version++;
    }
    
    template<class T>
    cli::array<T>* List<T>::ToArray() {
        cli::array<T> *t = (new cli::array<T>(this->_size));
        System::Array::Copy(this->_items, t, this->_size);
        return t;
    }
    
    template<class T>
    void List<T>::TrimExcess() {
        this->set_Capacity(this->_size);
    }
    
    template<class T>
    bool List<T>::TrueForAll(System::Predicate<T>* match) {
        CheckMatch(match);
        for(int32_t i = 0; (i < this->_size); i++) {
            if(!(match->Invoke(this->_items->at(i)))) 
            {
                return false;
            }
        }
        return true;
    }
    
    template<class T>
    IEnumerator2<T>* List<T>::GetEnumerator2() {
        return cli::box<IEnumerator2<T>*>(GetEnumerator());
    }
    
    template<class T>
    void List<T>::CopyTo4(System::Array* array, int32_t arrayIndex) {
        if((array ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("array"));
        }
        if(((array->get_Rank() > 1) || (array->GetLowerBound(0) != 0))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("Array must be zero based and single dimentional"), _T("array"));
        }
        System::Array::Copy2(this->_items, 0, array, arrayIndex, this->_size);
    }
    
    template<class T>
    System::Collections::IEnumerator* List<T>::GetEnumerator3() {
        return cli::box<System::Collections::IEnumerator*>(GetEnumerator());
    }
    
    template<class T>
    int32_t List<T>::Add2(System::Object* item) {
        try {
            Add(cli::unbox<T>(item));
            return (this->_size - 1);
        }
        catch(System::NullReferenceException*) {
        }
        catch(System::InvalidCastException*) {
        }
        throw cli::gcnew<System::ArgumentException>(_T("item"));
    }
    
    template<class T>
    bool List<T>::Contains2(System::Object* item) {
        try {
            return Contains(cli::unbox<T>(item));
        }
        catch(System::NullReferenceException*) {
        }
        catch(System::InvalidCastException*) {
        }
        return false;
    }
    
    template<class T>
    int32_t List<T>::IndexOf4(System::Object* item) {
        try {
            return IndexOf(cli::unbox<T>(item));
        }
        catch(System::NullReferenceException*) {
        }
        catch(System::InvalidCastException*) {
        }
        return -1;
    }
    
    template<class T>
    void List<T>::Insert2(int32_t index, System::Object* item) {
        CheckIndex(index);
        try {
            Insert(index, cli::unbox<T>(item));
            return;
        }
        catch(System::NullReferenceException*) {
        }
        catch(System::InvalidCastException*) {
        }
        throw cli::gcnew<System::ArgumentException>(_T("item"));
    }
    
    template<class T>
    void List<T>::Remove2(System::Object* item) {
        try {
            Remove(cli::unbox<T>(item));
            return;
        }
        catch(System::NullReferenceException*) {
        }
        catch(System::InvalidCastException*) {
        }
    }
    
    template<class T>
    int32_t List<T>::get_Capacity() {
        return this->_items->get_Length();
    }
    
    template<class T>
    int32_t List<T>::set_Capacity(int32_t value) {
        if(((uint32_t)value < (uint32_t)this->_size)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>();
        }
        System::Array::template Resize_1<T>(this->_items, value);
        return get_Capacity();
    }
    
    template<class T>
    int32_t List<T>::get_Count() {
        return this->_size;
    }
    
    template<class T>
    T List<T>::get_Item(int32_t index) {
        if(((uint32_t)index >= (uint32_t)this->_size)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("index"));
        }
        return this->_items->at(index);
    }
    
    template<class T>
    T List<T>::set_Item(int32_t index, T value) {
        CheckIndex(index);
        if(((uint32_t)index ==  (uint32_t)this->_size)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("index"));
        }
        this->_items->at(index) = value;
        this->_version++;
        return get_Item(index);
    }
    
    template<class T>
    bool List<T>::get_IsReadOnly() {
        return false;
    }
    
    template<class T>
    bool List<T>::get_IsSynchronized() {
        return false;
    }
    
    template<class T>
    System::Object* List<T>::get_SyncRoot() {
        return this;
    }
    
    template<class T>
    bool List<T>::get_IsFixedSize() {
        return false;
    }
    
    template<class T>
    bool List<T>::get_IsReadOnly2() {
        return false;
    }
    
    template<class T>
    System::Object* List<T>::get_Item2(int32_t index) {
        return cli::box(this->get_Item(index));
    }
    
    template<class T>
    System::Object* List<T>::set_Item2(int32_t index, System::Object* value) {
        try {
            this->set_Item(index, cli::unbox<T>(value));
            return get_Item2(index);
        }
        catch(System::NullReferenceException*) {
        }
        catch(System::InvalidCastException*) {
        }
        throw cli::gcnew<System::ArgumentException>(_T("value"));
        return get_Item2(index);
    }
    
}}}
 namespace System { namespace Collections { namespace ObjectModel {
    
    template<class T>
    void Collection<T>::constructor() {
        System::Collections::Generic::List<T> *l = cli::gcnew<System::Collections::Generic::List<T>>();
        System::Collections::IList *l2 = cli::cast<System::Collections::IList*>(l);
        this->syncRoot = l2->get_SyncRoot_257108f45cc89e19();
        this->list = l;
    }
    
    template<class T>
    void Collection<T>::constructor(System::Collections::Generic::IList2<T>* list) {
        if((list ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("list"));
        }
        this->list = list;
        System::Collections::ICollection *l = cli::as<System::Collections::ICollection*>(list);
        this->syncRoot = (l != nullptr) ? l->get_SyncRoot_257108f45cc89e19() : cli::gcnew<System::Object>();
    }
    
    template<class T>
    void Collection<T>::Add(T item) {
        int32_t idx = this->list->get_Count_a9c25d5c244affb9();
        InsertItem_30de9292a784d6bb(idx, item);
    }
    
    template<class T>
    void Collection<T>::Clear() {
        ClearItems_2bead28bfee60c73();
    }
    
    template<class T>
    void Collection<T>::ClearItems_2bead28bfee60c73() {
        this->list->Clear_16ef3c35b14f77a2();
    }
    
    template<class T>
    bool Collection<T>::Contains(T item) {
        return this->list->Contains_ca946a648e63e62e(item);
    }
    
    template<class T>
    void Collection<T>::CopyTo(cli::array<T>* array, int32_t index) {
        this->list->CopyTo_e6884c04285bc976(array, index);
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* Collection<T>::GetEnumerator() {
        return this->list->GetEnumerator_ad4887f30f9e4c5();
    }
    
    template<class T>
    int32_t Collection<T>::IndexOf(T item) {
        return this->list->IndexOf_9e82d7c34bb82d25(item);
    }
    
    template<class T>
    void Collection<T>::Insert(int32_t index, T item) {
        InsertItem_30de9292a784d6bb(index, item);
    }
    
    template<class T>
    void Collection<T>::InsertItem_30de9292a784d6bb(int32_t index, T item) {
        this->list->Insert_d9ae15974e481e9e(index, item);
    }
    
    template<class T>
    bool Collection<T>::Remove(T item) {
        int32_t idx = IndexOf(item);
        if((idx ==  -1)) 
        {
            return false;
        }
        RemoveItem_7622edc394af89c9(idx);
        return true;
    }
    
    template<class T>
    void Collection<T>::RemoveAt(int32_t index) {
        RemoveItem_7622edc394af89c9(index);
    }
    
    template<class T>
    void Collection<T>::RemoveItem_7622edc394af89c9(int32_t index) {
        this->list->RemoveAt_92d07238fa433d4a(index);
    }
    
    template<class T>
    void Collection<T>::SetItem_a7062d77a0b1825b(int32_t index, T item) {
        this->list->set_Item_13ad50de181a1c01(index, item);
    }
    
    template<class T>
    bool Collection<T>::IsValidItem(System::Object* item) {
        return (cli::is<T>(item) || ((item ==  nullptr) && !(cli::typeof<System::Type>::info->get_IsValueType())));
    }
    
    template<class T>
    T Collection<T>::ConvertItem(System::Object* item) {
        if(IsValidItem(item)) 
        {
            return cli::unbox<T>(item);
        }
        throw cli::gcnew<System::ArgumentException>(_T("item"));
    }
    
    template<class T>
    void Collection<T>::CheckWritable(System::Collections::Generic::IList2<T>* list) {
        if(list->get_IsReadOnly_9569eb0bb1daa9b5()) 
        {
            throw cli::gcnew<System::NotSupportedException>();
        }
    }
    
    template<class T>
    bool Collection<T>::IsSynchronized(System::Collections::Generic::IList2<T>* list) {
        System::Collections::ICollection *c = cli::as<System::Collections::ICollection*>(list);
        return (c != nullptr) ? c->get_IsSynchronized_20926e7dabc53dbf() : false;
    }
    
    template<class T>
    bool Collection<T>::IsFixedSize(System::Collections::Generic::IList2<T>* list) {
        System::Collections::IList *l = cli::as<System::Collections::IList*>(list);
        return (l != nullptr) ? l->get_IsFixedSize_4d3eaee3435ee591() : false;
    }
    
    template<class T>
    void Collection<T>::CopyTo2(System::Array* array, int32_t index) {
        cli::cast<System::Collections::ICollection*>(this->list)->CopyTo_7065a6e3cf6a140(array, index);
    }
    
    template<class T>
    System::Collections::IEnumerator* Collection<T>::GetEnumerator2() {
        return cli::cast<System::Collections::IEnumerator*>(this->list->GetEnumerator_ad4887f30f9e4c5());
    }
    
    template<class T>
    int32_t Collection<T>::Add2(System::Object* value) {
        int32_t idx = this->list->get_Count_a9c25d5c244affb9();
        InsertItem_30de9292a784d6bb(idx, ConvertItem(value));
        return idx;
    }
    
    template<class T>
    bool Collection<T>::Contains2(System::Object* value) {
        if(IsValidItem(value)) 
        {
            return this->list->Contains_ca946a648e63e62e(cli::unbox<T>(value));
        }
        return false;
    }
    
    template<class T>
    int32_t Collection<T>::IndexOf2(System::Object* value) {
        if(IsValidItem(value)) 
        {
            return this->list->IndexOf_9e82d7c34bb82d25(cli::unbox<T>(value));
        }
        return -1;
    }
    
    template<class T>
    void Collection<T>::Insert2(int32_t index, System::Object* value) {
        InsertItem_30de9292a784d6bb(index, ConvertItem(value));
    }
    
    template<class T>
    void Collection<T>::Remove2(System::Object* value) {
        CheckWritable(this->list);
        int32_t idx = IndexOf(ConvertItem(value));
        RemoveItem_7622edc394af89c9(idx);
    }
    
    template<class T>
    System::Collections::Generic::IList2<T>* Collection<T>::get_Items() {
        return this->list;
    }
    
    template<class T>
    int32_t Collection<T>::get_Count() {
        return this->list->get_Count_a9c25d5c244affb9();
    }
    
    template<class T>
    T Collection<T>::get_Item(int32_t index) {
        return this->list->get_Item_e6c1a54cb8f591e7(index);
    }
    
    template<class T>
    T Collection<T>::set_Item(int32_t index, T value) {
        SetItem_a7062d77a0b1825b(index, value);
        return get_Item(index);
    }
    
    template<class T>
    bool Collection<T>::get_IsReadOnly() {
        return this->list->get_IsReadOnly_9569eb0bb1daa9b5();
    }
    
    template<class T>
    bool Collection<T>::get_IsSynchronized() {
        return IsSynchronized(this->list);
    }
    
    template<class T>
    System::Object* Collection<T>::get_SyncRoot() {
        return this->syncRoot;
    }
    
    template<class T>
    bool Collection<T>::get_IsFixedSize() {
        return IsFixedSize(this->list);
    }
    
    template<class T>
    bool Collection<T>::get_IsReadOnly2() {
        return this->list->get_IsReadOnly_9569eb0bb1daa9b5();
    }
    
    template<class T>
    System::Object* Collection<T>::get_Item2(int32_t index) {
        return cli::box(this->list->get_Item_e6c1a54cb8f591e7(index));
    }
    
    template<class T>
    System::Object* Collection<T>::set_Item2(int32_t index, System::Object* value) {
        SetItem_a7062d77a0b1825b(index, ConvertItem(value));
        return get_Item2(index);
    }
    
}}}
 namespace System { namespace Collections { namespace ObjectModel {
    
    template<class TKey, class TItem>
    void KeyedCollection<TKey, TItem>::constructor() {
    }
    
    template<class TKey, class TItem>
    void KeyedCollection<TKey, TItem>::constructor(System::Collections::Generic::IEqualityComparer2<TKey>* comparer) {
    }
    
    template<class TKey, class TItem>
    void KeyedCollection<TKey, TItem>::constructor(System::Collections::Generic::IEqualityComparer2<TKey>* comparer, int32_t dictionaryCreationThreshold) {
        if((comparer != nullptr)) 
        {
            this->comparer = comparer;
        }
         else 
        {
            this->comparer = System::Collections::Generic::EqualityComparer<TKey>::get_Default();
        }
        this->dictionaryCreationThreshold = dictionaryCreationThreshold;
        if((dictionaryCreationThreshold ==  0)) 
        {
            this->dictionary = cli::gcnew<System::Collections::Generic::Dictionary<TKey, TItem>>(this->comparer);
        }
    }
    
    template<class TKey, class TItem>
    bool KeyedCollection<TKey, TItem>::Contains3(TKey key) {
        if((this->dictionary != nullptr)) 
        {
            return this->dictionary->ContainsKey(key);
        }
        return (IndexOfKey(key) >= 0);
    }
    
    template<class TKey, class TItem>
    int32_t KeyedCollection<TKey, TItem>::IndexOfKey(TKey key) {
        for(int32_t i = (this->get_Count() - 1); (i >= 0); i--){
            TKey lkey = GetKeyForItem_61f71d2768095475(this->get_Item(i));
            if(this->comparer->Equals_f783e5e22b72a1c0(key, lkey)) 
            {
                return i;
            }
        }
        return -1;
    }
    
    template<class TKey, class TItem>
    bool KeyedCollection<TKey, TItem>::Remove3(TKey key) {
        TItem item;
        if((this->dictionary != nullptr)) 
        {
            if(this->dictionary->TryGetValue(key, item)) 
            {
                return Collection<TItem>::Remove(item);
            }
             else 
            {
                return false;
            }
        }
        int32_t idx = IndexOfKey(key);
        if((idx ==  -1)) 
        {
            return false;
        }
        Collection<TItem>::RemoveAt(idx);
        return true;
    }
    
    template<class TKey, class TItem>
    void KeyedCollection<TKey, TItem>::ChangeItemKey(TItem item, TKey newKey) {
        if(!(Collection<TItem>::Contains(item))) 
        {
            throw cli::gcnew<System::ArgumentException>();
        }
        TKey oldKey = GetKeyForItem_61f71d2768095475(item);
        if(this->comparer->Equals_f783e5e22b72a1c0(oldKey, newKey)) 
        {
            return;
        }
        if(Contains3(newKey)) 
        {
            throw cli::gcnew<System::ArgumentException>();
        }
        if((this->dictionary != nullptr)) 
        {
            if(!(this->dictionary->Remove(oldKey))) 
            {
                throw cli::gcnew<System::ArgumentException>();
            }
            this->dictionary->Add(newKey, item);
        }
    }
    
    template<class TKey, class TItem>
    void KeyedCollection<TKey, TItem>::ClearItems_2bead28bfee60c73() {
        if((this->dictionary != nullptr)) 
        {
            this->dictionary->Clear();
        }
        Collection<TItem>::ClearItems_2bead28bfee60c73();
    }
    
    template<class TKey, class TItem>
    void KeyedCollection<TKey, TItem>::InsertItem_30de9292a784d6bb(int32_t index, TItem item) {
        TKey key = GetKeyForItem_61f71d2768095475(item);
        if((cli::box(key) ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("GetKeyForItem(item)"));
        }
        if(((this->dictionary != nullptr) && this->dictionary->ContainsKey(key))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("An element with the same key already exists in the dictionary."));
        }
        if((this->dictionary ==  nullptr)) 
        for(int32_t i = 0; (i < this->get_Count()); ++i){
            if(this->comparer->Equals_f783e5e22b72a1c0(key, GetKeyForItem_61f71d2768095475(this->get_Item(i)))) 
            {
                throw cli::gcnew<System::ArgumentException>(_T("An element with the same key already exists in the dictionary."));
            }
        }
        Collection<TItem>::InsertItem_30de9292a784d6bb(index, item);
        if((this->dictionary != nullptr)) 
        {
            this->dictionary->Add(key, item);
        }
         else 
        {
            if(((this->dictionaryCreationThreshold != -1) && (this->get_Count() > this->dictionaryCreationThreshold))) 
            {
                this->dictionary = cli::gcnew<System::Collections::Generic::Dictionary<TKey, TItem>>(this->comparer);
                for(int32_t i = 0; (i < this->get_Count()); ++i){
                    TItem dictitem = this->get_Item(i);
                    this->dictionary->Add(GetKeyForItem_61f71d2768095475(dictitem), dictitem);
                }
            }
        }
    }
    
    template<class TKey, class TItem>
    void KeyedCollection<TKey, TItem>::RemoveItem_7622edc394af89c9(int32_t index) {
        if((this->dictionary != nullptr)) 
        {
            TKey key = GetKeyForItem_61f71d2768095475(this->get_Item(index));
            this->dictionary->Remove(key);
        }
        Collection<TItem>::RemoveItem_7622edc394af89c9(index);
    }
    
    template<class TKey, class TItem>
    void KeyedCollection<TKey, TItem>::SetItem_a7062d77a0b1825b(int32_t index, TItem item) {
        if((this->dictionary != nullptr)) 
        {
            this->dictionary->Remove(GetKeyForItem_61f71d2768095475(this->get_Item(index)));
            this->dictionary->Add(GetKeyForItem_61f71d2768095475(item), item);
        }
        Collection<TItem>::SetItem_a7062d77a0b1825b(index, item);
    }
    
    template<class TKey, class TItem>
    System::Collections::Generic::IEqualityComparer2<TKey>* KeyedCollection<TKey, TItem>::get_Comparer() {
        return this->comparer;
    }
    
    template<class TKey, class TItem>
    TItem KeyedCollection<TKey, TItem>::get_Item3(TKey key) {
        if((this->dictionary != nullptr)) 
        {
            return this->dictionary->get_Item(key);
        }
        int32_t idx = IndexOfKey(key);
        if((idx >= 0)) 
        {
            return Collection<TItem>::get_Item(idx);
        }
         else 
        {
            throw cli::gcnew<System::Collections::Generic::KeyNotFoundException>();
        }
    }
    
    template<class TKey, class TItem>
    System::Collections::Generic::IDictionary2<TKey, TItem>* KeyedCollection<TKey, TItem>::get_Dictionary() {
        return this->dictionary;
    }
    
}}}
 namespace System { namespace Collections { namespace ObjectModel {
    
    template<class T>
    void ReadOnlyCollection<T>::constructor(System::Collections::Generic::IList2<T>* list) {
        if((list ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("list"));
        }
        this->list = list;
    }
    
    template<class T>
    void ReadOnlyCollection<T>::Add(T item) {
        throw cli::gcnew<System::NotSupportedException>();
    }
    
    template<class T>
    void ReadOnlyCollection<T>::Clear() {
        throw cli::gcnew<System::NotSupportedException>();
    }
    
    template<class T>
    bool ReadOnlyCollection<T>::Contains(T value) {
        return this->list->Contains_ca946a648e63e62e(value);
    }
    
    template<class T>
    void ReadOnlyCollection<T>::CopyTo(cli::array<T>* array, int32_t index) {
        this->list->CopyTo_e6884c04285bc976(array, index);
    }
    
    template<class T>
    System::Collections::Generic::IEnumerator2<T>* ReadOnlyCollection<T>::GetEnumerator() {
        return this->list->GetEnumerator_ad4887f30f9e4c5();
    }
    
    template<class T>
    int32_t ReadOnlyCollection<T>::IndexOf(T value) {
        return this->list->IndexOf_9e82d7c34bb82d25(value);
    }
    
    template<class T>
    void ReadOnlyCollection<T>::Insert(int32_t index, T item) {
        throw cli::gcnew<System::NotSupportedException>();
    }
    
    template<class T>
    bool ReadOnlyCollection<T>::Remove(T item) {
        throw cli::gcnew<System::NotSupportedException>();
    }
    
    template<class T>
    void ReadOnlyCollection<T>::RemoveAt(int32_t index) {
        throw cli::gcnew<System::NotSupportedException>();
    }
    
    template<class T>
    void ReadOnlyCollection<T>::CopyTo2(System::Array* array, int32_t index) {
        cli::cast<System::Collections::ICollection*>(this->list)->CopyTo_7065a6e3cf6a140(array, index);
    }
    
    template<class T>
    System::Collections::IEnumerator* ReadOnlyCollection<T>::GetEnumerator2() {
        return cli::cast<System::Collections::IEnumerable*>(this->list)->GetEnumerator_674ad93a972a4d67();
    }
    
    template<class T>
    int32_t ReadOnlyCollection<T>::Add2(System::Object* value) {
        throw cli::gcnew<System::NotSupportedException>();
    }
    
    template<class T>
    void ReadOnlyCollection<T>::Clear2() {
        throw cli::gcnew<System::NotSupportedException>();
    }
    
    template<class T>
    bool ReadOnlyCollection<T>::Contains2(System::Object* value) {
        if(Collection<T>::IsValidItem(value)) 
        {
            return this->list->Contains_ca946a648e63e62e(cli::unbox<T>(value));
        }
        return false;
    }
    
    template<class T>
    int32_t ReadOnlyCollection<T>::IndexOf2(System::Object* value) {
        if(Collection<T>::IsValidItem(value)) 
        {
            return this->list->IndexOf_9e82d7c34bb82d25(cli::unbox<T>(value));
        }
        return -1;
    }
    
    template<class T>
    void ReadOnlyCollection<T>::Insert2(int32_t index, System::Object* value) {
        throw cli::gcnew<System::NotSupportedException>();
    }
    
    template<class T>
    void ReadOnlyCollection<T>::Remove2(System::Object* value) {
        throw cli::gcnew<System::NotSupportedException>();
    }
    
    template<class T>
    void ReadOnlyCollection<T>::RemoveAt2(int32_t index) {
        throw cli::gcnew<System::NotSupportedException>();
    }
    
    template<class T>
    int32_t ReadOnlyCollection<T>::get_Count() {
        return this->list->get_Count_a9c25d5c244affb9();
    }
    
    template<class T>
    System::Collections::Generic::IList2<T>* ReadOnlyCollection<T>::get_Items() {
        return this->list;
    }
    
    template<class T>
    T ReadOnlyCollection<T>::get_Item(int32_t index) {
        return this->list->get_Item_e6c1a54cb8f591e7(index);
    }
    
    template<class T>
    T ReadOnlyCollection<T>::get_Item2(int32_t index) {
        return this->get_Item(index);
    }
    
    template<class T>
    T ReadOnlyCollection<T>::set_Item(int32_t index, T value) {
        throw cli::gcnew<System::NotSupportedException>();
        return get_Item2(index);
    }
    
    template<class T>
    bool ReadOnlyCollection<T>::get_IsReadOnly() {
        return true;
    }
    
    template<class T>
    bool ReadOnlyCollection<T>::get_IsSynchronized() {
        return false;
    }
    
    template<class T>
    System::Object* ReadOnlyCollection<T>::get_SyncRoot() {
        return this;
    }
    
    template<class T>
    bool ReadOnlyCollection<T>::get_IsFixedSize() {
        return true;
    }
    
    template<class T>
    bool ReadOnlyCollection<T>::get_IsReadOnly2() {
        return true;
    }
    
    template<class T>
    System::Object* ReadOnlyCollection<T>::get_Item3(int32_t index) {
        return cli::box(this->list->get_Item_e6c1a54cb8f591e7(index));
    }
    
    template<class T>
    System::Object* ReadOnlyCollection<T>::set_Item2(int32_t index, System::Object* value) {
        throw cli::gcnew<System::NotSupportedException>();
        return get_Item3(index);
    }
    
}}}
 namespace System { namespace Deployment { namespace Internal {
    
}}}
 namespace System { namespace Deployment { namespace Internal {
    
}}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics {
    
}}
 namespace System { namespace Diagnostics { namespace CodeAnalysis {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
    template<class TException>
    void Contract::EnsuresOnThrow_1(bool condition) {
        AssertMustUseRewriter(ContractFailureKind::Postcondition, _T("Contract.EnsuresOnThrow"));
    }
    
    template<class TException>
    void Contract::EnsuresOnThrow_12(bool condition, System::String* userMessage) {
        AssertMustUseRewriter(ContractFailureKind::Postcondition, _T("Contract.EnsuresOnThrow"));
    }
    
    template<class T>
    bool Contract::Exists_1(System::Collections::Generic::IEnumerable2<T>* collection, System::Predicate<T>* predicate) {
        if((predicate ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("predicate"));
        }
        if((collection ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("collection"));
        }
        for(auto tmp_22 : collection) {
            auto t = cli::cast<T>(tmp_22);
            if(predicate->Invoke(t)) 
            {
                return true;
            }
        }
        return false;
    }
    
    template<class T>
    bool Contract::ForAll_1(System::Collections::Generic::IEnumerable2<T>* collection, System::Predicate<T>* predicate) {
        if((predicate ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("predicate"));
        }
        if((collection ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("collection"));
        }
        for(auto tmp_23 : collection) {
            auto t = cli::cast<T>(tmp_23);
            if(!(predicate->Invoke(t))) 
            {
                return false;
            }
        }
        return true;
    }
    
    template<class T>
    T Contract::OldValue_1(T value) {
        return T();
    }
    
    template<class TException>
    void Contract::Requires_1(bool condition) {
        AssertMustUseRewriter(ContractFailureKind::Precondition, _T("Contract.Requires<TException>"));
    }
    
    template<class TException>
    void Contract::Requires_12(bool condition, System::String* userMessage) {
        AssertMustUseRewriter(ContractFailureKind::Precondition, _T("Contract.Requires<TException>"));
    }
    
    template<class T>
    T Contract::Result_1() {
        return T();
    }
    
    template<class T>
    T Contract::ValueAtReturn_1(T value) {
        return value = T();
    }
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts {
    
}}}
 namespace System { namespace Diagnostics { namespace Contracts { namespace Internal {
    
}}}}
 namespace System { namespace Diagnostics { namespace SymbolStore {
    
}}}
 namespace System { namespace Diagnostics { namespace SymbolStore {
    
}}}
 namespace System { namespace Diagnostics { namespace SymbolStore {
    
}}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace Globalization {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO {
    
    template<class T>
    void UnmanagedMemoryAccessor::Read_1(int64_t position, T structure) {
        if(!(this->canread)) 
        {
            throw cli::gcnew<System::NotSupportedException>();
        }
        if((this->buffer ==  nullptr)) 
        {
            throw cli::gcnew<System::ObjectDisposedException>(_T("buffer"));
        }
        if((position < 0L)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>();
        }
        structure = this->buffer->template Read_1<T>((uint64_t)position);
    }
    
    template<class T>
    int32_t UnmanagedMemoryAccessor::ReadArray_1(int64_t position, cli::array<T>* array, int32_t offset, int32_t count) {
        if((position < 0L)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>();
        }
        int64_t left = (this->capacity - position);
        int32_t slots = System::Math::Min5(count, (int32_t)(left / (int64_t)(System::Runtime::InteropServices::Marshal::SizeOf2(cli::typeof<System::Type>::info))));
        this->buffer->template ReadArray_1<T>((uint64_t)position, array, offset, slots);
        return slots;
    }
    
    template<class T>
    void UnmanagedMemoryAccessor::Write_1(int64_t position, T structure) {
        if(!(this->canwrite)) 
        {
            throw cli::gcnew<System::NotSupportedException>();
        }
        if((this->buffer ==  nullptr)) 
        {
            throw cli::gcnew<System::ObjectDisposedException>(_T("buffer"));
        }
        if((position < 0L)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>();
        }
        this->buffer->template Write_1<T>((uint64_t)position, structure);
    }
    
    template<class T>
    void UnmanagedMemoryAccessor::WriteArray_1(int64_t position, cli::array<T>* array, int32_t offset, int32_t count) {
        this->buffer->template WriteArray_1<T>((uint64_t)position, array, offset, count);
    }
    
}}
 namespace System { namespace IO {
    
}}
 namespace System { namespace IO { namespace IsolatedStorage {
    
}}}
 namespace System { namespace IO { namespace IsolatedStorage {
    
}}}
 namespace System { namespace IO { namespace IsolatedStorage {
    
}}}
 namespace System { namespace IO { namespace IsolatedStorage {
    
}}}
 namespace System { namespace IO { namespace IsolatedStorage {
    
}}}
 namespace System { namespace IO { namespace IsolatedStorage {
    
}}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
    template<class T>
    cli::array<T>* CustomAttributeData::UnboxValues_1(cli::array<System::Object*>* values) {
        cli::array<T> *retval = (new cli::array<T>(values->get_Length()));
        for(int32_t i = 0; (i < values->get_Length()); i++) {
            retval->at(i) = cli::unbox<T>(values->at(i));
        }
        return retval;
    }
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
    template<class T, class D>
    void EventInfo::AddEventFrame_2(AddEvent<T, D>* addEvent, System::Object* obj, System::Object* dele) {
        if((obj ==  nullptr)) 
        {
            throw cli::gcnew<TargetException>(_T("Cannot add a handler to a non static event with a null target"));
        }
        if(!(cli::is<T>(obj))) 
        {
            throw cli::gcnew<TargetException>(_T("Object doesn\'t match target"));
        }
        addEvent->Invoke(cli::unbox<T>(obj), cli::unbox<D>(dele));
    }
    
    template<class D>
    void EventInfo::StaticAddEventAdapterFrame_1(StaticAddEvent<D>* addEvent, System::Object* obj, System::Object* dele) {
        addEvent->Invoke(cli::unbox<D>(dele));
    }
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
    template<class T, class R>
    System::Object* MonoProperty::GetterAdapterFrame_2(Getter<T, R>* getter, System::Object* obj) {
        return cli::box(getter->Invoke(cli::unbox<T>(obj)));
    }
    
    template<class R>
    System::Object* MonoProperty::StaticGetterAdapterFrame_1(StaticGetter<R>* getter, System::Object* obj) {
        return cli::box(getter->Invoke());
    }
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection {
    
}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Reflection { namespace Emit {
    
}}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Resources {
    
}}
 namespace System { namespace Runtime {
    
}}
 namespace System { namespace Runtime {
    
}}
 namespace System { namespace Runtime {
    
}}
 namespace System { namespace Runtime {
    
}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
    template<class TKey, class TValue>
    void ConditionalWeakTable<TKey, TValue>::constructor() {
        this->data = (new cli::array<Ephemeron>(13));
        System::GC::register_ephemeron_array(this->data);
    }
    
    template<class TKey, class TValue>
    void ConditionalWeakTable<TKey, TValue>::Rehash() {
        uint32_t newSize = (uint32_t)System::Collections::Hashtable::ToPrime(((this->data->get_Length() << 1) | 1));
        cli::array<Ephemeron> *tmp = (new cli::array<Ephemeron>((int32_t)newSize));
        System::GC::register_ephemeron_array(tmp);
        this->size = 0;
        for(int32_t i = 0; (i < this->data->get_Length()); ++i){
            System::Object *key = this->data->at(i)->key;
            System::Object *value = this->data->at(i)->value;
            if(((key ==  nullptr) || (key ==  System::GC::EPHEMERON_TOMBSTONE))) 
            {
                continue;
            }
            int32_t len = tmp->get_Length();
            int32_t idx, initial_idx;
            int32_t free_slot = -1;
            idx = initial_idx = ((RuntimeHelpers::GetHashCode2(key) & 2147483647) % len);
            do {
                System::Object *k = tmp->at(idx)->key;
                if(((k ==  nullptr) || (k ==  System::GC::EPHEMERON_TOMBSTONE))) 
                {
                    free_slot = idx;
                    break;
                }
                if((++idx ==  len)) 
                {
                    idx = 0;
                }
            }
            while((idx != initial_idx));
            tmp->at(free_slot)->key = key;
            tmp->at(free_slot)->value = value;
            ++this->size;
        }
        this->data = tmp;
    }
    
    template<class TKey, class TValue>
    void ConditionalWeakTable<TKey, TValue>::Add(TKey key, TValue value) {
        if((cli::box(key) ==  cli::box(nullptr))) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("Null key"), _T("key"));
        }
        {
            cli::lock_guard{this->_lock};
            if(((float)(this->size) >= ((float)(this->data->get_Length()) * 0.7f))) 
            {
                Rehash();
            }
            int32_t len = this->data->get_Length();
            int32_t idx, initial_idx;
            int32_t free_slot = -1;
            idx = initial_idx = ((RuntimeHelpers::GetHashCode2(cli::cast<System::Object*>(key)) & 2147483647) % len);
            do {
                System::Object *k = this->data->at(idx)->key;
                if((k ==  nullptr)) 
                {
                    if((free_slot ==  -1)) 
                    {
                        free_slot = idx;
                    }
                    break;
                }
                 else 
                {
                    if(((k ==  System::GC::EPHEMERON_TOMBSTONE) && (free_slot ==  -1))) 
                    {
                        free_slot = idx;
                    }
                     else 
                    {
                        if((k ==  cli::box(key))) 
                        {
                            throw cli::gcnew<System::ArgumentException>(_T("Key already in the list"), _T("key"));
                        }
                    }
                }
                if((++idx ==  len)) 
                {
                    idx = 0;
                }
            }
            while((idx != initial_idx));
            this->data->at(free_slot)->key = cli::cast<System::Object*>(key);
            this->data->at(free_slot)->value = cli::cast<System::Object*>(value);
            ++this->size;
        }
    }
    
    template<class TKey, class TValue>
    bool ConditionalWeakTable<TKey, TValue>::Remove(TKey key) {
        if((cli::box(key) ==  cli::box(nullptr))) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("Null key"), _T("key"));
        }
        {
            cli::lock_guard{this->_lock};
            int32_t len = this->data->get_Length();
            int32_t idx, initial_idx;
            idx = initial_idx = ((RuntimeHelpers::GetHashCode2(cli::cast<System::Object*>(key)) & 2147483647) % len);
            do {
                System::Object *k = this->data->at(idx)->key;
                if((k ==  cli::box(key))) 
                {
                    this->data->at(idx)->key = System::GC::EPHEMERON_TOMBSTONE;
                    this->data->at(idx)->value = nullptr;
                    --this->size;
                    return true;
                }
                if((k ==  nullptr)) 
                {
                    break;
                }
                if((++idx ==  len)) 
                {
                    idx = 0;
                }
            }
            while((idx != initial_idx));
        }
        return false;
    }
    
    template<class TKey, class TValue>
    bool ConditionalWeakTable<TKey, TValue>::TryGetValue(TKey key, TValue value) {
        if((cli::box(key) ==  cli::box(nullptr))) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("Null key"), _T("key"));
        }
        value = nullptr;
        {
            cli::lock_guard{this->_lock};
            int32_t len = this->data->get_Length();
            int32_t idx, initial_idx;
            idx = initial_idx = ((RuntimeHelpers::GetHashCode2(cli::cast<System::Object*>(key)) & 2147483647) % len);
            do {
                System::Object *k = this->data->at(idx)->key;
                if((k ==  cli::box(key))) 
                {
                    value = cli::unbox<TValue>(this->data->at(idx)->value);
                    return true;
                }
                if((k ==  nullptr)) 
                {
                    break;
                }
                if((++idx ==  len)) 
                {
                    idx = 0;
                }
            }
            while((idx != initial_idx));
        }
        return false;
    }
    
    template<class TKey, class TValue>
    TValue ConditionalWeakTable<TKey, TValue>::GetOrCreateValue(TKey key) {
        return GetValue(key, cli::bind([&] (TKey k) -> TValue {
            return System::Activator::template CreateInstance_1<TValue>();
        }
        ));
    }
    
    template<class TKey, class TValue>
    TValue ConditionalWeakTable<TKey, TValue>::GetValue(TKey key, CreateValueCallback<TKey, TValue>* createValueCallback) {
        if((cli::box(key) ==  cli::box(nullptr))) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("Null key"), _T("key"));
        }
        if((createValueCallback ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("Null create delegate"), _T("createValueCallback"));
        }
        TValue res;
        {
            cli::lock_guard{this->_lock};
            if(TryGetValue(key, res)) 
            {
                return res;
            }
            res = createValueCallback->Invoke(key);
            Add(key, res);
        }
        return res;
    }
    
    template<class TKey, class TValue>
    TValue ConditionalWeakTable<TKey, TValue>::_GetOrCreateValue_m__10(TKey k) {
        return System::Activator::template CreateInstance_1<TValue>();
    }
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace CompilerServices {
    
}}}
 namespace System { namespace Runtime { namespace ConstrainedExecution {
    
}}}
 namespace System { namespace Runtime { namespace ConstrainedExecution {
    
}}}
 namespace System { namespace Runtime { namespace ConstrainedExecution {
    
}}}
 namespace System { namespace Runtime { namespace ExceptionServices {
    
}}}
 namespace System { namespace Runtime { namespace ExceptionServices {
    
}}}
 namespace System { namespace Runtime { namespace Hosting {
    
}}}
 namespace System { namespace Runtime { namespace Hosting {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
    template<class T>
    void SafeBuffer::Initialize_1(uint32_t numElements) {
        Initialize2(numElements, (uint32_t)Marshal::SizeOf2(cli::typeof<System::Type>::info));
    }
    
    template<class T>
    T SafeBuffer::Read_1(uint64_t byteOffset) {
        if(!(this->inited)) 
        {
            throw cli::gcnew<System::InvalidOperationException>();
        }
        unsigned char *source = ((unsigned char*)((void*)this->handle) + (uint64_t)(byteOffset));
        if(((source >= this->last_byte) || ((source + (int32_t)(Marshal::SizeOf2(cli::typeof<System::Type>::info))) > this->last_byte))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("byteOffset"));
        }
        return cli::unbox<T>(Marshal::PtrToStructure2((void*)(void*)(source), cli::typeof<System::Type>::info));
    }
    
    template<class T>
    void SafeBuffer::ReadArray_1(uint64_t byteOffset, cli::array<T>* array, int32_t index, int32_t count) {
        if(!(this->inited)) 
        {
            throw cli::gcnew<System::InvalidOperationException>();
        }
        int32_t size = (Marshal::SizeOf2(cli::typeof<System::Type>::info) * count);
        unsigned char *source = ((unsigned char*)((void*)this->handle) + (uint64_t)(byteOffset));
        if(((source >= this->last_byte) || ((source + (int32_t)(size)) > this->last_byte))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("byteOffset"));
        }
        Marshal::copy_from_unmanaged((void*)(void*)(source), index, array, count);
    }
    
    template<class T>
    void SafeBuffer::Write_1(uint64_t byteOffset, T value) {
        if(!(this->inited)) 
        {
            throw cli::gcnew<System::InvalidOperationException>();
        }
        unsigned char *target = ((unsigned char*)((void*)this->handle) + (uint64_t)(byteOffset));
        if(((target >= this->last_byte) || ((target + (int32_t)(Marshal::SizeOf2(cli::typeof<System::Type>::info))) > this->last_byte))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("byteOffset"));
        }
        Marshal::StructureToPtr(cli::box(value), (void*)(void*)(target), false);
    }
    
    template<class T>
    void SafeBuffer::WriteArray_1(uint64_t byteOffset, cli::array<T>* array, int32_t index, int32_t count) {
        if(!(this->inited)) 
        {
            throw cli::gcnew<System::InvalidOperationException>();
        }
        unsigned char *target = ((unsigned char*)((void*)this->handle) + (uint64_t)(byteOffset));
        int32_t size = (Marshal::SizeOf2(cli::typeof<System::Type>::info) * count);
        if(((target >= this->last_byte) || ((target + (int32_t)(size)) > this->last_byte))) 
        {
            throw cli::gcnew<System::ArgumentException>(_T("would overrite"));
        }
        Marshal::copy_to_unmanaged(array, index, (void*)(void*)(target), count);
    }
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace InteropServices {
    
}}}
 namespace System { namespace Runtime { namespace Reliability {
    
}}}
 namespace System { namespace Runtime { namespace Reliability {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Activation {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Activation {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Activation {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Activation {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Activation {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Activation {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Activation {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting {
    
}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Channels {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Contexts {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Lifetime {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Lifetime {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Lifetime {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Lifetime {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Lifetime {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Messaging {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Metadata { namespace W3cXsd2001 {
    
}}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Proxies {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Proxies {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Proxies {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Proxies {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Services {
    
}}}}
 namespace System { namespace Runtime { namespace Remoting { namespace Services {
    
}}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization {
    
}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters {
    
}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters {
    
}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters {
    
}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters {
    
}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters {
    
}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Serialization { namespace Formatters { namespace Binary {
    
}}}}}
 namespace System { namespace Runtime { namespace Versioning {
    
}}}
 namespace System { namespace Runtime { namespace Versioning {
    
}}}
 namespace System { namespace Runtime { namespace Versioning {
    
}}}
 namespace System { namespace Runtime { namespace Versioning {
    
}}}
 namespace System { namespace Runtime { namespace Versioning {
    
}}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security {
    
}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
    template<class T>
    void ObjectSecurity2<T>::constructor() {
    }
    
    template<class T>
    AccessRule* ObjectSecurity2<T>::AccessRuleFactory_550094ab95f1f5f6(System::Security::Principal::IdentityReference* identityReference, int32_t accessMask, bool isInherited, InheritanceFlags inheritanceFlags, PropagationFlags propagationFlags, AccessControlType type) {
        return nullptr;
    }
    
    template<class T>
    AuditRule* ObjectSecurity2<T>::AuditRuleFactory_1d5188c9a9f829df(System::Security::Principal::IdentityReference* identityReference, int32_t accessMask, bool isInherited, InheritanceFlags inheritanceFlags, PropagationFlags propagationFlags, AuditFlags flags) {
        return nullptr;
    }
    
    template<class T>
    System::Type* ObjectSecurity2<T>::get_AccessRightType_1a84bfe4f6428b49() {
        return nullptr;
    }
    
    template<class T>
    System::Type* ObjectSecurity2<T>::get_AccessRuleType_5fe73642cdc6c868() {
        return nullptr;
    }
    
    template<class T>
    System::Type* ObjectSecurity2<T>::get_AuditRuleType_9f84e3023e989cd7() {
        return nullptr;
    }
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace AccessControl {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography {
    
}}}
 namespace System { namespace Security { namespace Cryptography { namespace X509Certificates {
    
}}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Permissions {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Policy {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Security { namespace Principal {
    
}}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Text {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
    template<class T>
    T Interlocked::CompareExchange_1(T location1, T value, T comparand) {
      // TODO: "Unimplemented external method!"
      throw cli::gcnew<System::NotImplementedException>();
    }
    
    template<class T>
    T Interlocked::Exchange_1(T location1, T value) {
      // TODO: "Unimplemented external method!"
      throw cli::gcnew<System::NotImplementedException>();
    }
    
}}
 namespace System { namespace Threading {
    
    template<class T>
    T LazyInitializer::EnsureInitialized_1(T target) {
        return ([&]() {
            T tmp_24 = target;
            if(tmp_24 == nullptr) {
                return EnsureInitialized_12<T>(target, cli::bind(&LazyInitializer::template GetDefaultCtorValue_1<T>));
            } else
                return tmp_24;
        })();
    }
    
    template<class T>
    T LazyInitializer::EnsureInitialized_12(T target, System::Func<T>* valueFactory) {
        if((cli::box(target) ==  nullptr)) 
        {
            T value = valueFactory->Invoke();
            if((cli::box(value) ==  nullptr)) 
            {
                throw cli::gcnew<System::InvalidOperationException>();
            }
            Interlocked::template CompareExchange_1<T>(target, value, nullptr);
        }
        return target;
    }
    
    template<class T>
    T LazyInitializer::EnsureInitialized_13(T target, bool initialized, System::Object* syncLock) {
        return EnsureInitialized_14<T>(target, initialized, syncLock, cli::bind(&LazyInitializer::template GetDefaultCtorValue_1<T>));
    }
    
    template<class T>
    T LazyInitializer::EnsureInitialized_14(T target, bool initialized, System::Object* syncLock, System::Func<T>* valueFactory) {
        if(initialized) 
        {
            return target;
        }
        if((syncLock ==  nullptr)) 
        {
            Interlocked::CompareExchange2(syncLock, cli::gcnew<System::Object>(), nullptr);
        }
        {
            cli::lock_guard{syncLock};
            if(initialized) 
            {
                return target;
            }
            initialized = true;
            Thread::MemoryBarrier();
            target = valueFactory->Invoke();
        }
        return target;
    }
    
    template<class T>
    T LazyInitializer::GetDefaultCtorValue_1() {
        try {
            return System::Activator::template CreateInstance_1<T>();
        }
        catch(...) {
            throw cli::gcnew<System::MissingMemberException>(_T("The type being lazily initialized does not have a public, parameterless constructor."));
        }
    }
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
    template<class T>
    void ThreadLocal<T>::constructor() {
        this->tls_offset = Thread::AllocTlsData(cli::typeof<System::Type>::info);
    }
    
    template<class T>
    void ThreadLocal<T>::constructor(System::Func<T>* valueFactory) {
        if((valueFactory ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("valueFactory"));
        }
        this->valueFactory = valueFactory;
    }
    
    template<class T>
    void ThreadLocal<T>::Finalize_d47ac0db6df49686() {
        {
            cli::finally_guard([&]() {
                Finalize_b946fbc32e26afd6();
            });
            Dispose_e82b644b032f809e(false);
        }
    }
    
    template<class T>
    void ThreadLocal<T>::Dispose() {
        Dispose_e82b644b032f809e(true);
    }
    
    template<class T>
    void ThreadLocal<T>::Dispose_e82b644b032f809e(bool disposing) {
        if((this->tls_offset != 0U)) 
        {
            uint32_t o = this->tls_offset;
            this->tls_offset = 0U;
            if(disposing) 
            {
                this->valueFactory = nullptr;
            }
            Thread::DestroyTlsData(o);
            System::GC::SuppressFinalize(this);
        }
    }
    
    template<class T>
    T ThreadLocal<T>::GetSlowPath() {
        if((this->tlsdata->cachedException != nullptr)) 
        {
            throw this->tlsdata->cachedException;
        }
        if(((int32_t)(this->tlsdata->state) < 0)) 
        {
            throw cli::gcnew<System::InvalidOperationException>(_T("The initialization function attempted to reference Value recursively"));
        }
        this->tlsdata->state = -1;
        if((this->valueFactory != nullptr)) 
        {
            try {
                this->tlsdata->data = this->valueFactory->Invoke();
            }
            catch(System::Exception* ex) {
                this->tlsdata->cachedException = ex;
                throw ex;
            }
        }
         else 
        {
            this->tlsdata->data = T();
        }
        this->tlsdata->state = 1;
        return this->tlsdata->data;
    }
    
    template<class T>
    System::String* ThreadLocal<T>::ToString_1636a0751cb9ac11() {
        return System::String::Format3(_T("[ThreadLocal: IsValueCreated={0}, Value={1}]"), cli::box(this->get_IsValueCreated()), cli::box(this->get_Value()));
    }
    
    template<class T>
    bool ThreadLocal<T>::get_IsValueCreated() {
        if((this->tls_offset ==  0U)) 
        {
            throw cli::gcnew<System::ObjectDisposedException>(_T("ThreadLocal object"));
        }
        return ((int32_t)(this->tlsdata->state) > 0);
    }
    
    template<class T>
    T ThreadLocal<T>::get_Value() {
        if((this->tls_offset ==  0U)) 
        {
            throw cli::gcnew<System::ObjectDisposedException>(_T("ThreadLocal object"));
        }
        if(((int32_t)(this->tlsdata->state) > 0)) 
        {
            return this->tlsdata->data;
        }
        return GetSlowPath();
    }
    
    template<class T>
    T ThreadLocal<T>::set_Value(T value) {
        if((this->tls_offset ==  0U)) 
        {
            throw cli::gcnew<System::ObjectDisposedException>(_T("ThreadLocal object"));
        }
        this->tlsdata->state = 1;
        this->tlsdata->data = value;
        return get_Value();
    }
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading {
    
}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class T>
    void CyclicDeque<T>::constructor() {
    }
    
    template<class T>
    void CyclicDeque<T>::PushBottom(T obj) {
        int64_t b = System::Threading::Interlocked::Read(this->bottom);
        CircularArray<T> *a = this->array;
        if(((b - this->upperBound) >= (a->get_Size() - 1L))) 
        {
            this->upperBound = System::Threading::Interlocked::Read(this->top);
            a = a->Grow(b, this->upperBound);
            this->array = a;
        }
        a->segment->at((int32_t)(b % (int64_t)(a->size))) = obj;
        System::Threading::Interlocked::Increment2(this->bottom);
    }
    
    template<class T>
    PopResult CyclicDeque<T>::PopBottom(T obj) {
        obj = T();
        int64_t b = System::Threading::Interlocked::Decrement2(this->bottom);
        CircularArray<T> *a = this->array;
        int64_t t = System::Threading::Interlocked::Read(this->top);
        int64_t size = (b - t);
        if((size < 0L)) 
        {
            System::Threading::Interlocked::Add2(this->bottom, (t - b));
            return PopResult::Empty;
        }
        obj = a->segment->at((int32_t)(b % (int64_t)(a->size)));
        if((size > 0L)) 
        {
            return PopResult::Succeed;
        }
        System::Threading::Interlocked::Add2(this->bottom, ((t + 1L) - b));
        if((System::Threading::Interlocked::CompareExchange4(this->top, (t + 1L), t) != t)) 
        {
            return PopResult::Empty;
        }
        return PopResult::Succeed;
    }
    
    template<class T>
    PopResult CyclicDeque<T>::PopTop(T obj) {
        obj = T();
        int64_t t = System::Threading::Interlocked::Read(this->top);
        int64_t b = System::Threading::Interlocked::Read(this->bottom);
        if(((b - t) <= 0L)) 
        {
            return PopResult::Empty;
        }
        if((System::Threading::Interlocked::CompareExchange4(this->top, (t + 1L), t) != t)) 
        {
            return PopResult::Abort;
        }
        CircularArray<T> *a = this->array;
        obj = a->segment->at((int32_t)(t % (int64_t)(a->size)));
        return PopResult::Succeed;
    }
    
    template<class T>
    System::Collections::Generic::IEnumerable2<T>* CyclicDeque<T>::GetEnumerable() {
        CircularArray<T> *a = this->array;
        return a->GetEnumerable(this->bottom, this->top);
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class T>
    void CircularArray<T>::constructor(int32_t baseSize) {
        this->baseSize = baseSize;
        this->size = (1 << (baseSize & 31));
        this->segment = (new cli::array<T>(this->size));
    }
    
    template<class T>
    CircularArray<T>* CircularArray<T>::Grow(int64_t bottom, int64_t top) {
        CircularArray<T> *grow = cli::gcnew<CircularArray<T>>((this->baseSize + 1));
        for(int64_t i = top; (i < bottom); i++){
            grow->segment->at((int32_t)i) = this->segment->at((int32_t)(i % (int64_t)(this->size)));
        }
        return grow;
    }
    
    template<class T>
    System::Collections::Generic::IEnumerable2<T>* CircularArray<T>::GetEnumerable(int64_t bottom, int64_t top) {
        int64_t instantTop = top;
        cli::array<T> *slice = (new cli::array<T>((int32_t)(bottom - instantTop)));
        int32_t destIndex = -1;
        for(int64_t i = instantTop; (i < bottom); i++) {
            slice->at(++destIndex) = this->segment->at((int32_t)(i % (int64_t)(this->size)));
        }
        return RealGetEnumerable(slice, bottom, top, instantTop);
    }
    
    template<class T>
    System::Collections::Generic::IEnumerable2<T>* CircularArray<T>::RealGetEnumerable(cli::array<T>* slice, int64_t bottom, int64_t realTop, int64_t initialTop) {
        return (nullptr/*TODO: Implement Yield Expression!*/);
    }
    
    template<class T>
    int64_t CircularArray<T>::get_Size() {
        return (int64_t)(this->size);
    }
    
    template<class T>
    T CircularArray<T>::get_Item(int64_t index) {
        return this->segment->at((int32_t)(index % (int64_t)(this->size)));
    }
    
    template<class T>
    T CircularArray<T>::set_Item(int64_t index, T value) {
        this->segment->at((int32_t)(index % (int64_t)(this->size))) = value;
        return get_Item(index);
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TLocal>
    ParallelLoopResult Parallel::For_1(int32_t fromInclusive, int32_t toExclusive, System::Func<TLocal>* localInit, System::Func3<int32_t, ParallelLoopState*, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        return For_12<TLocal>(fromInclusive, toExclusive, ParallelOptions::Default2, localInit, body, localFinally);
    }
    
    template<class TLocal>
    ParallelLoopResult Parallel::For_12(int32_t fromInclusive, int32_t toExclusive, ParallelOptions* parallelOptions, System::Func<TLocal>* localInit, System::Func3<int32_t, ParallelLoopState*, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        auto storey_25 = cli::gcnew<_For_c__AnonStorey1F<TLocal>>();
        storey_25->fromInclusive = fromInclusive;
        storey_25->toExclusive = toExclusive;
        storey_25->parallelOptions = parallelOptions;
        storey_25->localInit = localInit;
        storey_25->body = body;
        storey_25->localFinally = localFinally;
        if((storey_25->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        if((storey_25->localInit ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("localInit"));
        }
        if((storey_25->localFinally ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("localFinally"));
        }
        if((storey_25->parallelOptions ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("options"));
        }
        if((storey_25->fromInclusive >= storey_25->toExclusive)) 
        {
            return cli::ctor<ParallelLoopResult>(nullptr, true);
        };
        storey_25->num = GetBestWorkerNumber3(storey_25->fromInclusive, storey_25->toExclusive, storey_25->parallelOptions, storey_25->step);
        cli::array<Task*> *tasks = (new cli::array<Task*>(storey_25->num));
        storey_25->ranges = (new cli::array<StealRange*>(storey_25->num));
        for(int32_t i = 0; (i < storey_25->num); i++) {
            storey_25->ranges->at(i) = cli::gcnew<StealRange>(storey_25->fromInclusive, i, storey_25->step);
        }
        storey_25->infos = cli::gcnew<ExternalInfos>();
        storey_25->currentIndex = -1;
        System::Action *workerMethod = cli::bind(storey_25, &_For_c__AnonStorey1F<TLocal>::__m__1A);
        InitTasks(tasks, storey_25->num, workerMethod, storey_25->parallelOptions);
        try {
            Task::WaitAll(tasks);
        }
        catch(...) {
            HandleExceptions2(tasks, storey_25->infos);
        }
        return cli::ctor<ParallelLoopResult>(storey_25->infos->LowestBreakIteration, !((storey_25->infos->IsStopped || storey_25->infos->IsExceptional)));
    }
    
    template<class TLocal>
    ParallelLoopResult Parallel::For_13(int64_t fromInclusive, int64_t toExclusive, System::Func<TLocal>* localInit, System::Func3<int64_t, ParallelLoopState*, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        return For_14<TLocal>(fromInclusive, toExclusive, ParallelOptions::Default2, localInit, body, localFinally);
    }
    
    template<class TLocal>
    ParallelLoopResult Parallel::For_14(int64_t fromInclusive, int64_t toExclusive, ParallelOptions* parallelOptions, System::Func<TLocal>* localInit, System::Func3<int64_t, ParallelLoopState*, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        if((body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        if((localInit ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("localInit"));
        }
        if((localFinally ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("localFinally"));
        }
        if((parallelOptions ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("options"));
        }
        if((fromInclusive >= toExclusive)) 
        {
            return cli::ctor<ParallelLoopResult>(nullptr, true);
        }
        throw cli::gcnew<System::NotImplementedException>();
    }
    
    template<class TSource, class TLocal>
    ParallelLoopResult Parallel::ForEach_2(System::Func2<int32_t, System::Collections::Generic::IList2<System::Collections::Generic::IEnumerator2<TSource>*>*>* enumerable, ParallelOptions* options, System::Func<TLocal>* init, System::Func3<TSource, ParallelLoopState*, TLocal, TLocal>* action, System::Action2<TLocal>* destruct) {
        auto storey_26 = cli::gcnew<_ForEach_c__AnonStorey22<TSource, TLocal>>();
        storey_26->options = options;
        storey_26->init = init;
        storey_26->action = action;
        storey_26->destruct = destruct;
        if((enumerable ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        if((storey_26->options ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("options"));
        }
        if((storey_26->action ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("action"));
        }
        if((storey_26->init ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("init"));
        }
        if((storey_26->destruct ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("destruct"));
        }
        int32_t num = System::Math::Min5(GetBestWorkerNumber(), ((storey_26->options != nullptr) && (storey_26->options->get_MaxDegreeOfParallelism() != -1)) ? storey_26->options->get_MaxDegreeOfParallelism() : 2147483647);
        cli::array<Task*> *tasks = (new cli::array<Task*>(num));
        storey_26->infos = cli::gcnew<ExternalInfos>();
        storey_26->bag = cli::gcnew<SimpleConcurrentBag<TSource>>(num);
        const int32_t bagCount = 5;
        storey_26->slices = enumerable->Invoke(num);
        storey_26->sliceIndex = -1;
        System::Action *workerMethod = cli::bind(storey_26, &_ForEach_c__AnonStorey22<TSource, TLocal>::__m__1F);
        InitTasks(tasks, num, workerMethod, storey_26->options);
        try {
            Task::WaitAll(tasks);
        }
        catch(...) {
            HandleExceptions2(tasks, storey_26->infos);
        }
        return cli::ctor<ParallelLoopResult>(storey_26->infos->LowestBreakIteration, !((storey_26->infos->IsStopped || storey_26->infos->IsExceptional)));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_1(System::Collections::Generic::IEnumerable2<TSource>* source, System::Action2<TSource>* body) {
        auto storey_27 = cli::gcnew<_ForEach_c__AnonStorey23<TSource>>();
        storey_27->body = body;
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        if((storey_27->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_28<TSource, System::Object*>(System::Collections::Concurrent::Partitioner2::template Create_1<TSource>(source), ParallelOptions::Default2, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_27, &_ForEach_c__AnonStorey23<TSource>::__m__21), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_12(System::Collections::Generic::IEnumerable2<TSource>* source, System::Action4<TSource, ParallelLoopState*>* body) {
        auto storey_28 = cli::gcnew<_ForEach_c__AnonStorey24<TSource>>();
        storey_28->body = body;
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        if((storey_28->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_28<TSource, System::Object*>(System::Collections::Concurrent::Partitioner2::template Create_1<TSource>(source), ParallelOptions::Default2, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_28, &_ForEach_c__AnonStorey24<TSource>::__m__24), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_13(System::Collections::Generic::IEnumerable2<TSource>* source, System::Action3<TSource, ParallelLoopState*, int64_t>* body) {
        auto storey_29 = cli::gcnew<_ForEach_c__AnonStorey25<TSource>>();
        storey_29->body = body;
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        if((storey_29->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_28<TSource, System::Object*>(System::Collections::Concurrent::Partitioner2::template Create_1<TSource>(source), ParallelOptions::Default2, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_29, &_ForEach_c__AnonStorey25<TSource>::__m__27), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_14(System::Collections::Concurrent::Partitioner<TSource>* source, System::Action4<TSource, ParallelLoopState*>* body) {
        auto storey_30 = cli::gcnew<_ForEach_c__AnonStorey26<TSource>>();
        storey_30->body = body;
        if((storey_30->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_28<TSource, System::Object*>(source, ParallelOptions::Default2, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_30, &_ForEach_c__AnonStorey26<TSource>::__m__2A), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_15(System::Collections::Concurrent::OrderablePartitioner<TSource>* source, System::Action3<TSource, ParallelLoopState*, int64_t>* body) {
        auto storey_31 = cli::gcnew<_ForEach_c__AnonStorey27<TSource>>();
        storey_31->body = body;
        if((storey_31->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_29<TSource, System::Object*>(source, ParallelOptions::Default2, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_31, &_ForEach_c__AnonStorey27<TSource>::__m__2D), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_16(System::Collections::Concurrent::Partitioner<TSource>* source, System::Action2<TSource>* body) {
        auto storey_32 = cli::gcnew<_ForEach_c__AnonStorey28<TSource>>();
        storey_32->body = body;
        if((storey_32->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_28<TSource, System::Object*>(source, ParallelOptions::Default2, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_32, &_ForEach_c__AnonStorey28<TSource>::__m__30), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_17(System::Collections::Generic::IEnumerable2<TSource>* source, ParallelOptions* parallelOptions, System::Action2<TSource>* body) {
        auto storey_33 = cli::gcnew<_ForEach_c__AnonStorey29<TSource>>();
        storey_33->body = body;
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        if((storey_33->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_28<TSource, System::Object*>(System::Collections::Concurrent::Partitioner2::template Create_1<TSource>(source), parallelOptions, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_33, &_ForEach_c__AnonStorey29<TSource>::__m__33), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_18(System::Collections::Generic::IEnumerable2<TSource>* source, ParallelOptions* parallelOptions, System::Action4<TSource, ParallelLoopState*>* body) {
        auto storey_34 = cli::gcnew<_ForEach_c__AnonStorey2A<TSource>>();
        storey_34->body = body;
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        if((storey_34->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_28<TSource, System::Object*>(System::Collections::Concurrent::Partitioner2::template Create_1<TSource>(source), parallelOptions, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_34, &_ForEach_c__AnonStorey2A<TSource>::__m__36), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_19(System::Collections::Generic::IEnumerable2<TSource>* source, ParallelOptions* parallelOptions, System::Action3<TSource, ParallelLoopState*, int64_t>* body) {
        auto storey_35 = cli::gcnew<_ForEach_c__AnonStorey2B<TSource>>();
        storey_35->body = body;
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        if((storey_35->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_29<TSource, System::Object*>(System::Collections::Concurrent::Partitioner2::template Create_1<TSource>(source), parallelOptions, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_35, &_ForEach_c__AnonStorey2B<TSource>::__m__39), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_110(System::Collections::Concurrent::OrderablePartitioner<TSource>* source, ParallelOptions* parallelOptions, System::Action3<TSource, ParallelLoopState*, int64_t>* body) {
        auto storey_36 = cli::gcnew<_ForEach_c__AnonStorey2C<TSource>>();
        storey_36->body = body;
        if((storey_36->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_29<TSource, System::Object*>(source, parallelOptions, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_36, &_ForEach_c__AnonStorey2C<TSource>::__m__3C), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_111(System::Collections::Concurrent::Partitioner<TSource>* source, ParallelOptions* parallelOptions, System::Action2<TSource>* body) {
        auto storey_37 = cli::gcnew<_ForEach_c__AnonStorey2D<TSource>>();
        storey_37->body = body;
        if((storey_37->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_28<TSource, System::Object*>(source, parallelOptions, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_37, &_ForEach_c__AnonStorey2D<TSource>::__m__3F), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource>
    ParallelLoopResult Parallel::ForEach_112(System::Collections::Concurrent::Partitioner<TSource>* source, ParallelOptions* parallelOptions, System::Action4<TSource, ParallelLoopState*>* body) {
        auto storey_38 = cli::gcnew<_ForEach_c__AnonStorey2E<TSource>>();
        storey_38->body = body;
        return ForEach_28<TSource, System::Object*>(source, parallelOptions, cli::bind([&] () -> System::Object* {
            return nullptr;
        }
        ), cli::bind(storey_38, &_ForEach_c__AnonStorey2E<TSource>::__m__42), cli::bind([&] (System::Object* _) -> void {
        }
        ));
    }
    
    template<class TSource, class TLocal>
    ParallelLoopResult Parallel::ForEach_22(System::Collections::Generic::IEnumerable2<TSource>* source, System::Func<TLocal>* localInit, System::Func3<TSource, ParallelLoopState*, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        return ForEach_28<TSource, TLocal>(cli::cast<System::Collections::Concurrent::Partitioner<TSource>*>(System::Collections::Concurrent::Partitioner2::template Create_1<TSource>(source)), ParallelOptions::Default2, localInit, body, localFinally);
    }
    
    template<class TSource, class TLocal>
    ParallelLoopResult Parallel::ForEach_23(System::Collections::Generic::IEnumerable2<TSource>* source, System::Func<TLocal>* localInit, System::Func5<TSource, ParallelLoopState*, int64_t, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        return ForEach_29<TSource, TLocal>(System::Collections::Concurrent::Partitioner2::template Create_1<TSource>(source), ParallelOptions::Default2, localInit, body, localFinally);
    }
    
    template<class TSource, class TLocal>
    ParallelLoopResult Parallel::ForEach_24(System::Collections::Concurrent::OrderablePartitioner<TSource>* source, System::Func<TLocal>* localInit, System::Func5<TSource, ParallelLoopState*, int64_t, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        return ForEach_29<TSource, TLocal>(source, ParallelOptions::Default2, localInit, body, localFinally);
    }
    
    template<class TSource, class TLocal>
    ParallelLoopResult Parallel::ForEach_25(System::Collections::Concurrent::Partitioner<TSource>* source, System::Func<TLocal>* localInit, System::Func3<TSource, ParallelLoopState*, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        return ForEach_28<TSource, TLocal>(source, ParallelOptions::Default2, localInit, body, localFinally);
    }
    
    template<class TSource, class TLocal>
    ParallelLoopResult Parallel::ForEach_26(System::Collections::Generic::IEnumerable2<TSource>* source, ParallelOptions* parallelOptions, System::Func<TLocal>* localInit, System::Func3<TSource, ParallelLoopState*, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        return ForEach_28<TSource, TLocal>(System::Collections::Concurrent::Partitioner2::template Create_1<TSource>(source), parallelOptions, localInit, body, localFinally);
    }
    
    template<class TSource, class TLocal>
    ParallelLoopResult Parallel::ForEach_27(System::Collections::Generic::IEnumerable2<TSource>* source, ParallelOptions* parallelOptions, System::Func<TLocal>* localInit, System::Func5<TSource, ParallelLoopState*, int64_t, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        return ForEach_29<TSource, TLocal>(System::Collections::Concurrent::Partitioner2::template Create_1<TSource>(source), parallelOptions, localInit, body, localFinally);
    }
    
    template<class TSource, class TLocal>
    ParallelLoopResult Parallel::ForEach_28(System::Collections::Concurrent::Partitioner<TSource>* source, ParallelOptions* parallelOptions, System::Func<TLocal>* localInit, System::Func3<TSource, ParallelLoopState*, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        if((body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_2<TSource, TLocal>(cli::bind(source, &System::Collections::Concurrent::Partitioner<TSource>::GetPartitions_388b8792e0ab2501), parallelOptions, localInit, body, localFinally);
    }
    
    template<class TSource, class TLocal>
    ParallelLoopResult Parallel::ForEach_29(System::Collections::Concurrent::OrderablePartitioner<TSource>* source, ParallelOptions* parallelOptions, System::Func<TLocal>* localInit, System::Func5<TSource, ParallelLoopState*, int64_t, TLocal, TLocal>* body, System::Action2<TLocal>* localFinally) {
        auto storey_39 = cli::gcnew<_ForEach_c__AnonStorey2F<TSource, TLocal>>();
        storey_39->body = body;
        if((source ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("source"));
        }
        if((storey_39->body ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("body"));
        }
        return ForEach_2<System::Collections::Generic::KeyValuePair<int64_t, TSource>, TLocal>(cli::bind(source, &System::Collections::Concurrent::OrderablePartitioner<TSource>::GetOrderablePartitions_abc13b50067e2c56), parallelOptions, localInit, cli::bind(storey_39, &_ForEach_c__AnonStorey2F<TSource, TLocal>::__m__44), localFinally);
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__20_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__22_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__23_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__25_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__26_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__28_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__29_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__2B_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__2C_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__2E_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__2F_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__31_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__32_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__34_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__35_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__37_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__38_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__3A_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__3B_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__3D_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__3E_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__40_1(System::Object* _) {
    }
    
    template<class TSource>
    System::Object* Parallel::_ForEach_1_m__41_1() {
        return nullptr;
    }
    
    template<class TSource>
    void Parallel::_ForEach_1_m__43_1(System::Object* _) {
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class T>
    void SimpleConcurrentBag<T>::constructor(int32_t num) {
        this->deques = (new cli::array<CyclicDeque<T>*>(num))->template CovariantCast<IConcurrentDeque<T>*>();
        for(int32_t i = 0; (i < this->deques->get_Length()); i++){
            this->deques->at(i) = cli::gcnew<CyclicDeque<T>>();
        }
        this->unique = (num <= 1);
    }
    
    template<class T>
    int32_t SimpleConcurrentBag<T>::GetNextIndex() {
        return System::Threading::Interlocked::Increment(this->index);
    }
    
    template<class T>
    bool SimpleConcurrentBag<T>::TryTake(int32_t index, T value) {
        value = T();
        return ((int32_t)(this->deques->at(index)->PopBottom_550cfc022701ac6c(value)) ==  0);
    }
    
    template<class T>
    bool SimpleConcurrentBag<T>::TrySteal(int32_t index, T value) {
        value = T();
        if(this->unique) 
        {
            return false;
        }
        const int32_t roundThreshold = 3;
        for(int32_t round = 0; (round < 3); ++round){
            if((this->stealIndex ==  index)) 
            {
                this->stealIndex = ((this->stealIndex + 1) % this->deques->get_Length());
            }
            if(((int32_t)(this->deques->at(this->stealIndex = ((this->stealIndex + 1) % this->deques->get_Length()))->PopTop_6ebc020e341f5b55(value)) ==  0)) 
            {
                return true;
            }
        }
        return false;
    }
    
    template<class T>
    void SimpleConcurrentBag<T>::Add(int32_t index, T value) {
        this->deques->at(index)->PushBottom_67d204615af76330(value);
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    Task2<TResult>* Task::ContinueWith_1(System::Func2<Task*, TResult>* continuationFunction) {
        return ContinueWith_12<TResult>(continuationFunction, TaskContinuationOptions::None);
    }
    
    template<class TResult>
    Task2<TResult>* Task::ContinueWith_12(System::Func2<Task*, TResult>* continuationFunction, TaskContinuationOptions continuationOptions) {
        return ContinueWith_15<TResult>(continuationFunction, System::Threading::CancellationToken::get_None(), continuationOptions, TaskScheduler::get_Current());
    }
    
    template<class TResult>
    Task2<TResult>* Task::ContinueWith_13(System::Func2<Task*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWith_15<TResult>(continuationFunction, cancellationToken, TaskContinuationOptions::None, TaskScheduler::get_Current());
    }
    
    template<class TResult>
    Task2<TResult>* Task::ContinueWith_14(System::Func2<Task*, TResult>* continuationFunction, TaskScheduler* scheduler) {
        return ContinueWith_15<TResult>(continuationFunction, System::Threading::CancellationToken::get_None(), TaskContinuationOptions::None, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* Task::ContinueWith_15(System::Func2<Task*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        if((continuationFunction ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("continuationFunction"));
        }
        if((scheduler ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("scheduler"));
        }
        return ContinueWith_16<TResult>(TaskActionInvoker::template Create_15<TResult>(continuationFunction), cancellationToken, continuationOptions, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* Task::ContinueWith_16(TaskActionInvoker* invoker, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        Task2<TResult> *continuation = cli::gcnew<Task2<TResult>>(invoker, nullptr, cancellationToken, GetCreationOptions(continuationOptions), this->parent, this);
        ContinueWithCore(continuation, continuationOptions, scheduler);
        return continuation;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    void ActionTaskObjectInvoke2<TResult>::constructor(System::Action4<Task2<TResult>*, System::Object*>* action) {
        this->action = action;
    }
    
    template<class TResult>
    void ActionTaskObjectInvoke2<TResult>::Invoke_a5a01f61088bfd9f(Task* owner, System::Object* state, Task* context) {
        this->action->Invoke(cli::cast<Task2<TResult>*>(owner), state);
    }
    
    template<class TResult>
    System::Delegate* ActionTaskObjectInvoke2<TResult>::get_Action_f151e6fb89195ccd() {
        return this->action;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    void ActionTaskInvoke2<TResult>::constructor(System::Action2<Task2<TResult>*>* action) {
        this->action = action;
    }
    
    template<class TResult>
    void ActionTaskInvoke2<TResult>::Invoke_a5a01f61088bfd9f(Task* owner, System::Object* state, Task* context) {
        this->action->Invoke(cli::cast<Task2<TResult>*>(owner));
    }
    
    template<class TResult>
    System::Delegate* ActionTaskInvoke2<TResult>::get_Action_f151e6fb89195ccd() {
        return this->action;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    void FuncInvoke<TResult>::constructor(System::Func<TResult>* action) {
        this->action = action;
    }
    
    template<class TResult>
    void FuncInvoke<TResult>::Invoke_a5a01f61088bfd9f(Task* owner, System::Object* state, Task* context) {
        cli::cast<Task2<TResult>*>(context)->set_Result(this->action->Invoke());
    }
    
    template<class TResult>
    System::Delegate* FuncInvoke<TResult>::get_Action_f151e6fb89195ccd() {
        return this->action;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    void FuncTaskInvoke<TResult>::constructor(System::Func2<Task*, TResult>* action) {
        this->action = action;
    }
    
    template<class TResult>
    void FuncTaskInvoke<TResult>::Invoke_a5a01f61088bfd9f(Task* owner, System::Object* state, Task* context) {
        cli::cast<Task2<TResult>*>(context)->set_Result(this->action->Invoke(owner));
    }
    
    template<class TResult>
    System::Delegate* FuncTaskInvoke<TResult>::get_Action_f151e6fb89195ccd() {
        return this->action;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    void FuncTasksInvoke<TResult>::constructor(System::Func2<cli::array<Task*>*, TResult>* action, cli::array<Task*>* tasks) {
        this->action = action;
        this->tasks = tasks;
    }
    
    template<class TResult>
    void FuncTasksInvoke<TResult>::Invoke_a5a01f61088bfd9f(Task* owner, System::Object* state, Task* context) {
        cli::cast<Task2<TResult>*>(context)->set_Result(this->action->Invoke(this->tasks));
    }
    
    template<class TResult>
    System::Delegate* FuncTasksInvoke<TResult>::get_Action_f151e6fb89195ccd() {
        return this->action;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    void FuncTaskSelected<TResult>::constructor(System::Func2<Task*, TResult>* action, cli::array<Task*>* tasks) {
        this->action = action;
        this->tasks = tasks;
    }
    
    template<class TResult>
    void FuncTaskSelected<TResult>::Invoke_a5a01f61088bfd9f(Task* owner, System::Object* state, Task* context) {
        int32_t result = cli::cast<Task2<int32_t>*>(owner)->get_Result();
        cli::cast<Task2<TResult>*>(context)->set_Result(this->action->Invoke(this->tasks->at(result)));
    }
    
    template<class TResult>
    System::Delegate* FuncTaskSelected<TResult>::get_Action_f151e6fb89195ccd() {
        return this->action;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult, class TNewResult>
    void FuncTaskInvoke2<TResult, TNewResult>::constructor(System::Func2<Task2<TResult>*, TNewResult>* action) {
        this->action = action;
    }
    
    template<class TResult, class TNewResult>
    void FuncTaskInvoke2<TResult, TNewResult>::Invoke_a5a01f61088bfd9f(Task* owner, System::Object* state, Task* context) {
        cli::cast<Task2<TNewResult>*>(context)->set_Result(this->action->Invoke(cli::cast<Task2<TResult>*>(owner)));
    }
    
    template<class TResult, class TNewResult>
    System::Delegate* FuncTaskInvoke2<TResult, TNewResult>::get_Action_f151e6fb89195ccd() {
        return this->action;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    void FuncObjectInvoke<TResult>::constructor(System::Func2<System::Object*, TResult>* action) {
        this->action = action;
    }
    
    template<class TResult>
    void FuncObjectInvoke<TResult>::Invoke_a5a01f61088bfd9f(Task* owner, System::Object* state, Task* context) {
        cli::cast<Task2<TResult>*>(context)->set_Result(this->action->Invoke(state));
    }
    
    template<class TResult>
    System::Delegate* FuncObjectInvoke<TResult>::get_Action_f151e6fb89195ccd() {
        return this->action;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    void FuncTaskObjectInvoke<TResult>::constructor(System::Func4<Task*, System::Object*, TResult>* action) {
        this->action = action;
    }
    
    template<class TResult>
    void FuncTaskObjectInvoke<TResult>::Invoke_a5a01f61088bfd9f(Task* owner, System::Object* state, Task* context) {
        cli::cast<Task2<TResult>*>(context)->set_Result(this->action->Invoke(owner, state));
    }
    
    template<class TResult>
    System::Delegate* FuncTaskObjectInvoke<TResult>::get_Action_f151e6fb89195ccd() {
        return this->action;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult, class TNewResult>
    void FuncTaskObjectInvoke2<TResult, TNewResult>::constructor(System::Func4<Task2<TResult>*, System::Object*, TNewResult>* action) {
        this->action = action;
    }
    
    template<class TResult, class TNewResult>
    void FuncTaskObjectInvoke2<TResult, TNewResult>::Invoke_a5a01f61088bfd9f(Task* owner, System::Object* state, Task* context) {
        cli::cast<Task2<TNewResult>*>(context)->set_Result(this->action->Invoke(cli::cast<Task2<TResult>*>(owner), state));
    }
    
    template<class TResult, class TNewResult>
    System::Delegate* FuncTaskObjectInvoke2<TResult, TNewResult>::get_Action_f151e6fb89195ccd() {
        return this->action;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    TaskActionInvoker* TaskActionInvoker::Create_1(System::Action2<Task2<TResult>*>* action) {
        return cli::gcnew<ActionTaskInvoke2<TResult>>(action);
    }
    
    template<class TResult>
    TaskActionInvoker* TaskActionInvoker::Create_12(System::Action4<Task2<TResult>*, System::Object*>* action) {
        return cli::gcnew<ActionTaskObjectInvoke2<TResult>>(action);
    }
    
    template<class TResult>
    TaskActionInvoker* TaskActionInvoker::Create_13(System::Func<TResult>* action) {
        return cli::gcnew<FuncInvoke<TResult>>(action);
    }
    
    template<class TResult>
    TaskActionInvoker* TaskActionInvoker::Create_14(System::Func2<System::Object*, TResult>* action) {
        return cli::gcnew<FuncObjectInvoke<TResult>>(action);
    }
    
    template<class TResult>
    TaskActionInvoker* TaskActionInvoker::Create_15(System::Func2<Task*, TResult>* action) {
        return cli::gcnew<FuncTaskInvoke<TResult>>(action);
    }
    
    template<class TResult>
    TaskActionInvoker* TaskActionInvoker::Create_16(System::Func4<Task*, System::Object*, TResult>* action) {
        return cli::gcnew<FuncTaskObjectInvoke<TResult>>(action);
    }
    
    template<class TResult, class TNewResult>
    TaskActionInvoker* TaskActionInvoker::Create_2(System::Func2<Task2<TResult>*, TNewResult>* action) {
        return cli::gcnew<FuncTaskInvoke2<TResult, TNewResult>>(action);
    }
    
    template<class TResult, class TNewResult>
    TaskActionInvoker* TaskActionInvoker::Create_22(System::Func4<Task2<TResult>*, System::Object*, TNewResult>* action) {
        return cli::gcnew<FuncTaskObjectInvoke2<TResult, TNewResult>>(action);
    }
    
    template<class TResult>
    TaskActionInvoker* TaskActionInvoker::Create_17(System::Func2<cli::array<Task*>*, TResult>* action, cli::array<Task*>* tasks) {
        return cli::gcnew<FuncTasksInvoke<TResult>>(action, tasks);
    }
    
    template<class TResult>
    TaskActionInvoker* TaskActionInvoker::Create_18(System::Func2<Task*, TResult>* action, cli::array<Task*>* tasks) {
        return cli::gcnew<FuncTaskSelected<TResult>>(action, tasks);
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    void TaskCompletionSource<TResult>::constructor() {
    }
    
    template<class TResult>
    void TaskCompletionSource<TResult>::constructor(System::Object* state) {
    }
    
    template<class TResult>
    void TaskCompletionSource<TResult>::constructor(TaskCreationOptions creationOptions) {
    }
    
    template<class TResult>
    void TaskCompletionSource<TResult>::constructor(System::Object* state, TaskCreationOptions creationOptions) {
        if(((int32_t)(((int32_t)(creationOptions) & 3)) != 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("creationOptions"));
        }
        this->source = cli::gcnew<Task2<TResult>>(TaskActionInvoker::Empty, state, System::Threading::CancellationToken::get_None(), creationOptions, nullptr);
        this->source->SetupScheduler(TaskScheduler::get_Current());
    }
    
    template<class TResult>
    void TaskCompletionSource<TResult>::SetCanceled() {
        if(!(TrySetCanceled())) 
        {
            ThrowInvalidException();
        }
    }
    
    template<class TResult>
    void TaskCompletionSource<TResult>::SetException(System::Exception* exception) {
        if((exception ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("exception"));
        }
        SetException2((new cli::array<System::Exception*>({exception})));
    }
    
    template<class TResult>
    void TaskCompletionSource<TResult>::SetException2(System::Collections::Generic::IEnumerable2<System::Exception*>* exceptions) {
        if(!(TrySetException2(exceptions))) 
        {
            ThrowInvalidException();
        }
    }
    
    template<class TResult>
    void TaskCompletionSource<TResult>::SetResult(TResult result) {
        if(!(TrySetResult(result))) 
        {
            ThrowInvalidException();
        }
    }
    
    template<class TResult>
    void TaskCompletionSource<TResult>::ThrowInvalidException() {
        throw cli::gcnew<System::InvalidOperationException>(_T("The underlying Task is already in one of the three final states: RanToCompletion, Faulted, or Canceled."));
    }
    
    template<class TResult>
    bool TaskCompletionSource<TResult>::TrySetCanceled() {
        return this->source->TrySetCanceled();
    }
    
    template<class TResult>
    bool TaskCompletionSource<TResult>::TrySetException(System::Exception* exception) {
        if((exception ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("exception"));
        }
        return TrySetException2((new cli::array<System::Exception*>({exception})));
    }
    
    template<class TResult>
    bool TaskCompletionSource<TResult>::TrySetException2(System::Collections::Generic::IEnumerable2<System::Exception*>* exceptions) {
        if((exceptions ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("exceptions"));
        }
        System::AggregateException *aggregate = cli::gcnew<System::AggregateException>(exceptions);
        if((aggregate->get_InnerExceptions()->get_Count() ==  0)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("exceptions"));
        }
        return this->source->TrySetException(aggregate);
    }
    
    template<class TResult>
    bool TaskCompletionSource<TResult>::TrySetResult(TResult result) {
        return this->source->TrySetResult(result);
    }
    
    template<class TResult>
    Task2<TResult>* TaskCompletionSource<TResult>::get_Task() {
        return this->source;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    Task2<TResult>* TaskFactory::StartNew_1(System::Func<TResult>* function) {
        return StartNew_14<TResult>(function, this->cancellationToken, this->creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::StartNew_12(System::Func<TResult>* function, TaskCreationOptions creationOptions) {
        return StartNew_14<TResult>(function, this->cancellationToken, creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::StartNew_13(System::Func<TResult>* function, System::Threading::CancellationToken cancellationToken) {
        return StartNew_14<TResult>(function, cancellationToken, this->creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::StartNew_14(System::Func<TResult>* function, System::Threading::CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler* scheduler) {
        Task2<TResult> *t = cli::gcnew<Task2<TResult>>(function, cancellationToken, creationOptions);
        if(!(t->get_IsCompleted())) 
        {
            t->Start2(scheduler);
        }
        return t;
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::StartNew_15(System::Func2<System::Object*, TResult>* function, System::Object* state) {
        return StartNew_18<TResult>(function, state, this->cancellationToken, this->creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::StartNew_16(System::Func2<System::Object*, TResult>* function, System::Object* state, System::Threading::CancellationToken cancellationToken) {
        return StartNew_18<TResult>(function, state, cancellationToken, this->creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::StartNew_17(System::Func2<System::Object*, TResult>* function, System::Object* state, TaskCreationOptions creationOptions) {
        return StartNew_18<TResult>(function, state, this->cancellationToken, creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::StartNew_18(System::Func2<System::Object*, TResult>* function, System::Object* state, System::Threading::CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler* scheduler) {
        Task2<TResult> *t = cli::gcnew<Task2<TResult>>(function, state, cancellationToken, creationOptions);
        t->Start2(scheduler);
        return t;
    }
    
    template<class TAntecedentResult>
    Task* TaskFactory::ContinueWhenAny_1(cli::array<Task2<TAntecedentResult>*>* tasks, System::Action2<Task2<TAntecedentResult>*>* continuationAction) {
        return ContinueWhenAny_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationAction, this->cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult>
    Task* TaskFactory::ContinueWhenAny_12(cli::array<Task2<TAntecedentResult>*>* tasks, System::Action2<Task2<TAntecedentResult>*>* continuationAction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWhenAny_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationAction, cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult>
    Task* TaskFactory::ContinueWhenAny_13(cli::array<Task2<TAntecedentResult>*>* tasks, System::Action2<Task2<TAntecedentResult>*>* continuationAction, TaskContinuationOptions continuationOptions) {
        return ContinueWhenAny_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationAction, this->cancellationToken, continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult>
    Task* TaskFactory::ContinueWhenAny_14(cli::array<Task2<TAntecedentResult>*>* tasks, System::Action2<Task2<TAntecedentResult>*>* continuationAction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        auto storey_40 = cli::gcnew<_ContinueWhenAny_c__AnonStorey31<TAntecedentResult>>();
        storey_40->continuationAction = continuationAction;
        return ContinueWhenAny4(cli::cast<cli::array<Task*>*>(tasks), cli::bind(storey_40, &_ContinueWhenAny_c__AnonStorey31<TAntecedentResult>::__m__49), cancellationToken, continuationOptions, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAny_15(cli::array<Task*>* tasks, System::Func2<Task*, TResult>* continuationFunction) {
        return ContinueWhenAny_18<TResult>(tasks, continuationFunction, this->cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAny_16(cli::array<Task*>* tasks, System::Func2<Task*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWhenAny_18<TResult>(tasks, continuationFunction, cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAny_17(cli::array<Task*>* tasks, System::Func2<Task*, TResult>* continuationFunction, TaskContinuationOptions continuationOptions) {
        return ContinueWhenAny_18<TResult>(tasks, continuationFunction, this->cancellationToken, continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAny_18(cli::array<Task*>* tasks, System::Func2<Task*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        Task2<int32_t> *t = cli::gcnew<Task2<int32_t>>(cli::bind([&] (System::Object* l) -> int32_t {
            System::Tuple4<cli::array<Task*>*, System::Threading::CancellationToken> *data = cli::cast<System::Tuple4<cli::array<Task*>*, System::Threading::CancellationToken>*>(l);
            return Task::WaitAny4(data->get_Item1(), data->get_Item2());
        }
        ), System::Tuple::template Create_2<cli::array<Task*>*, System::Threading::CancellationToken>(tasks, cancellationToken));
        Task2<TResult> *cont = t->template ContinueWith_16<TResult>(TaskActionInvoker::template Create_18<TResult>(continuationFunction, tasks), cancellationToken, continuationOptions, scheduler);
        t->Start2(scheduler);
        return cont;
    }
    
    template<class TAntecedentResult, class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAny_2(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<Task2<TAntecedentResult>*, TResult>* continuationFunction) {
        return ContinueWhenAny_24<TAntecedentResult, TResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, this->cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult, class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAny_22(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<Task2<TAntecedentResult>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWhenAny_24<TAntecedentResult, TResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult, class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAny_23(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<Task2<TAntecedentResult>*, TResult>* continuationFunction, TaskContinuationOptions continuationOptions) {
        return ContinueWhenAny_24<TAntecedentResult, TResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, this->cancellationToken, continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult, class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAny_24(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<Task2<TAntecedentResult>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        auto storey_41 = cli::gcnew<_ContinueWhenAny_c__AnonStorey32<TAntecedentResult, TResult>>();
        storey_41->continuationFunction = continuationFunction;
        return ContinueWhenAny_18<TResult>(cli::cast<cli::array<Task*>*>(tasks), cli::bind(storey_41, &_ContinueWhenAny_c__AnonStorey32<TAntecedentResult, TResult>::__m__4B), cancellationToken, continuationOptions, scheduler);
    }
    
    template<class TAntecedentResult>
    Task* TaskFactory::ContinueWhenAll_1(cli::array<Task2<TAntecedentResult>*>* tasks, System::Action2<cli::array<Task2<TAntecedentResult>*>*>* continuationAction) {
        return ContinueWhenAll_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationAction, this->cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult>
    Task* TaskFactory::ContinueWhenAll_12(cli::array<Task2<TAntecedentResult>*>* tasks, System::Action2<cli::array<Task2<TAntecedentResult>*>*>* continuationAction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWhenAll_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationAction, cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult>
    Task* TaskFactory::ContinueWhenAll_13(cli::array<Task2<TAntecedentResult>*>* tasks, System::Action2<cli::array<Task2<TAntecedentResult>*>*>* continuationAction, TaskContinuationOptions continuationOptions) {
        return ContinueWhenAll_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationAction, this->cancellationToken, continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult>
    Task* TaskFactory::ContinueWhenAll_14(cli::array<Task2<TAntecedentResult>*>* tasks, System::Action2<cli::array<Task2<TAntecedentResult>*>*>* continuationAction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        auto storey_42 = cli::gcnew<_ContinueWhenAll_c__AnonStorey33<TAntecedentResult>>();
        storey_42->tasks = tasks;
        storey_42->continuationAction = continuationAction;
        return ContinueWhenAll4(cli::cast<cli::array<Task*>*>(storey_42->tasks), cli::bind(storey_42, &_ContinueWhenAll_c__AnonStorey33<TAntecedentResult>::__m__4D), cancellationToken, continuationOptions, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAll_15(cli::array<Task*>* tasks, System::Func2<cli::array<Task*>*, TResult>* continuationFunction) {
        return ContinueWhenAll_18<TResult>(tasks, continuationFunction, this->cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAll_16(cli::array<Task*>* tasks, System::Func2<cli::array<Task*>*, TResult>* continuationFunction, TaskContinuationOptions continuationOptions) {
        return ContinueWhenAll_18<TResult>(tasks, continuationFunction, this->cancellationToken, continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAll_17(cli::array<Task*>* tasks, System::Func2<cli::array<Task*>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWhenAll_18<TResult>(tasks, continuationFunction, cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAll_18(cli::array<Task*>* tasks, System::Func2<cli::array<Task*>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        Task *t = cli::gcnew<Task>(cli::bind([&] (System::Object* l) -> void {
            System::Tuple4<cli::array<Task*>*, System::Threading::CancellationToken> *data = cli::cast<System::Tuple4<cli::array<Task*>*, System::Threading::CancellationToken>*>(l);
            Task::WaitAll2(data->get_Item1(), data->get_Item2());
        }
        ), System::Tuple::template Create_2<cli::array<Task*>*, System::Threading::CancellationToken>(tasks, cancellationToken));
        Task2<TResult> *cont = t->template ContinueWith_16<TResult>(TaskActionInvoker::template Create_17<TResult>(continuationFunction, tasks), cancellationToken, continuationOptions, scheduler);
        t->Start2(scheduler);
        return cont;
    }
    
    template<class TAntecedentResult, class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAll_2(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<cli::array<Task2<TAntecedentResult>*>*, TResult>* continuationFunction) {
        return ContinueWhenAll_24<TAntecedentResult, TResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, this->cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult, class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAll_22(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<cli::array<Task2<TAntecedentResult>*>*, TResult>* continuationFunction, TaskContinuationOptions continuationOptions) {
        return ContinueWhenAll_24<TAntecedentResult, TResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, this->cancellationToken, continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult, class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAll_23(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<cli::array<Task2<TAntecedentResult>*>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWhenAll_24<TAntecedentResult, TResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TAntecedentResult, class TResult>
    Task2<TResult>* TaskFactory::ContinueWhenAll_24(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<cli::array<Task2<TAntecedentResult>*>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        auto storey_43 = cli::gcnew<_ContinueWhenAll_c__AnonStorey34<TAntecedentResult, TResult>>();
        storey_43->tasks = tasks;
        storey_43->continuationFunction = continuationFunction;
        return ContinueWhenAll_18<TResult>(cli::cast<cli::array<Task*>*>(storey_43->tasks), cli::bind(storey_43, &_ContinueWhenAll_c__AnonStorey34<TAntecedentResult, TResult>::__m__4F), cancellationToken, continuationOptions, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::FromAsync_1(System::IAsyncResult* asyncResult, System::Func2<System::IAsyncResult*, TResult>* endMethod) {
        return FromAsync_12<TResult>(asyncResult, endMethod, this->creationOptions);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::FromAsync_12(System::IAsyncResult* asyncResult, System::Func2<System::IAsyncResult*, TResult>* endMethod, TaskCreationOptions creationOptions) {
        return FromAsync_13<TResult>(asyncResult, endMethod, creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::FromAsync_13(System::IAsyncResult* asyncResult, System::Func2<System::IAsyncResult*, TResult>* endMethod, TaskCreationOptions creationOptions, TaskScheduler* scheduler) {
        return TaskFactory2<TResult>::FromIAsyncResult(asyncResult, endMethod, creationOptions, scheduler);
    }
    
    template<class TArg1>
    Task* TaskFactory::FromAsync_14(System::Func3<TArg1, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Action2<System::IAsyncResult*>* endMethod, TArg1 arg1, System::Object* state) {
        return FromAsync_15<TArg1>(beginMethod, endMethod, arg1, state, this->creationOptions);
    }
    
    template<class TArg1>
    Task* TaskFactory::FromAsync_15(System::Func3<TArg1, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Action2<System::IAsyncResult*>* endMethod, TArg1 arg1, System::Object* state, TaskCreationOptions creationOptions) {
        auto storey_44 = cli::gcnew<_FromAsync_c__AnonStorey37<TArg1>>();
        storey_44->endMethod = endMethod;
        if((storey_44->endMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("endMethod"));
        }
        return TaskFactory2<System::Object*>::template FromAsyncBeginEnd_1<TArg1>(beginMethod, cli::bind(storey_44, &_FromAsync_c__AnonStorey37<TArg1>::__m__52), arg1, state, creationOptions);
    }
    
    template<class TArg1, class TArg2>
    Task* TaskFactory::FromAsync_2(System::Func5<TArg1, TArg2, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Action2<System::IAsyncResult*>* endMethod, TArg1 arg1, TArg2 arg2, System::Object* state) {
        return FromAsync_22<TArg1, TArg2>(beginMethod, endMethod, arg1, arg2, state, this->creationOptions);
    }
    
    template<class TArg1, class TArg2>
    Task* TaskFactory::FromAsync_22(System::Func5<TArg1, TArg2, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Action2<System::IAsyncResult*>* endMethod, TArg1 arg1, TArg2 arg2, System::Object* state, TaskCreationOptions creationOptions) {
        auto storey_45 = cli::gcnew<_FromAsync_c__AnonStorey38<TArg1, TArg2>>();
        storey_45->endMethod = endMethod;
        if((storey_45->endMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("endMethod"));
        }
        return TaskFactory2<System::Object*>::template FromAsyncBeginEnd_2<TArg1, TArg2>(beginMethod, cli::bind(storey_45, &_FromAsync_c__AnonStorey38<TArg1, TArg2>::__m__53), arg1, arg2, state, creationOptions);
    }
    
    template<class TArg1, class TArg2, class TArg3>
    Task* TaskFactory::FromAsync_3(System::Func6<TArg1, TArg2, TArg3, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Action2<System::IAsyncResult*>* endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, System::Object* state) {
        return FromAsync_32<TArg1, TArg2, TArg3>(beginMethod, endMethod, arg1, arg2, arg3, state, this->creationOptions);
    }
    
    template<class TArg1, class TArg2, class TArg3>
    Task* TaskFactory::FromAsync_32(System::Func6<TArg1, TArg2, TArg3, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Action2<System::IAsyncResult*>* endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, System::Object* state, TaskCreationOptions creationOptions) {
        auto storey_46 = cli::gcnew<_FromAsync_c__AnonStorey39<TArg1, TArg2, TArg3>>();
        storey_46->endMethod = endMethod;
        if((storey_46->endMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("endMethod"));
        }
        return TaskFactory2<System::Object*>::template FromAsyncBeginEnd_3<TArg1, TArg2, TArg3>(beginMethod, cli::bind(storey_46, &_FromAsync_c__AnonStorey39<TArg1, TArg2, TArg3>::__m__54), arg1, arg2, arg3, state, creationOptions);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::FromAsync_16(System::Func4<System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, System::Object* state) {
        return FromAsync_17<TResult>(beginMethod, endMethod, state, this->creationOptions);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory::FromAsync_17(System::Func4<System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, System::Object* state, TaskCreationOptions creationOptions) {
        return TaskFactory2<TResult>::FromAsyncBeginEnd(beginMethod, endMethod, state, creationOptions);
    }
    
    template<class TArg1, class TResult>
    Task2<TResult>* TaskFactory::FromAsync_23(System::Func3<TArg1, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, System::Object* state) {
        return FromAsync_24<TArg1, TResult>(beginMethod, endMethod, arg1, state, this->creationOptions);
    }
    
    template<class TArg1, class TResult>
    Task2<TResult>* TaskFactory::FromAsync_24(System::Func3<TArg1, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, System::Object* state, TaskCreationOptions creationOptions) {
        return TaskFactory2<TResult>::template FromAsyncBeginEnd_1<TArg1>(beginMethod, endMethod, arg1, state, creationOptions);
    }
    
    template<class TArg1, class TArg2, class TResult>
    Task2<TResult>* TaskFactory::FromAsync_33(System::Func5<TArg1, TArg2, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, TArg2 arg2, System::Object* state) {
        return FromAsync_34<TArg1, TArg2, TResult>(beginMethod, endMethod, arg1, arg2, state, this->creationOptions);
    }
    
    template<class TArg1, class TArg2, class TResult>
    Task2<TResult>* TaskFactory::FromAsync_34(System::Func5<TArg1, TArg2, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, TArg2 arg2, System::Object* state, TaskCreationOptions creationOptions) {
        return TaskFactory2<TResult>::template FromAsyncBeginEnd_2<TArg1, TArg2>(beginMethod, endMethod, arg1, arg2, state, creationOptions);
    }
    
    template<class TArg1, class TArg2, class TArg3, class TResult>
    Task2<TResult>* TaskFactory::FromAsync_4(System::Func6<TArg1, TArg2, TArg3, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, System::Object* state) {
        return FromAsync_42<TArg1, TArg2, TArg3, TResult>(beginMethod, endMethod, arg1, arg2, arg3, state, this->creationOptions);
    }
    
    template<class TArg1, class TArg2, class TArg3, class TResult>
    Task2<TResult>* TaskFactory::FromAsync_42(System::Func6<TArg1, TArg2, TArg3, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, System::Object* state, TaskCreationOptions creationOptions) {
        return TaskFactory2<TResult>::template FromAsyncBeginEnd_3<TArg1, TArg2, TArg3>(beginMethod, endMethod, arg1, arg2, arg3, state, creationOptions);
    }
    
    template<class TResult>
    int32_t TaskFactory::_ContinueWhenAny_1_m__4A_1(System::Object* l) {
        System::Tuple4<cli::array<Task*>*, System::Threading::CancellationToken> *data = cli::cast<System::Tuple4<cli::array<Task*>*, System::Threading::CancellationToken>*>(l);
        return Task::WaitAny4(data->get_Item1(), data->get_Item2());
    }
    
    template<class TResult>
    void TaskFactory::_ContinueWhenAll_1_m__4E_1(System::Object* l) {
        System::Tuple4<cli::array<Task*>*, System::Threading::CancellationToken> *data = cli::cast<System::Tuple4<cli::array<Task*>*, System::Threading::CancellationToken>*>(l);
        Task::WaitAll2(data->get_Item1(), data->get_Item2());
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    void TaskFactory2<TResult>::constructor() {
    }
    
    template<class TResult>
    void TaskFactory2<TResult>::constructor(TaskScheduler* scheduler) {
    }
    
    template<class TResult>
    void TaskFactory2<TResult>::constructor(System::Threading::CancellationToken cancellationToken) {
    }
    
    template<class TResult>
    void TaskFactory2<TResult>::constructor(TaskCreationOptions creationOptions, TaskContinuationOptions continuationOptions) {
    }
    
    template<class TResult>
    void TaskFactory2<TResult>::constructor(System::Threading::CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        this->cancellationToken = cancellationToken;
        this->scheduler = scheduler;
        this->creationOptions = creationOptions;
        this->continuationOptions = continuationOptions;
        TaskFactory::CheckContinuationOptions(continuationOptions);
        this->parent = cli::gcnew<TaskFactory>(cancellationToken, creationOptions, continuationOptions, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::StartNew(System::Func<TResult>* function) {
        return StartNew4(function, this->cancellationToken, this->creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::StartNew2(System::Func<TResult>* function, TaskCreationOptions creationOptions) {
        return StartNew4(function, this->cancellationToken, creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::StartNew3(System::Func<TResult>* function, System::Threading::CancellationToken cancellationToken) {
        return StartNew4(function, cancellationToken, this->creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::StartNew4(System::Func<TResult>* function, System::Threading::CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler* scheduler) {
        auto storey_47 = cli::gcnew<_StartNew_c__AnonStorey3A<TResult>>();
        storey_47->function = function;
        return StartNew8(cli::bind(storey_47, &_StartNew_c__AnonStorey3A<TResult>::__m__55), nullptr, cancellationToken, creationOptions, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::StartNew5(System::Func2<System::Object*, TResult>* function, System::Object* state) {
        return StartNew8(function, state, this->cancellationToken, this->creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::StartNew6(System::Func2<System::Object*, TResult>* function, System::Object* state, TaskCreationOptions creationOptions) {
        return StartNew8(function, state, this->cancellationToken, creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::StartNew7(System::Func2<System::Object*, TResult>* function, System::Object* state, System::Threading::CancellationToken cancellationToken) {
        return StartNew8(function, state, cancellationToken, this->creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::StartNew8(System::Func2<System::Object*, TResult>* function, System::Object* state, System::Threading::CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler* scheduler) {
        return this->parent->template StartNew_18<TResult>(function, state, cancellationToken, creationOptions, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAny(cli::array<Task*>* tasks, System::Func2<Task*, TResult>* continuationFunction) {
        return ContinueWhenAny4(tasks, continuationFunction, this->cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAny2(cli::array<Task*>* tasks, System::Func2<Task*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWhenAny4(tasks, continuationFunction, cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAny3(cli::array<Task*>* tasks, System::Func2<Task*, TResult>* continuationFunction, TaskContinuationOptions continuationOptions) {
        return ContinueWhenAny4(tasks, continuationFunction, this->cancellationToken, continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAny4(cli::array<Task*>* tasks, System::Func2<Task*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        return this->parent->template ContinueWhenAny_18<TResult>(tasks, continuationFunction, cancellationToken, continuationOptions, scheduler);
    }
    
    template<class TResult>
    template<class TAntecedentResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAny_1(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<Task2<TAntecedentResult>*, TResult>* continuationFunction) {
        return ContinueWhenAny_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, this->cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    template<class TAntecedentResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAny_12(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<Task2<TAntecedentResult>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWhenAny_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    template<class TAntecedentResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAny_13(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<Task2<TAntecedentResult>*, TResult>* continuationFunction, TaskContinuationOptions continuationOptions) {
        return ContinueWhenAny_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, this->cancellationToken, continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    template<class TAntecedentResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAny_14(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<Task2<TAntecedentResult>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        return this->parent->template ContinueWhenAny_24<TAntecedentResult, TResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, cancellationToken, continuationOptions, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAll(cli::array<Task*>* tasks, System::Func2<cli::array<Task*>*, TResult>* continuationFunction) {
        return ContinueWhenAll4(tasks, continuationFunction, this->cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAll2(cli::array<Task*>* tasks, System::Func2<cli::array<Task*>*, TResult>* continuationFunction, TaskContinuationOptions continuationOptions) {
        return ContinueWhenAll4(tasks, continuationFunction, this->cancellationToken, continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAll3(cli::array<Task*>* tasks, System::Func2<cli::array<Task*>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWhenAll4(tasks, continuationFunction, cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAll4(cli::array<Task*>* tasks, System::Func2<cli::array<Task*>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        return this->parent->template ContinueWhenAll_18<TResult>(tasks, continuationFunction, cancellationToken, continuationOptions, scheduler);
    }
    
    template<class TResult>
    template<class TAntecedentResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAll_1(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<cli::array<Task2<TAntecedentResult>*>*, TResult>* continuationFunction) {
        return ContinueWhenAll_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, this->cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    template<class TAntecedentResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAll_12(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<cli::array<Task2<TAntecedentResult>*>*, TResult>* continuationFunction, TaskContinuationOptions continuationOptions) {
        return ContinueWhenAll_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, this->cancellationToken, continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    template<class TAntecedentResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAll_13(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<cli::array<Task2<TAntecedentResult>*>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWhenAll_14<TAntecedentResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, cancellationToken, this->continuationOptions, GetScheduler());
    }
    
    template<class TResult>
    template<class TAntecedentResult>
    Task2<TResult>* TaskFactory2<TResult>::ContinueWhenAll_14(cli::array<Task2<TAntecedentResult>*>* tasks, System::Func2<cli::array<Task2<TAntecedentResult>*>*, TResult>* continuationFunction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        return this->parent->template ContinueWhenAll_24<TAntecedentResult, TResult>(tasks->template CovariantCast<Task2<TAntecedentResult>*>(), continuationFunction, cancellationToken, continuationOptions, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync(System::IAsyncResult* asyncResult, System::Func2<System::IAsyncResult*, TResult>* endMethod) {
        return FromAsync2(asyncResult, endMethod, this->creationOptions);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync2(System::IAsyncResult* asyncResult, System::Func2<System::IAsyncResult*, TResult>* endMethod, TaskCreationOptions creationOptions) {
        return FromAsync3(asyncResult, endMethod, creationOptions, GetScheduler());
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync3(System::IAsyncResult* asyncResult, System::Func2<System::IAsyncResult*, TResult>* endMethod, TaskCreationOptions creationOptions, TaskScheduler* scheduler) {
        return FromIAsyncResult(asyncResult, endMethod, creationOptions, scheduler);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::FromIAsyncResult(System::IAsyncResult* asyncResult, System::Func2<System::IAsyncResult*, TResult>* endMethod, TaskCreationOptions creationOptions, TaskScheduler* scheduler) {
        auto storey_48 = cli::gcnew<_FromIAsyncResult_c__AnonStorey3B<TResult>>();
        storey_48->asyncResult = asyncResult;
        storey_48->endMethod = endMethod;
        storey_48->scheduler = scheduler;
        if((storey_48->asyncResult ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("asyncResult"));
        }
        if((storey_48->endMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("endMethod"));
        }
        if((storey_48->scheduler ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("scheduler"));
        }
        if(((int32_t)(((int32_t)(creationOptions) & 3)) != 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("creationOptions"));
        }
        storey_48->source = cli::gcnew<System::Threading::CancellationTokenSource>();
        storey_48->task = cli::gcnew<Task2<TResult>>(cli::bind(storey_48, &_FromIAsyncResult_c__AnonStorey3B<TResult>::__m__56), nullptr, storey_48->source->get_Token(), creationOptions);
        if(storey_48->asyncResult->get_IsCompleted_908b07d70649b7ff()) 
        {
            storey_48->task->RunSynchronously2(storey_48->scheduler);
        }
         else 
        {
            System::Threading::ThreadPool::RegisterWaitForSingleObject(storey_48->asyncResult->get_AsyncWaitHandle_7620505c49d113f3(), cli::bind(storey_48, &_FromIAsyncResult_c__AnonStorey3B<TResult>::__m__57), nullptr, -1, true);
        }
        return storey_48->task;
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync4(System::Func4<System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, System::Object* state) {
        return FromAsync5(beginMethod, endMethod, state, this->creationOptions);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync5(System::Func4<System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, System::Object* state, TaskCreationOptions creationOptions) {
        return FromAsyncBeginEnd(beginMethod, endMethod, state, creationOptions);
    }
    
    template<class TResult>
    Task2<TResult>* TaskFactory2<TResult>::FromAsyncBeginEnd(System::Func4<System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, System::Object* state, TaskCreationOptions creationOptions) {
        auto storey_49 = cli::gcnew<_FromAsyncBeginEnd_c__AnonStorey3C<TResult>>();
        storey_49->endMethod = endMethod;
        if((beginMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("beginMethod"));
        }
        if((storey_49->endMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("endMethod"));
        }
        if(((int32_t)(((int32_t)(creationOptions) & 3)) != 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("creationOptions"));
        }
        storey_49->tcs = cli::gcnew<TaskCompletionSource<TResult>>(state, creationOptions);
        beginMethod->Invoke(cli::bind(storey_49, &_FromAsyncBeginEnd_c__AnonStorey3C<TResult>::__m__58), state);
        return storey_49->tcs->get_Task();
    }
    
    template<class TResult>
    template<class TArg1>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync_1(System::Func3<TArg1, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, System::Object* state) {
        return FromAsync_12<TArg1>(beginMethod, endMethod, arg1, state, this->creationOptions);
    }
    
    template<class TResult>
    template<class TArg1>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync_12(System::Func3<TArg1, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, System::Object* state, TaskCreationOptions creationOptions) {
        return FromAsyncBeginEnd_1<TArg1>(beginMethod, endMethod, arg1, state, creationOptions);
    }
    
    template<class TResult>
    template<class TArg1>
    Task2<TResult>* TaskFactory2<TResult>::FromAsyncBeginEnd_1(System::Func3<TArg1, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, System::Object* state, TaskCreationOptions creationOptions) {
        auto storey_50 = cli::gcnew<_FromAsyncBeginEnd_c__AnonStorey3D<TResult, TArg1>>();
        storey_50->endMethod = endMethod;
        if((beginMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("beginMethod"));
        }
        if((storey_50->endMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("endMethod"));
        }
        if(((int32_t)(((int32_t)(creationOptions) & 3)) != 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("creationOptions"));
        }
        storey_50->tcs = cli::gcnew<TaskCompletionSource<TResult>>(state, creationOptions);
        beginMethod->Invoke(arg1, cli::bind(storey_50, &_FromAsyncBeginEnd_c__AnonStorey3D<TResult, TArg1>::__m__59), state);
        return storey_50->tcs->get_Task();
    }
    
    template<class TResult>
    template<class TArg1, class TArg2>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync_2(System::Func5<TArg1, TArg2, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, TArg2 arg2, System::Object* state) {
        return FromAsync_22<TArg1, TArg2>(beginMethod, endMethod, arg1, arg2, state, this->creationOptions);
    }
    
    template<class TResult>
    template<class TArg1, class TArg2>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync_22(System::Func5<TArg1, TArg2, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, TArg2 arg2, System::Object* state, TaskCreationOptions creationOptions) {
        return FromAsyncBeginEnd_2<TArg1, TArg2>(beginMethod, endMethod, arg1, arg2, state, creationOptions);
    }
    
    template<class TResult>
    template<class TArg1, class TArg2>
    Task2<TResult>* TaskFactory2<TResult>::FromAsyncBeginEnd_2(System::Func5<TArg1, TArg2, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, TArg2 arg2, System::Object* state, TaskCreationOptions creationOptions) {
        auto storey_51 = cli::gcnew<_FromAsyncBeginEnd_c__AnonStorey3E<TResult, TArg1, TArg2>>();
        storey_51->endMethod = endMethod;
        if((beginMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("beginMethod"));
        }
        if((storey_51->endMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("endMethod"));
        }
        if(((int32_t)(((int32_t)(creationOptions) & 3)) != 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("creationOptions"));
        }
        storey_51->tcs = cli::gcnew<TaskCompletionSource<TResult>>(state, creationOptions);
        beginMethod->Invoke(arg1, arg2, cli::bind(storey_51, &_FromAsyncBeginEnd_c__AnonStorey3E<TResult, TArg1, TArg2>::__m__5A), state);
        return storey_51->tcs->get_Task();
    }
    
    template<class TResult>
    template<class TArg1, class TArg2, class TArg3>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync_3(System::Func6<TArg1, TArg2, TArg3, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, System::Object* state) {
        return FromAsync_32<TArg1, TArg2, TArg3>(beginMethod, endMethod, arg1, arg2, arg3, state, this->creationOptions);
    }
    
    template<class TResult>
    template<class TArg1, class TArg2, class TArg3>
    Task2<TResult>* TaskFactory2<TResult>::FromAsync_32(System::Func6<TArg1, TArg2, TArg3, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, System::Object* state, TaskCreationOptions creationOptions) {
        return FromAsyncBeginEnd_3<TArg1, TArg2, TArg3>(beginMethod, endMethod, arg1, arg2, arg3, state, creationOptions);
    }
    
    template<class TResult>
    template<class TArg1, class TArg2, class TArg3>
    Task2<TResult>* TaskFactory2<TResult>::FromAsyncBeginEnd_3(System::Func6<TArg1, TArg2, TArg3, System::AsyncCallback*, System::Object*, System::IAsyncResult*>* beginMethod, System::Func2<System::IAsyncResult*, TResult>* endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, System::Object* state, TaskCreationOptions creationOptions) {
        auto storey_52 = cli::gcnew<_FromAsyncBeginEnd_c__AnonStorey3F<TResult, TArg1, TArg2, TArg3>>();
        storey_52->endMethod = endMethod;
        if((beginMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("beginMethod"));
        }
        if((storey_52->endMethod ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("endMethod"));
        }
        if(((int32_t)(((int32_t)(creationOptions) & 3)) != 0)) 
        {
            throw cli::gcnew<System::ArgumentOutOfRangeException>(_T("creationOptions"));
        }
        storey_52->tcs = cli::gcnew<TaskCompletionSource<TResult>>(state, creationOptions);
        beginMethod->Invoke(arg1, arg2, arg3, cli::bind(storey_52, &_FromAsyncBeginEnd_c__AnonStorey3F<TResult, TArg1, TArg2, TArg3>::__m__5B), state);
        return storey_52->tcs->get_Task();
    }
    
    template<class TResult>
    TaskScheduler* TaskFactory2<TResult>::GetScheduler() {
        return ([&]() {
            TaskScheduler* tmp_53 = this->scheduler;
            if(tmp_53 == nullptr) {
                return TaskScheduler::get_Current();
            } else
                return tmp_53;
        })();
    }
    
    template<class TResult>
    void TaskFactory2<TResult>::InnerInvoke(TaskCompletionSource<TResult>* tcs, System::Func2<System::IAsyncResult*, TResult>* endMethod, System::IAsyncResult* l) {
        try {
            tcs->SetResult(endMethod->Invoke(l));
        }
        catch(System::OperationCanceledException*) {
            tcs->SetCanceled();
        }
        catch(System::Exception* e) {
            tcs->SetException(e);
        }
    }
    
    template<class TResult>
    TaskScheduler* TaskFactory2<TResult>::get_Scheduler() {
        return this->scheduler;
    }
    
    template<class TResult>
    TaskContinuationOptions TaskFactory2<TResult>::get_ContinuationOptions() {
        return this->continuationOptions;
    }
    
    template<class TResult>
    TaskCreationOptions TaskFactory2<TResult>::get_CreationOptions() {
        return this->creationOptions;
    }
    
    template<class TResult>
    System::Threading::CancellationToken TaskFactory2<TResult>::get_CancellationToken() {
        return this->cancellationToken;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
    template<class TResult>
    Task2<TResult>::Task2()
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
    
    template<class TResult>
    void Task2<TResult>::constructor(System::Func<TResult>* function) {
    }
    
    template<class TResult>
    void Task2<TResult>::constructor(System::Func<TResult>* function, System::Threading::CancellationToken cancellationToken) {
    }
    
    template<class TResult>
    void Task2<TResult>::constructor(System::Func<TResult>* function, TaskCreationOptions creationOptions) {
    }
    
    template<class TResult>
    void Task2<TResult>::constructor(System::Func<TResult>* function, System::Threading::CancellationToken cancellationToken, TaskCreationOptions creationOptions) {
        if((function ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("function"));
        }
    }
    
    template<class TResult>
    void Task2<TResult>::constructor(System::Func2<System::Object*, TResult>* function, System::Object* state) {
    }
    
    template<class TResult>
    void Task2<TResult>::constructor(System::Func2<System::Object*, TResult>* function, System::Object* state, System::Threading::CancellationToken cancellationToken) {
    }
    
    template<class TResult>
    void Task2<TResult>::constructor(System::Func2<System::Object*, TResult>* function, System::Object* state, TaskCreationOptions creationOptions) {
    }
    
    template<class TResult>
    void Task2<TResult>::constructor(System::Func2<System::Object*, TResult>* function, System::Object* state, System::Threading::CancellationToken cancellationToken, TaskCreationOptions creationOptions) {
        if((function ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("function"));
        }
    }
    
    template<class TResult>
    void Task2<TResult>::constructor(TaskActionInvoker* invoker, System::Object* state, System::Threading::CancellationToken cancellationToken, TaskCreationOptions creationOptions, Task* parent) {
    }
    
    template<class TResult>
    void Task2<TResult>::constructor(TaskActionInvoker* invoker, System::Object* state, System::Threading::CancellationToken cancellationToken, TaskCreationOptions creationOptions, Task* parent, Task* contAncestor) {
    }
    
    template<class TResult>
    void Task2<TResult>::static_constructor() {
    }
    
    template<class TResult>
    Task* Task2<TResult>::ContinueWith8(System::Action2<Task2<TResult>*>* continuationAction) {
        return ContinueWith9(continuationAction, TaskContinuationOptions::None);
    }
    
    template<class TResult>
    Task* Task2<TResult>::ContinueWith9(System::Action2<Task2<TResult>*>* continuationAction, TaskContinuationOptions continuationOptions) {
        return ContinueWith12(continuationAction, System::Threading::CancellationToken::get_None(), continuationOptions, TaskScheduler::get_Current());
    }
    
    template<class TResult>
    Task* Task2<TResult>::ContinueWith10(System::Action2<Task2<TResult>*>* continuationAction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWith12(continuationAction, cancellationToken, TaskContinuationOptions::None, TaskScheduler::get_Current());
    }
    
    template<class TResult>
    Task* Task2<TResult>::ContinueWith11(System::Action2<Task2<TResult>*>* continuationAction, TaskScheduler* scheduler) {
        return ContinueWith12(continuationAction, System::Threading::CancellationToken::get_None(), TaskContinuationOptions::None, scheduler);
    }
    
    template<class TResult>
    Task* Task2<TResult>::ContinueWith12(System::Action2<Task2<TResult>*>* continuationAction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        if((continuationAction ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("continuationAction"));
        }
        if((scheduler ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("scheduler"));
        }
        Task *t = cli::gcnew<Task>(TaskActionInvoker::template Create_1<TResult>(continuationAction), nullptr, cancellationToken, Task::GetCreationOptions(continuationOptions), this->parent, this);
        Task::ContinueWithCore(t, continuationOptions, scheduler);
        return t;
    }
    
    template<class TResult>
    template<class TNewResult>
    Task2<TNewResult>* Task2<TResult>::ContinueWith_17(System::Func2<Task2<TResult>*, TNewResult>* continuationFunction) {
        return ContinueWith_111<TNewResult>(continuationFunction, System::Threading::CancellationToken::get_None(), TaskContinuationOptions::None, TaskScheduler::get_Current());
    }
    
    template<class TResult>
    template<class TNewResult>
    Task2<TNewResult>* Task2<TResult>::ContinueWith_18(System::Func2<Task2<TResult>*, TNewResult>* continuationFunction, System::Threading::CancellationToken cancellationToken) {
        return ContinueWith_111<TNewResult>(continuationFunction, cancellationToken, TaskContinuationOptions::None, TaskScheduler::get_Current());
    }
    
    template<class TResult>
    template<class TNewResult>
    Task2<TNewResult>* Task2<TResult>::ContinueWith_19(System::Func2<Task2<TResult>*, TNewResult>* continuationFunction, TaskContinuationOptions continuationOptions) {
        return ContinueWith_111<TNewResult>(continuationFunction, System::Threading::CancellationToken::get_None(), continuationOptions, TaskScheduler::get_Current());
    }
    
    template<class TResult>
    template<class TNewResult>
    Task2<TNewResult>* Task2<TResult>::ContinueWith_110(System::Func2<Task2<TResult>*, TNewResult>* continuationFunction, TaskScheduler* scheduler) {
        return ContinueWith_111<TNewResult>(continuationFunction, System::Threading::CancellationToken::get_None(), TaskContinuationOptions::None, scheduler);
    }
    
    template<class TResult>
    template<class TNewResult>
    Task2<TNewResult>* Task2<TResult>::ContinueWith_111(System::Func2<Task2<TResult>*, TNewResult>* continuationFunction, System::Threading::CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler* scheduler) {
        if((continuationFunction ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("continuationFunction"));
        }
        if((scheduler ==  nullptr)) 
        {
            throw cli::gcnew<System::ArgumentNullException>(_T("scheduler"));
        }
        Task2<TNewResult> *t = cli::gcnew<Task2<TNewResult>>(TaskActionInvoker::template Create_2<TResult, TNewResult>(continuationFunction), nullptr, cancellationToken, Task::GetCreationOptions(continuationOptions), this->parent, this);
        Task::ContinueWithCore(t, continuationOptions, scheduler);
        return t;
    }
    
    template<class TResult>
    bool Task2<TResult>::TrySetResult(TResult result) {
        if(this->get_IsCompleted()) 
        {
            return false;
        }
        if(!(this->executing->TryRelaxedSet())) 
        {
            System::Threading::SpinWait sw = cli::ctor<System::Threading::SpinWait>();
            while(!(this->get_IsCompleted())) sw->SpinOnce();
            return false;
        }
        this->set_Status(TaskStatus::Running);
        this->value = result;
        System::Threading::Thread::MemoryBarrier();
        Task::Finish();
        return true;
    }
    
    template<class TResult>
    TResult Task2<TResult>::get_Result() {
        if(!(this->get_IsCompleted())) 
        {
            Task::Wait();
        }
        if(this->get_IsCanceled()) 
        {
            throw cli::gcnew<System::AggregateException>((new cli::array<System::Exception*>({cli::gcnew<TaskCanceledException>(this)})));
        }
        if((this->get_Exception() != nullptr)) 
        {
            throw this->get_Exception();
        }
        return this->value;
    }
    
    template<class TResult>
    TResult Task2<TResult>::set_Result(TResult value) {
        this->value = value;
        return get_Result();
    }
    
    template<class TResult>
    System::String* Task2<TResult>::get_ResultAsString() {
        if(((int32_t)(((int32_t)(this->get_Status()) & 5)) != 0)) 
        {
            return cli::concat(_T(""), cli::box(this->value));
        }
        return _T("<value not available>");
    }
    
    template<class TResult>
    TaskFactory2<TResult>* Task2<TResult>::get_Factory2() {
        return Task2<TResult>::factory;
    }
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 namespace System { namespace Threading { namespace Tasks {
    
}}}
 
template<class T> System::Func<T>* System::Lazy<T>::__f__am_cache0;
template<class T> System::Func<T>* System::Lazy<T>::__f__am_cache1;
template<class TKey, class TValue> System::Func2<System::Collections::Generic::KeyValuePair<TKey, TValue>, TKey>* System::Collections::Concurrent::ConcurrentDictionary<TKey, TValue>::__f__am_cache0;
template<class TKey, class TValue> System::Func2<System::Collections::Generic::KeyValuePair<TKey, TValue>, TValue>* System::Collections::Concurrent::ConcurrentDictionary<TKey, TValue>::__f__am_cache1;
template<class T> System::Collections::Concurrent::NodeObjectPool<T>* System::Collections::Concurrent::ConcurrentQueue<T>::pool;
template<class T> System::Collections::Concurrent::NodeObjectPool2<T>* System::Collections::Concurrent::ConcurrentStack<T>::pool;
template<class TKey, class T> System::Collections::Concurrent::NodeObjectPool3<TKey, T>* System::Collections::Concurrent::SplitOrderedList<TKey, T>::pool;
template<class TKey, class T> cli::array<unsigned char>* System::Collections::Concurrent::SplitOrderedList<TKey, T>::reverseTable;
template<class TKey, class T> cli::array<unsigned char>* System::Collections::Concurrent::SplitOrderedList<TKey, T>::logTable;
template<class T> System::Collections::Generic::Comparer2<T>* System::Collections::Generic::Comparer2<T>::_default;
template<class T> System::Collections::Generic::EqualityComparer<T>* System::Collections::Generic::EqualityComparer<T>::_default;
template<class T> cli::array<T>* System::Collections::Generic::List<T>::EmptyArray;
template<class TKey, class TValue> System::Runtime::CompilerServices::CreateValueCallback<TKey, TValue>* System::Runtime::CompilerServices::ConditionalWeakTable<TKey, TValue>::__f__am_cache0;
template<class TResult> System::Threading::Tasks::TaskFactory2<TResult>* System::Threading::Tasks::Task2<TResult>::factory;

