/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

//// operator new는 new와 다르게 재정의 할 수 있다.

void* operator new(size_t sz)
{
	cout << "my new" << endl;
	return malloc(sz);
}

void* operator new(size_t sz, const char* s, int n) //// 함수 오버로딩, 첫번째 인자는 반드시 size_t
{
	cout << "my new2" << endl;
	return malloc(sz);
}

void operator delete(void* p) noexcept  //// 예외가 없다. 예외가 없다는건 뭐지?
{
	cout << "my delete" << endl;
	free(p);
}

int main()
{
	//Point* p = new Point; // operator new( sizeof(Point))	
	Point* p = new("AA", 2) Point; // operator new( sizeof(Point), "AA", 2)	//// new를 이렇게 쓸수도 있구나, 오픈소스에서 이렇게 사용하는게 많음
	delete p;
}








