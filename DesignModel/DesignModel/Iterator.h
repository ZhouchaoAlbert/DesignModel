#ifndef __ITERATOR_H__
#define __ITERATOR_H__
#include <iostream>
#include <string>
#include "Aggregate.h"

class Aggregate;

class Iterator
{
public:
	virtual ~Iterator(){};
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual int CurrentItem() = 0;
protected:
	Iterator(){};
private:
};


class CConcreteIterator :public Iterator
{
public:
	CConcreteIterator(Aggregate* pag, int idx = 0);
	~CConcreteIterator(){}
	void First();
	void Next();
	bool IsDone();
	int  CurrentItem();
protected:
private:
	Aggregate* m_pag;
	int        m_idx;
};


#endif
