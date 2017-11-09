#ifndef __CHAIN_OF_RESPONSIBILITY_H__
#define __CHAIN_OF_RESPONSIBILITY_H__
#include <iostream>
#include <string>


//��������Ķ���ȫ������������
class CHandler
{
public:
	// ���캯��ָ�������
	CHandler(CHandler *p) : m_pHandler(p) { }
	virtual ~CHandler()	{}
	virtual void HandleRequest()
	{
		if (m_pHandler)
		{
			std::cout << "����к�����ô��,��ȥ��" << m_pHandler->m_strName << std::endl;
			m_pHandler->HandleRequest();
		}
		else
		{
			std::cout << "��ȥ��һ����,����к��Ӳ���" << std::endl;
		}
	}
    //�Ƿ�ͬ��
	virtual bool IsAgree()
	{
		return false;
	}

public:
	CHandler*   m_pHandler;
	std::string m_strName;
};

//ĸ��
class CMom : public CHandler
{
public:
	CMom(CHandler *p) : CHandler(p)
	{
		m_strName =  "����";
	}
	virtual void HandleRequest()
	{
		if (IsAgree())
		{
			std::cout << "����,����к��Ӳ���,ͬ��޸���" << std::endl;
		}
		else
		{
			CHandler::HandleRequest();
		}
	}
	virtual bool IsAgree()
	{
		return false;
	}
};

//����
class CFather : public CHandler
{
public:
	CFather(CHandler *p) : CHandler(p)
	{
		m_strName = "����";
	}
	virtual void HandleRequest()
	{
		if (IsAgree())
		{
			std::cout << "����,����к��Ӳ���,ͬ��޸���" << std::endl;
		}
		else
		{
			CHandler::HandleRequest();
		}
	}
	virtual bool IsAgree()
	{
		return true;
	}
};

void ResponsibilityTest()
{
	CFather father(NULL);	//����һ��ְ����
	CMom mon(&father);
	mon.HandleRequest();
}






#endif