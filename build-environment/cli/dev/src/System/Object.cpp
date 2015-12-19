namespace System
{

	void Object::constructor()
	{
	}

	void Object::Finalize_b946fbc32e26afd6()
	{
	}

	bool Object::Equals_ed975d2f4a7d193e(Object* obj)
	{
		return this == obj;
	}

	bool Object::Equals2(Object* objA, Object* objB)
	{
		return objA == objB;
	}

	int32_t Object::GetHashCode_6648aef0f235ee6c()
	{
		return InternalGetHashCode(this);
	}

	Type* Object::GetType()
	{
		throw cli::gcnew<NotImplementedException>(_T("Object::GetType"));
	}

	Object* Object::MemberwiseClone()
	{
		throw cli::gcnew<NotImplementedException>(_T("Object::MemberwiseClone"));
	}

	String* Object::ToString_1636a0751cb9ac11()
	{
		throw cli::gcnew<NotImplementedException>(_T("Object::ToString_1636a0751cb9ac11"));
	}

	bool Object::ReferenceEquals(Object* objA, Object* objB)
	{
		return objA == objB;
	}

	int32_t Object::InternalGetHashCode(Object* o)
	{
		return (int32_t)((0x24FAC676E05FF7CE ^ (int64_t)o) % std::numeric_limits<int32_t>::max());
	}

	void* Object::obj_address()
	{
		return this;
	}

	void Object::FieldGetter(String* typeName, String* fieldName, Object* val)
	{
		throw cli::gcnew<NotImplementedException>(_T("Object::FieldGetter"));
	}

	void Object::FieldSetter(String* typeName, String* fieldName, Object* val)
	{
		throw cli::gcnew<NotImplementedException>(_T("Object::FieldSetter"));
	}
}