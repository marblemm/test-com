//BeginningCOM.h
#ifndef __BEGINNINGCOM_H__
#define __BEGINNINGCOM_H__

#pragma once
#include <windows.h>

// {7BB69A25-68E4-427a-BE4B-B06ED17531AA}
CLSID CLSID_BeginningCOM = { 0x7bb69a25, 0x68e4, 0x427a, { 0xbe, 0x4b, 0xb0, 0x6e, 0xd1, 0x75, 0x31, 0xaa } };
IID IID_IBeginningCOM = { 0x7bb69a26, 0x68e4, 0x427a, { 0xbe, 0x4b, 0xb0, 0x6e, 0xd1, 0x75, 0x31, 0xaa } };


class IBeginningCOM : public IUnknown
{
public:
	virtual STDMETHODIMP Sum(int a, int b, int* sum) = 0;
};

#endif //__BEGINNINGCOM_H__
