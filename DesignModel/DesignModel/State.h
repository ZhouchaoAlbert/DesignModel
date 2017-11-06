#ifndef __STATE_H__
#define __STATE_H__
#include <iostream>
using namespace std;

/*
Stateģʽ: �򵥵�������ͨ��״̬�ı��������Ϊ
*/


class CState
{
public:
	virtual void Run() = 0;
};

class CRedState : public CState
{
public:
	virtual void Run()
	{
		std::cout << "��" << std::endl;
	}
};

class CYellowState : public CState
{
public:
	virtual void Run()
	{
		std::cout << "�� " << std::endl;
	}
};

class CGreenState : public CState
{
public:
	virtual void Run()
	{
		std::cout << "�� " << std::endl;
	}
};

//��ͨ��
class CTrafficLight
{
public:
	CTrafficLight()
	{
	}
	// ����״̬
	void SetState(CState* pState)  //�������,����Ķ���
	{
		m_pState = pState;
	}

	virtual void Run()
	{
		m_pState->Run();
		m_nCount++;
	}

	bool IsBad()
	{
		if (m_nCount > m_nTotalCount)
		{
			std::cout << "�ƻ���" << std::endl;
			return true;
		}
		return false;
	}
private:
	CState*  m_pState     { nullptr };
	int      m_nCount     { 0 };   //���еĴ���
	int      m_nTotalCount{ 100 }; //������
};


void StateTest()
{
	CTrafficLight tl;
	CRedState    rs;
	CGreenState  gs;
	CYellowState ys;

	while (!tl.IsBad())
	{
		tl.SetState(&rs);
		tl.Run();
		tl.SetState(&ys);
		tl.Run();
		tl.SetState(&gs);
		tl.Run();
	}
}






#endif // !__STATE_H__
