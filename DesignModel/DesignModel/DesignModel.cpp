// DesignModel.cpp : �������̨Ӧ�ó������ڵ㡣
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

int _tmain(int argc, _TCHAR* argv[])
{
	//������
	Factory1Test();
	Factory2Test();
	AbstractFactoryTest();
	SingletonTest();
	BuilderTest();
	PrototypeTest();
	//�ṹ��
	BridgeTest();
	AdaptorTest(); 
	DecoratorTest();
	CompositeTest();
	FlyWeightTest();
	FacadeTest();
	ProxyTest();
	//��Ϊģʽ
	TemplateTest();
	StrategyTest();
	StateTest();
	ObserverTest();
	system("pause");
	return 0;
}

