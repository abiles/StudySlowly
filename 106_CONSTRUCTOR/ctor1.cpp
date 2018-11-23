/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;
//// 1. 파생클래스 생성시 기반 클래스의 생성자가 먼저 호출됨
//// 2. 기반 클래스의 생성자는 '항상' 디폴트 생성자가 호출됨
//// 3. 기반 클래스의 디폴트 생성자가 없는 경우 파생 클래스의 객체를 만들 수 없다.
//// 4. 기반 클래스의 다른 생성자를 호출하려면 파생클래스의 생성자의 초기화 리스트에서 명시적으로 호출 해야 함


class Base
{
public:
//	Base()      { cout << "B()"    << endl; }
	Base(int a) { cout << "B(int)" << endl; }
	~Base()     { cout << "~B()"   << endl; }
};

class Derived : public Base
{
public:
	Derived()     : Base(0) { cout << "D()" << endl; }
	Derived(int a): Base(a) { cout << "D(int)" << endl; } //// 기반 클래스 생성자를 명시적으로 지정한 버전, 이 때 다른 생성자들도 명시적으로 지정하지 않으면 컴파일 오류남
	~Derived()     { cout << "~D()" << endl; }
};

int main()
{
	//Derived d;
	Derived d(5);
}