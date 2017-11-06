#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include<iostream>
#include<string>
#include <list>
#include "ObserverSub.h"
class CSubject2;

class CObserver2
{
public:
	virtual void Update(CSubject2* pSub) = 0;
	virtual void PrintInfo()	         = 0;

protected:
	std::string m_strState;
private:
};

class CConcreteObserverA :public CObserver2
{
public:
	CConcreteObserverA();
	~CConcreteObserverA();
	CConcreteObserverA(CSubject2* pSub);
	virtual void Update(CSubject2* pSub);
	virtual void PrintInfo();
private:
	CSubject2* m_pSub;
};


class CConcreteObserverB :public CObserver2
{
public:
	CConcreteObserverB();
	~CConcreteObserverB();
	CConcreteObserverB(CSubject2* pSub);
	virtual void Update(CSubject2* pSub);
	virtual void PrintInfo();
private:
	CSubject2* m_pSub;
};






#endif