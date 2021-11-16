#pragma once
class IExtensibleObject
{
public:
	virtual void* Dynamic_Cast(const char* pszType) = 0;
	virtual void AddRef() = 0;
	virtual void Release() = 0;
};

