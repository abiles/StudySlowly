/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new7.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) 
	{
		cout << "Point(int, int)" << endl;
	} 
};

int main()
{
	// Point 객체를 힙에 한개 만들고 싶다.
	Point* p1 = new Point(0, 0); // ok.


	// Point 객체를 힙에 10개 만들고 싶다.
	//Point* p2 = new Point[10]; // error. 
	//// default 생성자가 없기 때문에 이거 안됨
	//// 메모리 할당이랑 생성자 호출이 따로 있으면 유연성이 올라감

	// 1. 메모리만 먼저 힙에 할당
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));
	
	// 2. 할당한 메모리에 객체를 생성(생성자 호출)
	for (int i = 0; i < 10; i++)
		new(&p2[i]) Point(0,0);

	//// 이 과정의 순서도 잊지 말것
	// 3. 소멸자 호출
	for (int i = 9; i >= 0; i--)
		p2[i].~Point();

	// 4. 메모리 해지.
	operator delete(p2);

	//vector<Point> v(10, Point(0,0)); //// 이런식으로 vector 내부에서 버퍼를 할당할 때 new를 사용하지 않고

	//// operator new를 사용해서 메모리 할당하고, 임시객체 Point(0,0)의 복사생성자로 초기화를 해준다
	//// default 생성자가 없기 때문에!
}
