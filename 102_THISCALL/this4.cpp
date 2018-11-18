/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// this4.cpp - Thread 클래스 만들기
#include <iostream>
#include <windows.h>
using namespace std;


// 라이브러리 내부 클래스
class Thread
{
public:

	void run()
	{
															//// static 함수에서 this가 필요한 상황이 있기 때문에 이런 방법을 쓴다
		CreateThread(0, 0, threadMain,(void*)this, 0, 0);
	}

	//// CreateThread에 전달할 수 있는 기본 형태는 DWORD __stdcall funcname(void * p)
	//// 아래에는 static이 붙어 있다 왜일까?

	// 1. 아래 함수는 반드시 static 함수 이어야 합니다.
		//// createthread에 넘어가는 함수는 반드시 인자가 void* 하나여야 하기 때문에 this를 없애기 위해서 static을 붙입니다
	// 2. 아래 함수는 this가 없다. 그래서 함수 인자로 this를 전달하는 기술.
	//// 3. 안드로이드 프레임 워크에서 thread가 이런 식으로 만들어져 있음

	static DWORD __stdcall threadMain(void* p)
	{
		//// 1. Main을 그냥 부르려니 오류가 난다 왜일까?
		//// Main은 사실 this가 필요하기 때문이다. 그런데 static에는 this가 없다
		//Main(); // 가상함수 호출
		// this->Main() => Main( this) 로 변해야 한다.
		
		//// run 함수에는 this가 있다!
		//// run 함수에서 void * 로 this를 보내주는 방법 (2번에 정리)

		Thread* const self = static_cast<Thread*>(p);

		self->Main(); // == Main( self )



		return 0;
	}

	virtual void Main() // void Main(Thread* const this) //// this가 숨어있다는 것으 잊지 말 것
	{}
};






// 라이브러리 사용자 코드
class MyThread : public Thread
{
public:
	virtual void Main() { cout << "스레드 작업" << endl; }
};









int main()
{
	MyThread t;
	t.run();	// 이순간 스레드가 생성되어서 
				// 가상함수 Main()을 실행해야 합니다.
	getchar();
}






