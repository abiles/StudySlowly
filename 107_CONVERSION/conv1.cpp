/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// 변환 연산자 : 객체를 다른 타입으로 변환할때 호출된다.
	// 특징 : 리턴 타입을 표기하지 않는다. //// 이미 함수 이름에 포함하고 있다고 판단하기 때문에
	operator int()
	{
		return x;
	}
};

int main()
{
	int			n = 3;
	double		d = n; // 암시적 형변환 발생. //// 표준 타입끼리는 암시적 형변환 가능

	Point p1(1, 2);
	n = p1;		// p1.operator int() //// <-- 변환연산자를 컴파일러가 호출하는 방법

	cout << n << endl; // 1
}
















