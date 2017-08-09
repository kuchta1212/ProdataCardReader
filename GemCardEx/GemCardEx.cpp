// GemCardEx.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "resource.h"
#include "GemCardEx.h"

class CGemCardExModule : public CAtlDllModuleT< CGemCardExModule >
{
public :
	DECLARE_LIBID(LIBID_GemCardExLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_GEMCARDEX, "{67E951E6-E52E-475B-A3BC-D12292123D90}")
};

CGemCardExModule _AtlModule;

class CGemCardExApp : public CWinApp
{
public:

// Overrides
    virtual BOOL InitInstance();
    virtual int ExitInstance();

    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CGemCardExApp, CWinApp)
END_MESSAGE_MAP()

CGemCardExApp theApp;

BOOL CGemCardExApp::InitInstance()
{
    return CWinApp::InitInstance();
}

int CGemCardExApp::ExitInstance()
{
    return CWinApp::ExitInstance();
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return (AfxDllCanUnloadNow()==S_OK && _AtlModule.GetLockCount()==0) ? S_OK : S_FALSE;
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}
