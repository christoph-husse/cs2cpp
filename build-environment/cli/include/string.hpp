
namespace cli
{
	static ::System::String* make_string(const char* str);

	::System::String* make_string(const char* str)
	{
		return cli::gcnew<::System::String>(const_cast<signed char*>((const signed char*)str));
	}

	template<class T>
	::System::String* to_string(T value)
	{
		std::stringstream ss;
		ss << value;
		ss.flush();
		std::string s = ss.str();
		return cli::make_string(s.c_str());
	}

	template<int counter, int line> ::System::String* string(const char* str)
	{ 
		static ::System::String* value = make_string(str);
		return value;
	} 

	template<>
	::System::String* gcnew(signed char*&& str)
	{
		int len = std::char_traits<char>::length((char*)str);
		int strSize = len * sizeof(char16_t);
		::System::String* res = (::System::String*)malloc(sizeof(::System::String) + strSize);
		memset((void*)res, 0, sizeof(::System::String) + strSize);
		new (res) ::System::String();
		for(int i = 0; i < len; i++)
		{
			(&res->start_char)[i] = str[i];
		}
		res->length = len;

		return res;
	}

	template<class... T>
	static ::System::String* concat(T&&... args)
	{ 
		array<::System::Object*> arr = {static_cast<System::Object*>(args)...};
		return ::System::String::Concat8(&arr); 
	}

	static ::System::String* concat(std::initializer_list<::System::String*> args)
	{ 
		array<::System::String*> arr = args;
		return ::System::String::Concat9(&arr); 
	}
}
