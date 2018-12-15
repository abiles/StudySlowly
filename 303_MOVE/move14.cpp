/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <string>
#include "Test.h"
using namespace std;

class Buffer
{
	size_t sz;
//	int*   buf;
	//// 포인터도 스마트포인터로 만들었다면 .....
	////  Copy도 Move 생성자 없으면 컴파일러가 둘다 만들어주기 때문에 신경쓸게 없다
	string tag;
	Test   test;
public:
	Buffer(size_t s, string t)
		: sz(s), tag(t) {}
	
	//// Copy도 Move 생성자 없으면 컴파일러가 둘다 만들어줌
	//// Copy 있고 Move 생성자 없다면 컴파일러가 Move는 안만들어줌, 그냥 Move 호출해도 Copy를 쓰게함


	// 사용자가 만들지 않으면 컴파일러가 아래 모양제공.
	// 얕은복사..
	Buffer(const Buffer& b) : sz(b.sz), tag(b.tag), test(b.test)
	{
	}
	
	
	/*
	// move 생성자 : 모든 멤버를 move 로 옮기도록 작성한다.
	Buffer(Buffer&& b) noexcept
		: sz(move(b.sz)), tag(move(b.tag)), test(move(b.test))
	{
	}
	*/

	//// 숙제
	// 대입연산자.
	// move 대입연산자.
};

int main()
{
	Buffer b1(1024, "SHARED");
	Buffer b2 = b1; // copy
	Buffer b3 = move(b1); // move
}