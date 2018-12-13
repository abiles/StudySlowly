/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Cat() { delete[] name; }

	// 깊은 복사로 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	// 소유권 이전(자원전달)의  이동(move) 생성자
	//// name에 주소 복사후 기존 객체는 자원 푁 
	//// 임시객체에만 작동하도록 rvalue ref만 받을 수 있게 함
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = 0; // 자원 포기
	}
};

Cat foo()	// 값리턴 : 임시객체(rvalue)
{
	Cat cat("NABI", 2);
	return cat;	
}

int main()
{
	Cat c = foo(); // 임시객체. 이번 라인 끝에서 파괴될 예정, 자원도 사라질 예정
	//// 굳이 자원을 깊은 복사로 할 필요가 있을까?
	//// 이미 할당된 애를 주는게 낫지 않을까?라는 생각에서 move

}

