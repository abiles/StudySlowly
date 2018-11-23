/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Base
{
public:
//	Base()      { cout << "B()"    << endl; }
	Base(int a) { cout << "B(int)" << endl; }
	~Base()     { cout << "~B()" << endl; }
};
class Derived : public Base
{
public:
	Derived() : Base()
	{
		cout << "D()" << endl; 
	}
	//// 내가 아무것도 지정하지 않았다면 아래가 암묵적으로 만들어짐
	/*
	Derived ( int a ) : Base ( )
	{
		cout << "D(int)" << endl;
	}
	*/

	Derived(int a) : Base(a)
	{ 
		cout << "D(int)" << endl; 
	}
	~Derived()      { cout << "~D()" << endl; }
};

int main()
{
	Derived d(5);
}