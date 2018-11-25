/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// Point => int : 변환 연산자   p.operator int()
// int => Point : 변환 생성자   Point(int)

class Point
{
	int x, y;
public:
	Point()				: x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// 인자가 한개인 생성자 -  변환 생성자 //// 변환생성자는 인자가 한개일 수 밖에 없겠군 p = n 이런 식으로 밖에 쓰일 수 없을테니
	//	다른 타입이 Point로 변환 되게 한다.
	Point(int a) : x(a), y(0) {}

	operator int() 	{ return x; }
};

int main()
{
	Point p1;
	Point p2(1, 1);

	int n = 3;
	Point p(1, 2);

	n = p; // Point => int   p.operator int()
	p = n; // int => Point   n.operator Point() 가 있으면 된다.
		      //						하지만, n은 사용자정의 타입이 아니다(표준타입, Primitive 타입)
			  //// 이런 형태에서는 컴파일러가 변환 생성자를 가져온다
}



















