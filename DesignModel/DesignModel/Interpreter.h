#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#include <string>
#include <iostream>

class CContext
{
public:
	CContext()
	{
	}
	~CContext()
	{
	}
};

class CAbstractExpression
{
public:
	CAbstractExpression()
	{
	}
	virtual ~CAbstractExpression()
	{
	}

	void virtual Interpret(CContext *context) = 0;
};


class CTerminalExpression : public CAbstractExpression
{
public:
	CTerminalExpression()
	{
	}
	~CTerminalExpression()
	{
	}
	void Interpret(CContext *context)
	{
		std::cout << "Terminal Expression --> context" << std::endl;
	}
};


class CNonterminalExpression : public CAbstractExpression
{
public:
	CNonterminalExpression()
	{
	}
	~CNonterminalExpression()
	{
	}
	void Interpret(CContext *context)
	{
		std::cout << "Non-Terminal Expression --> context" << std::endl;
	}
};


void InterpreterTest()
{
	std::cout << "***InterpreterTest***" << std::endl;

	CContext *context = new CContext();
	CAbstractExpression *t = new CTerminalExpression();
	CAbstractExpression *n = new CNonterminalExpression();
	t->Interpret(context);
	n->Interpret(context);
}

#endif