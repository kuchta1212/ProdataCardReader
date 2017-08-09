// SCardDatabaseEx.cpp : Implementation of CSCardDatabaseEx

#include "stdafx.h"
#include "SCardDatabaseEx.h"
#include ".\scarddatabaseex.h"
#include <winscard.h>


// CSCardDatabaseEx


STDMETHODIMP CSCardDatabaseEx::ListReaders(VARIANT* ppReaders)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (ppReaders == NULL)
		return E_POINTER;

	LONG			lErr = -1;
	SCARDCONTEXT	hSC;
	LPTSTR			pmszReaders = NULL;
	LPTSTR			pReader;
	DWORD			cch = SCARD_AUTOALLOCATE;
	CStringArray	l_strReaderList;
	bool			l_bReaderFound = false;
	int				l_nNbReader = 0;
	HRESULT	l_hRes = E_POINTER;
	SAFEARRAYBOUND	l_bound[1];	
	SAFEARRAY	*psa;
	long	l_nIx[1];

	// 1 - Get reader list to know how many readers are present
	lErr = SCardEstablishContext(SCARD_SCOPE_USER,
								 NULL,
								 NULL,
								 &hSC );
	if (SCARD_S_SUCCESS == lErr)
	{
		pmszReaders = NULL;
		cch = SCARD_AUTOALLOCATE;
		lErr = SCardListReaders(hSC,
								 NULL,
								 (LPTSTR)&pmszReaders,
								 &cch );
		//ATLTRACE("SCardListReaders returned 0x%08X\r\n", lRet2);
		if (lErr == SCARD_S_SUCCESS)
		{
			// Get the list of readers
			// Do something with the multi string of readers.
			// Here, we'll merely output the values.
			// A double-null terminates the list of values.
			pReader = pmszReaders;
			while ( '\0' != *pReader )
			{
				l_strReaderList.Add(pReader);
				// Increase reader number
				l_nNbReader++;
				// Advance to the next value.
				pReader = pReader + strlen(pReader) + 1;
			}
		}

		// Free the memory.
		lErr = SCardFreeMemory( hSC,
								pmszReaders );
	}

	SCardReleaseContext(hSC);

	l_bound[0].lLbound = 0;
	l_bound[0].cElements = l_nNbReader;
		
	psa = SafeArrayCreate(VT_BSTR, 1, l_bound);
	for (int nI = 0; nI < l_nNbReader; nI++)
	{
		l_nIx[0] = nI;
		l_hRes = SafeArrayPutElement(psa, l_nIx, l_strReaderList.GetAt(nI).AllocSysString());
		if (FAILED(l_hRes))
			return l_hRes;
	}

	ppReaders->vt = VT_ARRAY | VT_BSTR;
	ppReaders->parray = psa;

	l_hRes = S_OK;

	return l_hRes;
}
