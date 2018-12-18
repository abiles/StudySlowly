#include <iostream>
#include <functional>

using namespace std;

/*
std::bind
- 함수 또는 함수 객체의 인자를 고정할 때 사용한다
- 인자의 값을 고정할 때 '값' 방식을 사용한다
- 참조로 인자를 고정하려면 ref()또는 cref()를 사용한다.
*/


void goo ( int& a ) { a=30; }	//// 참조로 인자를 받음



int main ()
{
	int n=0;

	function <void ()> f;

	f=bind ( &goo, n );

	f ();	// goo(n);

	cout << n << endl; // 30 나올까?

/////////////////
	f=bind ( &goo, ref(n) );

	cout << n << endl; // 30 나올까?
}