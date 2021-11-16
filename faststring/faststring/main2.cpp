//#include "IFastString2.h"
//#include <windows.h>
//#include <tchar.h>
//int main()
//{
//	int n = -1;
//	IFastString* pfs = CreateFastString("hello world");
//	if (pfs)
//	{
//		n = pfs->Find("hello");
//		pfs->Delete();
//	}
//
//	return n;
//}
//
//int call()
//{
//	const TCHAR szDLL[] = _TEXT("FastString.dll");
//	const char szfs[] = "CreateFastString";
//
//	HINSTANCE h = ::LoadLibrary(szDLL);
//	if (h)
//	{
//		typedef IFastString* (*pfn)(const char*);
//		pfn fs = (pfn)GetProcAddress(h, szfs);
//		if (fs)
//		{
//			(*fs)("hello world");
//		}
//	}
//}