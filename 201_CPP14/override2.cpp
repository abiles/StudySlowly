#include <type_traits>
#include <iostream>
using namespace std;
class A
{
public:
	virtual void f1() {}
};

class B final : public A //// �̷������� Ŭ�������� ���� �� �ִ� Ű����
{
public:
	virtual void f1() override final{} //// ���� ��� �ȵſ�~ Ű����
};

/*
class C : public B
{
public:
	//virtual void f1() override  {}
};
*/
int main()
{
	bool b = is_final<B>::value;
	cout << b << endl;
}