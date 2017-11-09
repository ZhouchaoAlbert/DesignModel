#include "stdafx.h"
#include "Iterator.h"


CConcreteIterator::CConcreteIterator(Aggregate* pag, int idx/* = 0*/)
{
	m_pag = pag;
	m_idx = idx;
}

void CConcreteIterator::First()
{
	m_idx = 0;
}
void CConcreteIterator::Next()
{
	if (m_idx < m_pag->GetSize())
	{
		m_idx++;
	}
}

bool CConcreteIterator::IsDone()
{
	return m_idx == m_pag->GetSize();
}

int CConcreteIterator::CurrentItem()
{
	return m_pag->GetItem(m_idx);
};