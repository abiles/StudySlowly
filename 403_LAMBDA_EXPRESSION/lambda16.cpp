#include <iostream>
using namespace std;

int main()
{
	auto f1 = [](int a, int b) { return a + b; };	

	decltype(f1) f2; // error, 컴퓨터가 만들어주는 ClosurType에는 defalut 생성자가 없어서 이게 안됨

	decltype(f1) f3 = f1; // ok.

	decltype(f1) f4 = move(f1); // ok

	
}