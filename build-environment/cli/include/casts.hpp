

namespace cli
{
	///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////// import()
	///////////////////////////////////////////////////////////////////////////////////////

	static ::System::Boolean import(bool_t val) { return val; }
	static ::System::Byte import(unsigned char val) { return val; }
	static ::System::Char import(char16_t val) { return val; }
	static ::System::Double import(double val) { return val; }
	static ::System::Single import(float val) { return val; }
	static ::System::Int32 import(int32_t val) { return val; }
	static ::System::Int64 import(int64_t val) { return val; }

	template<class T>
	static typename std::enable_if<std::is_same<T, void*>::value, ::System::IntPtr>::type import(T val) { return val; }

	static ::System::SByte import(signed char val) { return val; }
	static ::System::Int16 import(int16_t val) { return val; }
	static ::System::UInt32 import(uint32_t val) { return val; }
	static ::System::UInt64 import(uint64_t val) { return val; }
	static ::System::UInt16 import(uint16_t val) { return val; }

	static ::System::Boolean import(::System::Boolean val) { return val; }
	static ::System::Byte import(::System::Byte val) { return val; }
	static ::System::Char import(::System::Char val) { return val; }
	static ::System::Double import(::System::Double val) { return val; }
	static ::System::Single import(::System::Single val) { return val; }
	static ::System::Int32 import(::System::Int32 val) { return val; }
	static ::System::Int64 import(::System::Int64 val) { return val; }
	static ::System::IntPtr import(::System::IntPtr val) { return val; }
	static ::System::UIntPtr import(::System::UIntPtr val) { return val; }
	static ::System::SByte import(::System::SByte val) { return val; }
	static ::System::Int16 import(::System::Int16 val) { return val; }
	static ::System::UInt32 import(::System::UInt32 val) { return val; }
	static ::System::UInt64 import(::System::UInt64 val) { return val; }
	static ::System::UInt16 import(::System::UInt16 val) { return val; }

	template<class T>
	static typename std::enable_if<std::is_pointer<T>::value && std::is_base_of<::System::Object, typename std::remove_pointer<T>::type>::value, T>::type import(T val) { return val; }

	template<class T>
	static typename std::enable_if<std::is_enum<T>::value, typename cli::enum_to_impl<T>::type>::type import(T val) { return val; }

	template<typename T> struct is_importable 
	{
		static const bool value = 
			std::is_same<T, void*>::value ||
			(!std::is_pointer<T>::value &&
				(std::is_enum<T>::value ||
				std::is_arithmetic<T>::value ||
				std::is_same<T, bool_t>::value ||
				std::is_same<T, ::System::Boolean>::value ||
				std::is_same<T, ::System::Byte>::value ||
				std::is_same<T, ::System::Char>::value ||
				std::is_same<T, ::System::Double>::value ||
				std::is_same<T, ::System::Single>::value ||
				std::is_same<T, ::System::Int32>::value ||
				std::is_same<T, ::System::Int64>::value ||
				std::is_same<T, ::System::IntPtr>::value ||
				std::is_same<T, ::System::UIntPtr>::value ||
				std::is_same<T, ::System::SByte>::value ||
				std::is_same<T, ::System::Int16>::value ||
				std::is_same<T, ::System::UInt32>::value ||
				std::is_same<T, ::System::UInt64>::value ||
				std::is_same<T, ::System::UInt16>::value))
		;
	};

	///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////// unbox()
	///////////////////////////////////////////////////////////////////////////////////////

	template<class T>
	typename std::enable_if<std::is_base_of<::System::Object, typename std::remove_pointer<T>::type>::value, T>::type invalid_cast_on_null(T value)
	{
		if(value == nullptr)
			throw cli::gcnew<::System::InvalidCastException>();

		return value;
	}

	template<class TTo, class TFrom>
	typename std::enable_if<std::is_enum<TTo>::value, TTo>::type unbox_internal(TFrom from)
	{
		return *invalid_cast_on_null(dynamic_cast<typename enum_to_impl<TTo>::type*>(from));
	}

	template<class TTo, class TFrom>
	typename std::enable_if<std::is_pointer<TTo>::value && !is_importable<TTo>::value, TTo>::type unbox_internal(TFrom from)
	{
		return invalid_cast_on_null(dynamic_cast<TTo>(from));
	}

	template<class TTo, class TFrom>
	typename std::enable_if<!is_importable<TTo>::value && !std::is_enum<TTo>::value && !std::is_pointer<TTo>::value, TTo>::type unbox_internal(TFrom from)
	{
		return *invalid_cast_on_null(dynamic_cast<TTo*>(from));
	}

	template<class TTo, class TFrom>
	typename std::enable_if<is_importable<TTo>::value && !std::is_enum<TTo>::value, TTo>::type unbox_internal(TFrom from)
	{
		typedef decltype(import(TTo())) type;
		return *invalid_cast_on_null(dynamic_cast<type*>(from));
	}

