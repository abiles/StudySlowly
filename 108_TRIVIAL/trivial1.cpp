#include <iostream>
#include <type_traits>
using namespace std;
//// Trivial : 사소한, 하찮은, C++에서는 하는 일이 없다

//// Trivial default Constructor : 기본 생성자가 하는 일이 없는 경우

class A
{
public:
	A ()=default; //// 이렇게 명시적으로 지정하면 Trivial 하다고 판단, default 함수는 컴파일러가 생성하기 때문에
	//// A(); //// 이렇게만 하면 is_trivially_constructible가 판단할 때 선언부만 보고 판단하기 때문에 구현부가 어떻게 되어 있을지 몰라서  Trivial하지 않다고 판단
	//// A() {} 이것도 안됨
	
	virtual void foo() {}
	//// 가상함수가 class에 있으면 가상함수 테이블 초기화 때문에 trivial하지 않다

};

int main()
{
	//// 생성자가 trivial한지 확인하는 함수 
	//// 선언만 보고 확인함
	cout << is_trivially_constructible<A>::value << endl;
}

