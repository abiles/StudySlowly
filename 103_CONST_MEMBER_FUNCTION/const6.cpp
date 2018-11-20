/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;


//// mutable을 사용하지 않고 상수 멤버함수에서 바꾸기
//// 일반적으로 변하는 것과 변하지 않는 것은 분리하는 것이 좋다
//// 메모리적으로 생각해보면 const는 해당 Class의 메모리를 잠그는 것
//// 따라서 포인터 자체는 못바꾸지만 포인터가 가리키는 것은 바꿀 수 있다
//// 그래서 변하는 것 담당을 포인터로 만들어 놓고 const에서 그 안에 있는 값을 바꾸는 테크닉으로 문제 해결!

//// 변하는 것 담당
struct Cache
{
	char cache[16];
	bool cache_valid = false;
};

class Point
{
	int x, y;
	Cache* pCache;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		pCache = new Cache;
	}

	const char* toString() const
	{
		if (pCache->cache_valid == false)
		{
			sprintf(pCache->cache, "%d, %d", x, y);
			pCache->cache_valid = true;
		}
		return pCache->cache;
	}
	~Point() { delete pCache; }
};

int main()
{
	Point p1(1, 1);

	cout << p1.toString() << endl;
	cout << p1.toString() << endl;

}
