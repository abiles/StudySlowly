/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include "Test.h"
using namespace std;

// lvalue를 전달하면 T : lvalue 참조.. => const Test&, const 참조는 const 유지됨
template<typename T>
typename remove_reference<T>::type &&
xmove(T&& obj)  
{
	// const Test&&    remove_ref를 써서 => Test(Test&&)       : move는 error
	//															=> Test(const Test& ) : 복사생성자 모양, 그래서 t1을 Copy로 전달할수 있게됨

	return static_cast<const Test&&>(obj);
	return static_cast<typename remove_reference<T>::type &&>(obj);
}


int main()
{
	const Test t1; //// <- 상수, move후 pointer를 옮길수 없다. 하지만 error는 왜 안나는 걸까?
	//// 상수객체는 move를 사용할 수 없다.
	//// move를 부르면 Copy가 호출된다.

	//	Test t2 = static_cast<Test&&>(t1); // error //// <- 이렇게 적었다고 하면 error다, 그렇다면 move가 다른방식으로 적용된다는 뜻
	Test t2 = xmove(t1); // move ? copy ? error
					// t1 =  const Test, lvalue

	
}
