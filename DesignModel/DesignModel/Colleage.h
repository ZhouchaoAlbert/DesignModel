#ifndef __COLLEAGE_H__
#define __COLLEAGE_H__
#include <iostream>
#include <string>
#include "Mediator.h"
class CMediator;

class CColleage
{
public:
	CColleage();
	~CColleage();
	virtual void Aciton() = 0;
	virtual void SetState(std::string sdt) = 0;
	virtual std::string GetState() = 0;

	CColleage(CMediator* pMdt)
	{
		m_pMdt = pMdt;
	}
	CMediator* m_pMdt;
};

class CConcreteColleageA :public CColleage
{
public:
	CConcreteColleageA();
	CConcreteColleageA(CMediator* pMdt);
	~CConcreteColleageA();

	virtual void Aciton();
	virtual void SetState(std::string sdt);
	virtual std::string GetState();
protected:
private:
	std::string m_strState;
};

class CConcreteColleageB :public CColleage
{
public:
	CConcreteColleageB();
	CConcreteColleageB(CMediator* pMdt);
	~CConcreteColleageB();

	virtual void Aciton();
	virtual void SetState(std::string sdt);
	virtual std::string GetState();
protected:
private:
	std::string m_strState;
};


#endif
