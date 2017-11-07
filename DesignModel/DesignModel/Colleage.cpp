#include "stdafx.h"
#include "Colleage.h"


CColleage::CColleage()
{
}


CColleage::~CColleage()
{
}


CConcreteColleageA::CConcreteColleageA()
{
}

CConcreteColleageA::CConcreteColleageA(CMediator* pMdt) : CColleage(pMdt)
{
}

CConcreteColleageA::~CConcreteColleageA()
{
}

void CConcreteColleageA::Aciton()
{
	m_pMdt->DoActionFromAtoB();
	std::cout << "State of DoActionFromAtoB:" << GetState() << std::endl;
}

void CConcreteColleageA::SetState(std::string sdt)
{
	m_strState = sdt;
}

std::string CConcreteColleageA::GetState()
{
	return m_strState;
}

CConcreteColleageB::CConcreteColleageB()
{
}

CConcreteColleageB::CConcreteColleageB(CMediator* pMdt) : CColleage(pMdt)
{
}

CConcreteColleageB::~CConcreteColleageB()
{
}

void CConcreteColleageB::Aciton()
{
	m_pMdt->DoActionFromBtoA();
	std::cout << "State of DoActionFromBtoA:" << GetState() << std::endl;
}

void CConcreteColleageB::SetState(std::string sdt)
{
	m_strState = sdt;
}

std::string CConcreteColleageB::GetState()
{
	return m_strState;
}