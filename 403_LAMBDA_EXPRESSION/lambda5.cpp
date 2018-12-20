/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <functional>
using namespace std;

int main()
{
	//// 람다 표현식 담는 방법
	//// 1. auto
	auto f1 = [](int a, int b) { return a + b; };

	//// 2. 함수 포인터 타입으로 암시적 변환 -> 원리는 뒤에서 살펴볼꺼임
	int(*f2)(int, int) = 
			  [](int a, int b) { return a + b; };

	//f2 = [](int a, int b) { return a - b; };

	//// 3. stl fucntion
	function<int(int, int)> f3 =
		[](int a, int b) { return a + b; };


	f1(1, 2); // inline 치환 가능.			//// 함수 객체이기 때문에
	f2(1, 2); // inline 치환이 어렵다	//// 다른 함수를 중간에 대입 받을 수도 있는 변수이기 때문에
	f3(1, 2); // inline 치환이 어렵다	//// 애도 다른 함수를 중간에 대입 받을 수 있다

}

