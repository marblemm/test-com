#include "FastString2.h"
#include <string.h>

FastString::FastString(const char* psz)
	:m_psz(new char[strlen(psz) + 1])
	,m_cch(strlen(psz))
{
	strcpy(m_psz, psz);
}

FastString::~FastString()
{
	delete[] m_psz;
}

int FastString::Length() const
{
	return m_cch;
}

int FastString::Find(const char* psz) const
{
	//O(1)
}