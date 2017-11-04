#ifndef __FLYWEIGHT_H__
#define __FLYWEIGHT_H__
#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
享元模式：
主要意图是运用共享技术有效的支持大量细粒度的对象
*/

//这里主要介绍 共享的属性（享元）

class CPublishFlyweight
{
public:
	CPublishFlyweight(std::string publishCompany):
		m_publishCompany(publishCompany)
	{

	}
	virtual void SetAuthor(std::string strAuthor) = 0;
	virtual void SetPrice(int nPrice) = 0;
	virtual void SetBookName(std::string strBookName) = 0;

	std::string GetName()
	{
		return m_publishCompany;
	}

private:
	std::string m_publishCompany;  //出版社
};

class  CConceterPublishFlyweight : public CPublishFlyweight
{
public:
	CConceterPublishFlyweight(std::string publishCompany) :CPublishFlyweight(publishCompany)
	{
		std::cout << GetName() << std::endl;
	}

	void SetAuthor(std::string strAuthor)
	{
		m_strAuthor = strAuthor;
		std::cout << m_strAuthor << std::endl;
	}

	void SetPrice(int nPrice)
	{
		m_nPrice = nPrice;
		std::cout << m_nPrice << std::endl;
	}

	void SetBookName(std::string strBookName)
	{ 
		m_strBookName = strBookName;
		std::cout << m_strBookName << std::endl;
	}
private:

	std::string m_strBookName;     //书名
	int         m_nPrice;          //书的价格
	string      m_strAuthor;       //书的作者
};


class CFlyweightFactory
{
public:
	CFlyweightFactory()
	{

	}
	~CFlyweightFactory()
	{
		for (std::map<std::string, CPublishFlyweight*>::iterator it = m_mapPublish.begin(); it != m_mapPublish.end();it++)
		{
			delete it->second;
		}
	}

	CPublishFlyweight* GetPublish(std::string strPublish)
	{
		std::map<std::string, CPublishFlyweight*>::iterator it = m_mapPublish.find(strPublish);
		if (it != m_mapPublish.end())
		{
			if (it->second->GetName() != strPublish)
			{
				return NULL;
			}
			return it->second;	
		}
		CPublishFlyweight* pPublishFlyweight = new CConceterPublishFlyweight(strPublish);
		m_mapPublish[strPublish] = pPublishFlyweight;	
		return 	m_mapPublish[strPublish];
	}


private:
	std::map<std::string, CPublishFlyweight*> m_mapPublish;  //版权管理者
};


void FlyWeightTest()
{
	CFlyweightFactory* pFlyweightFactory = new CFlyweightFactory();
	CPublishFlyweight* pPublishFlyweight = pFlyweightFactory->GetPublish("深圳七度出版社");
	pPublishFlyweight->SetAuthor("老子");
	pPublishFlyweight->SetPrice(30);
	pPublishFlyweight->SetBookName("C++");

	CPublishFlyweight* pPublishFlyweight2 = pFlyweightFactory->GetPublish("深圳八仙出版社");
	pPublishFlyweight2->SetAuthor("庄子");
	pPublishFlyweight2->SetPrice(40);
	pPublishFlyweight2->SetBookName("设计模式");

	CPublishFlyweight* pPublishFlyweight3 = pFlyweightFactory->GetPublish("深圳七度出版社");
	pPublishFlyweight3->SetAuthor("孔子");
	pPublishFlyweight3->SetPrice(50);
	pPublishFlyweight3->SetBookName("哲学");
}

#endif