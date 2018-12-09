/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : temp1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

int main()
{
	int a = 1, b = 2, c = 3;

	int sum = a + b + c;	
	//// 아래 순서로 작업이 이루어짐
	// int temp = a + b;				//// 여기서 temp는 내가 만든게 아니고 컴파일러에 의해서 만들어지는 임시 메모리 공간(메모리 혹은 레지스터) = 기존 임시객체 정의
	// int sum  = temp + c;
}

