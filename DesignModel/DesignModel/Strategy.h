#ifndef __STRATEGY_H__
#define __STRATEGY_H__
#include <iostream>
#include <string>

/*
Strategy ģʽ:����һϵ�е��㷨,��ÿһ���㷨��װ����, ����ʹ���ǿ��໥�滻
*/



// �ȶ���һ���ӿ�
class CStrategy
{
public:
	virtual void BuyMobile(std::string s) = 0;
};

//��Ϊ�ֻ�
class CHuaweiStrategy : public CStrategy
{
public:
	virtual void BuyMobile(std::string s)
	{
		std::cout << s  <<  "˵:�Ҳ�������,��׼����Ϊ�ֻ�,��Ϊ��ˤ..." << std::endl;
	}
};

//С��
class CXiaomiStrategy : public CStrategy
{
public:
	virtual void BuyMobile(std::string s)
	{
		std::cout << s << "˵:�Ҳ�������,��׼����С���ֻ�,��Ϊ����..." << std::endl;
	}
};

//IPhoneX
class CIPhoneXStrategy : public CStrategy
{
public:
	virtual void BuyMobile(std::string s)
	{
		std::cout << s << "˵:��������,��׼��������IPhoneX,��Ϊ������...����,������ô����" << std::endl;
	}
};


// һ��ʹ��Strategy����������Context
class Context
{
public:
	void SetStrategy(CStrategy *pStrategy)
	{
		m_pStrategy = pStrategy;
	}

	void BuyMobile(std::string s) //��ʵ������ʵ�ʹ��ܺ���
	{
		m_pStrategy->BuyMobile(s);  //�����Ӧ�Ķ��� ����Ӧ���㷨 ������ѡ���Ӧ���ֻ�
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
	c.BuyMobile("С��");   //С��

	c.SetStrategy(&xiaomi);
	c.BuyMobile("С��");   //С��.. ������...

	c.SetStrategy(&iphonex);
	c.BuyMobile("ëүү");  //ëүү ��������...
}

#endif