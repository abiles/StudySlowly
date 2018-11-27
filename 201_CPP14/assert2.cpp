#include <iostream>
#include <mutex>
using namespace std;

//// static_assert�� Ȱ��
/*
�Լ� �ȿ� �������, �ۿ� ������� �ִ�
�Լ� �Ǵ� Ŭ���� ���ø��� ���� �� type_trait�� ����ؼ� T�� ������ �ϴ� ������ static_assert�� �����ϴ� �ڵ尡 �θ� ����
static_assert�� �� Ȱ���ϸ� ������ ���� ���� �޽����� ���� �� �ִ�
*/


#pragma pack(1)
struct PACKET
{
	char cmd;
	int  data;
};
static_assert(
	sizeof(PACKET) == sizeof(char) + sizeof(int),
	"error, unexpected padding !");

//// struct�� 5����Ʈ�� ��������� ȿ���� �������� �е��� �ϰ� �Ǵµ�
//// ��Ŷ�� ������ �� ���� �е����� ������ ���� �ʱ� ������ static_assert�� ���� ���� �е��� ������� Ȯ��
//// �ᱹ �� �е��� ���ִ� ���� �˾ƾ߰�����? #pragma pack(1) �ϸ� 1����Ʈ ������ �е��ϱ� ������ static_assert ������ �Ȼ���


template<typename T> void Swap(T& a, T& b)
{
	// T�� �������ϴ� ������ ����
	static_assert(is_copy_constructible<T>::value,
		"error. T is not copyable");
	
	T tmp = a; //// �� �κп��� ���� �����ڰ� �ʿ��ϱ� ������ �ռ� �˻縦 ��
	a = b; //// �̰� ������ ���� ���Ե� ���� �ؾ� �Ѵٴµ�1
	b = tmp;
}

int main()
{
	mutex m1; //// mutex�� ���� �����ڸ� �������� ����
	mutex m2;
	Swap(m1, m2);
}