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
	Base b1=	f1 (); //// rvalue	임시객체, move
	Base b2=	f2 (); //// lvalue	참조, copy
	Base b3=	f3 (); //// rvalue	rvalue ref, move

	f1 ().foo ();	//// Base 임시객체가 불렸을 테니 Base::foo	비다형적	, 이름없음
	f2 ().foo ();	//// Derived 참조이니 Derived::foo				다형적		, 이름있음
	f3 ().foo ();	//// rvalue 'REF'이기 때문에 Derived::foo	다형적		, 이름있음
	
	int n=10;
	n=20; // n : lvalue, 20 : prvalue
	int n3=move ( n ); // xvalue

}


