#ifndef __OBSERVERSUB_H__
#define __OBSERVERSUB_H__
#include<iostream>
#include<string>
#include <list>
#include "Observer.h"

class CObserver2;

class CSubject2
{
public:
	virtual void SetState(std::string strState) = 0;
	virtual std::string  GetState() = 0;

	void Attach(CObserver2* pObv);
	void Detach(CObserver2* pObv);
	void Notify();
private:
	std::list<CObserver2*>m_listObv;
};

class CConcreteSubject : public CSubject2
{
public:
	virtual void SetState(std::string strState)
	{
		m_strState = strState;
	}

	virtual std::string  GetState()
	{
		return m_strState;
	}

private:
	std::string m_strState;
};


#endif