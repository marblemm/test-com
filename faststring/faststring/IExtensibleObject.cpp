#include "IExtensibleObject.h"
#include <string.h>


IFastString* CreateFastString(const char* psz)
{
	return new FastString(psz);
}

FastString::FastString(const char* psz)
	:m_psz(new char[strlen(psz) + 1])
	, m_cch(strlen(psz))
{
	strcpy(m_psz, psz);
}

FastString::~FastString()
{
	delete[] m_psz;
}

void* FastString::Dynamic_Cast(const char* pszType)
{
	if (strcmp(pszType, "IFastString") == 0)
		return static_cast<IFastString*>(this);
	else if (strcmp(pszType, "IPersistentObject") == 0)
		return static_cast<IPersistentObject*>(this);
	else if (strcmp(pszType, "IExtensibleObject") == 0)
		return static_cast<IFastString*>(this);
	return 0;
}

void FastString::Delete()
{
	delete this;
}

int FastString::Length() const
{
	return m_cch;
}

int FastString::Find(const char* psz) const
{
	//O(1)
	return 1;
}


bool FastString::Load(const char* pszFileName)
{
	return true;
}


bool FastString::Save(const char* pszFileName)
{
	return true;
}