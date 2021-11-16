//BeginningCOM.cpp
#include "BeginningCOM.h"
#include <iostream>
#include "windows.h"
#include "Factory.h"
#include "ComProject_i.c"


//// {7BB69A25-68E4-427a-BE4B-B06ED17531AA}
//extern "C" const GUID  CLSID_BeginningCOM =
//{ 0x7bb69a25, 0x68e4, 0x427a, { 0xbe, 0x4b, 0xb0, 0x6e, 0xd1, 0x75, 0x31, 0xaa } };



//实现IBeginningCOM接口成员，属性需要分别实现set/put。
//...
STDMETHODIMP BeginningCOM::Sum(int a, int b, int* sum)
{
	*sum = a + b;
	return S_OK;
}

STDMETHODIMP BeginningCOM::QueryInterface(REFIID riid, VOID** ppv)
{
    if(riid == IID_IUnknown)
    {
        *ppv = static_cast<IUnknown*>(this);
    }
    else if (riid == IID_IBeginningCOM)
    {
		*ppv = static_cast<IBeginningCOM*>(this);
    }
    else
    {
        *ppv = NULL;

        return E_NOINTERFACE;
    }

    reinterpret_cast<IUnknown*>(*ppv) -> AddRef();
    return S_OK;
}

STDMETHODIMP_(ULONG) BeginningCOM::AddRef(VOID)
{
    return InterlockedIncrement(&m_ulRefCount);
}

STDMETHODIMP_(ULONG) BeginningCOM::Release(VOID)
{
    ULONG tmp = InterlockedDecrement(&m_ulRefCount);

    if(tmp == 0)
    {
        delete this;
    }

    return tmp;
}
HINSTANCE g_hModule = nullptr;

//DLL entry point.
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		g_hModule = hModule;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
	if (rclsid == CLSID_BeginningCOM)
	{
		BeginningCOMClassFactory* pbc = new BeginningCOMClassFactory;

		if (pbc == NULL)
		{
			return E_OUTOFMEMORY;
		}

		return pbc->QueryInterface(riid, ppv);
	}

	*ppv = 0;

	return CLASS_E_CLASSNOTAVAILABLE;
}




LPCTSTR RegTable[][3] =
{
    {"CLSID\\{586CDC7B-09F1-4f44-A110-F0E604AED81E}", 0, "BeginningCOM"},
    {"CLSID\\{586CDC7B-09F1-4f44-A110-F0E604AED81E}\\InprocServer32", 0, (LPCTSTR)-1},
    {"CLSID\\{586CDC7B-09F1-4f44-A110-F0E604AED81E}\\InprocServer32", "ThreadingModel", "Both"}
};

STDAPI DllUnregisterServer()
{
    HRESULT hr = S_OK;

    int regCount = sizeof(RegTable) / sizeof(*RegTable);

    for(int i = regCount - 1; i >= 0; i--)
    {
        LSTATUS error = RegDeleteKey(HKEY_CLASSES_ROOT, RegTable[i][0]);

        if(error != ERROR_SUCCESS)
        {
            hr = S_FALSE;
        }
    }

    return hr;
}

STDAPI DllRegisterServer(void)
{
    HRESULT hr = S_OK;
    TCHAR szFileName[MAX_PATH];

    ZeroMemory(&szFileName, MAX_PATH * sizeof(TCHAR));
    GetModuleFileName(g_hModule, szFileName, MAX_PATH);

    int regCount = sizeof(RegTable) / sizeof(*RegTable);

    for(int i = 0; i < regCount; i++)
    {
        if(RegTable[i][2] == (LPCTSTR)-1)
        {
            RegTable[i][2] = szFileName;
        }

        HKEY hKey;
        LSTATUS error = ::RegCreateKey(HKEY_CLASSES_ROOT, RegTable[i][0], &hKey);
        std::cout << error << std::endl;
        if(error == ERROR_SUCCESS)
        {
			std::cout << RegTable[i][2] << std::endl;
            error = RegSetValueEx(hKey, RegTable[i][1], 0, REG_SZ, (const BYTE*)RegTable[i][2], (lstrlen(RegTable[i][2]) + 1) * sizeof(TCHAR));
            RegCloseKey(hKey);
        }

        if(error != ERROR_SUCCESS)
        {
            DllUnregisterServer();
			//MessageBox(nullptr, L"failed", L"", 0);//弹窗来确认是否注册成功
		}
    }

    return hr;
}