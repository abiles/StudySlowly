class Base
{
public:
	virtual void f1(int) {}
	virtual void f2() const {}
	virtual void f3() {}
			void f4() {}
};
class Derived : public Base
{
public:
	virtual void f1 ( double ) {} //// <- f1�� ��ӹ޾Ƽ� ���°� �ǵ�, double�� �Ǽ�, ������ �����Ϸ��� ���ο� �����Լ���� ������
	virtual void f1(int) override {} //// <- override Ű���带 ���ؼ� �Ǽ��� ������ �� �ִ�

	virtual void f2 (){} //// const ��� ���� ���� �����ϵ�, ���ο� �����Լ���� �����ϴϱ�
	virtual void f2() const override {}

	virtual void foo3 () {} //// ���������� �̸� �߸� �ᵵ ���ο� �����Լ���� ����
	virtual void f3() override {}

	void f4 () {} //// ������ �ڵ������� ������ �ȵǴ� �� �ƴϴ�
	//void f4() override {} //// ��� ���� �� ���� �Լ��̱� ������ ������

	//// override = ��� �޾����� ��� �޾��� �� ���Ѿ� �Ǵ°� ��Ű�� ����
};

int main()
{

}