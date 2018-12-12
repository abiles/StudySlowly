/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//// 1. 
template<typename T> void foo(T&& a) {}

//// 2.
//// 1과 2는 경우가 다르다는것을 확인하자
template<typename T> class Test
{
public:
	void goo(T&& a) {} // forwarding reference 아님.., 와 이거 되게 헷갈리겠네

	template<typename U> void hoo(U&& a) {} // forwarding reference 맞음.
};

int main()
{
	int n = 10;
	
	foo(n);	// ok
	foo(10);// ok

	Test<int> t1; // T가 int로 결정.  void goo(int&& a)
	t1.goo(n);	// error, 이미 T의 타입이 결정되어 있으므로 자유도가 없고 그래서 forward ref 기능이 안된다.
	t1.goo(10); // ok

	Test<int&> t2; // T int& => void goo( int& && a) => void goo(int& )
	t2.goo(n); // ok
	t2.goo(10); // error
}