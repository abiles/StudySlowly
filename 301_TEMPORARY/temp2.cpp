/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : temp2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>

// 핵심 1. 임시객체를 생성하는 방법 - "클래스이름(생성자인자)"
//      2. 임시객체의 수명 - 문장의 끝.

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { std::cout << "Point()"  << std::endl; }
	~Point()					{ std::cout << "~Point()" << std::endl; }
};

int main()
{
	//// Point p1(1,1)
	//// 이름 p1, 파괴 : 함수 {}을 벗어날 때 	
	////  named object.

	////	Point(1, 1);
	//// 이름  없음, 파괴 : 문장의 ;를 만났을 때(문장의 끝)
	//// unamed object. temporary.

	Point(1, 1), std::cout << "X" << std::endl;
	//// 이것의 결과는?
	//// Point(), X, ~Point()

	std::cout << "----------" << std::endl;
}

