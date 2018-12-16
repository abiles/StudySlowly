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

//// return에 대한 고려를 해보자

// error
//// why error? why?
//// decltype( f(std::forward<T>(arg)) ) ?? <- f는 선언되는 시점이 F f인데 그 앞에서 쓰고 있으니 error
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
auto chronometry(F f, T&& arg) -> decltype(f(std::forward<T>(arg))) //// 이건 c++11의 후위형 리턴
{
	return f(std::forward<T>(arg));
}
*/

//// C++14부터는 후위형 리턴 없이 컴파일 가능
/*
// 컴파일 ok.. 원본 함수가 참조를 리턴하면 버그..
//// auto는 참조 속성을 제거해버리기 때문에 버그
template<typename F, typename T>
auto chronometry(F f, T&& arg) 
{
	return f(std::forward<T>(arg));
}
*/

// 컴파일 ok.. 원본 함수가 참조를 리턴해도 ok..
//// 참조 속성을 유지하도록 함
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




