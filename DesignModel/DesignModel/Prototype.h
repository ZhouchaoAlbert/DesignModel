#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__
#include <iostream>
#include <string>


class CPrototype
{
public:
	virtual CPrototype* Clone()const = 0;
};

class CConcretePrototype : public CPrototype
{
public:	
	CConcretePrototype()
	{
		std::cout << "CConcretePrototype " << std::endl;
	}
	CConcretePrototype(CConcretePrototype* cp)
	{
		std::cout << "CConcretePrototype copy....." << std::endl;
	}

	virtual CPrototype* Clone()const
	{
		return new CConcretePrototype(*this);
	}

	void SetPrinText(std::string strtext)
	{
		m_strtext = strtext;
	}
	std::string GetPrinText()
	{
		return m_strtext;
	}
	std::string m_strtext;
};

void PrototypeTest()
{
	CConcretePrototype* p = new CConcretePrototype();
	p->SetPrinText("i am beauty? yes or no?");

	CPrototype*p2 = p->Clone();
	std::string strText = ((CConcretePrototype*)p2)->GetPrinText();
	std::cout << strText.c_str() << std::endl;
}


#endif