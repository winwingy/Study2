

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Jun 13 11:22:17 2018
 */
/* Compiler settings for HelloATL.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __HelloATL_i_h__
#define __HelloATL_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IATLStudent_FWD_DEFINED__
#define __IATLStudent_FWD_DEFINED__
typedef interface IATLStudent IATLStudent;
#endif 	/* __IATLStudent_FWD_DEFINED__ */


#ifndef ___IATLStudentEvents_FWD_DEFINED__
#define ___IATLStudentEvents_FWD_DEFINED__
typedef interface _IATLStudentEvents _IATLStudentEvents;
#endif 	/* ___IATLStudentEvents_FWD_DEFINED__ */


#ifndef __ATLStudent_FWD_DEFINED__
#define __ATLStudent_FWD_DEFINED__

#ifdef __cplusplus
typedef class ATLStudent ATLStudent;
#else
typedef struct ATLStudent ATLStudent;
#endif /* __cplusplus */

#endif 	/* __ATLStudent_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IATLStudent_INTERFACE_DEFINED__
#define __IATLStudent_INTERFACE_DEFINED__

/* interface IATLStudent */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IATLStudent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6EF7438D-F8E6-4BE1-B099-635CCF2D0365")
    IATLStudent : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE showName( 
            /* [in] */ LONG para1,
            LONG para2,
            /* [retval][out] */ LONG *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE subStr( 
            /* [in] */ BSTR name,
            /* [in] */ BSTR text,
            /* [retval][out] */ BSTR *showText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IATLStudentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IATLStudent * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IATLStudent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IATLStudent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IATLStudent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IATLStudent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IATLStudent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IATLStudent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *showName )( 
            IATLStudent * This,
            /* [in] */ LONG para1,
            LONG para2,
            /* [retval][out] */ LONG *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *subStr )( 
            IATLStudent * This,
            /* [in] */ BSTR name,
            /* [in] */ BSTR text,
            /* [retval][out] */ BSTR *showText);
        
        END_INTERFACE
    } IATLStudentVtbl;

    interface IATLStudent
    {
        CONST_VTBL struct IATLStudentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IATLStudent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IATLStudent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IATLStudent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IATLStudent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IATLStudent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IATLStudent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IATLStudent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IATLStudent_showName(This,para1,para2,result)	\
    ( (This)->lpVtbl -> showName(This,para1,para2,result) ) 

#define IATLStudent_subStr(This,name,text,showText)	\
    ( (This)->lpVtbl -> subStr(This,name,text,showText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IATLStudent_INTERFACE_DEFINED__ */



#ifndef __HelloATLLib_LIBRARY_DEFINED__
#define __HelloATLLib_LIBRARY_DEFINED__

/* library HelloATLLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_HelloATLLib;

#ifndef ___IATLStudentEvents_DISPINTERFACE_DEFINED__
#define ___IATLStudentEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IATLStudentEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IATLStudentEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C5D4F1B7-203E-426F-BB71-8E14DFEAD624")
    _IATLStudentEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IATLStudentEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IATLStudentEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IATLStudentEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IATLStudentEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IATLStudentEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IATLStudentEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IATLStudentEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IATLStudentEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IATLStudentEventsVtbl;

    interface _IATLStudentEvents
    {
        CONST_VTBL struct _IATLStudentEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IATLStudentEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IATLStudentEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IATLStudentEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IATLStudentEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IATLStudentEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IATLStudentEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IATLStudentEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IATLStudentEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ATLStudent;

#ifdef __cplusplus

class DECLSPEC_UUID("8D5C2CB4-5CC9-45E2-AB2A-7886415C72F1")
ATLStudent;
#endif
#endif /* __HelloATLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


