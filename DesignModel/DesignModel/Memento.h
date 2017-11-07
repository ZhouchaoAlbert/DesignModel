#ifndef __MEMENTO_H__
#define __MEMENTO_H__
#include <string>
#include <iostream>

/*
Memento 备忘录状态 ： 世界上最好的后悔要
*/

class CMemento
{
public:
	std::string GetState()
	{
		return m_state;
	}
	void SetState(std::string s)
	{
		m_state = s;
	}
private:
	std::string m_state;
};

class COriginator
{
public:
	CMemento* CreateMemento()
	{
		CMemento *pMt = new CMemento();
		pMt->SetState(m_state);
		return pMt;
	}
	void SetMemento(CMemento *pMt)
	{
		m_state = pMt->GetState();
	}
	void SetState(std::string s)
	{
		m_state = s;
	}
	std::string GetState()
	{
		return m_state;
	}

private:
	std::string m_state;
};

void MementoTest()
{
	COriginator o;

	o.SetState("old-state");
	std::cout << "初始状态：" << o.GetState() << std::endl;
	
	CMemento *pMt;
	pMt = o.CreateMemento(); //创建备忘录对象保存状态

	o.SetState("new-state");
	std::cout << "现在状态：" << o.GetState() << std::endl;

	// 恢复原来状态
	o.SetMemento(pMt);
	std::cout << "恢复状态：" << o.GetState() << std::endl;

	delete pMt;
	pMt = NULL;
}


#endif