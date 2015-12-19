namespace Demo {
}
namespace Demo {
}
namespace Demo {
}
namespace Demo {
}
namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
}
 namespace Demo {
    
    template<class T>
    void CastTest::WriteCastCheck_1(System::Object* value, System::String* desc, bool expect) {
        bool res1 = true;
        try {
            T test = cli::unbox<T>(value);
        }
        catch(System::InvalidCastException*) {
            res1 = false;
        }
        bool res2 = cli::is<T>(value);
        System::Console::Write10(cli::concat(desc, _T(" = "), cli::box(res1), _T(" & "), cli::box(res2), _T(" (expected "), cli::box(expect), _T(")")));
        if(((res1 ==  expect) && (res2 ==  expect))) 
        {
            System::Console::WriteLine11(_T(" [OK]"));
        }
         else 
        {
            System::Console::WriteLine11(_T(" [ERROR]"));
        }
    }
    
    template<class T>
    void CastTest::WriteCastCheck_12(System::Object* value, T comp, System::String* desc, bool expect) {
        bool res1 = true;
        try {
            T test = cli::unbox<T>(value);
        }
        catch(System::InvalidCastException*) {
            res1 = false;
        }
        bool res2 = cli::is<T>(value);
        System::Console::Write10(cli::concat(desc, _T(" = "), cli::box(res1), _T(" & "), cli::box(res2), _T(" (expected "), cli::box(expect), _T(")")));
        if(((res1 ==  expect) && (res2 ==  expect))) 
        {
            if((!(expect) || value->Equals_ed975d2f4a7d193e(cli::box(comp)))) 
            {
                System::Console::WriteLine11(_T(" [OK]"));
            }
             else 
            {
                System::Console::WriteLine11(_T(" [ERROR]"));
            }
        }
         else 
        {
            System::Console::WriteLine11(_T(" [ERROR]"));
        }
    }
    
}
 namespace Demo {
    
}
 

