

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Jun 20 10:54:55 2018
 */
/* Compiler settings for taskbar.idl:
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

#ifndef __taskbar_h_h__
#define __taskbar_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITaskbarList_FWD_DEFINED__
#define __ITaskbarList_FWD_DEFINED__
typedef interface ITaskbarList ITaskbarList;
#endif 	/* __ITaskbarList_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITaskbarList_INTERFACE_DEFINED__
#define __ITaskbarList_INTERFACE_DEFINED__

/* interface ITaskbarList */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_ITaskbarList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("56FDF342-FD6D-11d0-958A-006097C9A090")
    ITaskbarList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ActivateTab( 
            /* [in] */ HWND hWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTab( 
            /* [in] */ HWND hWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteTab( 
            /* [in] */ HWND hWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HrInit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActiveAlt( 
            /* [in] */ HWND hWnd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITaskbarListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITaskbarList * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITaskbarList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITaskbarList * This);
        
        HRESULT ( STDMETHODCALLTYPE *ActivateTab )( 
            ITaskbarList * This,
            /* [in] */ HWND hWnd);
        
        HRESULT ( STDMETHODCALLTYPE *AddTab )( 
            ITaskbarList * This,
            /* [in] */ HWND hWnd);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteTab )( 
            ITaskbarList * This,
            /* [in] */ HWND hWnd);
        
        HRESULT ( STDMETHODCALLTYPE *HrInit )( 
            ITaskbarList * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveAlt )( 
            ITaskbarList * This,
            /* [in] */ HWND hWnd);
        
        END_INTERFACE
    } ITaskbarListVtbl;

    interface ITaskbarList
    {
        CONST_VTBL struct ITaskbarListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITaskbarList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITaskbarList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITaskbarList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITaskbarList_ActivateTab(This,hWnd)	\
    ( (This)->lpVtbl -> ActivateTab(This,hWnd) ) 

#define ITaskbarList_AddTab(This,hWnd)	\
    ( (This)->lpVtbl -> AddTab(This,hWnd) ) 

#define ITaskbarList_DeleteTab(This,hWnd)	\
    ( (This)->lpVtbl -> DeleteTab(This,hWnd) ) 

#define ITaskbarList_HrInit(This)	\
    ( (This)->lpVtbl -> HrInit(This) ) 

#define ITaskbarList_SetActiveAlt(This,hWnd)	\
    ( (This)->lpVtbl -> SetActiveAlt(This,hWnd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITaskbarList_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


