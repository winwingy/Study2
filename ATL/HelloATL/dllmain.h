// dllmain.h : 模块类的声明。

class CHelloATLModule : public ATL::CAtlDllModuleT< CHelloATLModule >
{
public :
	DECLARE_LIBID(LIBID_HelloATLLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_HELLOATL, "{69A238AD-74A1-41F8-A76B-B57A7183E73A}")
};

extern class CHelloATLModule _AtlModule;
