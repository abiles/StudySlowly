#include <iostream>
using namespace std;

// Concept Ts
//void foo(auto n) {}

int main()
{
	// generic lambda : C++14
	auto f1=[]( auto a, auto b ) { return a + b; };
	/*
	class ClosureType
	{
	public:
		template<typename T1, typename T2>
		decletype ( auto ) operator()( T1, a, T2 b ) const
		{
		return a + b;
		}
	};
	*/

	cout << f1(1, 2.1) << endl; // 3.1


	// nullary lambda
	//// 전달하는 인자가 없으면 () 생략 가능
	auto f2 = [] {return 10; }; 


	// C++17 : () 함수를 constexpr 함수로..
	auto f3 = [](int a, int b) constexpr
	{
		return a + b; 
	};

	int y[f3(1, 2)];	//// 배열의 크기는 컴파일 시간에 결정되어야 한다, 컴파일시간에 f3(1,2)가 결정된다면 이런데 쓰일수있겠지

	
}

