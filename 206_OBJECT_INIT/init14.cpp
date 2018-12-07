/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// aggregate initialization
// aggregate type : {} 로 초기화 가능한 것들을 모아서 부르는 말. 구조체(class 아님), 배열.
struct Point
{
	int x, y;
	
	void foo() {}

//	Point() {}						// 1
//	Point(int a, int b) { }	// 2

//	Point() = default;	//// default를 지정해도 aggregate는 유지됨

//	virtual void foo() {}  //// 가상함수 사용시 더이상 struct라고 볼 수 없음(class니까)
};

int main()
{
	Point p1;				// 1. ok
	Point p2 { 1,2 };	// 2. ???, 주석으로 막은 상태에서도 이게 가능하다 왜일까?, 원래 이게 되는 type임
							
}
