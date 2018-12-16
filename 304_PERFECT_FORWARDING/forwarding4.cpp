/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void goo(int& a) { cout << "goo" << endl; a = 30; }
void foo(int  a) { cout << "foo" << endl; }
void hoo(int&& a) { cout << "hoo" << endl; }


/*
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// int&		: 정수형 lvalue
// int&&	: 정수형 rvalue
// T&		: 모든 타입 lvalue
// T&&		: 모든 타입 lvalue와 rvalue를 받을수 있다. // forwarding 'reference' //// ref라는걸 생각하면 안헷갈림
template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}
//// 위 처럼만들면, lvalue, rvalue 버전 모두 상황에 맞게 컴파일러가 만들어줌. 잘생각해보셈!

int main()
{
	int n = 0;

	chronometry(&goo, n);
	chronometry(&hoo, 10);

	chronometry(&foo, 5);
	cout << n << endl;
}