	template<class TTo, class TFrom> TTo unbox(TFrom from)
	{
		return unbox_internal<TTo>(from);
	}

	///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////// cast()
	///////////////////////////////////////////////////////////////////////////////////////

	template<class TTo, class TFrom> 
	static typename std::enable_if<std::is_pointer<TFrom>::value && !std::is_pointer<TTo>::value, TTo>::type cast(TFrom from)
	{
		return unbox<TTo>(from);
	}

	template<class TTo, class TFrom> 
	static typename std::enable_if<std::is_pointer<TFrom>::value && std::is_pointer<TTo>::value, TTo>::type cast(TFrom from)
	{
		return dynamic_cast<TTo>(from);
	}

	template<class TTo, class TFrom> 
	static typename std::enable_if<!std::is_pointer<TFrom>::value && !std::is_pointer<TTo>::value, TTo>::type cast(TFrom from)
	{
		return static_cast<TTo>(from);
	}

	///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////// box()
	///////////////////////////////////////////////////////////////////////////////////////

	template<class TTo, class TFrom> 
	static typename std::enable_if<!std::is_pointer<TFrom>::value && !std::is_pointer<TTo>::value, TTo>::type 
	box_internal(TFrom from)
	{
		return static_cast<TTo>(from);
	}

	template<class TTo, class TFrom> 
	static typename std::enable_if<std::is_same<TFrom, void*>::value, TTo>::type 
	box_internal(TFrom from)
	{
		return static_cast<TTo>(new decltype(import(from)) (import(from)));
	}

	template<class TTo, class TFrom> 
	static typename std::enable_if<
		is_importable<TFrom>::value && 
			!std::is_same<TFrom, void*>::value &&
			std::is_base_of<::System::Object, typename std::remove_pointer<TTo>::type>::value && 
			std::is_pointer<TTo>::value
		, 
		TTo>::type 
	box_internal(TFrom from)
	{
		return static_cast<TTo>(new decltype(import(from)) (import(from)));
	}

	template<class TTo, class TFrom> 
	static typename std::enable_if<
		!is_importable<TFrom>::value && !std::is_pointer<TFrom>::value &&
			!std::is_same<TFrom, void*>::value &&
			std::is_base_of<::System::Object, typename std::remove_pointer<TTo>::type>::value && 
			std::is_base_of<::System::Object, TFrom>::value && 
			std::is_pointer<TTo>::value
		, 
		TTo>::type 
	box_internal(TFrom from)
	{
		return static_cast<TTo>(new TFrom(from));
	}

	template<class TTo, class TFrom> 
	static typename std::enable_if<
		std::is_pointer<TFrom>::value && 
			!std::is_same<TFrom, void*>::value &&
			std::is_pointer<TTo>::value
		, 
		TTo>::type box_internal(TFrom from)
	{
		return dynamic_cast<TTo>(from);
	}

	template<class TTo, class TFrom> TTo box(TFrom from)
	{
		return box_internal<TTo>(from);
	}

	///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////// as()
	///////////////////////////////////////////////////////////////////////////////////////

	template<class TDst, class TSrc> 
	typename std::enable_if
	<
		!is_importable<TSrc>::value,
		TDst
	>::type as(TSrc src) 
	{ 
		return dynamic_cast<TDst>(src); 
	}

	template<class TDst, class TSrc> 
	typename std::enable_if
	<
		is_importable<TSrc>::value,
		TDst
	>::type 
	as(TSrc src) 
	{
		static_assert(std::is_base_of<System::Object, typename std::remove_pointer<TDst>::type>::value, "Target type must be derived from System::Object.");
		static_assert(std::is_pointer<TDst>::value, "Operator must be used with nullable type. (Importable types can only be converted to interfaces with this operator)");
		// Conversion of value types to interface causes them to be duplicated and reallocated on the heap (C# specification)
		return dynamic_cast<TDst>(new decltype(import(src))(import(src))); 
	}

	///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////// is()
	///////////////////////////////////////////////////////////////////////////////////////

	template<typename TDst, typename TSrc> 
	typename std::enable_if
	<
		std::is_enum<TDst>::value,
		bool_t
	>::type is(TSrc src) { return dynamic_cast<cli::enumeration<TDst>*>(src) != nullptr; }

	template<typename TDst, typename TSrc> 
	typename std::enable_if
	<
		!std::is_enum<TDst>::value && !cli::is_importable<TDst>::value,
		bool_t
	>::type is(TSrc src) { return dynamic_cast<typename std::remove_pointer<TDst>::type*>(box(src)) != nullptr; }

	template<typename TDst, typename TSrc>
		typename std::enable_if
		<
			!std::is_enum<TDst>::value && cli::is_importable<TDst>::value,
			bool_t
		>::type is(TSrc src) { return dynamic_cast<decltype(import(TDst()))*>(box(src)) != nullptr; }
}
