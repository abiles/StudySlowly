/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor8.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// 생성자에서는 가상함수가 동작하지 않는다. 
//// 그럴 수 밖에 없을 것 같은데? 아직 Derived는 생성자가 호출되기 전이니까 가상함수가 동작하지 않음
//// 생성자에서 가상함수를 부르기 위한 테크닉이 있다
struct Base
{
	Base() { goo(); }
	
//	void foo() { goo(); }
	virtual void goo() { cout << "Base::goo" << endl; }
};

struct Derived : public Base
{
	int x;

	Derived() : x(10) {}
	virtual void goo() { cout << "Derived::goo" << x << endl; }
};

int main()
{
	Derived d;
//	d.foo();
}







