/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <functional>
using namespace std;


//void foo( int (*f)(int, int) )				//// �ζ���ġȯ �ȵ�
//void foo(function<int(int, int)> f)	//// �ζ���ġȯ �ȵ�

//void foo(auto f) // auto�� �Լ� ���ڰ� �ɼ� ����.
							 // error

//template<typename T> void foo( T f )
//template<typename T> void foo(T& f)		//// �ӽð�ü �޾ƾ� �ϴϱ� �׳� T&�δ� �ȵ�
template<typename T> void foo(const T& f)
{
	f(1, 2);
}

int main()
{
	foo( [](int a, int b) { return a + b; } );
	foo( [](int a, int b) { return a - b; });

}

