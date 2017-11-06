#ifndef __STATE_H__
#define __STATE_H__
#include <iostream>
using namespace std;

/*
State模式: 简单的理解就是通过状态改变其类的行为
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
		std::cout << "红" << std::endl;
	}
};

class CYellowState : public CState
{
public:
	virtual void Run()
	{
		std::cout << "黄 " << std::endl;
	}
};

class CGreenState : public CState
{
public:
	virtual void Run()
	{
		std::cout << "绿 " << std::endl;
	}
};

//交通灯
class CTrafficLight
{
public:
	CTrafficLight()
	{
	}
	// 设置状态
	void SetState(CState* pState)  //传入该类,子类的对象
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
			std::cout << "灯坏了" << std::endl;
			return true;
		}
		return false;
	}
private:
	CState*  m_pState     { nullptr };
	int      m_nCount     { 0 };   //运行的次数
	int      m_nTotalCount{ 100 }; //总寿命
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
