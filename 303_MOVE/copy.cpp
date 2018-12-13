/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	//Point(Point p) // Point p = p1. 결국 복사 생성자가 무한히 호출.

	// Point(Point& p)
	// lvalue 객체만 인자로 받을수 있다. 함수 리턴값으로 반환되는 임시객체를 받을 수 없다.


	Point(const Point& p) // lvalue객체와 rvalue 객체를 모두 받을수 있다. //// const 니까 rvalue도 받을 수 있지
	{
		// 모든 멤버 복사.
	}
};

//// 임시객체 리턴
Point foo()
{
	Point ret(0, 0);
	return ret;
}

int main()
{
	Point p1(1, 1);	// 생성자 호출
	Point p2(p1);	// Point( Point )  복사 생성자.

	Point p3( foo() ); //// 이런경우도 있으니까 rvalue도 받을 수 있어야 한다. 
}