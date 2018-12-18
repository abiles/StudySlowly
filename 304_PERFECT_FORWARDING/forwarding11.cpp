/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//// 이 부분은 다시 만들어보기

#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> T&& xforward(T& arg)
{
	return static_cast<T&&>(arg);
}
/*
//// lvalue버전만 있으면 안된다 rvalue버전도 있어야 한다.
//// static_cast<Type&&>(static_cast<T&&>(arg).get()) 이런게 rvalue를 return하기 때문에
//// 이 버전은 rvalue로 인자, rvalue로 리턴
template<typename T> T&& xforward(typename remove_reference<T>::type && arg)
{
	return static_cast<T&&>(arg);
}
*/

struct Arg
{
	int i = 1;
	int  get() && { cout << "&&" << endl; return i; } // call to this overload is rvalue
	int& get() &  { cout << "&" << endl; return i; }  // call to this overload is lvalue
};
void foo(int&)  { cout << "foo int&" << endl;}
void foo(int&&) { cout << "foo int&&" << endl; }

template<class T>
void wrapper(T&& arg)
{
//	using Type = decltype(xforward<T>(arg).get());
//	foo(xforward<Type>( xforward<T>(arg).get()) );

	using Type = decltype(static_cast<T&&>(arg).get());
	foo(static_cast<Type&&>(static_cast<T&&>(arg).get()) );
	//// 이렇게 복잡한 이유. 
	//// arg.get()이최종적으로 fowarding하고 싶은 내용이다
	//// static_cast<T&&>(arg)는 받은 인자만 캐스팅한거지

}

int main()
{
	wrapper(Arg());

	Arg a;
	wrapper(a);
}