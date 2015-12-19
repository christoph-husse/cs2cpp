

namespace System
{
	void ValueType::constructor()
	{
	}

	bool ValueType::InternalEquals(Object* o1, Object* o2, cli::array<Object*>* fields)
	{
		throw cli::gcnew<NotImplementedException>(_T("ValueType::InternalEquals"));
	}

	bool ValueType::DefaultEquals(Object* o1, Object* o2)
	{
		throw cli::gcnew<NotImplementedException>(_T("ValueType::DefaultEquals"));
	}

	bool ValueType::Equals_ed975d2f4a7d193e(Object* obj)
	{
		throw cli::gcnew<NotImplementedException>(_T("ValueType::Equals_ed975d2f4a7d193e"));
	}

	int32_t ValueType::InternalGetHashCode2(Object* o, cli::array<Object*>* fields)
	{
		throw cli::gcnew<NotImplementedException>(_T("ValueType::InternalGetHashCode2"));
	}

	int32_t ValueType::GetHashCode_6648aef0f235ee6c()
	{
		throw cli::gcnew<NotImplementedException>(_T("ValueType::GetHashCode_6648aef0f235ee6c"));
	}

	String* ValueType::ToString_1636a0751cb9ac11()
	{
		throw cli::gcnew<NotImplementedException>(_T("ValueType::ToString_1636a0751cb9ac11"));
	}

}