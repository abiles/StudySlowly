#include <iostream>
#include <type_traits>
using namespace std;

struct Point
{
	int x, y;

	Point() {} // 사용자가 생성자 제공.

	//Point() = default; // 컴파일러가 제공. //// 위 모습하고 똑같이 만들어짐

	//// 무슨 차이가 있을까요?
	//// 1. trivial 확인시 default 함수 일 때만 trivial 하다

//	Point(const Point& ) = default; //// 복사 생성자 default 함수
//	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p1{};  //// {}를 주목하라, 객체 초기화 강의에서 다시 확인


	cout << p1.x << endl;
	// default 생성자 - 0 나옴
	 // 사용자가 제공 - garbage  값 나옴

	cout << is_trivially_constructible<Point>::value	 << endl;
}
