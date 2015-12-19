
namespace cli
{
	/////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////// STL Wrapper for IEnumerable<T>
	/////////////////////////////////////////////////////////////////////////////////

	template<class T>
	class IEnumerable_iterator
	{
	private:
		System::Collections::Generic::IEnumerator2<T>* m_Enum;
		int m_Position;
	public:
		IEnumerable_iterator (System::Collections::Generic::IEnumerable2<T>* iter) : m_Enum(iter->GetEnumerator_ad4887f30f9e4c5()), m_Position(-1) 
		{ 
			if(m_Enum->MoveNext_4e78e145935f5417())
				m_Position = 0;
		}

		IEnumerable_iterator (System::Collections::Generic::IEnumerator2<T>* iter) : m_Enum(iter), m_Position(-1) 
		{ 
			if(m_Enum->MoveNext_4e78e145935f5417())
				m_Position = 0;
		}
		
		IEnumerable_iterator () : m_Enum(nullptr), m_Position(-1)
		{
			// end iterator
		}

		bool operator!= (const IEnumerable_iterator<T>& other) 
		{ 
			return (m_Enum != other.m_Enum) || (m_Position != other.m_Position); 
		}
		
		T operator*() 
		{ 
			return m_Enum->get_Current_9be2a11682d08be8(); 
		}
		
		IEnumerable_iterator<T>& operator++ () 
		{ 
			if(m_Enum->MoveNext_4e78e145935f5417())
				m_Position++;
			else
				m_Position = -1; 
			
			return *this; 
		}
	};

	/////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////// STL Wrapper for IEnumerable
	/////////////////////////////////////////////////////////////////////////////////
	class IEnumerableObj_iterator
	{
	private:
		System::Collections::IEnumerator* m_Enum;
		int m_Position;
	public:
		IEnumerableObj_iterator (System::Collections::IEnumerable* iter) : m_Enum(iter->GetEnumerator_674ad93a972a4d67()), m_Position(-1) 
		{ 
			if(m_Enum->MoveNext_4e78e145935f5417())
				m_Position = 0;
		}

		IEnumerableObj_iterator (System::Collections::IEnumerator* iter) : m_Enum(iter), m_Position(-1) 
		{ 
			if(m_Enum->MoveNext_4e78e145935f5417())
				m_Position = 0;
		}
		
		IEnumerableObj_iterator () : m_Enum(nullptr), m_Position(-1)
		{
			// end iterator
		}

		bool operator!= (const IEnumerableObj_iterator& other) 
		{ 
			return (m_Enum != other.m_Enum) || (m_Position != other.m_Position); 
		}
		
		System::Object* operator*() 
		{ 
			return m_Enum->get_Current_8eca9b3da02b123a(); 
		}
		
		IEnumerableObj_iterator& operator++ () 
		{ 
			if(m_Enum->MoveNext_4e78e145935f5417())
				m_Position++;
			else
				m_Position = -1; 
			
			return *this; 
		}
	};


	template<class T>
	int32_t enumeration<T>::CompareTo_ed9d39205b7812f0(::System::Object* obj)  
	{ 
		if(cli::is<T>(obj))
		{
			auto other = (int32_t)cli::cast<T>(obj);

			if((int32_t)value < other) return -1;
			else if((int32_t)value > other) return 1;
			else return 0;
		}
		else
			return false;
	}
}

namespace System 
{
	template<typename T>
	typename std::enable_if<
		std::is_convertible<T, System::Collections::IEnumerable*>::value &&
		!std::is_convertible<T, System::Collections::IEnumerator*>::value, 
		::cli::IEnumerableObj_iterator>::type 
	begin(T iter) { return ::cli::IEnumerableObj_iterator((System::Collections::IEnumerable*)iter); }
	static ::cli::IEnumerableObj_iterator end(System::Collections::IEnumerable* iter) { return ::cli::IEnumerableObj_iterator(); }

	static ::cli::IEnumerableObj_iterator begin(System::Collections::IEnumerator* iter) { return ::cli::IEnumerableObj_iterator(iter); }
	static ::cli::IEnumerableObj_iterator end(System::Collections::IEnumerator* iter) { return ::cli::IEnumerableObj_iterator(); }

}
