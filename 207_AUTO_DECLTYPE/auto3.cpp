/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int  n = 0;
	int* p = &n;

	//// decltype(expr) 일 때 expr이 변수 자체면 변수의 선언을 보고 결정
	decltype(n) d1;	// int   // n = 10;
	decltype(p) d2;	// int*


	//// decltype(expr) 일 때 expr이 변수 + 연산자라면 아래의 공식 따름
	//  수식이 lvalue라면 참조, 아니면 값 타입
	decltype(*p)  d3; // *p = 10;   int&
	decltype((n)) d4; // (n) = 10;  int&

	decltype(n + n) d5; // n+n = 10 가 될수 없다.  int 
	decltype(++n)   d6; // ++n = 10; ok..     int&
	decltype(n++)   d7; // n++ = 10; error.   int	//// 이 부분은 헷갈릴 수 있겠다

	int x[3] = { 1,2,3 };

	decltype(x[0]) d8;  // x[0] = 10; ok    int&
	auto a1 = x[0];		// int
}