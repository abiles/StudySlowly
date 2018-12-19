/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <bitset>
using namespace std;

// 0 ~ 9 사이의 '중복되지 않은' 난수를 리턴하는 함수.

// 일반함수 : 동작만 있고 상태가 없기 때문에 아래와 같은 문제가 발생 (여기서 random을 말함)
//// 그럼 어떻게 극복할까? 함수객체

bitset<10> bs;
bitset<10> bs1;	//// 동시에 random이 또 필요하다면?
							//// 3개 필요하다면?
							//// 4개 필요하다면?

void clear_random() { bs.reset(); }

int random()
{
	int v = -1;
	//static bitset<10> bs; // 10개가 0으로 초기화
	//// clear_random을 쓰기 위해서 static으로 놓은걸 전역 변수로 옮긴다.
	do
	{
		v = rand() % 10;
	} while (bs.test(v));

	bs.set(v);	
	return v;
}

int main()
{
	for ( int i = 0; i < 10; i++)
		cout << random() << " "; 
	
	random();	//// 무한루프 될수 있겠죠? 이미 앞에서 10개 썼으니까?
}
