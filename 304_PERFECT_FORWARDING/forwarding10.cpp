/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;
/*
static_cast<T&&>(arg); T의 타입에 따라 rvalue 또는 lvalue 캐스팅
*/

void goo(int& a)  { cout << "goo" << endl; }
void hoo(int&& a) { cout << "hoo" << endl; }


template<typename T> T&& xforward(T& arg)
{
	return static_cast<T&&>(arg);
}

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	//f(static_cast<T&&>(arg));

	//// 그냥 foward() 이걸로 보내면 안돼, 꼭 <T> 포함해야됨, T 없으면 컴파일러가 알아서 추론함
	//// 그러면 원하는 방식으로 추론안됨, 그림 참조
	f(forward<T&&>(static_cast<int&&>(arg))); 

	// lvalue 일때 T : int& => int&
	// rvalue 일때 T : int  => int&&
	//f(xforward(arg));
}

int main()
{
	int n = 0;

//	chronometry(&goo, n);
	chronometry(&hoo, 10);

	cout << n << endl;
}




