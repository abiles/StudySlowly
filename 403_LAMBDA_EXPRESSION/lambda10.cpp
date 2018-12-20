#include <iostream>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0;

	//// ĸ�ĵ� ������������ �����Ϸ��� �߱� ������
	//auto f1 = [v1, v2]() { v1 = 10; v2 = 20;};// error 
	
	// mutable lambda : () ������ �Լ��� ���� �Լ��� 
	//// �ڵ����� const ���ִ� �κ��� ���ٴ� ���
	//// operator()() const -> operator()()
	auto f1 = [v1, v2]() mutable { v1 = 10; v2 = 20; };

	f1(); // ���� ǥ���� ����..

	cout << v1 << endl; // 0	//// ���ٿ��� ���纻�� �����߱� ������ ������ �ٲ�� ����.
	cout << v2 << endl; // 0

}