#ifndef __BRIDGE_H__
#define __BRIDGE_H__
#include <iostream>

/*
Bridge模式:将实现部分和它的抽象部分分离
*/

class CDrawLib1
{
public: 
	void DrawRectangle()
	{
		std::cout << "Draw1:画一个长方形" << std::endl;
	}
	void DrawTriangle()
	{
		std::cout << "Draw1:画一个三角形" << std::endl;
	}
	void DrawCircle()
	{
		std::cout << "Draw1:画一个圆形" << std::endl;
	}
};


class CDrawLib2
{
public:
	void DrawRectangle()
	{
		std::cout << "Draw2:画一个长方形" << std::endl;
	}
	void DrawTriangle()
	{
		std::cout << "Draw2:画一个三角形" << std::endl;
	}
	void DrawCircle()
	{
		std::cout << "Draw2:画一个圆形" << std::endl;
	}
};


class CShapeImp   
{
public:
	virtual void DrawTriangle() = 0;
	virtual void DrawRectangle() = 0;
};

//用库1画形状
class CShape1Imp : CShapeImp
{
public: 
	virtual void DrawTriangle()
	{
		m_Draw1.DrawTriangle();
	}
	virtual void DrawRectangle()
	{
		m_Draw1.DrawRectangle();
	}
private:
	CDrawLib1 m_Draw1;
};

//用库2画形状
class CShape2Imp : CShapeImp
{
public:
	virtual void DrawTriangle()
	{
		m_Draw2.DrawTriangle();
	}
	virtual void DrawRectangle()
	{
		m_Draw2.DrawRectangle();
	}
private:
	CDrawLib2 m_Draw2;
};


class CShape
{
public:
	virtual void Draw() = 0;
public:
	CShapeImp* m_imp;
};

class CTriangle : public CShape
{
public:
	CTriangle(CShapeImp* imp)
	{
		m_imp = imp;
	}
	virtual void Draw()
	{
		m_imp->DrawTriangle();
	}
};


class CRectangle : public CShape
{
public:
	CRectangle(CShapeImp* imp)
	{
		m_imp = imp;
	}
	virtual void Draw()
	{
		m_imp->DrawRectangle();
	}
};



void BridgeTest()
{
	CShape1Imp imp1;
	CShape2Imp imp2;

	CTriangle tri1((CShapeImp*)&imp1);
	CTriangle tri2((CShapeImp*)&imp2);
	tri1.Draw();
	tri2.Draw();

	CRectangle r1((CShapeImp*)&imp1);
	CRectangle r2((CShapeImp*)&imp2);
	r1.Draw();
	r2.Draw();

}
#endif