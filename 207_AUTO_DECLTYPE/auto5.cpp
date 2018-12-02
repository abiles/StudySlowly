/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

int main()
{
	// 배열.
	int x[3] = { 1,2,3 }; // x : int[3]

	auto  a1 = x;	// int a1[3] = x; error //// 배열은 복사 초기화 될수 없으니까 이거 안됨
							// int* a1 = x;  //// 첫번째 요소의 주소로 암시적 형변환 해줌

	auto& a2 = x;	// int (&a2)[3] = x; // ok //// 복사가 아니기 때문에 가능
							// a2 : int (&)[3]
	
	decltype(x) d;  // int [3]

	cout << typeid(a1).name() << endl;	// int*
	cout << typeid(a2).name() << endl;	// int(&)[3] /// 실제 출력하면 int [3]으로 나오는데 typeid는 &랑 const를 못 나타내서 그렇게 나오는 거임
	cout << typeid(d).name() << endl;		// int [3]

	//------------------------

	auto a3 = 1;	// int
	auto a4{ 1 };	// int
	auto a5 = { 1 };// int ? initializer_list => initializer_list

	cout << typeid(a4).name() << endl;
	cout << typeid(a5).name() << endl;

	//--------------------------

	vector<int> v1(10, 0);
	auto a6 = v1[0];	// int

	vector<bool> v2(10, 0);
	auto a7 = v2[0];	// bool 아님, vector에서 bool을 따로 관리하기 때문이당 std::_Vb_reference, temparary proxy

	cout << typeid(a6).name() << endl; // int
	cout << typeid(a7).name() << endl; // temporary proxy 참고

}