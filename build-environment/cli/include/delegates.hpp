	

namespace cli
{
	template<typename T> struct get_signature;
	
	template<typename Mem, typename Ret, typename... Args> struct get_signature<Ret(Mem::*)(Args...) const> {
		typedef Ret type(Args...);
		typedef Ret return_type;
		typedef Mem member_type;
		typedef std::tuple<Args...> args;
	};

	template<typename Mem, typename Ret, typename... Args> struct get_signature<Ret(Mem::*)(Args...)> {
		typedef Ret type(Args...);
		typedef Ret return_type;
		typedef Mem member_type;
		typedef std::tuple<Args...> args;
	};

	template<typename Ret, typename... Args> struct get_signature<Ret(*)(Args...)> {
		typedef Ret type(Args...);
		typedef Ret return_type;
		typedef std::tuple<Args...> args;
	};

	template<typename Ret, typename... Args> struct get_signature<Ret(Args...)> {
		typedef Ret type(Args...);
		typedef Ret return_type;
		typedef std::tuple<Args...> args;
	};


	template<class T> struct delegate;
	template<typename Ret, typename... Args> struct delegate<Ret(Args...)> : public ::System::MulticastDelegate
	{
		typedef Ret signature(Args...);

		bool get_HasSingleTarget() { return true; }

		virtual Ret InternalInvoke(std::tuple<Args...> args)
		{
			return Ret();
		}

		/*
			an Invoke() method. The arguments of the method are dynamically generated and match the delegate declaration. 
			Calling the Invoke() method runs the delegate target method on the same thread, a synchronous call. You rarely 
			use it in C#, you just use the syntax sugar that allows a delegate object to be invoked by just using the object 
			name, followed by parentheses.
		*/
		Ret Invoke(Args... args)
		{
			return InternalInvoke(std::make_tuple(args...));
		}

		/*
			A BeginInvoke() method, provides a way to make an asynchronous call. The method quickly completes while 
			the target method is busy executing, similar to ThreadPool.QueueUserWorkItem but with type-safe arguments. 
			The return type is always System.IAsyncResult, used to find out when the asynchronous call is completed 
			and supplied to the EndInvoke() method. First argument is an optional System.AsyncCallback delegate object, 
			it's target will automatically be called when the asynchronous call is complete. Second argument is an optional
			object, it will be passed as-is to the callback, useful to keep track of state. Additional arguments are 
			dynamically generated and match the delegate declaration.
		*/
		System::IAsyncResult* BeginInvoke(Args..., System::AsyncCallback* callback, System::Object* context)
		{
			return nullptr;
		}

		/*
			An EndInvoke() method. It takes a single argument of type IAsyncResult, you must pass the one you got from 
			BeginInvoke(). It completes the asynchronous call and releases resources.
		*/
		Ret EndInvoke(System::IAsyncResult* result)
		{
			return Ret();
		}

		template<class T> T Cast()
		{
			typedef typename std::remove_pointer<T>::type::signature toSignature;

			// this is meant to be a compile-time check and we don't want dead code in release builds
			// (not sure if compilers can really optimize this away)
#if _DEBUG
			// If this fails, the delegates can not be converted!
			// Return values can only be generalized and arguments specialized...
			std::function<typename signature> from;
			std::function<typename toSignature> to = from;
#endif

			static_assert(std::is_pointer<T>::value && std::is_same<delegate<toSignature>, typename std::remove_pointer<T>::type>::value,
				"Target type shall be a pointer to a cli::delegate.");

			return (T)this;
		}
	};

	// [SOURCE] http://stackoverflow.com/questions/7858817/unpacking-a-tuple-to-call-a-matching-function-pointer
	template<int ...> struct template_seq {};
	template<int N, int ...S> struct template_gens : template_gens<N-1, N-1, S...> {};
	template<int ...S> struct template_gens<0, S...>{ typedef template_seq<S...> type; };
	// [/SOURCE]


	/*/////////////// static_delegate_binder

		Allows binding static methods to delegates.
	*/

	template<typename T>
	struct static_delegate_binder : public delegate<typename get_signature<T>::type>
	{
		typedef get_signature<T> signature;

		T anonymous;

		static_delegate_binder(T anonymous) : anonymous(anonymous) { }

		virtual typename signature::return_type InternalInvoke(typename signature::args args) override
		{
			return Dispatcher(typename template_gens<std::tuple_size<typename signature::args>::value>::type(), args);
		}

	private:

		template<int ...S>
		typename signature::return_type Dispatcher(template_seq<S...>, typename signature::args args)
		{
			return anonymous(std::get<S>(args)...);
		}
	};


	template<class T> 
	delegate<typename get_signature<T>::type>* bind(T func)
	{
		return new static_delegate_binder<T>(func);
	}


	/*/////////////// lambda_delegate_binder

		Allows binding C++ lambda methods to delegates.
	*/

	template<typename TLambda>
	struct lambda_delegate_binder : public delegate<typename get_signature<decltype(&TLambda::operator())>::type>
	{
		typedef get_signature<decltype(&TLambda::operator())> signature;

		TLambda lambda;

		lambda_delegate_binder(TLambda lambda) : lambda(lambda) { }

		virtual typename signature::return_type InternalInvoke(typename signature::args args) override
		{
			return Dispatcher(typename template_gens<std::tuple_size<typename signature::args>::value>::type(), args);
		}

	private:

		template<int ...S>
		typename signature::return_type Dispatcher(template_seq<S...>, typename signature::args args)
		{
			return lambda(std::get<S>(args)...);
		}
	};

	template<class T> 
	delegate<typename get_signature<decltype(&T::operator())>::type>* bind(T func)
	{
		return new lambda_delegate_binder<T>(func);
	}


	/*/////////////// storey_delegate_binder

		Allows binding storeys and non-static member methods to delegates.
	*/
	template<typename TFunc, class TStorey, class TStoreyFunc>
	struct storey_delegate_binder : public delegate<TFunc>
	{
		typedef get_signature<TFunc> signature;

		TStorey storey;
		TStoreyFunc storeyFunc;

		storey_delegate_binder(TStorey storey, TStoreyFunc storeyFunc) : storey(storey), storeyFunc(storeyFunc) { }

		virtual typename signature::return_type InternalInvoke(typename signature::args args) override
		{
			return Dispatcher(typename template_gens<std::tuple_size<typename signature::args>::value>::type(), args);
		}

	private:
		template<int ...S>
		typename signature::return_type Dispatcher(template_seq<S...>, typename signature::args args)
		{
			return (storey->*storeyFunc)(std::get<S>(args)...);
		}
	};

	template<class TStorey, class TFunc> 
	delegate<typename get_signature<TFunc>::type>* bind(TStorey storey, TFunc storeyFunc)
	{
		return new storey_delegate_binder<typename get_signature<TFunc>::type, TStorey, TFunc>(storey, storeyFunc);
	}
}