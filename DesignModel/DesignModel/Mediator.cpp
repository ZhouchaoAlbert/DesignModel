#include "stdafx.h"
#include "Mediator.h"





CConcreteMediator::CConcreteMediator()
{

}
CConcreteMediator::CConcreteMediator(CColleage* pClgA, CColleage* pClgB)
{
	m_pClgA = pClgA;
	m_pClgB = pClgB;
}

CConcreteMediator::~CConcreteMediator()
{

}
void CConcreteMediator::SetConcreteColleageA(CColleage* pClgA)
{
	m_pClgA = pClgA;
}

void CConcreteMediator::SetConcreteColleageB(CColleage* pClgB)
{
	m_pClgB = pClgB;
}

CColleage* CConcreteMediator::GetConcreteColleageA()
{
	return m_pClgA;
}

CColleage* CConcreteMediator::GetConcreteColleageB()
{
	return m_pClgB;
}

void CConcreteMediator::IntroColleage(CColleage* pClgA, CColleage* pClgB)
{
	m_pClgA = pClgA;
	m_pClgB = pClgB;
}

void CConcreteMediator::DoActionFromAtoB()
{
	m_pClgB->SetState(m_pClgA->GetState());
}

void CConcreteMediator::DoActionFromBtoA()
{
	m_pClgA->SetState(m_pClgB->GetState());
}

