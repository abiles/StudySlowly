#include <iostream>
using namespace std;

void foo(int n)
{
	cout << "foo(int)" << endl;
}

//void foo(double); // ����
//// �Ͻ��� ����ȯ �Ͼ�� �� ������ �߻��ϵ���
//// �̷����ϸ� ������ ���� �� ������ ������ �ƴ϶� ��ũ����

//void foo(double) = delete; //// <- �� �Լ��� ������ �ּ��� (�Լ�����)
//// ������ Ÿ�ӿ� ������ �Լ��� ����ϰ� �Ǹ� ������ �߻��Ѵ�

int main()
{
	foo(3.4); // foo(double) //// <- double�� int�� ����ȯ�� �����ϴϱ� foo(int)�� �Ҹ���(�Ͻ��� ����ȯ)
}