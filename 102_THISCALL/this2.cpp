/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// this2.cpp - this 와 멤버 함수 포인터

// 핵심 1. 일반 함수 포인터에 멤버함수의 주소를 담을수 없다. [ 멤버 함수는 this를 포함하고 있기 때문에]
// 핵심 2. 일반 함수 포인터에 static 멤버함수의 주소를 담을수 있다. [static은 this를 포함하고 있지 않기 때문에]
// 핵심 3. 멤버 함수 포인터 모양과 사용법. ( .*), (p.*f3)(),   (p->*f3)() [코드 볼 때 이정도는 알아야 한다]

class Dialog
{
public:
	void Close() {}
};

void foo() {}

int main()
{
	void(*f1)() = &foo;
	f1();

//	void(*f2)() = &Dialog::Close; // error. this 가 추가되는 함수.

	void(Dialog::*f3)() = &Dialog::Close; // ok.. 멤버 함수 포인터. [일반 함수 포인터 + 클래스name::]
	
	//f3(); // error. 객체(this)가 없다. [Close함수는 this가 있다는 것을 잊지 말것]

	Dialog dlg;
	//dlg.f3(); // dlg.Close()를 하고 싶었다. 하지만..f3이라는 멤버를 찾게된다.- error
	//dlg.*f3(); // ".*" : pointer to member operator <- (.*) 를  하나의 연산자로 취급
				// error. 연산자 우선순위 문제..

	(dlg.*f3)(); // ok.. dlg.Close();
	
}