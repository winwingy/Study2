// dllmain.h : 模块类的声明。

class CMy0202IShellExcuteHookModule : public ATL::CAtlDllModuleT< CMy0202IShellExcuteHookModule >
{
public :
	DECLARE_LIBID(LIBID_My0202IShellExcuteHookLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MY0202ISHELLEXCUTEHOOK, "{22284BB7-54DA-4104-9C38-6115E7B66194}")
};

extern class CMy0202IShellExcuteHookModule _AtlModule;
