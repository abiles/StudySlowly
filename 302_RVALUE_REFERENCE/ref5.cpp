/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

void f1(int&  a) {}	// lvalue �� ���ڷ� ���� ����. f1(n) : ok      f1(10) : error
void f2(int&& a) {}	// rvalue �� ���ڷ� ���� ����. f2(n) : error  f2(10) : ok


template<typename T> void f3(T& a) {} // T : int&   T& : int& &, ref collapse ��Ģ�� �����ؾ� �Ѵٴ°� �˾ƶ�!
// ��� Ÿ���� lvalue �� ���� ����.
//// T�� ��� �ٲ۴ٰ��ص� rvalue ���� �� �ְھ��?


int main()
{
	int n = 10;

	// T�� Ÿ���� ����ڰ� ������ ��� <> ���
	f3<int>(n );			// f3( int & a)  => lvalue ���� ����.
	f3<int&>(n );		// f3( int& & a) => f3( int& a) => lvalue ���� ����.
	f3<int&&>(n );		// f3( int&& & a)=> f3( int& a) => lvalue ���� ����.

	// ����ڰ� T Ÿ���� �������� ���� ���
	f3(10);		// 10�� ���� ���� �� �ֵ��� T�� �����غ���! -> T�� ���� �ٲ㵵 rvalue�� ���� �� ����. �׷��� error
	f3(n);		// T : int.  ok.
}