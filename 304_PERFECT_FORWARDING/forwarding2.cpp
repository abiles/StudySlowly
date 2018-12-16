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

//// 완벽한 전달을 위해서는 복사가 일어나서는 안된다. so 반드시 ref를 사용해야 한다
//// lvalue, rvalue ref 버전을 모두 제공해야 한다.
//// 하지만 여기에도 문제점이 있당

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	int n = 0;

	chronometry(&goo, n);
	chronometry(&foo, 5);

	cout << n << endl; 

}