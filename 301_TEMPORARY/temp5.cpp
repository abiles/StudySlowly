/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : temp3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};
// temp5.cpp
//// 함수에서 값을 리턴하면 임시객체가 생성된다.

Point foo()
{
	Point pt(1, 1);		// 2. 생성자
	return pt;				// return Point(pt) 임시객체 생성, pt는 {} 벗어나면 파괴되기 때문에 여기서 임시객체로 복사본 만들어 놔야함
								// 3. 복사 생성자 ( pt -> 임시객체로 복사)
}	

Point foo2()
{
	// 임시객체를 사용한 리턴
	// RVO ( Return Value Optimization )
	return Point ( 1, 1 );	// 2. 생성자
										// 복사 생성자 만드는 작업 X
}

int main()
{
	Point ret(0, 0);	// 1. 생성자
	ret = foo();			// 4. 임시 객체가 대입연산자 통해서 ret로 
								// 5. 임시 객체 소멸

	Point ret2 ( 1, 1 );	// 1. 생성자
	ret2 = foo2();			//  4, 5 동일

	//// 요즘은 foo 처럼 사용해도 컴파일러가 알아서 RVO로 최적화 해줌 이를 NRVO(Named...)라고 함
	//// 마이크로소프트에서 NRVO 사용하고 싶으면 /O2 옵션 주면 됨

	cout << endl;

}

