/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int n)   { cout << "int" << endl; }			// 1
void foo(void* p) { cout << "void*" << endl; }	// 2

void foo2(char* p) { cout << "foo2" << endl; }	// 3

int main()
{
	foo(0);				// 정수니까 1번으로 감
	foo((void*)0);	// 정확하게 2번으로 가게 하는법

//// 왜 이걸 나눠 놨을까요?
#ifdef __cplusplus
	#define NULL	0
#else
	#define NULL (void*)0
#endif
	
	foo2 ( NULL );	// void* => char* 로의 암시적 변환 필요.
							// C   : ok
							// C++ : 암시적 변환 안됨. 타입에 대해서 더 엄격하게 다루기 때문에. void*에서 char*로의 암시적 변환 안됨
							//// 따라서 C와 C++을 구별해서 NULL을 define 해줘야 됨


	foo(NULL);		//// C++에서 2번을 부르고 싶은데 현재로서는 1번이 불린다
							//// 따라서 point 0 이라는게 필요해서 만든게 nullptr


}



















