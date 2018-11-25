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
//// String16���� const char* �� �޴� ��ȯ �����ڰ� explicit�̱� ������ �׳� "hello"�� ���� �� ����
{}

int main()
{
	//foo("hello"); // error
	foo(String16("hello")); // ok..

	String16 s = "hello"; // error

	// STL �� string Ŭ������ �����ڰ� explicit �� �ƴ�.
	string s1("hello");		// ok    
	string s2 = "hello";		// ok		//// �� �Ѵ� ���������? �����ϴϱ�


	shared_ptr<int> p1 = new int;	// error  �����ڰ� explicit Ű���� ������ ���� //// copy initialization ���Ƶ�
	shared_ptr<int> p2(new int);		// ok.. //// direct initialization  ���� //// �� ���Ƶξ�����? �����ص� ���� ����� �� �����ϰ� �;�����

}