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

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10
	//// arg 자체는 lvalue이다. (이름이 있으니까)
	//f(arg); //// <--- hoo는 rvalue만 받을 수 있기 때문에 캐스팅이 없으면 오류남
	
	// 해결책 : lvalue인 arg를 rvalue로 다시 캐스팅한다
	f(static_cast<int&&>(arg)); //// 이런건 move로 대체하려나?, 안하려나?
}

int main()
{
	//hoo(10); // ok..
	chronometry(&hoo, 10); // error //// why?
	
	int&& arg = 10; // 10 은 rvalue,
					// arg는 lvalue 이다.

	
	int n = 0;

	chronometry(&goo, n);
	chronometry(&foo, 5);

	cout << n << endl;

}