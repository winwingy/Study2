

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Jun 14 17:27:31 2018
 */
/* Compiler settings for ShellUse.idl:
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

#ifndef __ShellUse_i_h__
#define __ShellUse_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IImportShellExt_FWD_DEFINED__
#define __IImportShellExt_FWD_DEFINED__
typedef interface IImportShellExt IImportShellExt;
#endif 	/* __IImportShellExt_FWD_DEFINED__ */


#ifndef __ImportShellExt_FWD_DEFINED__
#define __ImportShellExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImportShellExt ImportShellExt;
#else
typedef struct ImportShellExt ImportShellExt;
#endif /* __cplusplus */

#endif 	/* __ImportShellExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IImportShellExt_INTERFACE_DEFINED__
#define __IImportShellExt_INTERFACE_DEFINED__

/* interface IImportShellExt */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IImportShellExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("13F45D8B-2F37-4767-BBA7-C9602D1134D3")
    IImportShellExt : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IImportShellExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImportShellExt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImportShellExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImportShellExt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IImportShellExt * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IImportShellExt * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IImportShellExt * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IImportShellExt * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IImportShellExtVtbl;

    interface IImportShellExt
    {
        CONST_VTBL struct IImportShellExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImportShellExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImportShellExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImportShellExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImportShellExt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IImportShellExt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IImportShellExt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IImportShellExt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImportShellExt_INTERFACE_DEFINED__ */



#ifndef __ShellUseLib_LIBRARY_DEFINED__
#define __ShellUseLib_LIBRARY_DEFINED__

/* library ShellUseLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ShellUseLib;

EXTERN_C const CLSID CLSID_ImportShellExt;

#ifdef __cplusplus

class DECLSPEC_UUID("A8681CA0-C36D-40CD-AF4F-340F4A944B9B")
ImportShellExt;
#endif
#endif /* __ShellUseLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


