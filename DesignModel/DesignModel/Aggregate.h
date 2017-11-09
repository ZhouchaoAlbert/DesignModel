#ifndef __AGGREGATE_H__
#define __AGGREGATE_H__
#include "Iterator.h"
class Iterator;

class Aggregate
{
public:
	virtual ~Aggregate(){};
	virtual Iterator* CreateIterator() = 0;
	virtual int  GetItem(int idx) = 0;
	virtual int  GetSize() = 0;
	virtual void Insert(int obj) = 0;
protected:
	Aggregate(){};
private:
};



class CConcreteAggregate :public Aggregate
{
public:
	enum { SIZE = 10 };
	CConcreteAggregate();
	~CConcreteAggregate();
	Iterator* CreateIterator();
	void Insert(int obj);
	int  GetItem(int idx);
	int  GetSize();
protected:
private:
	int m_objs[SIZE];
	int m_idx;
};


#endif