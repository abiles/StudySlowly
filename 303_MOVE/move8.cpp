/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <type_traits>
#include "Test.h"		// class Test {}
using namespace std;

int main()
{
	//// move에서 중간에 예외가 나오면 안됨
	//// move Exception 그림 참조
	//// 이미 배열 앞에껄 move한 상태에서 Exception가 나면 다시 복구할 수 없다
	//// 복구 할 때 exception 나지 말라는 법이 없기 때문에

	/*
	Test* p1 = new Test[2];
	Test* p2 = new Test[4];

	for (int i = 0; i < 2; i++)
		p2[i] = move( p1[i] );
	*/


	Test t1;
	Test t2 = t1; // copy
	Test t3 = move(t2); // move
	 
	bool b = is_nothrow_move_constructible<Test>::value; //// Move 생성자가 예외가 있는지 확인
	cout << b << endl;

	Test t4 = move_if_noexcept(t1); //// 예외 없을 때만 move, 있으면 Copy




}


















