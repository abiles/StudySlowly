#include <iostream>
using namespace std;

void algo1()
{
	// �������� ���� ���ɼ��� �ִ�.
}

void algo2() noexcept  // ������
{
	// �������� ���ܰ� ������ �ʴ´�.
}

class Test
{
public:
	Test() noexcept {}
};

//// noexcept
/*
noexcept specifier - ������ void algo2() "noexcept"
noexcept operator - ������ "noexcept"(algo1());
*/

int main()
{
	bool b1 = noexcept(algo1()); // 0. ������, ������ Ÿ�� Ȯ��, statc_assert�� �־ ��� ����
	bool b2 = noexcept(algo2()); // 1

	cout << b1 << ", " << b2 << endl;

	bool b3 = is_nothrow_constructible<Test>::value; //// �����ڿ��� noexcept �پ� �ִ��� Ȯ���ϴ� ����(type_traits ���), ������ Ÿ�� Ȯ��
	cout << b3 << endl;

}




