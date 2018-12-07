/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b)           { cout << "int, int" << endl; }						// 1
	Point(initializer_list<int> ) { cout << "initializer_list<int>" << endl; }	// 2
};

int main()
{
	// Point p1(1, 1);	// 1번, 없다면 error
		
	//Point p2( { 1, 1 } );   // 2번. 2번을 주석으로 처리해도 error 안남 
										// 왜냐? {1,1} 변환생성자를 사용해서 임시객체생성. 복사생성자를 사용해서 p2복사
										// 없으면 error지만, explicit 가 아닐경우. 변환 생성(int, int ) .

	//// 핵심, 왜 핵심일까? 중괄호 초기화로 initilaizer_list가 먼저 불린다는 것을 알아야 함
	//Point p3{ 1,1 }; // 2. 없으면 1번 

	//Point p4 = { 1,1 }; // 2. 없으면 1번.
	
	//Point p5(1, 2, 3); // error
	
	//Point p6{ 1,2,3 }; // 2번.
	
	Point p7 = { 1,2,3 };

	vector<int> v = { 1,2,3,4 };
	
}
