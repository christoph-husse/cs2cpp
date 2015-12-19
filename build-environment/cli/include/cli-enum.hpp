#ifndef _COMMON_LANGUAGE_INFRASTRUCTURE_ENUM_H_
#define _COMMON_LANGUAGE_INFRASTRUCTURE_ENUM_H_

namespace cli
{

	template<class T>
	struct enumeration : public System::Enum
	{
		/*template<class TEnum>
        static bool TryParse_1(String* value, TEnum result);
        template<class TEnum>
        static bool TryParse_12(String* value, bool ignoreCase, TEnum result);
		String* ToString3(IFormatProvider* provider);
        String* ToString4(String* format);
        String* ToString5(String* format, IFormatProvider* provider);
		bool HasFlag(Enum* flag);
		*/

		T value;

		virtual const std::vector<T>& GetValues() const = 0;
		virtual const std::vector<::System::String*>& GetStrings() const = 0;

		enumeration<T>* operator ->() { return this; }
		enumeration(const T& val) : value(val) { }

		::System::TypeCode GetTypeCode() { return GetTypeCode_701c52aeb2913904(); }
		int32_t CompareTo(::System::Object* target) { return CompareTo_ed9d39205b7812f0(target); }

        virtual ::System::String* ToString_1636a0751cb9ac11() override
		{
			for(int i = 0; i < GetValues().size(); i++)
			{
				if(GetValues()[i] == value)
					return GetStrings()[i];
			}

			return _T("[Unknown]");
		}

		virtual bool Equals_ed975d2f4a7d193e(::System::Object* obj) override { return CompareTo_ed9d39205b7812f0(obj) == 0; }

		virtual ::System::TypeCode GetTypeCode_701c52aeb2913904() override { return ::System::TypeCode(); }

		virtual int32_t CompareTo_ed9d39205b7812f0(::System::Object* obj) override;

		virtual int32_t GetHashCode_6648aef0f235ee6c() override { return (int32_t)value; }
	};
};


#endif
