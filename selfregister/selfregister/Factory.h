#pragma once
#include "unknwn.h"

class BeginningCOMClassFactory :
	public IClassFactory
{
public:
	BeginningCOMClassFactory(VOID);    
	//IUknown
	STDMETHODIMP QueryInterface(REFIID riid, VOID** ppv);
	STDMETHODIMP_(ULONG) AddRef(VOID);
	STDMETHODIMP_(ULONG) Release(VOID);

	//IClassFactory
	STDMETHODIMP CreateInstance(LPUNKNOWN punkOuter, REFIID riid, VOID** ppv);
	STDMETHODIMP LockServer(BOOL fLock);

protected:
	ULONG m_ulRefCount = 0;
};