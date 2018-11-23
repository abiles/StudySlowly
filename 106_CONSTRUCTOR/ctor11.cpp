/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor11.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <memory>
using namespace std;

struct Resource
{
	Resource() { cout << "acquire Resource" << endl; }
	~Resource() { cout << "release Resource" << endl; }
};

// �ذ�å 2. two-phase constructor
//// 2�� ������ ȣ��
//// ���� : 2�� ȣ���ؾߵ�
//// ���� : 2��° �����ڿ��� �����Լ� ȣ���� �� ����

class Test
{
	Resource* p;
public:
	Test() : p(nullptr)
	{
		// ���� ���ɼ��� �ִ� ��� �۾��� ���� �ʴ´�.
		//// ���ܰ� �߻����� ������ �Ҹ��ڰ� �Ҹ��� ���� �����Ѵ�
		// �����Լ� ȣ��() //// �����ڿ����� �����Լ��� ȣ�� �� �� ����
									//// 2��° ������( Construct() )������ �����Լ��� ȣ�� �� �� ����
	}

	// �ڿ� �Ҵ� ������
	//// �����ڿ��� ������ �Ͼ���� ���� �ϰ� ���� �����ϱ�
	void Construct()
	{
		p = new Resource;
		//cout << "Test()" << endl;
		// �����Լ� ȣ��()
		throw 1;
	}

	~Test()
	{
		delete p;
		cout << "~Test()" << endl;
	}
};


int main()
{
	try
	{
		Test t;
		t.Construct(); // �ʿ��� �ڿ� �Ҵ�.
	}
	catch (...)
	{
		cout << "���� �߻�" << endl;
	}
}

