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
1. 지역 변수는 참조로 리턴할 수 없다
2. 함수 리턴 타입의 종류에 따라서 리턴하는 방법 알기
*/
int x=0;
int f4 () { return x; };
int& f5 () { return x; };
//int&& f6 () { return x; };
int&& f6 () { return move ( x ); };