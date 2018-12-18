#include <iostream>
#include <functional>

using namespace std;

/*
1. std::fuction
- �Լ� ������ ������ �ϴ� ���ø�
- �Ϲ� �Լ� �Ӹ� �ƴ϶� ��ü, ���� ǥ���ĵ� ���� �� �ִ�
- bind�� ���Բ� ����ϸ� ������ ������ �ٸ� �Լ�(�Լ���ü) �� ����� �� �ִ�.
*/

void foo () {}
void goo ( int a ) {}

int main ()
{
	void ( *f )()=&foo;
	// f = &goo; // error

	function<void ()> f2=&foo;

	f2 (); // foo;

	f2=bind ( &goo, 5 );

	f2 (); // goo(5);
}