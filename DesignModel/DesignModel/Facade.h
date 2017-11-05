#ifndef __FACADE_H__
#define __FACADE_H__
#include <iostream>

/*
Facade ģʽ�����ģʽ
��ҪΪ����ṩһ��ͳһ�ġ��򵥵Ľӿڣ��Է���ͻ�ʹ�ã��Ѹ��ӵĴ����������������
�������ģʽ�Ľ�ɫ���û�ֻ��Ҫ����۽�ɫ����������Ҫֱ�Ӳ�����ϵͳ���û�����ϵͳ�ĸ��ӹ�ϵ������۽�ɫ��ʵ�֣��Ӷ�������ϵͳ����϶ȡ�
*/

//�ٸ�������.... һ���˵���Ϊ....�Է���˯�����򶹶���PlayGame��

class CEatSubSystem
{
public:
	void DoEat()
	{
		std::cout << "���Ӻö�... ��������ô�...��ȥŪ��Ե�..." << std::endl;
	}
};

class CSleepSubSystem
{
public:
	void DoSleep()
	{
		std::cout << "����... �ҵ�˯��...���˰����Ҷ���...����" << std::endl;
	}
};

class CGameSubSystem
{
public:
	void DoGame()
	{
		std::cout << "������...ǰŮ������������...����...��Ҳ�Ͻ��漸�Ѱ�..." << std::endl;
	}
};

class CPeopleFacade
{
public:
	void Behavior()  //ÿ���˵���Ϊ...�ҵ���Ϊ���ǳԷ�˯���򶹶�.... ������Ը��ͻ��ƶ���Ӧ����ΪŶ....
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