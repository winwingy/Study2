// dllmain.h : 模块类的声明。

class CShellUseModule : public ATL::CAtlDllModuleT< CShellUseModule >
{
public :
	DECLARE_LIBID(LIBID_ShellUseLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SHELLUSE, "{17BCF724-56CF-4AE1-AB33-9CE4260CF3A8}")
};

extern class CShellUseModule _AtlModule;
