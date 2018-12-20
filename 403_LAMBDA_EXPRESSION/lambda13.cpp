#include <iostream>
using namespace std;

class Test
{
	int data = 0;		//// <- ���ٴ��

public:
	void foo() // Test* const this
	{
		int v = 0;

		//auto f = [this]() { this->data = 10; };		//// <- class�ȿ��� ���� ���鼭 ��� Data�� �����ϴ¹�
		//auto f = [this]() { data = 10; };

		// ��� ����Ÿ�� ���纻���� ĸ�� - C++17
		//// ������ �Ѽ��ϰ� ���� ���� �� ������?
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