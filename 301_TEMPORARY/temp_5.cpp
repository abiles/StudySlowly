#include <iostream>
using namespace std;

class Test
{
public:
	int data;

	////// C++11�� ���� �߰��� ����
	void foo() &		{ cout << "foo &" << endl; }			// lvalue ��ü�� ���ؼ��� ȣ��.
	void foo() &&	{ cout << "foo &&" << endl; }		// rvalue ��ü�� ���ؼ��� ȣ��.

	int& goo() & { return data; }
};

int main()
{
	Test t;
	t.foo();				//// lvalue ���� �θ�
	Test ().foo ();	//// rvalue ���� �θ�

	int& ret = t.goo();

	int& ret2 = Test().goo(); // error

	

}