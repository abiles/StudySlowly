#include <iostream>
using namespace std;
/*
// c++98
int foo()  // 예외가 있을수도 있고, 없을수도 있다. //// 이런 의미와 이런 문법이 있었군
int foo() throw(int) // 예외가 있다는 의미.
int foo() throw()    // 예외가 없다는 의미.
{
	throw 1;
	return 0;
}
*/
// C++11
//void goo() noexcept(true) // 예외가 없다.
//void goo() noexcept(false) // 예외가 있다.
void goo() noexcept // 예외가 없다와 동일
{
	throw 1;
}

void goo() 
{
	throw 1;
}

//// throw가 있는 함수에 대해서 try catch를 안하면 throw 발생시 abort로 프로그램 죽음
//// noexcept 라고 했는데 throw가 발생하면 abort로 프로그램 죽음(try catch로 감싸더라도 죽음)
//// noexcept로 했으면 thorw 하지마라

//// 예외가 있는지 없는지 표기하면 이점이 뭐가 있을가?
//// 컴파일러가 최적화 할 때 예외가 없다는 것을 명백히 표현하면 조금 더 좋은 코드를 만들 수 있음
int main()
{
	goo();

	try
	{
		goo();
	}
	catch (...)
	{
		cout << "exception..." << endl;
	}
}




