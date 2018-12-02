/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int n = 10;
	int& r = n;
	const int c = n;
	const int& cr = c;

	// auto : 값 type
	//// auto가 값 타입으로 사용 되면 우변이 가진 reference, const, volatile 속성제거
	auto a1 = n;	// int
	auto a2 = r;		// int
	auto a3 = c;		// int
	auto a4 = cr;	// int

	//// auto : 참조 type
	//// auto가 참조 타입으로 사용되면 reference 속성만 제거되고 const, volatile 속성 유지
	auto& a5 = n;		// auto : int					a5 : int&
	auto& a6 = r;		// auto : int					a6 : int&
	auto& a7 = c;		// auto : const int		a7 : const int& 
								//// 만약 auto가 그냥 int로 추론된다면 int& a7 = c 인데 int& 는 const int를 가리킬 수 없는게 C++ 문법이기 때문에 
								//// auto가 const int가 되어야만 한다.
	auto& a8 = cr;		// auto : const int		a8 : const int&


	const char* s1 = "hello";		// s1 자체는 const 아님
													// s1을 따라가면(s1이 가리키는 곳을 따라가면, 즉 내용이 const라는 뜻) const
	auto a9 = s1;	// const char*

	const char* const s2 = "hello";
	auto a10 = s2;  // const char* //// 변수 자체의 const만 없애주기 때문에 이렇게 됨
}