/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <initializer_list>
using namespace std;
//// 일반 list와의 차이점은 일반 list는 연속적인 메모리에 놓여있지 않다
//// copy 초기화, direct초기화 가능

void foo( initializer_list<int> e )
{
	auto p1 = begin(e);
	auto p2 = end(e);

	for (auto n : e)
		cout << n << " ";
	cout << endl;
}

int main()
{
	initializer_list<int> e1 = { 1,2,3 };
	initializer_list<int> e2  { 1,2,3,4,5 };

	foo(e1);
	foo({ 1,2,3,4 });
	foo({ 1,2,3,4,5,6,7 });

}