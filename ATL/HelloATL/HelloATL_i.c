

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IATLStudent,0x6EF7438D,0xF8E6,0x4BE1,0xB0,0x99,0x63,0x5C,0xCF,0x2D,0x03,0x65);


MIDL_DEFINE_GUID(IID, LIBID_HelloATLLib,0x854F2BA5,0x1599,0x41D0,0xAA,0x12,0x06,0x4E,0x66,0xB6,0x58,0xFD);


MIDL_DEFINE_GUID(IID, DIID__IATLStudentEvents,0xC5D4F1B7,0x203E,0x426F,0xBB,0x71,0x8E,0x14,0xDF,0xEA,0xD6,0x24);


MIDL_DEFINE_GUID(CLSID, CLSID_ATLStudent,0x8D5C2CB4,0x5CC9,0x45E2,0xAB,0x2A,0x78,0x86,0x41,0x5C,0x72,0xF1);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



