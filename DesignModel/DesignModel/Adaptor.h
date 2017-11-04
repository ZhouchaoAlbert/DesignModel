#ifndef __ADAPTOR_H__
#define __ADAPTOR_H__
#include <iostream>

/*
������ģʽ:
��Ҫ��Ϊ��ģʽ�Ͷ���ģʽ
��Ҫ��������ӿڲ����ݲ�����һ����
*/

//����Ŀ��ӿ�

class ISocketTarget
{
public: 
	virtual void CreateSocket()    = 0;   //����socket
	virtual void BindSocket()      = 0;   //��socket
	virtual void ListenSocket()    = 0;   //����socket
	virtual void ConnectSocket()   = 0;   //����socket
};

//���˸���ʵ�ֽӿ�
class CSocketAdaptee
{
public:
	virtual void CreateSpecificSocket()    //����socket
	{
		std::cout << "�����׽���" << std::endl;
	}
	virtual void BindSpecificSocket()      //��socket
	{
		std::cout << "���׽���" << std::endl;
	}
	virtual void ListenSpecificSocket()    //����socket
	{
		std::cout << "�����׽���" << std::endl;
	}
	virtual void ConnectSpecificSocket()   //����socket
	{
		std::cout << "�����׽���" << std::endl;
	}
};


//������ ��ģʽ
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



//������ ����ģʽ
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
	//��ģʽ����
	ISocketTarget* pISocketTarget = new CSocketAdapter;
	pISocketTarget->CreateSocket();
	
	//����ģʽ
	CSocketAdaptee* pSocketAdaptee = new CSocketAdaptee;
	CSocketAdapterObj socketAdapterObj(pSocketAdaptee);
	socketAdapterObj.BindSocket();
}


#endif