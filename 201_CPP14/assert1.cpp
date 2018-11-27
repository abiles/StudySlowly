#include <iostream>
#include <cassert>
using namespace std;

void foo(int age)
{
	assert(age > 0); //// 실행시간에 오류 발생시 실행을 멈춰라
	static_assert(age > 0, "error"); //// 컴파일 시간에 오류가 발생시 컴파일을 멈춰라
	//// 위와 같은 형식으로 해서는 안된다. 변수를 컴파일시간에 확인할 순 없기 때문에
	// ......
}

int main()
{
//	static_assert(sizeof(void*) >= 8,"error. 32bit");
//	static_assert(sizeof(void*) >= 16); // C++17

	foo(-10);
}
