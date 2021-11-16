//BeginningCOM.h
#ifndef __BEGINNINGCOM_H__
#define __BEGINNINGCOM_H__

#pragma once
#include <windows.h>
#include "ComProject_h.h"

//BeginningCOM¼Ì³Ð×ÔIBeginningCOM½Ó¿Ú
//...
class BeginningCOM : public IBeginningCOM
{
public:
	virtual HRESULT __stdcall Sum(int a, int b, int* sum);
	STDMETHODIMP QueryInterface(REFIID riid, VOID** ppv);
	STDMETHODIMP_(ULONG) AddRef(VOID);
	STDMETHODIMP_(ULONG) Release(VOID);

protected:
	ULONG m_ulRefCount;
};
	//...
#endif //__BEGINNINGCOM_H__
