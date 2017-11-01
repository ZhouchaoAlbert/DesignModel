
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <iostream>
/*
这个单列 是我以前带我的老大写的 就问厉害不 哈哈
*/

template<class T>
class Singleton
{
public:
	static T& Instance()
	{ 
		if(NULL == m_pInstance)
		{
			m_pInstance = new T;
		}
		return *m_pInstance;
	}
	static void UnInstance()
	{
		if (NULL != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}
protected:
	Singleton(){}; //不可以被实例化
private:
	static T* m_pInstance;
 };

template<class T>
T*	Singleton<T>::m_pInstance	=	NULL;

///////////////////////////////////////////////////////////////////////////
class CPrintIn
{
public:
	void PrinText()
	{
		std::cout << "Next my lif, Software is my passion!" << std::endl;
	}
};


void SingletonTest()
{
	Singleton<CPrintIn>::Instance().PrinText();
	Singleton<CPrintIn>::UnInstance();
}
#endif // SINGLETON_H_
