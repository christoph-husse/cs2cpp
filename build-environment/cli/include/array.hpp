
namespace cli
{
	template<class T>
	class array_iterator
	{
	private:
		int m_Position;
		array<T>* m_Array;
	public:
		array_iterator (array<T>* arr, int position) : m_Position(position), m_Array(arr) {  }
		bool operator!= (const array_iterator<T>& other) { return m_Position != other.m_Position; }
		T operator*();
		array_iterator<T>& operator++ () { ++m_Position; return *this; }
	};

	template<class T>
	class array : public virtual System::Array, public virtual System::Collections::Generic::IList2<T>
	{
	private:
		int length;
		T* entries;

		void allocate(std::size_t length)
		{
			this->length = 0;
			this->entries = nullptr;

			if(length == 0)
				return;

			this->length = length;
			this->entries = new T[length];
			for(int i = 0; i < length; i++) entries[i] = T();
		}

	public:
		array()
		{
			allocate(0);
		}

		array(std::initializer_list<T> entries)
		{
			allocate(entries.size());

			int i = 0;
			for(T e : entries) this->entries[i++] = e;
		}

		array(int length)
		{
			allocate(length);
		}

		array(std::vector<T> entries)
		{
			allocate(entries.size());

			int i = 0;
			for(int i = 0; i < length; i++) this->entries[i] = entries[i];
		}

		void constructor(int length)
		{
			allocate(length);
		}

		int get_Length() { return length; }

		T& at(int index)
		{
			if((index < 0) || (index >= length))
				throw cli::gcnew<System::Exception>(_T("Index out of range!"));

			return entries[index];
		}

		// multi-dimensional overload
		template<typename... TIndices>
		T& at(int index, TIndices... tail) { throw cli::gcnew<::System::NotImplementedException>(_T("Multidimensional array access")); }

		array<T>* Clone() 
		{ 
			auto res = new array<T>(length); 
			for(int i = 0; i < length; i++) res->at(i) = at(i);
			return res;
		}

		array_iterator<T> begin() { return array_iterator<T>(this, 0); }
		array_iterator<T> end() { return array_iterator<T>(this, get_Length()); }

		// covariant casts
		// TODO: We need to throw an exception if new elements do not match the original type of the array elements
		template<class U>
		array<U>* CovariantCast()
		{
			static_assert(std::is_base_of<typename std::remove_pointer<U>::type, typename std::remove_pointer<T>::type>::value,
				"Array cast is not covariant.");

			return reinterpret_cast<array<U>*>(this); 
		}

		// IList<T>
		int32_t IndexOf_9e82d7c34bb82d25(T item) override { return IndexOf_7f6d78d7aa6d53e5(box<::System::Object*>(item)); }
		void Insert_d9ae15974e481e9e(int32_t index, T item) override { Insert_16e8bd69dfc603f4(index, nullptr); }
		void RemoveAt_92d07238fa433d4a(int32_t index) override { RemoveAt_dce190584913328b(index); }
		T get_Item_e6c1a54cb8f591e7(int32_t index) override { return unbox<T>(get_Item_8550d21996ef9dc5(index)); }
		T set_Item_13ad50de181a1c01(int32_t index, T value) override 
		{ 
			set_Item_d57705373e0668e7(index, box<::System::Object*>(value)); 
			return get_Item_e6c1a54cb8f591e7(index);
		}

		// ICollection<T>
		void Add_a6fc54bc2aa3c029(T item) override { Add_985508e3bf9b7a73(nullptr); }
        void Clear_16ef3c35b14f77a2() override { Clear_e0ee496065507a2f(); }
        bool_t Contains_ca946a648e63e62e(T item) override { return Contains_2a2192a595869f4e(box<::System::Object*>(item)); }
        void CopyTo_e6884c04285bc976(cli::array<T>* array, int32_t arrayIndex) override { // TODO: implement
		}
        bool_t Remove_67948971902d0cce(T item) override { Remove_69f1b1e57bb34112(nullptr); return false; }
        int32_t get_Count_a9c25d5c244affb9() override { return get_Count_8f254f3dd8e2403(); }
        bool_t get_IsReadOnly_9569eb0bb1daa9b5() override { return get_IsReadOnly_53b6e02d46187790(); }

		// IEnumerable<T>
		::System::Collections::Generic::IEnumerator2<T>* GetEnumerator_ad4887f30f9e4c5() override { return nullptr; }
	};

	template<class T>
	T array_iterator<T>::operator*() { return m_Array->at(m_Position); }

	template<class T>
	array_iterator<T> begin(array<T>* arr) { return arr->begin(); }

	template<class T>
	array_iterator<T> end(array<T>* arr) { return arr->end(); }
}