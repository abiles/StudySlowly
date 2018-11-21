/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new5.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()  { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// placement new : 생성자를 호출하기 위해 만든 new //// C++ 표준
// 
/*
void* operator new(size_t sz, void* p)
{
	return p; //// 인자로 받은 포인터 그대로 돌려주기
}
*/
int main()
{
	Point p;	//// 일단 생성자 한번 불림
	//// p.Point (); 이런식으로 생성자를 호출할 수가 없다.

	//new Point; // 인자가 1개인 operator new()호출. //// 기본 new연산자

	new(&p) Point; // 인자가 2개인 operator new()호출. //// size는 알아서 넘어감
					// 메모리 할당이 아닌 생성자를 호출하는 코드
	//// new(&p)를 어떻게 이해해야 하냐 하면
	//// 1. 새로 만든 인자 2개자리 operator new를 부르고
	//// 2. 메모리 주소를 새로만든 operator new 를 통해서 반환하게 된다 
	//// 3. 이 때 유효한 주소를 리턴하기 때문에 생성자를 호출하게 된다
	//// 결국 중요한건 생성자를 p에 대해서 한번 호출한다는 것이다. 
	p.~Point(); 
}