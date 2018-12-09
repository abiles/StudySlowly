/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0)	{ cout << "Point()" << endl; }
	~Point()								{ cout << "~Point()" << endl; }
};

// 임시객체와 함수 인자
//// void foo ( Point& p ) <- 이렇게 쓸 수는 없다. 왜냐면 임시객체는 const&일 때만 받을 수 있으니까, 복사하고 싶지도 않고
void foo(const Point& p) 
{
}

int main()
{
	Point p(1,1);	//// 이 객체는 {} 끝에서 소멸된다.
	foo(p);

	//// 함수 호출에만 필요하다면 이렇게 만드는 것도 괜찮지 않을까?
	// 임시 객체를 사용한 인자 전달
	foo(Point(1, 1));

	// STL에서 임시객체를 사용하는 경우
	//	sort(x, x + 10, less<int>());

	cout << "end" << endl;

}

