#include <iostream>
using namespace std;

//// �ӽð�ü�� �����Ǵ� �پ��� ���
struct Base
{
	int v = 10;
};

struct Derived : public Base
{
	int v = 20;
};

int main()
{
	Derived d;
	cout << d.v			 << endl; // 20
	cout << d.Base::v << endl; // 10

	
	//// �Ʒ� �� ���� �������� �����ϱ��?
	cout << (static_cast<Base>(d)).v		<< endl; // 1. 10
	cout << (static_cast<Base&>(d)).v  << endl; // 2. 10
	//// 1���� ��� Base Type�� �ӽ� ��ü�� ���������, d�� ���ؼ� ���� �����ڰ� �Ҹ���.
	//// �� 'ĳ����' : �ӽð�ü ����!!!!
	//// 2���� ��� �ӽð�ü �� �������, �׳� d�� Base�� ���ڴ�

	(static_cast<Base>(d)).v		= 30; // error, �ӽð�ü�� �����ϰ� �ֱ� ������ error
	(static_cast<Base&>(d)).v	= 30; // ok
	
}