#ifndef __CHAIN_OF_RESPONSIBILITY_H__
#define __CHAIN_OF_RESPONSIBILITY_H__
#include <iostream>
#include <string>


//这条链里的对象全部都派生于它
class CHandler
{
public:
	// 构造函数指定后继者
	CHandler(CHandler *p) : m_pHandler(p) { }
	virtual ~CHandler()	{}
	virtual void HandleRequest()
	{
		if (m_pHandler)
		{
			std::cout << "这个男孩不怎么样,你去问" << m_pHandler->m_strName << std::endl;
			m_pHandler->HandleRequest();
		}
		else
		{
			std::cout << "在去找一个吧,这个男孩子不行" << std::endl;
		}
	}
    //是否同意
	virtual bool IsAgree()
	{
		return false;
	}

public:
	CHandler*   m_pHandler;
	std::string m_strName;
};

//母亲
class CMom : public CHandler
{
public:
	CMom(CHandler *p) : CHandler(p)
	{
		m_strName =  "妈妈";
	}
	virtual void HandleRequest()
	{
		if (IsAgree())
		{
			std::cout << "妈妈,这个男孩子不错,同意嫁给他" << std::endl;
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

//父亲
class CFather : public CHandler
{
public:
	CFather(CHandler *p) : CHandler(p)
	{
		m_strName = "父亲";
	}
	virtual void HandleRequest()
	{
		if (IsAgree())
		{
			std::cout << "父亲,这个男孩子不错,同意嫁给他" << std::endl;
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
	CFather father(NULL);	//串起一条职责链
	CMom mon(&father);
	mon.HandleRequest();
}






#endif