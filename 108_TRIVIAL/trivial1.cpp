#include <iostream>
#include <type_traits>
using namespace std;
//// Trivial : �����, ������, C++������ �ϴ� ���� ����

//// Trivial default Constructor : �⺻ �����ڰ� �ϴ� ���� ���� ���

class A
{
public:
	A ()=default; //// �̷��� ��������� �����ϸ� Trivial �ϴٰ� �Ǵ�, default �Լ��� �����Ϸ��� �����ϱ� ������
	//// A(); //// �̷��Ը� �ϸ� is_trivially_constructible�� �Ǵ��� �� ����θ� ���� �Ǵ��ϱ� ������ �����ΰ� ��� �Ǿ� ������ ����  Trivial���� �ʴٰ� �Ǵ�
	//// A() {} �̰͵� �ȵ�
	
	virtual void foo() {}
	//// �����Լ��� class�� ������ �����Լ� ���̺� �ʱ�ȭ ������ trivial���� �ʴ�

};

int main()
{
	//// �����ڰ� trivial���� Ȯ���ϴ� �Լ� 
	//// ���� ���� Ȯ����
	cout << is_trivially_constructible<A>::value << endl;
}

