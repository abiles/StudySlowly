/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor9.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct Resource
{
	Resource()  { cout << "acquire Resource" << endl; }
	~Resource() { cout << "release Resource" << endl; }
};

class Test
{
	Resource* p;
public:
	//// 생성자는 리턴값이 없다
	//// 뭔가 실패했을 때 알리만한게 예외 밖에 없다
	//// 생성자에서 예외가 나오면 소멸자를 부를 수가 없다 ( 이건 C++ 규칙 )
	Test() : p( new Resource )
	{
		cout << "Test()" << endl;
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
	}
	catch (...)
	{
		cout << "예외 발생" << endl;
	}
}

