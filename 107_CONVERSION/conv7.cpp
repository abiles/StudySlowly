/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv7.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int   n1 = 10; // ok
	void* p1 = 10; // error.

	int   n2 = 0; // ok
	void* p2 = 0; // ok. 정수는 원래 포인터로 암시적 형변환 안됨, 특별히 0은 '정수'지만 컴파일러에 의해 포인터로 암시적 형변환된다.

}



















