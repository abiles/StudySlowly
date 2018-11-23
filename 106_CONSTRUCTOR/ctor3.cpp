/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//// protected constructor
//// 자신은 객체를 만들 수 없지만( 추상적인 존재), 파생클래스의 객체는 만들 수 있게 한다. ( 인터페이스 같은거이려나?)
//// animal은 현실에 없잖아, 이런 식으로 현실을 가져오는건가, 관념, 정의만 가져온다는 느낌인가 ㅋㅋ
//// 사실은 추상 클래스 같은걸로 만들긴하지만 protected 생성자를 사용할수 있다
//// 많은 오픈 소스들이 최상위 클래스의 생성자는 protected로 만듦

class Animal
{
protected:   //// <-- 이 부분이 public 일 때랑 protected 일 때랑 잘 알아야됨
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() : Animal() {}
};

int main()
{
	// 다음중 에러를 모두 골라 보세요.
	Animal a; // error.
	Dog    d; // ok..
}