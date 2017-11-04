#ifndef __ADAPTOR_H__
#define __ADAPTOR_H__
#include <iostream>

/*
适配器模式:
主要分为类模式和对象模式
主要解决两个接口不兼容不能在一起工作
*/

//网络目标接口

class ISocketTarget
{
public: 
	virtual void CreateSocket()    = 0;   //创建socket
	virtual void BindSocket()      = 0;   //绑定socket
	virtual void ListenSocket()    = 0;   //监听socket
	virtual void ConnectSocket()   = 0;   //连接socket
};

//别人给的实现接口
class CSocketAdaptee
{
public:
	virtual void CreateSpecificSocket()    //创建socket
	{
		std::cout << "创建套接字" << std::endl;
	}
	virtual void BindSpecificSocket()      //绑定socket
	{
		std::cout << "绑定套接字" << std::endl;
	}
	virtual void ListenSpecificSocket()    //监听socket
	{
		std::cout << "监听套接字" << std::endl;
	}
	virtual void ConnectSpecificSocket()   //连接socket
	{
		std::cout << "连接套接字" << std::endl;
	}
};


//适配器 类模式
class CSocketAdapter : public ISocketTarget, public CSocketAdaptee
{
public:
	virtual void CreateSocket()
	{
		this->CreateSpecificSocket();
	}
	virtual void BindSocket()
	{
		this->BindSpecificSocket();
	}
	virtual void ListenSocket()
	{
		this->ListenSpecificSocket();
	}
	virtual void ConnectSocket()
	{
		this->ConnectSpecificSocket();
	}
};



//适配器 对象模式
class CSocketAdapterObj : ISocketTarget
{
public:
	CSocketAdapterObj(CSocketAdaptee * obj)
	{
		m_pSocketAdaptee = obj;
	}
	virtual void CreateSocket()
	{
		m_pSocketAdaptee->CreateSpecificSocket();
	}
	virtual void BindSocket()
	{
		m_pSocketAdaptee->BindSpecificSocket();
	}
	virtual void ListenSocket()
	{
		m_pSocketAdaptee->ListenSpecificSocket();
	}
	virtual void ConnectSocket()
	{
		m_pSocketAdaptee->ConnectSpecificSocket();
	}
private:
	CSocketAdaptee* m_pSocketAdaptee;
};


void AdaptorTest()
{
	//类模式测试
	ISocketTarget* pISocketTarget = new CSocketAdapter;
	pISocketTarget->CreateSocket();
	
	//对象模式
	CSocketAdaptee* pSocketAdaptee = new CSocketAdaptee;
	CSocketAdapterObj socketAdapterObj(pSocketAdaptee);
	socketAdapterObj.BindSocket();
}


#endif