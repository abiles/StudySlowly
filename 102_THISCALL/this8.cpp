/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this8.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include "ecourse.hpp"	
using namespace std;
using namespace ecourse;

// 라이브러리 내부 클래스..
class Window
{
	static map<int, Window*> m_mWindows;

public:
	// Create() 및 기타 함수(메세지 처리함수)를 만들어 보세요.
	void Create ()
	{
		int h1=ec_make_window ( foo ); // 윈도우창 생성.
		m_mWindows[ h1 ]=this;
	}

	static int foo ( int hwnd, int msg, int param1, int param2 )
	{
		Window* const pWindow=m_mWindows[ hwnd ];
		switch ( msg )
		{
		case WM_LBUTTONDOWN: pWindow->OnLButtonDown(); break;
		case WM_KEYDOWN: pWindow->OnKeyDown(); break;
		}
		return 0;
	}

	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() {}
};

// 사용자 클래스.
class MyWindow : public Window
{
public:
	virtual void OnLButtonDown() { cout << "마우스 왼쪽 버튼 누름" << endl; }
	virtual void OnKeyDown () { cout << "키보드 누름" << endl; }
};

int main()
{
	MyWindow w;
	w.Create(); // 이순간 윈도우가 생성되어야 합니다.
				// 마우스 버튼을 누르면OnLButtonDown() 함수 호출.

	ec_process_message();
}