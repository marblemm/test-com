#include "IFastString.h"

IFastString* CreateFastString(const char* psz)
{
	return new FastString(psz);
}