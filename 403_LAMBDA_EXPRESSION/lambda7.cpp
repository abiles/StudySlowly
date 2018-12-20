/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
											//// '->' 후위형 리턴
	auto f2 = [](int a, int b) -> int { return a + b; };

	auto f3 = [](int a, int b){ 
						if (a == 1)
							return a;
						else
							return b;
						};

	//// 컴파일러가 return Type을 예측하기 어려운경우, 사용자가 지정해줘야함
	//// -> double이라고 명시적으로 해줌
	auto f4 = [](int a, double b) -> double {
						if (a == 1)
							return a;
						else
							return b;
					};

}