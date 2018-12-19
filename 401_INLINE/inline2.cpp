/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//// 인라인 함수와 함수 포인터
// inline2.cpp
// 1. 인라인 함수 문법은 컴파일 시간 동작한다.
// 2. 인라인 함수라도 '함수포인터'에 담아서 사용하면 '호출'된다.

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 치환
	
	int(*f)(int, int);

	f = &Add2;
	//if (사용자입력이 1 이면)
	//	f = &Add1;	//// f는 변할 수 있음 = 컴파일할 때 알 수 없음

	int n3 = f(1, 2); // 호출 ? 치환 ?	명확하게 알고 싶을 땐 asm으로 만들어서 보면 됨
}

