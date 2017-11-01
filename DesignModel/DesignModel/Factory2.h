#ifndef __FACTORY2_H__
#define __FACTORY2_H__
#include<iostream>
class CProduct
{
public:
	virtual void WhatProduct() = 0;
};

class CConcretProduct1 : public CProduct
{
public:
	virtual void WhatProduct()
	{
		std::cout << "I am CConcretProduct1" << std::endl;
	}
};

class CConcretProduct2 : public CProduct
{
public:
	virtual void WhatProduct()
	{
		std::cout << "I am CConcretProduct2" << std::endl;
	}
};

enum E_PRODUCT_TYPE
{
	E_TYPE_CONCRET1 = 1,
	E_TYPE_CONCRET2 = 2,
};

class CFactory
{
public:
	virtual  CProduct* CreateProduct(E_PRODUCT_TYPE eType) = 0;
};


class CConcretFactory : public CFactory
{
public:
	virtual  CProduct* CreateProduct(E_PRODUCT_TYPE eType)
	{
		switch (eType)
		{
		case E_TYPE_CONCRET1:
			return new  CConcretProduct1;
		case E_TYPE_CONCRET2:
			return new CConcretProduct2;
		default:
			return NULL;
			break;
		}
	}
};


 void Factory2Test()
 {
 	CFactory* pFactory = new CConcretFactory;
 	CProduct* pProduct = pFactory->CreateProduct(E_TYPE_CONCRET1);
 	pProduct->WhatProduct();
 }

#endif