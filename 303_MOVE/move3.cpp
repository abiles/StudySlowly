/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Test
{
	int* resource;
public:
	Test()  {}	// 자원할당
	~Test() {}	// 자원해지
	
	// 복사 생성자 : 깊은복사 또는 참조계수
	// 인자로 lvalue 와 rvalue 를 모두 받을수 있다
	Test(const Test& t) { cout << "Copy" << endl; }

	// Move 생성자 : 소유권 이전(자원 전달)
	// rvalue만 전달 받을수 있다.
	Test(Test&& t)      { cout << "Move" << endl; }
};
Test foo()
{
	Test t;
	return t;
}
int main()
{
	Test t1;
	Test t2 = t1;		// 복사 생성자
	//Test t3 = Test();	// (move 없으면) 복사 생성자.  //move 생성자, 이런 코드는 컴파일러가 바로 t3의 생성자를 부르도록 최적화 해버리는 경우가 있다
	Test t4 = foo();
}