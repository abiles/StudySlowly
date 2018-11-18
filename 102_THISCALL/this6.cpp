/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <string>
#include "ecourse.hpp"	
using namespace std;
using namespace ecourse;

// 타이머 개념을 사용해서 Clock 클래스 만들기.
#include <map>

//class Clock;

//map<int, Clock*> this_map;

class Clock
{
	static map<int, Clock*> this_map;
	string name;
public:
	Clock(string n) : name(n) {}

	void start(int ms)
	{
		int id = ec_set_timer(ms, timerHandler );

		this_map[id] = this;
	}

	// 핵심 1. 아래 함수는 반드시 static 멤버 이어야 합니다.
	//// ec_set_timer에 전달되는 함수는 인자가 반드시 1개여야 하기 때문에(this를 포함해서는 안됨)

	static void timerHandler(int id)
	{
		Clock* const self = this_map[id];

		//cout << name << endl;	// this->name
		cout << self->name << endl;
	}
};

map<int, Clock*> Clock::this_map;
//// 맵에 넣어서 this를 관리하는 방법이 왜 좋냐
//// timerHandler와 start 함수의 공통점이 뭐냐, id를 사용하고 있다는 것
//// 이 공통점을 사용해서 문제를 해결하는 거지



int main()
{
	Clock c1("A");
	Clock c2("\tB");

	c1.start(1000); // 1000ms 에 한번씩 이름출력
	c2.start(500);  // 500ms 에 한번씩 이름출력

	ec_process_message();
}