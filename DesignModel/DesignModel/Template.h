#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
#include <iostream>
#include <string>


/* 行为模式
Template 模式:
Template模式是采用继承的方式实现这一点：将逻辑（算法）框架放在抽象基类中，并定义好细节的接口，子类中实现细节。
*/

// 追MM基类模版
class CCatchMMTemplate
{
public:
	virtual bool BuyGift() = 0;        //买礼物给MM
	virtual bool Accompany() = 0;      //陪伴在她身边
	virtual bool ToTravel() = 0;       //一起旅游

	void CatchMM()
	{
		// 失败次数大于等于2就没戏了
		int nFailedCnt = 0;
		if (!BuyGift())
			nFailedCnt++;
		if (!Accompany())
			nFailedCnt++;
		if (!ToTravel())
			nFailedCnt++;

		if (nFailedCnt > 1)
		{
			std::cout << m_strName << "追MM失败" << std::endl;
		}
		else
		{
			std::cout << m_strName << "成功追到MM" << std::endl;
		}
	}
	
	std::string m_strName;
};

//小耗子
class CHaozi : public CCatchMMTemplate
{
public:
	CHaozi(std::string strName)
	{
		m_strName = strName;
		std::cout << "我是:" << m_strName << std::endl;
	}
	virtual bool BuyGift()
	{
		std::cout << "我买的东西,你收到了没,你喜欢吗?" << std::endl;
		return true;
	}
	virtual bool Accompany()
	{
		std::cout << "不要难过不要伤心,我会一直陪在你身边!" << std::endl;
		return true;
	}
	virtual bool ToTravel()
	{
		std::cout << "好久没一起出去玩了,我准备一下,看去哪里一起旅游玩玩." << std::endl;
		return true;
	}
};
//小猪
class CPig : public CCatchMMTemplate
{
public:
	CPig(std::string strName)
	{
		m_strName = strName;
		std::cout << "我是:" << m_strName << std::endl;
	}
	virtual bool BuyGift()
	{
		std::cout << "没看到你喜欢的礼物,这次不买了" << std::endl;
		return false;
	}
	virtual bool Accompany()
	{
		std::cout << "我要玩几把游戏,你先等等我..." << std::endl;
		return false;
	}
	virtual bool ToTravel()
	{
		std::cout << "旅游太累了..算了还是不去吧" << std::endl;
		return false;
	}
};


void TemplateTest()
{
	CHaozi haozi("小耗子");
	haozi.CatchMM();

	CPig pig("小猪");
	pig.CatchMM();
}

#endif