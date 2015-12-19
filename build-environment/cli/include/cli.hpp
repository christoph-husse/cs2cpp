#pragma once


#include "array.hpp"
#include "casts.hpp"
#include "delegates.hpp"
#include "guards.hpp"
#include "main.hpp"
#include "memory.hpp"
#include "string.hpp"
#include "enumerable.hpp"

namespace cli
{
	template<class T>
	::System::Decimal decimal(const char* str)
	{ 
		throw cli::gcnew<::System::NotImplementedException>(_T("System::Decimal"));
	}

	template<class T>
	T unwrap_nullable(::System::Nullable2<T> nullable) { return T(); }

	template<class T>
	::System::Nullable2<T> wrap_nullable(T nullable) { return ::System::Nullable2<T>(); }
}