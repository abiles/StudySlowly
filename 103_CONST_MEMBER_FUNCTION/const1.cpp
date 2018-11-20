/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void set(int a, int b) 
	{
		x = a; 
		y = b; 
	}
	void print()  //const	// 상수 멤버 함수 //// 실수할까봐 붙이는게 아님, 반드시 필요함 어디서? 상수 객체가 호출할 수 있는 함수라는 뜻이 있으니까
	//// 상수객체는 상수 멤버함수만 호출 할 수 있다.
	{
	//	x = 10;	// error. 모든 멤버를 상수 취급한다.

		cout << x << ", " << y << endl;
	}
};

int main()
{
	const Point p(1, 1);

	p.x = 10;		// error
	p.set(10, 20);	// error
	p.print();		// ok. error.

}
