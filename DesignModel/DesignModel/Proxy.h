#ifndef __PROXY_H__
#define __PROXY_H__
#include <iostream>
#include <string>
/*
Proxy 模式:
代理模式,顾名思义就是代我们处理一些事情,自己不用全力以赴
*/
//列子:比如你刚到深圳,你自己去找租房子的(很难找).....你就可以找中介(要交费)...

class CSubject
{
public:
	virtual void FindRoom() = 0;
};


class ConcreteSubject : public CSubject
{
public:
	ConcreteSubject(std::string strTips)
	{
		m_strTips = strTips;
	}

	virtual void FindRoom()
	{
		std::cout << m_strTips << std::endl;
	}
	virtual	void SetTipsContent(std::string strTips)
	{
		m_strTips = strTips;
	}
private:
	std::string m_strTips;
};

class CProxy : public CSubject
{
public:
	CProxy(CSubject* sub)
	{
		m_pSub = sub;
	}
	void FindRoom()
	{
		m_pSub->FindRoom();
	}
private:
	CSubject* m_pSub;

};


void ProxyTest()
{
	//自己找房
	ConcreteSubject sub("自己找房, 很难找到呀...咋办, 要不去请求中介 ? ");
	sub.FindRoom();

	//中介代理 帮你去找房
	CProxy proxy((CSubject*)&sub);
	sub.SetTipsContent("我是中介,我帮你找到了房子,请给money!!!! 哈哈");
	proxy.FindRoom();
}
#endif