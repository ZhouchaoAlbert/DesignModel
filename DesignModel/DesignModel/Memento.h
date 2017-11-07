#ifndef __MEMENTO_H__
#define __MEMENTO_H__
#include <string>
#include <iostream>

/*
Memento ����¼״̬ �� ��������õĺ��Ҫ
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
	std::cout << "��ʼ״̬��" << o.GetState() << std::endl;
	
	CMemento *pMt;
	pMt = o.CreateMemento(); //��������¼���󱣴�״̬

	o.SetState("new-state");
	std::cout << "����״̬��" << o.GetState() << std::endl;

	// �ָ�ԭ��״̬
	o.SetMemento(pMt);
	std::cout << "�ָ�״̬��" << o.GetState() << std::endl;

	delete pMt;
	pMt = NULL;
}


#endif