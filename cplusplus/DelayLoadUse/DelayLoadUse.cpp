// DelayLoadUse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "windows.h"
#include <delayimp.h>
#include "../DelayLoadDll/DelayClass.h"
#include "strsafe.h"
#pragma comment(lib, "Delayimp.lib")
#pragma comment(lib, "DelayLoadDll.lib")

TCHAR g_szDelayLoadModuleName[] = TEXT("DelayLoadDll");  

LONG WINAPI DelayLoadDllExceptionFilter(PEXCEPTION_POINTERS pep);  

inline void chMB(PCSTR szMsg) {  
	char szTitle[MAX_PATH];  
	GetModuleFileNameA(NULL, szTitle, _countof(szTitle));  
	MessageBoxA(GetActiveWindow(), szMsg, szTitle, MB_OK);  
}  

// ���DLL�Ƿ�����  
void IsModuleLoaded(PCTSTR pszModuleName) {  

	HMODULE hmod = GetModuleHandle(pszModuleName);  
	char sz[100];  
#ifdef UNICODE  
	StringCchPrintfA(sz, _countof(sz), "Module \"%s\" is %s loaded.",  
		pszModuleName, (hmod == NULL) ? "not" : " ");  
#else  
	StringCchPrintfA(sz, _countof(sz), "Module \"%s\" is %s loaded.",   
		pszModuleName, (hmod == NULL) ? "not" : " ");  
#endif  
	chMB(sz);  
}

int _tmain(int argc, _TCHAR* argv[])
{

	// ��װ�ṹ���쳣����  
	__try{  
		int x = 0;  
		IsModuleLoaded(g_szDelayLoadModuleName);  

		x = fnLib(1);  
		IsModuleLoaded(g_szDelayLoadModuleName);  

		x = fnLib2(2);  
		IsModuleLoaded(g_szDelayLoadModuleName);  

		PCSTR pszDll = "DelayLoadDll.dll";  

		__FUnloadDelayLoadedDLL2(pszDll);  

		IsModuleLoaded(g_szDelayLoadModuleName);  

		x = fnLib(1);  

		IsModuleLoaded(g_szDelayLoadModuleName);  

	}  
	__except(DelayLoadDllExceptionFilter(GetExceptionInformation()))  
	{  
		// Ԥ���ӿ�  
	}  
	system("pause");
	return 0;
}


/////////////////////////////////////////////////////////////////  
// �����쳣����  
LONG WINAPI DelayLoadDllExceptionFilter(PEXCEPTION_POINTERS pep)  
{  
	LONG lDisposition = EXCEPTION_EXECUTE_HANDLER;  
	PDelayLoadInfo pdli = PDelayLoadInfo(pep->ExceptionRecord->ExceptionInformation[0]);  

	char error_sz[500] = {0};  
	// �쳣�����֣���Ϊ���֣�����Ҫ���ṹ���쳣����  
	switch (pep->ExceptionRecord->ExceptionCode)  
	{  
	case VcppException(ERROR_SEVERITY_ERROR, ERROR_MOD_NOT_FOUND):  
		StringCchPrintfA(error_sz, _countof(error_sz), "Dll not found: %s", pdli->szDll);  
		break;  
	case VcppException(ERROR_SEVERITY_ERROR, ERROR_PROC_NOT_FOUND):  
		if (pdli->dlp.fImportByName) {  
			StringCchPrintfA(error_sz, _countof(error_sz), "Function %s was not found in %s",  
				pdli->dlp.szProcName, pdli->szDll);  
		}  
		else {  
			StringCchPrintfA(error_sz, _countof(error_sz), "Function ordinal %d was not found in %s",  
				pdli->dlp.dwOrdinal, pdli->szDll);  
		}  
		break;  
	default:  
		// û�в�׽���쳣  
		lDisposition = EXCEPTION_CONTINUE_SEARCH;  
		break;  
	}  

	if (lDisposition == EXCEPTION_EXECUTE_HANDLER)  
	{  
		chMB(error_sz);  
	}  

	return lDisposition;  

}  

///////////////////////////////////////////////////////////  
FARPROC WINAPI DliHook(unsigned dliNotify, PDelayLoadInfo pdli)  
{  
	FARPROC fp = NULL;  
	switch (dliNotify)  
	{  
	case dliStartProcessing:  
		break;  

	case dliNotePreLoadLibrary:  
		fp = (FARPROC)(HMODULE)NULL;  
		break;  

	case dliFailLoadLib:  
		fp = (FARPROC)(HMODULE)NULL;  
		break;  

	case dliNotePreGetProcAddress:  
		fp = (FARPROC)NULL;  
		break;  

	case dliFailGetProc:  
		fp = (FARPROC)NULL;  
		break;  

	case dliNoteEndProcessing:  
		break;  

	default:  
		break;  
	}  

	return fp;  

}  

////////////////////////////////////////////////////  
PfnDliHook __pfnDliNotifyHook2 = DliHook;  
PfnDliHook __pfnDliFailureHook2 = DliHook;

