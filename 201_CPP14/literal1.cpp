#include <iostream>
using namespace std;

// _ : 사용자 사용가능.
// _로 시작하지 않은것 : reserved(미래에 C++ 표준으로 사용할 수 있기 때문에)

//// int는 unsigned long long 혹은 const char*로 받는 것이 user define literal의 규칙이기 때문에 지키자
//// 그외에도 literal 마다 규칙이 있음

int operator""_k(unsigned long long v)
{
	return v * 1000;
}

int main()
{
	int n1 = 10_k; // operator""k(10)

	cout << n1 << endl; // 10000
}


