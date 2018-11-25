/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <string>
#include <memory>
using namespace std;

class String16
{
public:
	explicit		String16 ( const char* o );
};

void foo(String16 s)  // String16 s = "hello"  
//// String16에서 const char* 를 받는 변환 생성자가 explicit이기 때문에 그냥 "hello"를 받을 수 없음
{}

int main()
{
	//foo("hello"); // error
	foo(String16("hello")); // ok..

	String16 s = "hello"; // error

	// STL 의 string 클래스는 생성자가 explicit 가 아님.
	string s1("hello");		// ok    
	string s2 = "hello";		// ok		//// 왜 둘다 허용했을까? 불편하니까


	shared_ptr<int> p1 = new int;	// error  생성자가 explicit 키워드 가지고 있음 //// copy initialization 막아둠
	shared_ptr<int> p2(new int);		// ok.. //// direct initialization  가능 //// 왜 막아두었을까? 불편해도 문제 생기는 걸 방지하고 싶었겠지

}