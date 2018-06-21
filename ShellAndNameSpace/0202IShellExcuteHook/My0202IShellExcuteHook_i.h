

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Jun 15 18:15:18 2018
 */
/* Compiler settings for My0202IShellExcuteHook.idl:
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

#ifndef __My0202IShellExcuteHook_i_h__
#define __My0202IShellExcuteHook_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IShellCopAndExcuteHook_FWD_DEFINED__
#define __IShellCopAndExcuteHook_FWD_DEFINED__
typedef interface IShellCopAndExcuteHook IShellCopAndExcuteHook;
#endif 	/* __IShellCopAndExcuteHook_FWD_DEFINED__ */


#ifndef __ShellCopAndExcuteHook_FWD_DEFINED__
#define __ShellCopAndExcuteHook_FWD_DEFINED__

#ifdef __cplusplus
typedef class ShellCopAndExcuteHook ShellCopAndExcuteHook;
#else
typedef struct ShellCopAndExcuteHook ShellCopAndExcuteHook;
#endif /* __cplusplus */

#endif 	/* __ShellCopAndExcuteHook_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IShellCopAndExcuteHook_INTERFACE_DEFINED__
#define __IShellCopAndExcuteHook_INTERFACE_DEFINED__

/* interface IShellCopAndExcuteHook */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IShellCopAndExcuteHook;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ADC9133C-B1E5-4603-8264-0524D32F48C9")
    IShellCopAndExcuteHook : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IShellCopAndExcuteHookVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellCopAndExcuteHook * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellCopAndExcuteHook * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellCopAndExcuteHook * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IShellCopAndExcuteHook * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IShellCopAndExcuteHook * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IShellCopAndExcuteHook * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IShellCopAndExcuteHook * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IShellCopAndExcuteHookVtbl;

    interface IShellCopAndExcuteHook
    {
        CONST_VTBL struct IShellCopAndExcuteHookVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellCopAndExcuteHook_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IShellCopAndExcuteHook_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IShellCopAndExcuteHook_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IShellCopAndExcuteHook_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IShellCopAndExcuteHook_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IShellCopAndExcuteHook_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IShellCopAndExcuteHook_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IShellCopAndExcuteHook_INTERFACE_DEFINED__ */



#ifndef __My0202IShellExcuteHookLib_LIBRARY_DEFINED__
#define __My0202IShellExcuteHookLib_LIBRARY_DEFINED__

/* library My0202IShellExcuteHookLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_My0202IShellExcuteHookLib;

EXTERN_C const CLSID CLSID_ShellCopAndExcuteHook;

#ifdef __cplusplus

class DECLSPEC_UUID("05687CFA-195A-40DF-BDCE-B53489128046")
ShellCopAndExcuteHook;
#endif
#endif /* __My0202IShellExcuteHookLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


