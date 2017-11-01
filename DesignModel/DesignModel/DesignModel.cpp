// DesignModel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Factory1.h"
#include "Factory2.h"
#include "AbstractFactory.h"
#include "Singleton.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Factory1Test();
	Factory2Test();
	AbstractFactoryTest();
	SingletonTest();
	system("pause");
	return 0;
}

