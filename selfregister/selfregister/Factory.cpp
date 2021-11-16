#include "Factory.h"
#include "BeginningCOM.h"

BeginningCOMClassFactory::BeginningCOMClassFactory(VOID)
{

}


HRESULT  BeginningCOMClassFactory::QueryInterface(const IID& iid, void** ppv)
{
	if (iid == IID_IUnknown)
	{
		*ppv = (IUnknown*)this;
		((IUnknown*)(*ppv))->AddRef();
	}
	else if (iid == IID_IClassFactory)
	{
		*ppv = (IClassFactory*)this;
		((IClassFactory*)(*ppv))->AddRef();
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	return S_OK;
}

ULONG	  BeginningCOMClassFactory::AddRef()
{
	m_ulRefCount++;
	return  (ULONG)m_ulRefCount;
}

ULONG	  BeginningCOMClassFactory::Release()
{
	m_ulRefCount--;
	if (m_ulRefCount == 0) {
		delete this;
		return 0;
	}
	return  (ULONG)m_ulRefCount;
}


//...
STDMETHODIMP BeginningCOMClassFactory::CreateInstance(LPUNKNOWN punkOuter, REFIID riid, VOID** ppv)
{
	BeginningCOM* pbc;
	HRESULT hr;

	//暂不支持聚合
	if (punkOuter != NULL)
	{
		return CLASS_E_NOAGGREGATION;
	}

	pbc = new BeginningCOM;

	if (pbc == NULL)
	{
		return E_OUTOFMEMORY;
	}

	pbc->AddRef();
	hr = pbc->QueryInterface(riid, ppv);
	pbc->Release();

	return hr;
}

STDMETHODIMP BeginningCOMClassFactory::LockServer(BOOL fLock)
{
	return E_FAIL;
}
