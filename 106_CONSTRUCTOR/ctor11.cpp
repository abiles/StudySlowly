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

// 해결책 2. two-phase constructor
//// 2단 생성자 호출
//// 단점 : 2번 호출해야됨
//// 장점 : 2번째 생성자에서 가상함수 호출할 수 있음

class Test
{
	Resource* p;
public:
	Test() : p(nullptr)
	{
		// 예외 가능성이 있는 어떠한 작업도 하지 않는다.
		//// 예외가 발생하지 않으면 소멸자가 불리는 것을 보장한다
		// 가상함수 호출() //// 생성자에서는 가상함수을 호출 할 수 없음
									//// 2번째 생성자( Construct() )에서는 가상함수를 호출 할 수 있음
	}

	// 자원 할당 전용함
	//// 생성자에서 오류가 일어날만한 일을 하고 싶지 않으니까
	void Construct()
	{
		p = new Resource;
		//cout << "Test()" << endl;
		// 가상함수 호출()
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
		t.Construct(); // 필요한 자원 할당.
	}
	catch (...)
	{
		cout << "예외 발생" << endl;
	}
}

