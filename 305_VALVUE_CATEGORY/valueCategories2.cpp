#include <iostream>
using namespace std;

struct Base
{
	virtual void foo () { cout << "B::foo" << endl; }
};
struct Derived : public Base
{
	virtual void foo () { cout << "D::foo" << endl; }
};

Derived d;
Base			f1 () { return d;  }
Base&		f2 () { return d; }
Base&&	f3 () { return move(d); }


int main ()
{
	Base b1=	f1 (); //// rvalue	�ӽð�ü, move
	Base b2=	f2 (); //// lvalue	����, copy
	Base b3=	f3 (); //// rvalue	rvalue ref, move

	f1 ().foo ();	//// Base �ӽð�ü�� �ҷ��� �״� Base::foo	�������	, �̸�����
	f2 ().foo ();	//// Derived �����̴� Derived::foo				������		, �̸�����
	f3 ().foo ();	//// rvalue 'REF'�̱� ������ Derived::foo	������		, �̸�����
	
	int n=10;
	n=20; // n : lvalue, 20 : prvalue
	int n3=move ( n ); // xvalue

}


