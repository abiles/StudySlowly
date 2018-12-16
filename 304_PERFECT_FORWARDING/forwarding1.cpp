/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void goo(int& a) { 
	cout << "goo" << endl;
	a = 30;
}

void foo(int  a) { 
	cout << "foo" << endl;
}

// 완벽한 전달 : 래퍼함수(여기서는 chronometry)가 인자를 받아서 원본 함수에게 완벽하게 전달하는 개념
// perfect forwarding.
template<typename F, typename A> 
void chronometry(F f, const A& arg) //// A -> A&, -> const A& 이렇게 해도 goo를 보냈을 때 error가 있다. 그럼 어떻게 해야할까?
{
	f(arg);
}

int main()
{
	int n = 0;
	//goo(n);
	//foo(5);
	chronometry(&goo, n); // goo(n)
	chronometry(&foo, 5); // foo(5) 실행시 수행시간.

	cout << n << endl; // 30

}