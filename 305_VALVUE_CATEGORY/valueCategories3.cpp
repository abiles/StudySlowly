#include <iostream>
using namespace std;

int x=0;
int		f1 () { return x; };
int&		f2 () { return x; };
int&&	f3 () { return move ( x ); };

int main ()
{
	f1 ()=10; //// f1은 임시객체				error			value return				rvalue (왼쪽에 올수 없어서)
	f2 ()=10; //// f2는 참조리턴				okay			lvalue ref return		lvalue
	f3 ()=10; //// f3는 rvalue ref 리턴	error			rvalue ref return		rvalue (왼쪽에 올수 없어서)
}


