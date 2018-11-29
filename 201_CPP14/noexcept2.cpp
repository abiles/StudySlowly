#include <iostream>
using namespace std;

void algo1()
{
	// 빠르지만 예외 가능성이 있다.
}

void algo2() noexcept  // 지정자
{
	// 느리지만 예외가 나오지 않는다.
}

class Test
{
public:
	Test() noexcept {}
};

//// noexcept
/*
noexcept specifier - 지정자 void algo2() "noexcept"
noexcept operator - 연산자 "noexcept"(algo1());
*/

int main()
{
	bool b1 = noexcept(algo1()); // 0. 연산자, 컴파일 타임 확인, statc_assert에 넣어서 사용 가능
	bool b2 = noexcept(algo2()); // 1

	cout << b1 << ", " << b2 << endl;

	bool b3 = is_nothrow_constructible<Test>::value; //// 생성자에서 noexcept 붙어 있는지 확인하는 문법(type_traits 사용), 컴파일 타임 확인
	cout << b3 << endl;

}




