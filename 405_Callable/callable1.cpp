#include <iostream>
#include <functional>
using namespace std;

void foo()
{

}

//// function Object
/*
괄호의 왼쪽에 올 수 있는 '객체'
- 모든 종류의 함수 포인터
- () 연산자를 재정의한 클래스
- Lambda

- 함수와 함수를 가리키는 참조는 Function Object가 아니다.
*/

int main()
{
	void(&r)() = foo;		//// <- 함수객체 아님
	r();							//// <- 함수객체 아님
	foo();						//// <- 함수객체 아님

	less<int> f;
	f(1, 2);

	[](int a, int b) { return  a + b; }(1, 2);



	
}

