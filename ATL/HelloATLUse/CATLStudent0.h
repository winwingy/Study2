// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "F:\\WingyWork\\Study2\\ATL\\Debug\\HelloATL.dll" no_namespace
// CATLStudent0 ��װ��

class CATLStudent0 : public COleDispatchDriver
{
public:
	CATLStudent0(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CATLStudent0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CATLStudent0(const CATLStudent0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IATLStudent ����
public:
	long showName(long para1, long para2)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, para1, para2);
		return result;
	}
	CString subStr(LPCTSTR name, LPCTSTR text)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, name, text);
		return result;
	}

	// IATLStudent ����
public:

};
