class Base
{
public:
	void foo(int a) {}
};

class Derived : public Base
{
public:
	using Base::foo; //// <- �̰� ���ٸ� �Ʒ��� error�� ���´�
							   //// base�� foo�� ����� �� �ְ� �ش޶�� ����(�������� Ǯ���ִ� ��)

	void foo() { } //// �Ļ�Ŭ������ foo��°� �ִٸ� ���Ŭ������ foo�� �Ǿ� �ִ� �Լ��� ��� ��������(����� �� ���� �ȴ�)
};

int main()
{
	Derived d;
	d.foo(10); // error
	d.foo();
}