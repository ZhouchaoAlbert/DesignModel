#ifndef __FLYWEIGHT_H__
#define __FLYWEIGHT_H__
#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
��Ԫģʽ��
��Ҫ��ͼ�����ù�������Ч��֧�ִ���ϸ���ȵĶ���
*/

//������Ҫ���� ��������ԣ���Ԫ��

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
	std::string m_publishCompany;  //������
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

	std::string m_strBookName;     //����
	int         m_nPrice;          //��ļ۸�
	string      m_strAuthor;       //�������
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
	std::map<std::string, CPublishFlyweight*> m_mapPublish;  //��Ȩ������
};


void FlyWeightTest()
{
	CFlyweightFactory* pFlyweightFactory = new CFlyweightFactory();
	CPublishFlyweight* pPublishFlyweight = pFlyweightFactory->GetPublish("�����߶ȳ�����");
	pPublishFlyweight->SetAuthor("����");
	pPublishFlyweight->SetPrice(30);
	pPublishFlyweight->SetBookName("C++");

	CPublishFlyweight* pPublishFlyweight2 = pFlyweightFactory->GetPublish("���ڰ��ɳ�����");
	pPublishFlyweight2->SetAuthor("ׯ��");
	pPublishFlyweight2->SetPrice(40);
	pPublishFlyweight2->SetBookName("���ģʽ");

	CPublishFlyweight* pPublishFlyweight3 = pFlyweightFactory->GetPublish("�����߶ȳ�����");
	pPublishFlyweight3->SetAuthor("����");
	pPublishFlyweight3->SetPrice(50);
	pPublishFlyweight3->SetBookName("��ѧ");
}

#endif