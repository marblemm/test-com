

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ComProject.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ComProject_h_h__
#define __ComProject_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IBeginningCOM_FWD_DEFINED__
#define __IBeginningCOM_FWD_DEFINED__
typedef interface IBeginningCOM IBeginningCOM;

#endif 	/* __IBeginningCOM_FWD_DEFINED__ */


#ifndef __BeginningCOM_FWD_DEFINED__
#define __BeginningCOM_FWD_DEFINED__

#ifdef __cplusplus
typedef class BeginningCOM BeginningCOM;
#else
typedef struct BeginningCOM BeginningCOM;
#endif /* __cplusplus */

#endif 	/* __BeginningCOM_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IBeginningCOM_INTERFACE_DEFINED__
#define __IBeginningCOM_INTERFACE_DEFINED__

/* interface IBeginningCOM */
/* [uuid][object] */ 


EXTERN_C const IID IID_IBeginningCOM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("93C3840F-AD5A-4020-AAAB-313C4B61B184")
    IBeginningCOM : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Sum( 
            /* [in] */ int a,
            /* [in] */ int b,
            /* [retval][out] */ int *sum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBeginningCOMVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBeginningCOM * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBeginningCOM * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBeginningCOM * This);
        
        HRESULT ( STDMETHODCALLTYPE *Sum )( 
            IBeginningCOM * This,
            /* [in] */ int a,
            /* [in] */ int b,
            /* [retval][out] */ int *sum);
        
        END_INTERFACE
    } IBeginningCOMVtbl;

    interface IBeginningCOM
    {
        CONST_VTBL struct IBeginningCOMVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBeginningCOM_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBeginningCOM_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBeginningCOM_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBeginningCOM_Sum(This,a,b,sum)	\
    ( (This)->lpVtbl -> Sum(This,a,b,sum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBeginningCOM_INTERFACE_DEFINED__ */



#ifndef __BEGINNINGCOMLib_LIBRARY_DEFINED__
#define __BEGINNINGCOMLib_LIBRARY_DEFINED__

/* library BEGINNINGCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_BEGINNINGCOMLib;

EXTERN_C const CLSID CLSID_BeginningCOM;

#ifdef __cplusplus

class DECLSPEC_UUID("586CDC7B-09F1-4f44-A110-F0E604AED81E")
BeginningCOM;
#endif
#endif /* __BEGINNINGCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


