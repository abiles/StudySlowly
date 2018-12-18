/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//// perfect forwarding 활용

#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b, int& c)  { cout << "Point()" << endl; }
	~Point()             { cout << "~Point()" << endl; }
	Point(const Point&)  
	{
		cout << "Point(const Point&)" << endl; 
	}
};

int main()
{
	vector<Point> v;

//	Point p(1, 2);
//	v.push_back(p); 	// 소멸자 호출 횟수 : 2,  p와  push_back에 복사 생성으로 만들어진 애


	int n = 10;
	v.emplace_back(1, 2, n);	//// 객체를 만들어서 전달하는게 아니라 객체를 만들기위한 인자를 전달
	// 소멸자 호출 횟수 : 1

	//// emplace_back은 인자 받아서 다시 생성자로 보내줘야 하니 perfect_forward으로 만들어져야 한다.
}
