#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
#include <iostream>
#include <string>


/* ��Ϊģʽ
Template ģʽ:
Templateģʽ�ǲ��ü̳еķ�ʽʵ����һ�㣺���߼����㷨����ܷ��ڳ�������У��������ϸ�ڵĽӿڣ�������ʵ��ϸ�ڡ�
*/

// ׷MM����ģ��
class CCatchMMTemplate
{
public:
	virtual bool BuyGift() = 0;        //�������MM
	virtual bool Accompany() = 0;      //����������
	virtual bool ToTravel() = 0;       //һ������

	void CatchMM()
	{
		// ʧ�ܴ������ڵ���2��ûϷ��
		int nFailedCnt = 0;
		if (!BuyGift())
			nFailedCnt++;
		if (!Accompany())
			nFailedCnt++;
		if (!ToTravel())
			nFailedCnt++;

		if (nFailedCnt > 1)
		{
			std::cout << m_strName << "׷MMʧ��" << std::endl;
		}
		else
		{
			std::cout << m_strName << "�ɹ�׷��MM" << std::endl;
		}
	}
	
	std::string m_strName;
};

//С����
class CHaozi : public CCatchMMTemplate
{
public:
	CHaozi(std::string strName)
	{
		m_strName = strName;
		std::cout << "����:" << m_strName << std::endl;
	}
	virtual bool BuyGift()
	{
		std::cout << "����Ķ���,���յ���û,��ϲ����?" << std::endl;
		return true;
	}
	virtual bool Accompany()
	{
		std::cout << "��Ҫ�ѹ���Ҫ����,�һ�һֱ���������!" << std::endl;
		return true;
	}
	virtual bool ToTravel()
	{
		std::cout << "�þ�ûһ���ȥ����,��׼��һ��,��ȥ����һ����������." << std::endl;
		return true;
	}
};
//С��
class CPig : public CCatchMMTemplate
{
public:
	CPig(std::string strName)
	{
		m_strName = strName;
		std::cout << "����:" << m_strName << std::endl;
	}
	virtual bool BuyGift()
	{
		std::cout << "û������ϲ��������,��β�����" << std::endl;
		return false;
	}
	virtual bool Accompany()
	{
		std::cout << "��Ҫ�漸����Ϸ,���ȵȵ���..." << std::endl;
		return false;
	}
	virtual bool ToTravel()
	{
		std::cout << "����̫����..���˻��ǲ�ȥ��" << std::endl;
		return false;
	}
};


void TemplateTest()
{
	CHaozi haozi("С����");
	haozi.CatchMM();

	CPig pig("С��");
	pig.CatchMM();
}

#endif