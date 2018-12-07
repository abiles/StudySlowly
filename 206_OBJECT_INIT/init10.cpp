/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <initializer_list>
using namespace std;

//// Initializer_list
/*
1. brace-init-list로 초기화된 요소의 시작과 끝(혹은 개수)를 가리키는 클래스
2. 반복자는 상수를 가리킨다
*/

int main()
{
	// brace-init-'list'
	// VC++ : int* first, *last, 처음 주소, 마지막 주소
	// g++  : int* first, count, 처음주소, 개수
	initializer_list<int> s = { 1, 2, 3, 4, 5 };

	auto p = begin(s); // 상수를 가리키는 반복자
	//*p = 20; // error

	cout << *p << endl;

}