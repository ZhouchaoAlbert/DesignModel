#ifndef __DECORATOR_H__
#define __DECORATOR_H__
#include <iostream>
#include <string>

/*
װ����ģʽ: ����Ҫ�Ǹ�һ����������һ���µĹ���,
			�ŵ�:�����ظ�����,����������������͵ȵ�

*/

//�����Ƕ���������һ����װ�����ļ�����

//����������
class IStream
{
public:
	virtual std::string Read(int num) = 0;     //������
	virtual void Write(char data)     = 0;  //д����
	virtual void Seek(int pos)        = 0;  //��λ����
};

//������ (�ļ���\������\�ڴ���)
class CFileStream
{
public:
	virtual std::string Read(int num)
	{
		std::cout << "FileStream:" << num << std::endl;
		return "FileStream";
	}
	virtual void Write(char data)
	{
		std::cout << "FileStream:" << data << std::endl;
	}
	virtual void Seek(int pos)
	{
		std::cout << "FileStream:" << pos << std::endl;
	}
};

class CNetworkStream
{
public:
	virtual std::string Read(int num)
	{
		std::cout << "NetworkStream:" << num << std::endl;
		return "NetworkStream";
	}
	virtual void Write(char data)
	{
		std::cout << "NetworkStream:" << data << std::endl;
	}
	virtual void Seek(int pos)
	{
		std::cout << "NetworkStream:" << pos << std::endl;
	}

};

class CMemoryStream
{
public:
	virtual std::string Read(int num)
	{
		std::cout << "MemoryStream:" << num << std::endl;
		return "MemoryStream";
	}
	virtual void Write(char data)
	{
		std::cout << "MemoryStream:" << data << std::endl;
	}
	virtual void Seek(int pos)
	{
		std::cout << "MemoryStream:" << pos << std::endl;
	}
};

//װ����
class CDecoratorStream : public IStream
{
public: 
	CDecoratorStream(IStream* pIStream) :
		m_pIStream(pIStream)
	{

	}
	virtual std::string Read(int num)
	{
		std::cout << "DecoratorStream:" << num << std::endl;
		return "DecoratorStream";
	}
	virtual void Write(char data)
	{
		std::cout << "DecoratorStream:" << data << std::endl;
	}
	virtual void Seek(int pos)
	{
		std::cout << "DecoratorStream:" << pos << std::endl;
	}

	IStream* m_pIStream;
};

//���ܴ���
class CCryptoStream : public CDecoratorStream
{
public:
	CCryptoStream(IStream* pIStream) : CDecoratorStream(pIStream)
	{

	}

	virtual std::string Read(int num)
	{
		//������Խ��м��ܲ���
		m_pIStream->Read(num);
		std::cout << "CryptoStream:" << num << std::endl;
		return "CryptoStream";
	}
	virtual void Write(char data)
	{
		//������Խ��м��ܲ���
		m_pIStream->Write(data);
		std::cout << "CryptoStream:" << data << std::endl;
	}
	virtual void Seek(int pos)
	{
		//������Խ��м��ܲ���
		m_pIStream->Seek(pos);
		std::cout << "CryptoStream:" << pos << std::endl;
	}
};

//���ܴ���
class CBufferedStream : public CDecoratorStream
{
public:
	CBufferedStream(IStream* pIStream) : CDecoratorStream(pIStream)
	{

	}

	virtual std::string Read(int num)
	{
		//������Խ��л������
		m_pIStream->Read(num);
		std::cout << "BufferedStream:" << num << std::endl;
		return "BufferedStream";
	}
	virtual void Write(char data)
	{
		//������Խ��л������
		m_pIStream->Write(data);
		std::cout << "BufferedStream:" << data << std::endl;
	}
	virtual void Seek(int pos)
	{
		//������Խ��л������
		m_pIStream->Seek(pos);
		std::cout << "BufferedStream:" << pos << std::endl;
	}
};


void DecoratorTest()
{
	//����һ���ļ�������
	CFileStream* pFileStream = new CFileStream();
	//���ж����� Ȼ����������ݲ���ȫ ��Ѷ������ݽ��м���
	pFileStream->Read(111);

	//ʹ��װ���� ���ļ�������
	CDecoratorStream* pDecoratorStream = new CCryptoStream((IStream*)pFileStream);
	pDecoratorStream->Read(111);

	//ʹ��װ���� �����ݻ���
	CDecoratorStream* pDecoratorStream2 = new CBufferedStream((IStream*)pFileStream);
	pDecoratorStream2->Read(111);
}
#endif