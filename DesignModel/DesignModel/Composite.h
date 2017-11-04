#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__
#include<iostream>
#include <vector>
#include <string>

/*
���ģʽ�������������νṹ��֯�������Ѵﵽ�����������塱 ��ʹ���û��Ե����������������ʹ�þ���һ����
*/


/*
���� ������Լ��ĺ���ȥ����(ǰ���������кܶ����...)
������Լ��������ĺ���ȥ�����ͽ����еĺ���һ��ȥ��������ʵ����һ����
*/

class IMontherComponent
{
public:
	virtual void DoBuySomething() = 0;
};


class CChild : public IMontherComponent
{
public:
	CChild(std::string strName):
	m_strName(strName)
	{
	}
	void DoBuySomething()
	{
		std::cout << m_strName << "˵:����,��������,�Ұ���ȥ����..." << std::endl;
	}
private:
	std::string m_strName;
};


class CChildComposite
{
public:  
	void Add(IMontherComponent* people)
	{
		m_vecPeople.push_back(people);
	}
	void Remove(int idx)
	{
		delete m_vecPeople[idx];
		m_vecPeople.erase(m_vecPeople.begin() + idx);
	}

	void DoBuySomething()
	{
		for (std::vector<IMontherComponent*>::iterator it = m_vecPeople.begin(); it != m_vecPeople.end(); it++)
		{
			(*it)->DoBuySomething();
		}
	}

	IMontherComponent* GetChild(int idx)
	{
		return m_vecPeople[idx];
	}

	void RemoveAll()
	{
		for (std::vector<IMontherComponent*>::iterator it = m_vecPeople.begin(); it != m_vecPeople.end(); it++)
		{
			delete (*it);
		}
		m_vecPeople.clear();
	}

private:
	std::vector<IMontherComponent*> m_vecPeople; 
};


void CompositeTest()
{
	//����Ҫһ������ȥ����
	CChild* pChid = new CChild("��");
	pChid->DoBuySomething();

	//����Ҫ��������һ��ȥ����
	CChild* pChid1 = new CChild("ٻ��");
	CChild* pChid2 = new CChild("Ө��");
	CChild* pChid3 = new CChild("����");
	CChild* pChid4 = new CChild("����");

	CChildComposite * pGoupChid = new CChildComposite();

	pGoupChid->Add(pChid1);
	pGoupChid->Add(pChid2);
	pGoupChid->Add(pChid3);
	pGoupChid->Add(pChid4);

	pGoupChid->DoBuySomething();

}


#endif