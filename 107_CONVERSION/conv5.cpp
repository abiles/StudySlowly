/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

class Test
{
	int value;
public:
	//// Test ( int n ) : value ( n ) {} 원래 이 모양인데 암시적 '형변환'을 막기위해서 아래처럼 사용
	//// explicit 붙이면 '생성'할 때는 사용할 수 있지만 '변환'할 때는 사용할 수 없게 된다.
	explicit Test(int n) : value(n) {}
};

int main()
{
	// 아래 2줄의 차이점은 ?
	
	Test t1(5);  //// 인자가 한개인 생성자 호출
					   //// direct initialization ( 괄호를 이용해서 초기화 하는 방법)

	Test t2 = 5;  //// 1. 변환 생성자를 사용해서 5를 가지고 Test의 임시객체 생성 ( 생성자 첫번째)
					     //// 2. 임시객체를 복사 생성자를 사용해서 t2에 복사 (생성자 두번째)
						 //// 왜 두 번에 걸쳐서 하게 했는지는 모르겠네, 결국 메모리 단위에서 Test라는 객체를 하나 잡아놓고 바로 하느냐 2개 잡아서 넣어주느냐의 차이인가?
					     //// copy initialization ( = 를 이용해서 초기화 하는 방법)
}
