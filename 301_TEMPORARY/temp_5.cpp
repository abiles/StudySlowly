#include <iostream>
using namespace std;

class Test
{
public:
	int data;

	////// C++11에 새로 추가된 문법
	void foo() &		{ cout << "foo &" << endl; }			// lvalue 객체에 대해서만 호출.
	void foo() &&	{ cout << "foo &&" << endl; }		// rvalue 객체에 대해서만 호출.

	int& goo() & { return data; }
};

int main()
{
	Test t;
	t.foo();				//// lvalue 버전 부름
	Test ().foo ();	//// rvalue 버전 부름

	int& ret = t.goo();

	int& ret2 = Test().goo(); // error

	

}