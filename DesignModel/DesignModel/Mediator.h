#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__
#include "Colleage.h"

class CColleage;

class CMediator
{
public:
	virtual void DoActionFromAtoB() = 0;
	virtual void DoActionFromBtoA() = 0;
};



class CConcreteMediator :public CMediator
{
public:
	CConcreteMediator();
	CConcreteMediator(CColleage* pClgA, CColleage* pClgB);
	~CConcreteMediator();
	void SetConcreteColleageA(CColleage* pClgA);
	void SetConcreteColleageB(CColleage* pClgB);

	CColleage* GetConcreteColleageA();
	CColleage* GetConcreteColleageB();

	void IntroColleage(CColleage* pClgA, CColleage* pClgB);

	void DoActionFromAtoB();
	void DoActionFromBtoA();

private:
	CColleage* m_pClgA;
	CColleage* m_pClgB;
};

#endif
