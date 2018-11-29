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
	virtual void f1 ( double ) {} //// <- f1을 상속받아서 쓰는게 의도, double은 실수, 하지만 컴파일러는 새로운 가상함수라고 생각함
	virtual void f1(int) override {} //// <- override 키워드를 통해서 실수를 방지할 수 있다

	virtual void f2 (){} //// const 없어도 문제 없이 컴파일됨, 새로운 가상함수라고 생각하니까
	virtual void f2() const override {}

	virtual void foo3 () {} //// 마찬가지로 이름 잘못 써도 새로운 가상함수라고 생각
	virtual void f3() override {}

	void f4 () {} //// 위험한 코드이지만 컴파일 안되는 건 아니다
	//void f4() override {} //// 상속 받을 수 없는 함수이기 때문에 오류남

	//// override = 상속 받았으면 상속 받았을 때 지켜야 되는걸 지키게 해줌
};

int main()
{

}