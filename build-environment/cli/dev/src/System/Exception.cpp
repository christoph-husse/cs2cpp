namespace System
{

	void Exception::constructor()
	{
		this->class_name = _T("System.Exception");
	}

    void Exception::constructor(String* message)
	{
    	this->class_name = _T("System.Exception");
    	this->message = message;
	}

    void Exception::constructor(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::constructor"));
	}

    void Exception::constructor(String* message, Exception* innerException)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::constructor"));
	}

    void Exception::SetMessage(String* s)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::SetMessage"));
	}

    void Exception::SetStackTrace(String* s)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::SetStackTrace"));
	}

    void Exception::AddFrames(Text::StringBuilder* sb, String* newline, String* unknown, Diagnostics::StackTrace* st)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::AddFrames"));
	}

    Exception* Exception::GetBaseException_3c80088934e2347b()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::GetBaseException_3c80088934e2347b"));
	}

    void Exception::GetObjectData_bc9b88d7eb43b6d8(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::GetObjectData_bc9b88d7eb43b6d8"));
	}

    String* Exception::ToString_1636a0751cb9ac11()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::ToString_1636a0751cb9ac11"));
	}

    Exception* Exception::FixRemotingException()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::FixRemotingException"));
	}

    void Exception::GetFullNameForStackTrace(Text::StringBuilder* sb, Reflection::MethodBase* mi)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::GetFullNameForStackTrace"));
	}

    void Exception::CaptureTrace()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::CaptureTrace"));
	}

    Type* Exception::GetType2()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::GetType2"));
	}

    Exception* Exception::get_InnerException()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_InnerException"));
	}

    String* Exception::get_HelpLink_523fb8e8db786972()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_HelpLink_523fb8e8db786972"));
	}

    String* Exception::set_HelpLink_dc2ca9999b121201(String* value)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::set_HelpLink_dc2ca9999b121201"));
	}

    int32_t Exception::get_HResult()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_HResult"));
	}

    int32_t Exception::set_HResult(int32_t value)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::set_HResult"));
	}

    String* Exception::get_ClassName()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_ClassName"));
	}

    String* Exception::get_Message_d211df4045b57cbf()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_Message_d211df4045b57cbf"));
	}

    String* Exception::get_Source_fe63b25bfdf963b9()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_Source_fe63b25bfdf963b9"));
	}

    String* Exception::set_Source_4a11d6bd5ca37e45(String* value)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::set_Source_4a11d6bd5ca37e45"));
	}

    String* Exception::get_StackTrace_f3fc28619b4f921()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_StackTrace_f3fc28619b4f921"));
	}

    Reflection::MethodBase* Exception::get_TargetSite()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_TargetSite"));
	}

    Collections::IDictionary* Exception::get_Data_6dba6d3fc94b4ca2()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_Data_6dba6d3fc94b4ca2"));
	}

    void Exception::add_SerializeObjectState(EventHandler2<Runtime::Serialization::SafeSerializationEventArgs*>* value)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::add_SerializeObjectState"));
	}

    void Exception::remove_SerializeObjectState(EventHandler2<Runtime::Serialization::SafeSerializationEventArgs*>* value)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::remove_SerializeObjectState"));
	}
        
    Exception* Exception::GetBaseException_253c3eebfe2fed4a()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::GetBaseException_253c3eebfe2fed4a"));
	}

    void Exception::GetObjectData_11b895a112e04409(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::GetObjectData_11b895a112e04409"));
	}

    void Exception::GetObjectData_cacfaf455dbef0a5(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::GetObjectData_cacfaf455dbef0a5"));
	}

    String* Exception::ToString_118e365de8f6791a()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::ToString_118e365de8f6791a"));
	}

    Type* Exception::GetType_74b1e7e5e0897ded()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::GetType_74b1e7e5e0897ded"));
	}

    Exception* Exception::get_InnerException_fee5e87d6404fbbb()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_InnerException_fee5e87d6404fbbb"));
	}

    String* Exception::get_HelpLink_c746e07ff3b23b1d()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_HelpLink_c746e07ff3b23b1d"));
	}

    String* Exception::set_HelpLink_c6d532780c9a4ffa(String* value)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::set_HelpLink_c6d532780c9a4ffa"));
	}

    String* Exception::get_Message_236e49c6b265ab9b()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_Message_236e49c6b265ab9b"));
	}

    String* Exception::get_Source_1ad0ababbacddeca()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_Source_1ad0ababbacddeca"));
	}

    String* Exception::set_Source_593b7183e562d37d(String* value)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::set_Source_593b7183e562d37d"));
	}

    String* Exception::get_StackTrace_eedb0499938735b7()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_StackTrace_eedb0499938735b7"));
	}

    Reflection::MethodBase* Exception::get_TargetSite_d5a44210796e0db()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::get_TargetSite_d5a44210796e0db"));
	}

    bool Exception::Equals_8745d1c324afa9f2(Object* obj)
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::Equals_8745d1c324afa9f2"));
	}

    int32_t Exception::GetHashCode_3274e1baccc4f8d1()
	{
		throw cli::gcnew<NotImplementedException>(_T("Exception::GetHashCode_3274e1baccc4f8d1"));
	}

}
