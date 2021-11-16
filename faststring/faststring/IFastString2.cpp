#include "IFastString2.h"
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
