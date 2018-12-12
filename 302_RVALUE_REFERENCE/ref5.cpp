/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

void f1(int&  a) {}	// lvalue 만 인자로 전달 가능. f1(n) : ok      f1(10) : error
void f2(int&& a) {}	// rvalue 만 인자로 전달 가능. f2(n) : error  f2(10) : ok


template<typename T> void f3(T& a) {} // T : int&   T& : int& &, ref collapse 규칙을 적용해야 한다는걸 알아라!
// 모든 타입의 lvalue 만 전달 가능.
//// T를 어떻게 바꾼다고해도 rvalue 받을 수 있겠어요?


int main()
{
	int n = 10;

	// T의 타입을 사용자가 지정할 경우 <> 사용
	f3<int>(n );			// f3( int & a)  => lvalue 전달 가능.
	f3<int&>(n );		// f3( int& & a) => f3( int& a) => lvalue 전달 가능.
	f3<int&&>(n );		// f3( int&& & a)=> f3( int& a) => lvalue 전달 가능.

	// 사용자가 T 타입을 지정하지 않은 경우
	f3(10);		// 10을 전달 받을 수 있도록 T를 결정해보자! -> T를 뭐로 바꿔도 rvalue를 받을 수 없다. 그래서 error
	f3(n);		// T : int.  ok.
}