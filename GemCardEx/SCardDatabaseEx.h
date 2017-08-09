// SCardDatabaseEx.h : Declaration of the CSCardDatabaseEx

#pragma once
#include "resource.h"       // main symbols

#include "GemCardEx.h"


// CSCardDatabaseEx

class ATL_NO_VTABLE CSCardDatabaseEx : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSCardDatabaseEx, &CLSID_SCardDatabaseEx>,
	public IDispatchImpl<ISCardDatabaseEx, &IID_ISCardDatabaseEx, &LIBID_GemCardExLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSCardDatabaseEx()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SCARDDATABASEEX)


BEGIN_COM_MAP(CSCardDatabaseEx)
	COM_INTERFACE_ENTRY(ISCardDatabaseEx)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:

	STDMETHOD(ListReaders)(VARIANT* ppReaders);
};

OBJECT_ENTRY_AUTO(__uuidof(SCardDatabaseEx), CSCardDatabaseEx)
