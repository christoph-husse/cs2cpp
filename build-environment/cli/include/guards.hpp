
namespace cli
{
	class finally_guard
	{
	private:
		std::function<void ()> m_Cleanup;

		finally_guard(const finally_guard&) = delete;
		finally_guard& operator=(const finally_guard&) = delete;
	public:
		finally_guard(std::function<void ()> cleanup) : m_Cleanup(cleanup) { }
		~finally_guard() { m_Cleanup(); }
	};

	class lock_guard
	{
	private:
		::System::Object* m_Lock;

		lock_guard(const lock_guard&) = delete;
		lock_guard& operator=(const lock_guard&) = delete;
	public:
		lock_guard(::System::Object* lock) : m_Lock(lock) 
		{ 
		}

		~lock_guard() 
		{ 
			m_Lock = nullptr;
		}
	};

	class using_guard
	{
	private:
		::System::IDisposable* m_Disposable;

		using_guard(const using_guard&) = delete;
		using_guard& operator=(const using_guard&) = delete;
	public:
		using_guard(::System::IDisposable* disposable) : m_Disposable(disposable) 
		{ 
		}

		~using_guard() 
		{ 
			if(m_Disposable != nullptr)
				m_Disposable->Dispose_95cb2516542c2f97();

			m_Disposable = nullptr;
		}
	};

	template<class T> T* fixed_guard(cli::array<T>* arr)
	{
		static_assert(!std::is_pointer<T>::value || !std::is_base_of<System::Object, T>::value || std::is_base_of<System::ValueType, T>::value,
			"Pointer access to array members is only supported for non-class types.");

		return nullptr;
	}

	template<class T> T fixed_guard(T ptr)
	{
		static_assert(std::is_pointer<T>::value && std::is_fundamental<typename std::remove_pointer<T>::type>::value,
			"Access to arbitrary memory is only supported for pointers to fundamental types.");

		return ptr;
	}

	static char16_t* fixed_guard(::System::String* str)
	{
		return nullptr;
	}
}