/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int n = 0;
	int* p = &n;

	decltype(n) n1; // int

	decltype(p) d1; // int*

	decltype(*p) d2;
	// int ? int&  // *p = 20 <- 연산자가 있기 때문에 lvalue가 될 수 있으면 참조, 아니면 값
	 // d2는 등호의 왼쪽에 올 수 있기 때문에 int&.  따라서 대입해주는 값이 없어서  error

	int x[3] = { 1,2,3 };

	decltype(x[0]) d3; // int&. 참조 타입인데 초기값이 없어서 error
	auto a1 = x[0];    // int, auto를 값으로 받을 때는 오른쪽 참조표현은 무시하기 때문에 auto가 int

	decltype(++n) d4; // int&
	decltype(n++) d5; // int
}
