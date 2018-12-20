#include <iostream>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0;

	// capture
	//// Closer Class 안에 int v1, int v2 멤버 변수를 생성함
	//// sizeof(f0)를 통해서 확인할 수 있음

	auto f0 = []()       { return 0; };
	auto f1 = [v1, v2]() { return v1 + v2; };

	cout << sizeof(f0) << endl; // 1, c++에서 empty class는 크기가 1
	cout << sizeof(f1) << endl; // 8

}