/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <type_traits>
using namespace std;

//// move�� foward�� ����

//// �Լ� ���� : lvalue�� rvalue�� ��� �޾Ƽ�
//// ���� Ÿ�� : rvalue��
template<typename T>
typename remove_reference<T>::type&&
xmove ( T&& obj )
{
	return static_cast< typename remove_reference<T>::type && >( obj );
}


//// �Լ� ���� : lvalue�� �޾Ƽ�
//// ���� Ÿ�� : T�� ���� lvalue �Ǵ� rvalue 
//// �߰����ΰ� �ڿ� ����
template<typename T> T&& xforward(T& arg)
{
	return static_cast<T&&>(arg);
}


int main()
{

}