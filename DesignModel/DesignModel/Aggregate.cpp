#include "stdafx.h"
#include "Aggregate.h"


CConcreteAggregate::CConcreteAggregate()
{
	m_idx = 0;
}

CConcreteAggregate::~CConcreteAggregate()
{

}

Iterator* CConcreteAggregate::CreateIterator()
{
	return new CConcreteIterator(this);
}

void CConcreteAggregate::Insert(int obj)
{
	m_objs[m_idx] = obj;
	m_idx++;
}

int CConcreteAggregate::GetItem(int idx)
{
	if (idx < GetSize())
	{
		return m_objs[idx];
	}
	return -1;
}
int CConcreteAggregate::GetSize()
{
	if (m_idx < SIZE)
	{
		return m_idx;
	}
	return 0;
}