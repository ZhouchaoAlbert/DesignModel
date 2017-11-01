#ifndef __BUILDER_H__
#define __BUILDER_H__
#include <iostream>

// 汽车类，要制作一部车，要多大? 所以使用BUILDER模式将对象的建造分开。
class CCar
{
public:
	void WhatCar()
	{
		std::cout << m_szCar.c_str() << std::endl;
	}

	void Drive()
	{
		std::cout << "开车咯" << std::endl;
	}

	std::string m_szCar;
};

// 车的Builder
class CCarBuilder
{
public:
	virtual void   BuildCar() = 0;
	virtual CCar* GetResult() = 0;

};


class CBenchBuilder : public CCarBuilder
{
public:
	CBenchBuilder()
	{
		m_pCar = NULL;
	}
	virtual void BuildCar()
	{
		if (m_pCar == NULL)
			m_pCar = new CCar;
		m_pCar->m_szCar = "我是奔驰车！";
	};
	virtual CCar* GetResult()
	{
		return m_pCar; 
	}
private:
	CCar *m_pCar;
};

class CBaomaBuilder : public CCarBuilder
{
public:
	CBaomaBuilder()
	{
		m_pCar = NULL;
	}
	virtual void BuildCar()
	{
		if (m_pCar == NULL)
			m_pCar = new CCar;
		m_pCar->m_szCar = "我是宝马车！";
	};
	virtual CCar* GetResult()
	{
		return m_pCar;
	}
private:
	CCar *m_pCar;
};


/*
我想开不同的车，只要传个不同的建造者进去就行了。
*/
void Drive(CCarBuilder &builder)
{
	CCar *car;
	builder.BuildCar();
	car = builder.GetResult();
	car->WhatCar();
	car->Drive();
}

void BuilderTest()
{
	CBenchBuilder builder;
	Drive(builder);
	CBaomaBuilder builder2;
	Drive(builder2);
}
#endif