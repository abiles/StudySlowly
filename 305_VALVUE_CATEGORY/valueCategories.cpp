#include <iostream>
using namespace std;

void f1 ( int a ) {}
void f2 ( int& a ) {}
void f3 ( int&& a ) {}

int main ()
{
	int n= 10;

	f1 ( n );
	f2 ( n );
	// f3 ( n ); : error
	f3 ( static_cast< int&& > ( n ) ); // f3(move(n));
}

/*
1. ���� ������ ������ ������ �� ����
2. �Լ� ���� Ÿ���� ������ ���� �����ϴ� ��� �˱�
*/
int x=0;
int f4 () { return x; };
int& f5 () { return x; };
//int&& f6 () { return x; };
int&& f6 () { return move ( x ); };