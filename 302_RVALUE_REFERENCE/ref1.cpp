/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int x = 10;
int  f1() { return x; }
int& f2() { return x; }

/*
lvalue
1.등호 왼쪽 오른쪽 모두 놓일 수 있다
2.이름이 있다. 그래서 단일 문장을 벗어나서 사용될 수 있다.
3.주소연산자로 주소를 구할 수 있다.
4. 참조를 리턴하는 함수

rvalue 
1.등호 오른쪽에만 놓일 수 있다
2. 이름이 없다. 값만 있다. 단일 문장을 벗어나서 사용될 수 없다.
3.주소연산자로 주소를 구할 수 없다.
4.값을 리턴하는 함수. 임시객체. 정수/실수형 리터럴
*/

int main()
{
	int v1 = 10, v2 = 10;
	v1 = 20; // v1 : lvalue  20 : rvalue
	20 = v1; // error
	v2 = v1; //

	int* p1 = &v1; // ok
	int* p2 = &10; // error.

	f1() = 10; // error, 값 리턴은 임시객체를 리턴하기 때문에  rvalue
	f2() = 20; // ok.

	const int c = 10;
	c = 20; // c는 rvalue ? lvalue ?
	// c 는 수정 불가능한 lvalue

	// rvalue가 모두 상수인 것은 아니다.
	//Point().x = 10; // error
	//Point().set(10, 20); // ok, rvalue인 임시객체이지만 수정할 수 있으므로 상수는 아니다.

}

