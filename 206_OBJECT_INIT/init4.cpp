/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//// direct initialization
/*
초기화 시에 = 을 사용하지 않는 것
T object(arg);
T object(arg1, arg2,...);
T obejct{arg};
T(other)
T(arg1,arg2,...)
static_cast<T>(other)
new T(args,...)
Class::Class()::member(args){}
{arg}(){...}; // 람다 표현식
*/

//// Copy Initialization
/*
초기화시에 = 을 사용하는 초기화
T object = other;
T object = {other};
f(other)
return other; // return by value
throw object;
catch (T object)
T array[N] = { other };
*/

int main()
{
	int n1 = 0; // copy initialization
	int n2(0);	// direct initialization

	int n3 = { 0 };
	int n4{ 0 };
}
