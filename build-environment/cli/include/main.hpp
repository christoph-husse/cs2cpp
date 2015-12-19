namespace cli
{
	static int Main(int argc, char** argv, void main(cli::array<System::String*>*));

	static int Main(int argc, char** argv, void main(cli::array<System::String*>*))
	{

		try
		{
			cli::array<System::String*>* args = cli::gcnew<cli::array<System::String*>>(argc);

			for(int i = 0; i < argc; i++)
			{
				args->at(i) = cli::make_string(argv[i]);
			}

			main(args);
		}
		catch(System::Exception* e)
		{
			std::cout << std::endl << "[UNHANDLED MANAGED EXCEPTION]: ";
			::System::Console::WriteLine11(e->class_name);
			std::cout << " => ";
			::System::Console::WriteLine11(e->message);
		}
		catch(std::exception& e)
		{
			std::cout << std::endl << "[UNHANDLED NATIVE EXCEPTION]: " << e.what() << std::endl;
		}
		catch(...)
		{
			std::cout << std::endl << "[FATAL ERROR]: Unknown exception!" << std::endl;
		}

		return 0;
	}
}

#define DEFINE_MAIN_ROUTINE(proc) int main(int argc, char** argv) { return cli::Main(argc, argv, &(proc)); } 
