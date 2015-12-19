#ifndef _COMMON_LANGUAGE_INFRASTRUCTURE_H_
#define _COMMON_LANGUAGE_INFRASTRUCTURE_H_

#include <stdint.h>
#include <stdlib.h>
#include <limits>
#include <array>
#include <string>
#include <vector>
#include <functional>
#include <type_traits>
#include <initializer_list>
#include <cstring>
#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <mutex>

// undefine all those fancy C macros... they are an eternal curse.
#undef EOF

#define MANAGED_API

#define __arglist

namespace System 
{
	struct Object;
	struct ValueType;
	struct Array;
	struct Type;
	struct String;
	struct Decimal;

	enum class TypeCode;
}

typedef bool bool_t;

namespace cli
{
	// creates a string constant. Each instanciation will have a unique number,
	// thanks to "__COUNTER__", and thus have its own static function variable,
	// where the System::String for the string constant is saved.
	#define _T(str) ::cli::string<__COUNTER__, __LINE__>(str)

	template<int counter, int line> ::System::String* string(const char* str);
	template<class T> ::System::Decimal decimal(const char* value);

	template<class T> struct delegate;
	template<class T> class array;
 

	template<class TTo = ::System::Object*, class TFrom> TTo box(TFrom from);
	template<class TTo, class TFrom> TTo unbox(TFrom from);

	template<class TTo, class TFrom> 
	static typename std::enable_if<std::is_pointer<TFrom>::value && !std::is_pointer<TTo>::value, TTo>::type cast(TFrom from);

	template<class TTo, class TFrom> 
	static typename std::enable_if<std::is_pointer<TFrom>::value && std::is_pointer<TTo>::value, TTo>::type cast(TFrom from);

	template<class TTo, class TFrom> 
	static typename std::enable_if<!std::is_pointer<TFrom>::value && !std::is_pointer<TTo>::value, TTo>::type cast(TFrom from);

	template<typename T> 
	struct typeof
	{
		static constexpr System::Type* info = nullptr;
	};

	template<class T> struct enum_to_impl {};
	template<class TObject, class ... TArgs> static TObject* gcnew(TArgs&&... args);
	template<> ::System::String* gcnew(signed char*&& str);
	static ::System::String* make_string(const char* str);
	::System::String* make_string(const char* str);
	template<class T> ::System::String* to_string(T value);
	template<class TObject> TObject ctor();
	template<class TObject, class ... TArgs> TObject ctor(TArgs&&... args);
	template<class T> T&& unchecked(T&& val) { return std::forward<T>(val); }
	template<class T> T&& checked(T&& val) { return std::forward<T>(val); }
}; 

#endif
