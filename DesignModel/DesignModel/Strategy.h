#ifndef __STRATEGY_H__
#define __STRATEGY_H__
#include <iostream>
#include <string>

/*
Strategy 模式:定义一系列的算法,把每一个算法封装起来, 并且使它们可相互替换
*/



// 先定义一个接口
class CStrategy
{
public:
	virtual void BuyMobile(std::string s) = 0;
};

//华为手机
class CHuaweiStrategy : public CStrategy
{
public:
	virtual void BuyMobile(std::string s)
	{
		std::cout << s  <<  "说:我不是土豪,我准备买华为手机,因为耐摔..." << std::endl;
	}
};

//小米
class CXiaomiStrategy : public CStrategy
{
public:
	virtual void BuyMobile(std::string s)
	{
		std::cout << s << "说:我不是土豪,我准备买小米手机,因为便宜..." << std::endl;
	}
};

//IPhoneX
class CIPhoneXStrategy : public CStrategy
{
public:
	virtual void BuyMobile(std::string s)
	{
		std::cout << s << "说:我是土豪,我准备买最贵的IPhoneX,因为有刘海...哈哈,就是这么任性" << std::endl;
	}
};


// 一个使用Strategy的上下文类Context
class Context
{
public:
	void SetStrategy(CStrategy *pStrategy)
	{
		m_pStrategy = pStrategy;
	}

	void BuyMobile(std::string s) //现实中这里实际功能函数
	{
		m_pStrategy->BuyMobile(s);  //传入对应的对象 掉对应的算法 这里是选择对应的手机
	}
private:
	CStrategy *m_pStrategy;
};

void StrategyTest()
{
	Context c;
	CHuaweiStrategy  huawei;
	CXiaomiStrategy  xiaomi;
	CIPhoneXStrategy iphonex;

	c.SetStrategy(&huawei);
	c.BuyMobile("小明");   //小明

	c.SetStrategy(&xiaomi);
	c.BuyMobile("小红");   //小红.. 她最穷...

	c.SetStrategy(&iphonex);
	c.BuyMobile("毛爷爷");  //毛爷爷 最土豪了...
}

#endif