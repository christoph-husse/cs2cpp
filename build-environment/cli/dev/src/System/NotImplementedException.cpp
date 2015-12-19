namespace System
{        
	void NotImplementedException::constructor()
	{
		Exception::constructor();
		this->class_name = _T("System.NotImplementedException");
	}

    void NotImplementedException::constructor(String* message)
	{
    	Exception::constructor(message);
    	this->class_name = _T("System.NotImplementedException");
	}

    void NotImplementedException::constructor(String* message, Exception* inner)
	{
		throw cli::gcnew<NotImplementedException>(_T("NotImplementedException::constructor"));
	}

    void NotImplementedException::constructor(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context)
	{
		throw cli::gcnew<NotImplementedException>(_T("NotImplementedException::constructor"));
	}


    void ArgumentException::constructor()
    {
    	Exception::constructor();
    	this->class_name = _T("System.ArgumentException");
    }
    void ArgumentException::constructor(String* message) { constructor(); this->message = message; }
    void ArgumentException::constructor(String* message, Exception* innerException) { constructor(message); }
    void ArgumentException::constructor(String* message, String* paramName) { constructor(message); this->param_name = paramName; }
    void ArgumentException::constructor(String* message, String* paramName, Exception* innerException) { constructor(message); this->param_name = paramName; }
    void ArgumentException::GetObjectData_bc9b88d7eb43b6d8(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context) { throw cli::gcnew<NotImplementedException>(_T("NotImplementedException::GetObjectData_bc9b88d7eb43b6d8")); }
    String* ArgumentException::get_ParamName_299aa21f59781bb8() { throw cli::gcnew<NotImplementedException>(_T("NotImplementedException::get_ParamName_299aa21f59781bb8")); }
    String* ArgumentException::get_Message_d211df4045b57cbf() { throw cli::gcnew<NotImplementedException>(_T("NotImplementedException::get_Message_d211df4045b57cbf")); }

    void ArgumentOutOfRangeException::constructor()
	{
    	ArgumentException::constructor();
		this->class_name = _T("System.ArgumentOutOfRangeException");
	}
	void ArgumentOutOfRangeException::constructor(String* paramName) { constructor(); this->param_name = paramName;  }
	void ArgumentOutOfRangeException::constructor(String* paramName, String* message) { constructor(paramName); this->message = message; }
	void ArgumentOutOfRangeException::constructor(String* paramName, Object* actualValue, String* message) { constructor(paramName); this->message = message; }
	void ArgumentOutOfRangeException::constructor(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context) { constructor(); }
	void ArgumentOutOfRangeException::constructor(String* message, Exception* innerException) { constructor(); this->message = message; }
	void ArgumentOutOfRangeException::GetObjectData_bc9b88d7eb43b6d8(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context) { throw cli::gcnew<NotImplementedException>(_T("NotImplementedException::GetObjectData_bc9b88d7eb43b6d8")); }
	Object* ArgumentOutOfRangeException::get_ActualValue_aa5ed9bfb68c696f() { throw cli::gcnew<NotImplementedException>(_T("NotImplementedException::get_ActualValue_aa5ed9bfb68c696f")); }
	String* ArgumentOutOfRangeException::get_Message_d211df4045b57cbf() { throw cli::gcnew<NotImplementedException>(_T("NotImplementedException::get_Message_d211df4045b57cbf")); }

    void ArgumentNullException::constructor()
	{
    	ArgumentException::constructor();
		this->class_name = _T("System.ArgumentNullException");
	}
	void ArgumentNullException::constructor(String* paramName) { constructor(); this->param_name = paramName;  }
	void ArgumentNullException::constructor(String* paramName, String* message) { constructor(paramName); this->message = message;  }
	void ArgumentNullException::constructor(String* message, Exception* innerException) { constructor(); this->message = message;  }
	void ArgumentNullException::constructor(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context) { constructor(); }

    void SystemException::constructor()
	{
    	Exception::constructor();
		this->class_name = _T("System.SystemException");
	}
    void SystemException::constructor(String* message) { constructor(); this->message = message;  }
    void SystemException::constructor(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context) { throw cli::gcnew<NotImplementedException>(_T("SystemException::constructor")); }
    void SystemException::constructor(String* message, Exception* innerException) { throw cli::gcnew<NotImplementedException>(_T("SystemException::constructor")); }

    void InvalidCastException::constructor()
	{
    	SystemException::constructor();
		this->class_name = _T("System.InvalidCastException");
	}
    void InvalidCastException::constructor(String* message) { constructor(); this->message = message;  }
    void InvalidCastException::constructor(String* message, Exception* innerException) { throw cli::gcnew<NotImplementedException>(_T("InvalidCastException::constructor")); }
    void InvalidCastException::constructor(String* message, int32_t errorCode) { throw cli::gcnew<NotImplementedException>(_T("InvalidCastException::constructor")); }
    void InvalidCastException::constructor(Runtime::Serialization::SerializationInfo* info, Runtime::Serialization::StreamingContext context) { throw cli::gcnew<NotImplementedException>(_T("InvalidCastException::constructor")); }

}
