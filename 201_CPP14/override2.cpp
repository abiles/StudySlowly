#include <type_traits>
#include <iostream>
using namespace std;
class A
{
public:
	virtual void f1() {}
};

class B final : public A //// 이런식으로 클래스에도 붙일 수 있는 키워드
{
public:
	virtual void f1() override final{} //// 이제 상속 안돼요~ 키워드
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