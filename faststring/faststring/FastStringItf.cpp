#include "FastStringItf.h"
#include <string.h>
#include "FastStringExport.h"

FastStringItf::FastStringItf(const char* psz)
	:m_pThis(new FastString(psz))
{
}

FastStringItf::~FastStringItf()
{
	delete m_pThis;
}

int FastStringItf::Length() const
{
	return m_pThis->Length();
}

int FastStringItf::Find(const char* psz) const
{
	return m_pThis->Find(psz);
}