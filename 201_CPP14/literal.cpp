#include <iostream>
using namespace std;

//// literal이 무엇이냐
/*
integer literal					11, 013, 0xa
floating point literal		15.75
character literal				"A"
string literal						"hello"
*/

/

int operator""_k(unsigned long long v)
{
	return 1000 * v;
}

int main()
{
	int n1 = 10; // meter
	int n2 = 10_k;// 10000  operator""k(10)

	cout << n2 << endl; /// 10000
}