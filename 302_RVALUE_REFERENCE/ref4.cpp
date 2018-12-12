/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

using LREF = int&;	// typedef int&  LREF;
using RREF = int&&; // typedef int&& RREF;

/*
reference collapse 규칙
 &			&			= &
 &			&&		= &
 &&		&			= &
 &&		&&		= &&
*/

template<typename T> void foo(T& a) {}

int main()
{
	int n = 10;

	foo<int&>(n ); // foo( int& & a) => foo(int& a) //// <- ref collapse가 일어나는 상황

	LREF r1 = n;
	RREF r2 = 10;

	LREF&  r3 = n; // int& & r3 => int&
	RREF&  r4 = n; // int&& & => int&
	LREF&& r5 = n; // int& && => int&
	RREF&& r6 = 10; // int&& && => int&&

	int& && r7; // 직접쓰면 컴파일 에러...typedef, template등 사용할 때 발생할 수 있는 문제

}