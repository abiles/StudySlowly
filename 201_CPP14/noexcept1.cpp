#include <iostream>
using namespace std;
/*
// c++98
int foo()  // ���ܰ� �������� �ְ�, �������� �ִ�. //// �̷� �ǹ̿� �̷� ������ �־���
int foo() throw(int) // ���ܰ� �ִٴ� �ǹ�.
int foo() throw()    // ���ܰ� ���ٴ� �ǹ�.
{
	throw 1;
	return 0;
}
*/
// C++11
//void goo() noexcept(true) // ���ܰ� ����.
//void goo() noexcept(false) // ���ܰ� �ִ�.
void goo() noexcept // ���ܰ� ���ٿ� ����
{
	throw 1;
}

void goo() 
{
	throw 1;
}

//// throw�� �ִ� �Լ��� ���ؼ� try catch�� ���ϸ� throw �߻��� abort�� ���α׷� ����
//// noexcept ��� �ߴµ� throw�� �߻��ϸ� abort�� ���α׷� ����(try catch�� ���δ��� ����)
//// noexcept�� ������ thorw ��������

//// ���ܰ� �ִ��� ������ ǥ���ϸ� ������ ���� ������?
//// �����Ϸ��� ����ȭ �� �� ���ܰ� ���ٴ� ���� ����� ǥ���ϸ� ���� �� ���� �ڵ带 ���� �� ����
int main()
{
	goo();

	try
	{
		goo();
	}
	catch (...)
	{
		cout << "exception..." << endl;
	}
}




