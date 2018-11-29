class Base
{
public:
	void foo(int a) {}
};

class Derived : public Base
{
public:
	using Base::foo; //// <- 이게 없다면 아래가 error가 나온다
							   //// base의 foo를 사용할 수 있게 해달라는 선언(가려진걸 풀어주는 것)

	void foo() { } //// 파생클래스에 foo라는게 있다면 기반클래스의 foo로 되어 있는 함수는 모두 가려진다(사용할 수 없게 된다)
};

int main()
{
	Derived d;
	d.foo(10); // error
	d.foo();
}