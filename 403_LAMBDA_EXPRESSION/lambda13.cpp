#include <iostream>
using namespace std;

class Test
{
	int data = 0;		//// <- 접근대상

public:
	void foo() // Test* const this
	{
		int v = 0;

		//auto f = [this]() { this->data = 10; };		//// <- class안에서 람다 쓰면서 멤버 Data에 접근하는법
		//auto f = [this]() { data = 10; };

		// 멤버 데이타를 복사본으로 캡쳐 - C++17
		//// 원본을 훼손하고 싶지 않을 때 쓰겠지?
		auto f = [*this]() mutable { data = 10; };
		f();
		cout << data << endl; // 10
	}
};

int main()
{
	Test t;
	t.foo();
}