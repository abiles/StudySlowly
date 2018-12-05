/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//// 기존 초기화 구문의 문제점

int main()
{
	// 1. 
	//// 객체(변수)의 종류에 따라 초기화 방법이 다르다
	int n1 = 0;
	int n2(0);
	int ar[3] = { 1,2,3 };
	Point p = { 1,2 };		// 구조체
	complex c(1, 2);		// 클래스

	// 2.
	//// 클래스의 멤버로 있는 배열을 초기화 할 수 없다
	class Test
	{
		int x[10];
	};

	// 3. 
	//// 동적 메모리 할당으로 만들어진 배열을 초기화 할 수 없다
	int* p = new int[3];

	// 4.
	//// STL의 컨테이너를 초기화하는 편리한 방법이 없다
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(1);
}






