/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;
/*
static_cast<T&&>(arg); T�� Ÿ�Կ� ���� rvalue �Ǵ� lvalue ĳ����
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

	//// �׳� foward() �̰ɷ� ������ �ȵ�, �� <T> �����ؾߵ�, T ������ �����Ϸ��� �˾Ƽ� �߷���
	//// �׷��� ���ϴ� ������� �߷оȵ�, �׸� ����
	f(forward<T&&>(static_cast<int&&>(arg))); 

	// lvalue �϶� T : int& => int&
	// rvalue �϶� T : int  => int&&
	//f(xforward(arg));
}

int main()
{
	int n = 0;

//	chronometry(&goo, n);
	chronometry(&hoo, 10);

	cout << n << endl;
}




