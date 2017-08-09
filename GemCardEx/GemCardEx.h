

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Aug 09 21:13:54 2017
 */
/* Compiler settings for GemCardEx.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
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

#ifndef __GemCardEx_h__
#define __GemCardEx_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISCardDatabaseEx_FWD_DEFINED__
#define __ISCardDatabaseEx_FWD_DEFINED__
typedef interface ISCardDatabaseEx ISCardDatabaseEx;

#endif 	/* __ISCardDatabaseEx_FWD_DEFINED__ */


#ifndef __SCardDatabaseEx_FWD_DEFINED__
#define __SCardDatabaseEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class SCardDatabaseEx SCardDatabaseEx;
#else
typedef struct SCardDatabaseEx SCardDatabaseEx;
#endif /* __cplusplus */

#endif 	/* __SCardDatabaseEx_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISCardDatabaseEx_INTERFACE_DEFINED__
#define __ISCardDatabaseEx_INTERFACE_DEFINED__

/* interface ISCardDatabaseEx */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISCardDatabaseEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FF1B206D-D909-4B7D-B82F-D7D6549815E3")
    ISCardDatabaseEx : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ListReaders( 
            /* [retval][out] */ VARIANT *ppReaders) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISCardDatabaseExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISCardDatabaseEx * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISCardDatabaseEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISCardDatabaseEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISCardDatabaseEx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISCardDatabaseEx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISCardDatabaseEx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISCardDatabaseEx * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ListReaders )( 
            ISCardDatabaseEx * This,
            /* [retval][out] */ VARIANT *ppReaders);
        
        END_INTERFACE
    } ISCardDatabaseExVtbl;

    interface ISCardDatabaseEx
    {
        CONST_VTBL struct ISCardDatabaseExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISCardDatabaseEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISCardDatabaseEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISCardDatabaseEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISCardDatabaseEx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISCardDatabaseEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISCardDatabaseEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISCardDatabaseEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISCardDatabaseEx_ListReaders(This,ppReaders)	\
    ( (This)->lpVtbl -> ListReaders(This,ppReaders) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISCardDatabaseEx_INTERFACE_DEFINED__ */



#ifndef __GemCardExLib_LIBRARY_DEFINED__
#define __GemCardExLib_LIBRARY_DEFINED__

/* library GemCardExLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_GemCardExLib;

EXTERN_C const CLSID CLSID_SCardDatabaseEx;

#ifdef __cplusplus

class DECLSPEC_UUID("CF6EC0CE-086E-409D-9B5F-B7AFF2434721")
SCardDatabaseEx;
#endif
#endif /* __GemCardExLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


