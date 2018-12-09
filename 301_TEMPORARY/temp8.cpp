#include <iostream>
using namespace std;

//// 임시객체가 생성되는 다양한 경우
struct Base
{
	int v = 10;
};

struct Derived : public Base
{
	int v = 20;
};

int main()
{
	Derived d;
	cout << d.v			 << endl; // 20
	cout << d.Base::v << endl; // 10

	
	//// 아래 두 줄의 차이점은 무엇일까요?
	cout << (static_cast<Base>(d)).v		<< endl; // 1. 10
	cout << (static_cast<Base&>(d)).v  << endl; // 2. 10
	//// 1번의 경우 Base Type의 임시 객체가 만들어지고, d를 통해서 복사 생성자가 불린다.
	//// 값 '캐스팅' : 임시객체 생성!!!!
	//// 2번의 경우 임시객체 안 만들어짐, 그냥 d를 Base로 보겠다

	(static_cast<Base>(d)).v		= 30; // error, 임시객체에 대입하고 있기 때문에 error
	(static_cast<Base&>(d)).v	= 30; // ok
	
}