// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "F:\\WingyWork\\Study2\\ATL\\Debug\\HelloATL.dll" no_namespace
// CATLStudent ��װ��

class CATLStudent : public COleDispatchDriver
{
public:
	CATLStudent(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CATLStudent(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CATLStudent(const CATLStudent& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

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

	// IATLStudent ����
public:

};
