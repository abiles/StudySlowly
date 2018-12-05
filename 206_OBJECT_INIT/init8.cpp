/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;

	//Point() {}			//// 그냥 이렇게만 해놓으면 value 초기화 할 때 0으로 초기화 안됨, 쓰레기값나옴
	Point() = default;
};
int main()
{
	// www.cppreference.com
	Point p1;   // default initialization
	Point p2{}; // value   initialization

	cout << p1.x << endl; // 쓰레기값
	cout << p2.x << endl; // 0
}
