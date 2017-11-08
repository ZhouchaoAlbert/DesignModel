#ifndef __COMMAND_H__
#define __COMMAND_H__
#include <iostream>
#include <string>

//����������
class CCommand
{
public:
	CCommand(){}
	virtual ~CCommand(){}
	virtual void Execute() = 0;
};

// ������
class CReceiver
{
public:
	CReceiver(std::string strName) :m_strName(strName)
	{
	}
	~CReceiver()
	{
	}
	void Action()
	{
		std::cout << "Receiver:" << m_strName << std::endl;
	}

private:
	std::string m_strName;
};

// �������������A
class CConcreteCommandA : public CCommand
{
public:
	CConcreteCommandA(CReceiver *r) : m_pReicver(r)
	{
	}
	~CConcreteCommandA()
	{
	}
	virtual void Execute()
	{
		std::cout << "ConcreteCommandA:" << std::endl;
		m_pReicver->Action();
	}
private:
	CReceiver *m_pReicver;
};

// �������������B
class CConcreteCommandB : public CCommand
{
public:
	CConcreteCommandB(CReceiver *r) : m_pReicver(r)
	{
	}
	~CConcreteCommandB()
	{
	}
	virtual void Execute()
	{
		std::cout << "ConcreteCommandB:" << std::endl;
		m_pReicver->Action();
	}
private:
	CReceiver *m_pReicver;
};


// ������
class CInvoker
{
public:
	CInvoker(CCommand *c) : m_pCmd(c)
	{
	}
	~CInvoker()
	{
	}
	void Invoke()
	{
		m_pCmd->Execute();
	}
private:
	CCommand *m_pCmd;
};


void CommandTest()
{

	CReceiver r1("С����");
	CReceiver r2("С����");

	CConcreteCommandA ac(&r1);
	CConcreteCommandB bc(&r2);

	CInvoker I1(&ac);
	CInvoker I2(&bc);

	I1.Invoke();
	I2.Invoke();
}







#endif