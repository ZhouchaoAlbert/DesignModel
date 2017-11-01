#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__
#include<iostream>


//抽象产品A
class CAbstractProductA
{
public:
	virtual void WhatProduct() = 0;
};

class CProductA1 : public CAbstractProductA
{
public:
	virtual void WhatProduct()
	{
		std::cout << "I am ProductA1" << std::endl;
	}
};

class CProductA2 : public CAbstractProductA
{
public:
	virtual void WhatProduct()
	{
		std::cout << "I am ProductA2" << std::endl;
	}
};

//抽象产品B
class CAbstractProductB
{
public:
	virtual void WhatProduct() = 0;
};

class CProductB1 : public CAbstractProductB
{
public:
	virtual void WhatProduct()
	{
		std::cout << "I am ProductB1" << std::endl;
	}
};

class CProductB2 : public CAbstractProductB
{
public:
	virtual void WhatProduct()
	{
		std::cout << "I am ProductB2" << std::endl;
	}
};




enum E_ABSTRACT_TYPE
{
	E_TYPE_PRODUCTA1 = 1,
	E_TYPE_PRODUCTA2 = 2,
	E_TYPE_PRODUCTB1 = 3,
	E_TYPE_PRODUCTB2 = 4,
};

class CAbstractFactory
{
public:
	virtual  CAbstractProductA* CreateProductA(E_ABSTRACT_TYPE eType) = 0;
	virtual  CAbstractProductB* CreateProductB(E_ABSTRACT_TYPE eType) = 0;
};


class CAConcretFactory : public CAbstractFactory
{
public:
	virtual  CAbstractProductA* CreateProductA(E_ABSTRACT_TYPE eType)
	{
		switch (eType)
		{
		case E_TYPE_PRODUCTA1:
			return new  CProductA1;
		case E_TYPE_PRODUCTA2:
			return new CProductA2;
		default:
			return NULL;
			break;
		}
	}
	virtual  CAbstractProductB* CreateProductB(E_ABSTRACT_TYPE eType)
	{
		switch (eType)
		{
		case E_TYPE_PRODUCTB1:
			return new  CProductB1;
		case E_TYPE_PRODUCTB2:
			return new CProductB2;
		default:
			return NULL;
			break;
		}
	}
};


 void AbstractFactoryTest()
 {
	 CAbstractFactory* pFactory = new CAConcretFactory;
	 CAbstractProductA* pProductA1 = pFactory->CreateProductA(E_TYPE_PRODUCTA1);
	 pProductA1->WhatProduct();
	 CAbstractProductB* pProductB1 = pFactory->CreateProductB(E_TYPE_PRODUCTB1);
	 pProductB1->WhatProduct();
 }

#endif