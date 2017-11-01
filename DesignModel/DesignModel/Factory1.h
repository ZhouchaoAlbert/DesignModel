#ifndef __FACTORY1_H__
#define __FACTORY1_H__
#include <iostream>
class CAnimal   //基类
{
public:
	virtual void WhatAnimal() = 0;
};

class CSheep : public CAnimal
{
public:
	virtual void WhatAnimal()
	{
		std::cout << "我是一只可爱的小羊" << std::endl;
	}
};

class CMonkey : public CAnimal
{
public:
	virtual void WhatAnimal()
	{
		std::cout << "我是一只聪明的猴子" << std::endl;
	}
};

class CPiggy : public CAnimal
{
public:
	virtual void WhatAnimal()
	{
		std::cout << "我是一只懒惰的笨猪" << std::endl;
	}
};

enum E_ANIMAL_TYPE
{
	E_TYPE_SHEEP  = 1,
	E_TYPE_MONKEY = 2,
	E_TYPE_PIGGY  = 3,
};
class CAnimalFactory
{
public: 
	CAnimal* GetInstance(E_ANIMAL_TYPE eTYpe)
	{
		switch (eTYpe)
		{
		case E_TYPE_SHEEP:
			return new  CSheep;
		case E_TYPE_MONKEY:
			return new CMonkey;
		case E_TYPE_PIGGY:
			return new CPiggy;
		default:
			return NULL;
			break;
		}
	}
};

void Factory1Test()
{
	CAnimalFactory factory;
	CAnimal *pAnimal;

	std::cout<< "你喜欢什么动物?" << std::endl;
	std::cout << "1 小羊, 2 猴子, 3 笨猪" << std::endl;
	int nType = 0;
	scanf_s("%d", &nType);
	pAnimal = factory.GetInstance(E_ANIMAL_TYPE(nType));
	if (pAnimal == NULL)
	{
		std::cout << "没有这个动物" << std::endl;
		return;
	}
	pAnimal->WhatAnimal();
}



#endif