

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Jun 14 17:24:31 2018
 */
/* Compiler settings for ShellIconUse.idl:
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

#ifndef __ShellIconUse_i_h__
#define __ShellIconUse_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITxtExt_FWD_DEFINED__
#define __ITxtExt_FWD_DEFINED__
typedef interface ITxtExt ITxtExt;
#endif 	/* __ITxtExt_FWD_DEFINED__ */


#ifndef __TxtExt_FWD_DEFINED__
#define __TxtExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class TxtExt TxtExt;
#else
typedef struct TxtExt TxtExt;
#endif /* __cplusplus */

#endif 	/* __TxtExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITxtExt_INTERFACE_DEFINED__
#define __ITxtExt_INTERFACE_DEFINED__

/* interface ITxtExt */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITxtExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0EC7E82E-2BD7-45C2-BA08-17D4FD30D963")
    ITxtExt : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ITxtExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITxtExt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITxtExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITxtExt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITxtExt * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITxtExt * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITxtExt * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITxtExt * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ITxtExtVtbl;

    interface ITxtExt
    {
        CONST_VTBL struct ITxtExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITxtExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITxtExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITxtExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITxtExt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITxtExt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITxtExt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITxtExt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITxtExt_INTERFACE_DEFINED__ */



#ifndef __ShellIconUseLib_LIBRARY_DEFINED__
#define __ShellIconUseLib_LIBRARY_DEFINED__

/* library ShellIconUseLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ShellIconUseLib;

EXTERN_C const CLSID CLSID_TxtExt;

#ifdef __cplusplus

class DECLSPEC_UUID("A20C6BA6-7F77-4A1B-B68A-EB87CDACD87A")
TxtExt;
#endif
#endif /* __ShellIconUseLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


