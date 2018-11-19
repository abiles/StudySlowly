/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this13.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
};

int main()
{
	int   n = 10;
	int* p1 = &n;

	//void(Point::*f)() = &Point::print; // 멤버 함수 포인터
	
	int Point::*p2 = &Point::x; // 멤버 변수 포인터
							    // 0
	int Point::*p3 = &Point::y; // 4
								// C의 offset_of 
								//// 위 상황에서 멤버 변수 포인터는 실제로 메모리를 잡을 수가 없다 ( Point로 할당된 애가 없기 때문에)
								//// 위 상황에서 멤버 변수 포인터는 Class에서 Offset 값을 알려준다 

	//cout << p3 << endl;
	printf("%d, %d\n", p2, p3);

	Point pt;

	pt.y = 10;
	pt.*p3 = 20; //// 사용법... 신기하네.. 이거 어디서 써먹으려나  //// pt에서 offset 만큼이동해서 오른쪽을 저장해라 이런식이겠네
						 ////  람다나 invoke 쪽 알려면 이정도는 알아둬야 한다.

	cout << pt.y << endl; // 20
}