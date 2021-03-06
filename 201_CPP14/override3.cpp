#include <iostream>
using namespace std;

template<typename T> class Base
{
public:
	virtual void foo(const T a)
	{
		cout << "Base foo" << endl;
	}
};

/*
class Base<int*>
{
public:
virtual void foo(const int* a)
{
cout << "Base foo" << endl;
}
}
*/
class Derived : public Base<int*>
{
public:
	// 가상 함수 foo를 재정의해서
	// "Derived foo" 라고 출력해 보세요.
	// override 사용하지 말고.
	virtual void foo ( const int* a )
	{
		cout << "Derived foo" << endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);	// "Derived foo"
}




