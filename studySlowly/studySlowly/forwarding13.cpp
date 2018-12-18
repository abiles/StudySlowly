#include <iostream>
#include <functional>

using namespace std;

/*
1. std::fuction
- 함수 포인터 역할을 하는 템플릿
- 일반 함수 뿐만 아니라 객체, 람다 표현식도 담을 수 있다
- bind오 ㅏ함께 사용하면 인자의 개수가 다른 함수(함수객체) 도 사용할 수 있다.
*/

void foo () {}
void goo ( int a ) {}

int main ()
{
	void ( *f )()=&foo;
	// f = &goo; // error

	function<void ()> f2=&foo;

	f2 (); // foo;

	f2=bind ( &goo, 5 );

	f2 (); // goo(5);
}