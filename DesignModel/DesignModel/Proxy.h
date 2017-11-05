#ifndef __PROXY_H__
#define __PROXY_H__
#include <iostream>
#include <string>
/*
Proxy ģʽ:
����ģʽ,����˼����Ǵ����Ǵ���һЩ����,�Լ�����ȫ���Ը�
*/
//����:������յ�����,���Լ�ȥ���ⷿ�ӵ�(������).....��Ϳ������н�(Ҫ����)...

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
	//�Լ��ҷ�
	ConcreteSubject sub("�Լ��ҷ�, �����ҵ�ѽ...զ��, Ҫ��ȥ�����н� ? ");
	sub.FindRoom();

	//�н���� ����ȥ�ҷ�
	CProxy proxy((CSubject*)&sub);
	sub.SetTipsContent("�����н�,�Ұ����ҵ��˷���,���money!!!! ����");
	proxy.FindRoom();
}
#endif