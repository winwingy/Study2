// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "F:\\WingyWork\\Study2\\ATL\\Debug\\HelloATL.dll" no_namespace
// CATLStudent 包装类

class CATLStudent : public COleDispatchDriver
{
public:
	CATLStudent(){} // 调用 COleDispatchDriver 默认构造函数
	CATLStudent(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CATLStudent(const CATLStudent& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IATLStudent 方法
public:
	long showName(long para1, long para2)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, para1, para2);
		return result;
	}

	// IATLStudent 属性
public:

};
