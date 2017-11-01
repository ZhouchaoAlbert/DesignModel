#ifndef __BUILDER_H__
#define __BUILDER_H__
#include <iostream>

// �����࣬Ҫ����һ������Ҫ���? ����ʹ��BUILDERģʽ������Ľ���ֿ���
class CCar
{
public:
	void WhatCar()
	{
		std::cout << m_szCar.c_str() << std::endl;
	}

	void Drive()
	{
		std::cout << "������" << std::endl;
	}

	std::string m_szCar;
};

// ����Builder
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
		m_pCar->m_szCar = "���Ǳ��۳���";
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
		m_pCar->m_szCar = "���Ǳ�����";
	};
	virtual CCar* GetResult()
	{
		return m_pCar;
	}
private:
	CCar *m_pCar;
};


/*
���뿪��ͬ�ĳ���ֻҪ������ͬ�Ľ����߽�ȥ�����ˡ�
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