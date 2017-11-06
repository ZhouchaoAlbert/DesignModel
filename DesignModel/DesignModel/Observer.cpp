#include "stdafx.h"
#include "Observer.h"


CConcreteObserverA::CConcreteObserverA()
{
}

CConcreteObserverA::~CConcreteObserverA()
{
	m_pSub->Detach(this);
	delete m_pSub;
}

CConcreteObserverA::CConcreteObserverA(CSubject2* pSub)
{
	m_pSub = pSub;
	m_pSub->Attach(this);
}

void CConcreteObserverA::Update(CSubject2* pSub)
{
	m_strState = pSub->GetState();
	PrintInfo();
}

void CConcreteObserverA::PrintInfo()
{
	std::cout << "ConcreteObserverA[PrintInfo]£º" << m_strState << std::endl;
}


CConcreteObserverB::CConcreteObserverB()
{
}

CConcreteObserverB::~CConcreteObserverB()
{
	m_pSub->Detach(this);
	delete m_pSub;
}
CConcreteObserverB::CConcreteObserverB(CSubject2* pSub)
{
	m_pSub = pSub;
	m_pSub->Attach(this);
}

void CConcreteObserverB::Update(CSubject2* pSub)
{
	m_strState = pSub->GetState();
	PrintInfo();
}

void CConcreteObserverB::PrintInfo()
{
	std::cout << "ConcreteObserverB[PrintInfo]£º" << m_strState << std::endl;
}
