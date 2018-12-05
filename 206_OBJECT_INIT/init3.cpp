/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

struct Point
{
	int x, y;
};

class Complex
{
	int re, im;
public:
	Complex(int r, int i) : re(r), im(i) {}
};

int main()
{
//	int n = 0;
//	int x[2] = { 1,2 };
//	Point p = { 1,2 };
//	Complex c(1, 2);

	//// 일관되게 하나의 방법으로 초기화 할 수 있도록 한거지
	//// 일관된 초기화 (Uniform initialize, brace init)
	/*
	int  n{ 0 };
	int  x[2]{ 1,2 };
	Point   p{ 1,2 };
	Complex c{ 1, 2 };
	*/

	int  n = { 0 };
	int  x[2] = { 1,2 };
	Point   p = { 1,2 };
	Complex c = { 1, 2 };


	int n2 = 3.4; // ok
	//int n3 = { 3.4 }; // error. //// 데이터 손실이 발생시 error발생, prevent narrow

	//char c1{ 300 }; // error
	char c2{ 100 }; // ok

}