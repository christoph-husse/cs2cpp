
namespace System
{
	String::String() { }

	String* String::Concat8(cli::array<Object*>* args)
	{
		auto strs = cli::gcnew<cli::array<String*>>(args->get_Length());

		for(int i = 0; i < args->get_Length(); i++)
		{
			auto e = args->at(i);
			strs->at(i) = e->ToString_1636a0751cb9ac11();
		}

		return Concat9(strs);
	}

	String* String::Concat9(cli::array<String*>* values)
	{
		int len = 0;
		for(auto e : values) len += e->length;

		int strSize = len * sizeof(char16_t);
		::System::String* res = (::System::String*)malloc(sizeof(::System::String) + strSize);
		::memset((void*)res, 0, sizeof(::System::String) + strSize);
		new (res)::System::String();

		int x = 0;
		for(auto e : values)
		{
			for(int i = 0; i < e->length; i++)
			{
				(&res->start_char)[x++] = (&e->start_char)[i];
			}
		}

		res->length = len;
		return res;
	}

	bool String::Equals_ed975d2f4a7d193e(Object* obj)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::Equals_ed975d2f4a7d193e"));
	}

	bool String::Equals_ea48fd0c13a733fe(String* value)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::Equals_ea48fd0c13a733fe"));
	}

	String* String::ToString_1636a0751cb9ac11()
	{
		return this;
	}

	int32_t String::GetHashCode_6648aef0f235ee6c()
	{
		throw cli::gcnew<NotImplementedException>(_T("String::GetHashCode_6648aef0f235ee6c"));
	}

	Object* String::Clone_d5efb96d327809c8()
	{
		throw cli::gcnew<NotImplementedException>(_T("String::Clone_d5efb96d327809c8"));
	}

	TypeCode String::GetTypeCode_701c52aeb2913904()
	{
		throw cli::gcnew<NotImplementedException>(_T("String::GetTypeCode_701c52aeb2913904"));
	}

	int32_t String::CompareTo_ed9d39205b7812f0(Object* value)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::CompareTo_ed9d39205b7812f0"));
	}

	int32_t String::CompareTo_8a8b7d6c83beb422(String* strB)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::CompareTo_8a8b7d6c83beb422"));
	}

	String* String::ToString_f121fe9e066b5628(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToString_f121fe9e066b5628"));
	}

	bool String::ToBoolean_f2ed021e3648bfba(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToBoolean_f2ed021e3648bfba"));
	}

	unsigned char String::ToByte_ce47dcc06c443b11(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToByte_ce47dcc06c443b11"));
	}

	char16_t String::ToChar_12adc960e23347fe(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToChar_12adc960e23347fe"));
	}

	DateTime String::ToDateTime_86b01e143a29eff2(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToDateTime_86b01e143a29eff2"));
	}

	Decimal String::ToDecimal_9c02fd5cdb5f6a0c(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToDecimal_9c02fd5cdb5f6a0c"));
	}

	double String::ToDouble_bf8714f37f489c82(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToDouble_bf8714f37f489c82"));
	}

	int16_t String::ToInt16_5e1de9bafa245bf2(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToInt16_5e1de9bafa245bf2"));
	}

	int32_t String::ToInt32_9e7108d4c09b7e42(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToInt32_9e7108d4c09b7e42"));
	}

	int64_t String::ToInt64_9801f9765e5301f6(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToInt64_9801f9765e5301f6"));
	}

	signed char String::ToSByte_e1f09487d48936db(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToSByte_e1f09487d48936db"));
	}

	float String::ToSingle_1cfd1ce472f9fad6(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToSingle_1cfd1ce472f9fad6"));
	}

	Object* String::ToType_bf083accfb52550a(Type* targetType, IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToType_bf083accfb52550a"));
	}

	uint16_t String::ToUInt16_1e02ae7e2827241a(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToUInt16_1e02ae7e2827241a"));
	}

	uint32_t String::ToUInt32_9a72f29c26115cfd(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToUInt32_9a72f29c26115cfd"));
	}

	uint64_t String::ToUInt64_fe563f2a802e4265(IFormatProvider* provider)
	{
		throw cli::gcnew<NotImplementedException>(_T("String::ToUInt64_fe563f2a802e4265"));
	}

	Collections::Generic::IEnumerator2<char16_t>* String::GetEnumerator_ad4887f30f9e4c5()
	{
		throw cli::gcnew<NotImplementedException>(_T("String::GetEnumerator_ad4887f30f9e4c5"));
	}

	Collections::IEnumerator* String::GetEnumerator_674ad93a972a4d67()
	{
		throw cli::gcnew<NotImplementedException>(_T("String::GetEnumerator_674ad93a972a4d67"));
	}


}
