#include <iostream>
using namespace std;

int x=0;
int		f1 () { return x; };
int&		f2 () { return x; };
int&&	f3 () { return move ( x ); };

int main ()
{
	f1 ()=10; //// f1�� �ӽð�ü				error			value return				rvalue (���ʿ� �ü� ���)
	f2 ()=10; //// f2�� ��������				okay			lvalue ref return		lvalue
	f3 ()=10; //// f3�� rvalue ref ����	error			rvalue ref return		rvalue (���ʿ� �ü� ���)
}


