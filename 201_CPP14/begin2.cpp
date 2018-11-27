#include <iostream>
#include <list>
#include <vector>
using namespace std;

// container version.
template<typename C> 
constexpr auto begin(C& c) -> decltype(c.begin())
{
	return c.begin();
}

template<typename C>
constexpr auto end(C& c) -> decltype(c.end())
{
	return c.end();
}

//// 여기서 새롭게 배운거
/*
decltype( c.begin () ) begin ( C& c )
왜 리턴값을 앞에다가 쓰지 못하는가?
이유는 c가 (C& c )에서 선언되는데 decltype( c.begin () 은 이보다 앞에서
c를 사용하려고 한다 그래서 문법적으로
-> decltype(c.begin()) 라는건 만들어서 return type을 정하게 하는 것!
와우
후위형 반환 타입
*/


// arr version
//// 배열 버전은 사이즈가 필요하군
template<typename T, std::size_t N>
constexpr T* begin(T(&arr)[N])  //// <- T타입 arr는 역시 헷갈리네
{
	return arr; //// 배열이니까 시작 주소 리턴
}
template<typename T, std::size_t N>
constexpr T* end(T(&arr)[N])
{
	return arr + N;
}



int main()
{
	list<int> s = { 1,2,3 };
	int x[3]    = { 1,2,3 };

	auto p1 = begin(s);
	auto p2 = begin(x);
}