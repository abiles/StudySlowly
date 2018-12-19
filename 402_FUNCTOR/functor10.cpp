/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <bitset>
using namespace std;


// 일반함수 : 동작만 있고 상태가 없다.
// 함수객체(functor) : 동작과 상태가 있다.
class Random
{
	bitset<10> bs;		//// 상태

public:
	//// 동작
	Random () { bs.reset (); }// 모든 비트를 0으로

	int operator()()
	{
		int v = -1;
		do
		{
			v = rand() % 10;
		} while (bs.test(v));

		bs.set(v);
		return v;
	}
};


int main()
{
	Random random;
	Random random1;
	for (int i = 0; i < 10; i++)
		cout << random() << " ";
	random();
}


/*
1. 함수 객체
괄호 연산자의 왼쪽에 놓여서 함수처럼 사용할 수 있는 객체

() 연산자를 정의한 클래스
함수포인터, 멤버함수 포인터

2. 일반 함수와 함수 객체의 차이점
- 일반 함수는 자신만의 타입이 없다. 시그니처 동일시 모두 같은 타입
- 함수 객체는 자신만의 타입이 있다. 시그니처 동일해도 모두 다른 타입

3. 함수 객체의 장점
- 다른 함수의 인자로 사용될 때 인라인 치환 가능
- 상태를 가지는 함수를 만들 수 있다
*/