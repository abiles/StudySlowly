/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new8.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(10, 0);
	v.resize(7);
	cout << v.size() << endl; // 7
	cout << v.capacity() << endl; // 10
	//// 메모리 사용량은 줄어들지 않고 size 변수만 줄였다는 얘기
	//// 성능저하를 피하기 위해서

	// DBConnect : "생성자에서 DB 접속."
	vector<DBConnect> v2(10);

	v2.resize(7);
	// 메모리는 제거하지 않지만
	// 줄어든 객체의 소멸자는 호출해야한다 
	//// DB의 접속을 해제하기 위하여
	//// delete말고 소멸자의 명시적 호출이 필요
	//// 벡터가 resize될 때 placement new를 사용하라고 할수 있는건가?
				
	v2.resize(8); 
	// 새로운 객체에 대한 메모리는 있다
	// 하지만 생성자를 호출해서
	// 다시 DB 접속을 해야 한다.
	//// 새로운 메모리 할당은 빼고 늘어난 객체에 대해서 DB에 다시 접근할 수 있도록 생성자를 호출해줘야됨
}