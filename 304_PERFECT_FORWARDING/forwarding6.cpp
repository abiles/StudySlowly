/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int x = 10;
int& foo(int  a) { return x; }

//// return�� ���� ����� �غ���

// error
//// why error? why?
//// decltype( f(std::forward<T>(arg)) ) ?? <- f�� ����Ǵ� ������ F f�ε� �� �տ��� ���� ������ error
/*
template<typename F, typename T>
decltype( f(std::forward<T>(arg)) ) chronometry(F f, T&& arg)
{
	return f( std::forward<T>(arg) ); 
}
*/

// ok.
/*
template<typename F, typename T>
auto chronometry(F f, T&& arg) -> decltype(f(std::forward<T>(arg))) //// �̰� c++11�� ������ ����
{
	return f(std::forward<T>(arg));
}
*/

//// C++14���ʹ� ������ ���� ���� ������ ����
/*
// ������ ok.. ���� �Լ��� ������ �����ϸ� ����..
//// auto�� ���� �Ӽ��� �����ع����� ������ ����
template<typename F, typename T>
auto chronometry(F f, T&& arg) 
{
	return f(std::forward<T>(arg));
}
*/

// ������ ok.. ���� �Լ��� ������ �����ص� ok..
//// ���� �Ӽ��� �����ϵ��� ��
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg)
{
	return f(std::forward<T>(arg));
}

int main()
{
	int& ret = chronometry(&foo, 10);
	ret = 20;
	cout << x << endl;
}




