#include <iostream>
#include <type_traits>
using namespace std;

//// ������ ����ϴ� enum�� unscoped enum
//// ���� 
/*
1. Ÿ���� �̸� ���� ��� ����
2. ����� Ÿ���� ������ �� ����
*/
enum Color { red = 1, green = 2 };

//// Scoped Enum������ red�� Ÿ���� ������ �� �ְ���?
//// enum2 Ȯ��

int main()
{
	int n1 = Color::red;
	int n2 = red;
	int red = 0;
	int n3 = red;

	cout << typeid(underlying_type_t<Color>).name() << endl;
	//// enum ����� type�� �˾� ���� ���

}
