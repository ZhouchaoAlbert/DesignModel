#ifndef __DECORATOR_H__
#define __DECORATOR_H__
#include <iostream>
#include <string>

/*
装饰器模式: 其主要是给一个类对象添加一个新的功能,
			优点:减少重复代码,减少类代码量的膨胀等等

*/

//下面是对流操作的一个用装饰器的简单列子

//流操作基类
class IStream
{
public:
	virtual std::string Read(int num) = 0;     //读操作
	virtual void Write(char data)     = 0;  //写操作
	virtual void Seek(int pos)        = 0;  //定位操作
};

//主体类 (文件流\网络流\内存流)
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

//装饰器
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

//加密处理
class CCryptoStream : public CDecoratorStream
{
public:
	CCryptoStream(IStream* pIStream) : CDecoratorStream(pIStream)
	{

	}

	virtual std::string Read(int num)
	{
		//这里可以进行加密操作
		m_pIStream->Read(num);
		std::cout << "CryptoStream:" << num << std::endl;
		return "CryptoStream";
	}
	virtual void Write(char data)
	{
		//这里可以进行加密操作
		m_pIStream->Write(data);
		std::cout << "CryptoStream:" << data << std::endl;
	}
	virtual void Seek(int pos)
	{
		//这里可以进行加密操作
		m_pIStream->Seek(pos);
		std::cout << "CryptoStream:" << pos << std::endl;
	}
};

//加密处理
class CBufferedStream : public CDecoratorStream
{
public:
	CBufferedStream(IStream* pIStream) : CDecoratorStream(pIStream)
	{

	}

	virtual std::string Read(int num)
	{
		//这里可以进行缓冲操作
		m_pIStream->Read(num);
		std::cout << "BufferedStream:" << num << std::endl;
		return "BufferedStream";
	}
	virtual void Write(char data)
	{
		//这里可以进行缓冲操作
		m_pIStream->Write(data);
		std::cout << "BufferedStream:" << data << std::endl;
	}
	virtual void Seek(int pos)
	{
		//这里可以进行缓冲操作
		m_pIStream->Seek(pos);
		std::cout << "BufferedStream:" << pos << std::endl;
	}
};


void DecoratorTest()
{
	//创建一个文件流对象
	CFileStream* pFileStream = new CFileStream();
	//进行读数据 然而这里读数据不安全 想把读的数据进行加密
	pFileStream->Read(111);

	//使用装饰器 对文件流加密
	CDecoratorStream* pDecoratorStream = new CCryptoStream((IStream*)pFileStream);
	pDecoratorStream->Read(111);

	//使用装饰器 对数据缓存
	CDecoratorStream* pDecoratorStream2 = new CBufferedStream((IStream*)pFileStream);
	pDecoratorStream2->Read(111);
}
#endif