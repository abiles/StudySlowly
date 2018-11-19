/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this10.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class A { int a; };
class B { int b; };

class C : public A, public B
{
	int c;
};

int main()
{
	C obj;

	A* pA = &obj;
	B* pB = &obj; // &obj + sizeof(A) //// A만큼 뒤로 밀려나도록 컴파일러가 신경써줌, 그래야 진짜 B가 있으니까
	//// 다중 상속 객체에서 자식 class의 주소를 취할 때 순서에 따라 같은 &obj 이어도 다른 주소를 토해낼 수 있다

	cout << &obj << endl; // 1000 
	cout << pA   << endl; // 1000
	cout << pB   << endl; // 1004
}