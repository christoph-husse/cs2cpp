
namespace cli
{
	template<class TObject, class ... TArgs>
	static TObject* gcnew(TArgs&&... args)
	{
		TObject* res = (TObject*)malloc(sizeof(TObject));
		memset((void*)res, 0, sizeof(TObject));
		new (res) TObject();
		res->constructor(std::forward<TArgs>(args)...);
		return res;
	}

	template<class TObject>
	TObject ctor()
	{
		unsigned char buf[sizeof(TObject)];
		memset((void*)buf, 0, sizeof(TObject));
		new (buf) TObject();
		return *((TObject*)buf);
	}

	template<class TObject, class ... TArgs>
	TObject ctor(TArgs&&... args)
	{
		unsigned char buf[sizeof(TObject)];
		memset((void*)buf, 0, sizeof(TObject));
		new (buf) TObject();
		TObject* res = (TObject*)buf;
		res->constructor(std::forward<TArgs>(args)...);
		return *res;
	}
}