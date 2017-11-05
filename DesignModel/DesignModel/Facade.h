#ifndef __FACADE_H__
#define __FACADE_H__
#include <iostream>

/*
Facade 模式：外观模式
主要为外界提供一个统一的、简单的接口，以方便客户使用，把复杂的处理过程隐藏起来。
引入外观模式的角色后，用户只需要与外观角色交互，不需要直接操作子系统，用户与子系统的复杂关系都由外观角色来实现，从而降低了系统的耦合度。
*/

//举个简单列子.... 一个人的行为....吃饭，睡觉，打豆豆（PlayGame）

class CEatSubSystem
{
public:
	void DoEat()
	{
		std::cout << "肚子好饿... 外面阳光好大...出去弄点吃的..." << std::endl;
	}
};

class CSleepSubSystem
{
public:
	void DoSleep()
	{
		std::cout << "好困... 我得睡会...除了帮我找对象...哈哈" << std::endl;
	}
};

class CGameSubSystem
{
public:
	void DoGame()
	{
		std::cout << "好无聊...前女友在玩消消乐...哈哈...我也赶紧玩几把吧..." << std::endl;
	}
};

class CPeopleFacade
{
public:
	void Behavior()  //每个人的行为...我的行为就是吃饭睡觉打豆豆.... 这里可以给客户制定相应的行为哦....
	{
		m_Eat.DoEat();
		m_Sleep.DoSleep();
		m_Game.DoGame();
	}

private:
	CEatSubSystem   m_Eat;
	CSleepSubSystem m_Sleep;
	CGameSubSystem  m_Game;
};

void FacadeTest()
{
	CPeopleFacade people;
	people.Behavior();
}
#endif