/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	
	sort(x, x+10, less<int>());


	sort(x, x+10, [](int a, int b) { return a < b; });
	// class ClosureType{};ClosureType()(1,2);
	
	//// 컴파일러가 이걸 딱~ 만들어줌, 괄호 연산자 제공
	//// 컴파일러가 만들어주는 이런걸 CloserType
	////  클로저 타입으로 만들어지는 객체를 Closer 라고 한다
	//// 결국 위는 sort(x, x+10, CloserType() ); 으로 바뀜
	//// 진짜는 Closer.cpp 확인
	/*
	class CloserType
	{
	public:
		bool operator()(int a, int b) const		//// 여기 const 붙는거 중요함
		{
			return a< b;
		}
	};
	*/

	bool b = [](int a, int b) { return a < b; }(1, 2);	//// 이것도 결국 CloserType(1,2) 불러주는 거임

	//// 원래 있는 함수객체를 좀 편하게 쓸 수 있게 바꿔준거임

	cout << b << endl; // 1
}















