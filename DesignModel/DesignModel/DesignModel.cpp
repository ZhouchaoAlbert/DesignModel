// DesignModel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Factory1.h"
#include "Factory2.h"
#include "AbstractFactory.h"
#include "Singleton.h"
#include "Builder.h"
#include "Prototype.h"
#include "Bridge.h"
#include "Adaptor.h"
#include "Decorator.h"
#include "Composite.h"
#include "Flyweight.h"
#include "Facade.h"
#include "Proxy.h"
#include "Template.h"
#include "Strategy.h"
#include "State.h"
#include "Observer.h"
#include "Memento.h"
#include "Mediator.h"
#include "Colleage.h"
#include "Command.h"
#include "Visitor.h"

void ObserverTest()
{
	CSubject2* pSubject = new CConcreteSubject();
	CObserver2* pObv1 = new CConcreteObserverA(pSubject);
	CObserver2* pObv2 = new CConcreteObserverB(pSubject);
	pSubject->SetState("old state");
	pSubject->Notify();
	pSubject->SetState("new state");
	pSubject->Notify();
}

void  MediatorTest()
{
	CConcreteMediator* m = new	CConcreteMediator();
	CConcreteColleageA* c1 = new CConcreteColleageA(m);
	CConcreteColleageB* c2 = new CConcreteColleageB(m);
	m->IntroColleage(c1, c2);
	c1->SetState("old");
	c2->SetState("old");
	c1->Aciton();
	c2->Aciton();
	cout << endl;

	c1->SetState("new");
	c1->Aciton();
	c2->Aciton();

	cout << endl;
	c2->SetState("old");
	c2->Aciton();
	c1->Aciton();
}

int _tmain(int argc, _TCHAR* argv[])
{
	//创建型
	Factory1Test();
	Factory2Test();
	AbstractFactoryTest();
	SingletonTest();
	BuilderTest();
	PrototypeTest();
	//结构型
	BridgeTest();
	AdaptorTest(); 
	DecoratorTest();
	CompositeTest();
	FlyWeightTest();
	FacadeTest();
	ProxyTest();
	//行为模式
	TemplateTest();
	StrategyTest();
	StateTest();
	ObserverTest();
	MementoTest();
	MediatorTest();
	CommandTest();
	VisitorTest();
	system("pause");
	return 0;
}

