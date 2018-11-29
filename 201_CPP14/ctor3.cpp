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
	using Base::Base; //// 기본 클래스의 생성자를 사용하겠다, 즉 기반 클래스의 생성자를 상속 받겠다

	//Derived(string s) : Base(s) {} //// 인자 1개를 받아서 기반 클래스로 보내는 역할만 한다
};

int main()
{
	Derived d("aa");
}
