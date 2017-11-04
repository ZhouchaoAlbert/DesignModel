#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__
#include<iostream>
#include <vector>
#include <string>

/*
组合模式：将对象已树形结构组织起来，已达到“部分与整体” ，使得用户对单个对象和整个对象使用具有一致性
*/


/*
比如 妈妈叫自己的孩子去做事(前提她家里有很多个哈...)
妈妈叫自己最听话的孩子去买东西和叫所有的孩子一起去买东西，其实都是一样的
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
		std::cout << m_strName << "说:妈妈,我最听话,我帮你去买东西..." << std::endl;
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
	//妈妈要一个孩子去买东西
	CChild* pChid = new CChild("我");
	pChid->DoBuySomething();

	//妈妈要几个孩子一起去买东西
	CChild* pChid1 = new CChild("倩猪");
	CChild* pChid2 = new CChild("莹宝");
	CChild* pChid3 = new CChild("海神");
	CChild* pChid4 = new CChild("耗子");

	CChildComposite * pGoupChid = new CChildComposite();

	pGoupChid->Add(pChid1);
	pGoupChid->Add(pChid2);
	pGoupChid->Add(pChid3);
	pGoupChid->Add(pChid4);

	pGoupChid->DoBuySomething();

}


#endif