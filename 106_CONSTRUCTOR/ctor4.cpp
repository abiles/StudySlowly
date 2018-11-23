/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

class Point
{
	int x, y;
public:
//	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
class Rect
{
	Point p1;
	Point p2;
public:
	Rect() : p1(0,0), p2(0,0) //: p1(), p2()  //// <- 기본적으로 (암묵적으로 만들어 주는 애들)
																   //// 기본생성자가 없다면 사용자가 특정 생성자(초기화 리스트에서)를 지정해서 사용할 수 있다
	{
	}
};

int main()
{
	Rect r; // p1의 생성자, p2 생성자, Rect 생성자
}