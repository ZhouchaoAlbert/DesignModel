// DesignModel.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Factory1.h"
#include "Factory2.h"
#include "AbstractFactory.h"
#include "Singleton.h"
#include "Builder.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Factory1Test();
	Factory2Test();
	AbstractFactoryTest();
	SingletonTest();
	BuilderTest();
	system("pause");
	return 0;
}

