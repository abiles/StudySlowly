#include <iostream>
#include <functional>

using namespace std;

/*
std::bind
- �Լ� �Ǵ� �Լ� ��ü�� ���ڸ� ������ �� ����Ѵ�
- ������ ���� ������ �� '��' ����� ����Ѵ�
- ������ ���ڸ� �����Ϸ��� ref()�Ǵ� cref()�� ����Ѵ�.
*/


void goo ( int& a ) { a=30; }	//// ������ ���ڸ� ����



int main ()
{
	int n=0;

	function <void ()> f;

	f=bind ( &goo, n );

	f ();	// goo(n);

	cout << n << endl; // 30 ���ñ�?

/////////////////
	f=bind ( &goo, ref(n) );

	cout << n << endl; // 30 ���ñ�?
}