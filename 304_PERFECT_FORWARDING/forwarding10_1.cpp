/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <type_traits>
using namespace std;

//// move와 foward의 차이

//// 함수 인자 : lvalue와 rvalue를 모두 받아서
//// 리턴 타임 : rvalue로
template<typename T>
typename remove_reference<T>::type&&
xmove ( T&& obj )
{
	return static_cast< typename remove_reference<T>::type && >( obj );
}


//// 함수 인자 : lvalue를 받아서
//// 리턴 타임 : T에 따라서 lvalue 또는 rvalue 
//// 추가적인건 뒤에 있음
template<typename T> T&& xforward(T& arg)
{
	return static_cast<T&&>(arg);
}


int main()
{

}