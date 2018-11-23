/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor5.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;
//// 생성자는 메모리에 놓이는 순서대로 만들어짐
//// 1. 기반 클래스 멤버의 생성자( 멤버가 생성자가 필요한 아이라면)
//// 2. 기반 클래스의 생성자
//// 3. 파생 클래스의 멤버의 생성자
//// 4. 파생 클래스의 생성자
//// bm 객체  (base)
//// int x		 (base)
//// dm 객체  (derived)
//// int y         (derived)

struct BM { BM() { cout << "BM()" << endl; } };
struct DM { DM() { cout << "DM()" << endl; } };

struct Base
{
	BM bm;
	int x;
	Base() { cout << "Base()" << endl; }
};

struct Derived : public Base
{
	DM dm;
	int y;
	Derived() : dm(), Base()
	{
		cout << "Derived()" << endl; 
	}
};

int main()
{
	Derived d;
}






