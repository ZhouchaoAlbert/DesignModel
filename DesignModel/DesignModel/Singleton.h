
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <iostream>
/*
������� ������ǰ���ҵ��ϴ�д�� ���������� ����
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
	Singleton(){}; //�����Ա�ʵ����
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
