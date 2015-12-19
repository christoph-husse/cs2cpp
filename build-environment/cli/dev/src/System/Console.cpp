
namespace System
{
	void Console::Write(bool value)
	{
		std::cout << (value ? "true" : "false");
	}

	void Console::Write2(char16_t value)
	{
		std::cout << value;
	}

	void Console::Write3(cli::array<char16_t>* buffer)
	{
		if(buffer != nullptr)
			for(auto e : buffer) std::cout << e;
	}

	void Console::Write4(Decimal value)
	{
		throw cli::gcnew<NotImplementedException>(_T("Console::WriteLine5"));
	}

	void Console::Write5(double value)
	{
		std::cout << value;
	}

	void Console::Write6(int32_t value)
	{
		std::cout << value;
	}

	void Console::Write7(int64_t value)
	{
		std::cout << value;
	}

	void Console::Write8(Object* value)
	{
		if(value == nullptr)
			Write10(_T("null"));
		else
			Write10(value->ToString_1636a0751cb9ac11());
	}

	void Console::Write9(float value)
	{
		std::cout << value;
	}

	void Console::Write10(String* value)
	{
		if(value == nullptr)
			std::cout << "null";
		else
		{
			auto str = &value->start_char;
			for(int i = 0; i < value->length; i++)
			{
				std::cout << (char)str[i];
			}
		}
	}

	void Console::Write11(uint32_t value)
	{
		std::cout << value;
	}

	void Console::Write12(uint64_t value)
	{
		std::cout << value;
	}


	void Console::WriteLine()
	{
		std::cout << std::endl;
	}

	void Console::WriteLine2(bool value)
	{
		Write(value);
		std::cout << std::endl;
	}

	void Console::WriteLine3(char16_t value)
	{
		Write2(value);
		std::cout << std::endl;
	}

	void Console::WriteLine5(Decimal value)
	{
		Write4(value);
		std::cout << std::endl;
	}

	void Console::WriteLine6(double value)
	{
		Write5(value);
		std::cout << std::endl;
	}

	void Console::WriteLine7(int32_t value)
	{
		Write6(value);
		std::cout << std::endl;
	}
 
	void Console::WriteLine8(int64_t value)
	{
		Write7(value);
		std::cout << std::endl;
	}

	void Console::WriteLine10(float value)
	{
		Write9(value);
		std::cout << std::endl;
	}

	void Console::WriteLine11(String* value)
	{
		Write10(value);
		std::cout << std::endl;
	}

	void Console::WriteLine12(uint32_t value)
	{
		Write11(value);
		std::cout << std::endl;
	}

	void Console::WriteLine13(uint64_t value)
	{
		Write12(value);
		std::cout << std::endl;
	}

	String* Console::ReadLine()
	{
		std::string str;
		std::cin >> str;
		return cli::make_string(str.c_str());
	}
}
