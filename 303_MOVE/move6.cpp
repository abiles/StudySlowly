/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Test
{
public:
	Test() {}
	~Test() {}
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t)      { cout << "Move" << endl; }

	Test& operator=(const Test& t) 
	{
		cout << "Copy=" << endl; 
		return *this; 
	} 
	
	Test& operator=(Test&& t) 
	{
		cout << "Move=" << endl; 
		return *this; 
	} 
};




template<typename T> void Swap(T& x, T& y)
{
//	Test temp = x; // 복사 생성자
//	x = y;		   // 복사 대입
//	y = temp;

	Test temp = move(x); // static_cast<Test&&>
	x = move(y);
	y = move(temp);
}

int main()
{
	Test t1, t2;
	//Swap(t1, t2);
	swap(t1, t2); //// 이미 만들어진 move를 이용한 swap
	//// 만약에 유저가 move 생성자를 안만들었다?
	//// 그럼 const Test&를 사용하게 돼서 복사를 이용한 swap이 된다. (move는 사실 static_cast<T&&> 하는 것이기 때문에)
	//// 그래서 아무튼 성능 좋게 하려면 move 생성자랑, move 대입 연산자는 만들어 놔야겠지?

}











