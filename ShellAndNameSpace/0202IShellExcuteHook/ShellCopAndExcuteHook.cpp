// ShellCopAndExcuteHook.cpp : CShellCopAndExcuteHook 的实现

#include "stdafx.h"
#include "ShellCopAndExcuteHook.h"


// CShellCopAndExcuteHook


UINT CShellCopAndExcuteHook::CopyCallback(HWND hwnd, UINT wFunc, 
	UINT wFlags, LPCTSTR pszSrcFile, DWORD dwSrcAttribs, 
	LPCTSTR pszDestFile, DWORD dwDestAttribs)
{
	TCHAR  szMsg[1024];
	wsprintf(szMsg, _T("是否允许将目录从 %s 复制文件到 %s ?"), pszSrcFile, pszDestFile);
	return MessageBox(NULL, szMsg, _T("提示"), 
		MB_YESNO | MB_ICONQUESTION| MB_SETFOREGROUND);
}

// not hook, reason don't know
HRESULT CShellCopAndExcuteHook::Execute(LPSHELLEXECUTEINFO pei)
{
		
	TCHAR               szMsg[1024];
	FILE* fp = fopen("d:/test/test.log", "a");
	fseek(fp, 0, SEEK_END);
	char* p = "CShellCopAndExcuteHook::Execute\n";
	fwrite(p, 1, strlen(p), fp);
	fclose(fp);
	wsprintf(szMsg, _T("是否允许执行 %s %s ?"), pei->lpFile, pei->lpParameters);
	return (MessageBox(NULL, szMsg, _T("提示"),
		MB_YESNO | MB_ICONQUESTION | MB_SETFOREGROUND) == IDYES) ? S_FALSE : S_OK;
}
