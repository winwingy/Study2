// dllmain.h : 模块类的声明。

class CShellIconUseModule : public ATL::CAtlDllModuleT< CShellIconUseModule >
{
public :
	DECLARE_LIBID(LIBID_ShellIconUseLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SHELLICONUSE, "{D780983E-D4BA-48D1-9F98-9284399B172E}")
};

extern class CShellIconUseModule _AtlModule;
