#include <iostream>
#include <string>
using namespace std;

class Base
{
	string name;
public:
	Base(string s) : name(s) {}
};

class Derived : public Base
{
public:
	using Base::Base; //// �⺻ Ŭ������ �����ڸ� ����ϰڴ�, �� ��� Ŭ������ �����ڸ� ��� �ްڴ�

	//Derived(string s) : Base(s) {} //// ���� 1���� �޾Ƽ� ��� Ŭ������ ������ ���Ҹ� �Ѵ�
};

int main()
{
	Derived d("aa");
}
