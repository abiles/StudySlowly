#include <iostream>
#include <functional>
using namespace std;

void foo()
{

}

//// function Object
/*
��ȣ�� ���ʿ� �� �� �ִ� '��ü'
- ��� ������ �Լ� ������
- () �����ڸ� �������� Ŭ����
- Lambda

- �Լ��� �Լ��� ����Ű�� ������ Function Object�� �ƴϴ�.
*/

int main()
{
	void(&r)() = foo;		//// <- �Լ���ü �ƴ�
	r();							//// <- �Լ���ü �ƴ�
	foo();						//// <- �Լ���ü �ƴ�

	less<int> f;
	f(1, 2);

	[](int a, int b) { return  a + b; }(1, 2);



	
}

