#include <iostream>
#include <type_traits>
using namespace std;

//// 기존에 사용하던 enum은 unscoped enum
//// 단점 
/*
1. 타입의 이름 없이 사용 가능
2. 요소의 타입을 지정할 수 없다
*/
enum Color { red = 1, green = 2 };

//// Scoped Enum에서는 red의 타입을 정해줄 수 있겠죠?
//// enum2 확인

int main()
{
	int n1 = Color::red;
	int n2 = red;
	int red = 0;
	int n3 = red;

	cout << typeid(underlying_type_t<Color>).name() << endl;
	//// enum 요소의 type을 알아 내는 방법

}
