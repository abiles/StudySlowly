/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <algorithm>	
#include <iostream>
using namespace std;
//// Functor의 장점

// 라이브러리 설계자들의 고려
// 변하지 않은 전체 흐름속에서
// 변경되어야 하는 부분을 분리한다. (functor 부분)

// qsort() 함수와 유사한 방법

// '일반함수는 자신만의 타입이 없다.'
// signature가 동일하면 모두 같은 타입이다.			//// int xx(int,int) = int yy(int, int)
// so 이런 저런 함수가 다 cmp 자리로 올 수 있다는 뜻
void Sort(int* x, int n, bool(*cmp)(int, int))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//	if (x[i] > x[j])

			if (cmp(x[i], x[j]))		//// 변하는 부분, 함수포인터를 통해서 부르기 때문에 inline 적용 안됨, 그래서 쓰지 말자고? ㄴㄴ
				swap(x[i], x[j]);
		}
	}
}

//// 다른 함수, 같은 타입!
inline bool cmp1(int a, int b) { return a > b; }	//// 오름차순, 여기서 inline 했다고 적용될까? 
inline bool cmp2(int a, int b) { return a < b; }	//// 내림차순

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, cmp2);
}
