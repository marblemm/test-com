// noselftregisterclient.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#include "../selfregisterno/BeginningCom.h"
using namespace std;

int main()
{
	//第一种方法，不用注册dll
	{
		CLSID clsid;
		typedef HRESULT(__stdcall* pfnGCO) (REFCLSID, REFIID, void**);
		pfnGCO fnGCO = NULL;
		HINSTANCE hdllInst = LoadLibrary(L"selfregisterno.dll"); //加载dll
		fnGCO = (pfnGCO)GetProcAddress(hdllInst, "DllGetClassObject"); //从dll中得到DllGetClassObject
		if (fnGCO != 0)
		{
			IBeginningCOM* pcf = nullptr;
			HRESULT hr = (fnGCO)(CLSID_BeginningCOM, IID_IBeginningCOM, (void**)&pcf); //创建工厂
			if (SUCCEEDED(hr) && (pcf != NULL))
			{
				int sum = 0;
				pcf->Sum(1, 2, &sum);
				cout << sum << endl;
			}
			pcf->Release();

		}
		FreeLibrary(hdllInst);//释放dll资源
	}

	CoInitialize(NULL);

	HRESULT hr = NULL;

	{
		IBeginningCOM* bc = nullptr;
		hr = CoGetClassObject(CLSID_BeginningCOM, CLSCTX_INPROC_SERVER, NULL, IID_IBeginningCOM, (void**)&bc);
		if (SUCCEEDED(hr))
		{
			int sum = 0;
			bc->Sum(1, 2, &sum);
			cout << sum << endl;

			bc->Release();
		}
		else
		{
			cout << "Failed to create object" << endl;
		}
	}

	{
		IBeginningCOM* bc = nullptr;
		hr = CoCreateInstance(CLSID_BeginningCOM, nullptr, CLSCTX_INPROC_SERVER, IID_IBeginningCOM, (void**)&bc);
		if (SUCCEEDED(hr))
		{
			int sum = 0;
			bc->Sum(1, 2, &sum);
			cout << sum << endl;

			bc->Release();
		}
		else
		{
			cout << "Failed to create object" << endl;
		}
	}

	CoUninitialize();

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
