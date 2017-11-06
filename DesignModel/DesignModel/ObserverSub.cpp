#include "stdafx.h"
#include "ObserverSub.h"


void CSubject2::Attach(CObserver2* pObv)
{
	m_listObv.push_front(pObv);
}

void CSubject2::Detach(CObserver2* pObv)
{
	if (pObv)
	{
		m_listObv.remove(pObv);
	}
}

void CSubject2::Notify()
{
	for (std::list<CObserver2*>::iterator it = m_listObv.begin(); it != m_listObv.end(); it++)
	{
		CObserver2* pObv = *it;
		if (pObv)
		{
			pObv->Update(this);// 通知所有的观察者更新
		}
	}
}