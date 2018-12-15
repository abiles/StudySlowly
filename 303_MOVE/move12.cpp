/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include "Test.h"
using namespace std;

// lvalue�� �����ϸ� T : lvalue ����.. => const Test&, const ������ const ������
template<typename T>
typename remove_reference<T>::type &&
xmove(T&& obj)  
{
	// const Test&&    remove_ref�� �Ἥ => Test(Test&&)       : move�� error
	//															=> Test(const Test& ) : ��������� ���, �׷��� t1�� Copy�� �����Ҽ� �ְԵ�

	return static_cast<const Test&&>(obj);
	return static_cast<typename remove_reference<T>::type &&>(obj);
}


int main()
{
	const Test t1; //// <- ���, move�� pointer�� �ű�� ����. ������ error�� �� �ȳ��� �ɱ�?
	//// �����ü�� move�� ����� �� ����.
	//// move�� �θ��� Copy�� ȣ��ȴ�.

	//	Test t2 = static_cast<Test&&>(t1); // error //// <- �̷��� �����ٰ� �ϸ� error��, �׷��ٸ� move�� �ٸ�������� ����ȴٴ� ��
	Test t2 = xmove(t1); // move ? copy ? error
					// t1 =  const Test, lvalue

	
}
