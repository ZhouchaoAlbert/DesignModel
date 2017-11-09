#ifndef __VISITOR_H__
#define __VISITOR_H__
#include <iostream>
#include <string>

class CElement;


class CVisitor
{
public:
	virtual void Visit(CElement *e) = 0;
};

class CVisitorA : public CVisitor
{
public:
	virtual void Visit(CElement *e)
	{
		std::cout << "：Execute VisitorA" << std::endl;
	}
};

class CVisitorB : public CVisitor
{
public:
	virtual void Visit(CElement *e)
	{
		std::cout << "：Execute VisitorB" << std::endl;
	}
};


class CElement
{
public:
	virtual void Accept(CVisitor *v)
	{
		std::cout << m_strName;
		v->Visit(this);
	}

	std::string GetName()
	{
		return m_strName;
	}


	std::string m_strName;
};

class CElementA : public CElement
{
public:
	CElementA(std::string s)
	{
		m_strName = s;
	}
};

class CElementB : public CElement
{
public:
	CElementB(std::string s)
	{
		m_strName = s;
	}
};


void VisitorTest()
{
	CElementA ea("小耗子");
	CElementB eb("小猴子");

	CVisitorA va;
	CVisitorB vb;

	ea.Accept(&va);
	ea.Accept(&vb);

	eb.Accept(&va);
	eb.Accept(&vb);
}



#endif