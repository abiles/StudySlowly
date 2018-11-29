#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	
	//Point()				: x(0), y(0) {} //// <- 기본 형태

	Point() : Point(0,0) //// <- C++11에 새롭게 추가된 하나의 생성자에서 다른 생성자를 부르는 방식
									//// 위임 생성자, delegate constructor
	{
		// 다른 생성자를 호출할수 없을까 ? //// 인자 2개받는 Point에서 하는 작업을 여러 번 만들기 싫으니까
		//Point(0, 0);	// 임시객체를 생성하는 표현. <- 생성자에서 다른 생성자를 불러오는 표현이 아니다

		//new(this) Point(0, 0); //// 과거에 쓰던 placement new 방식

	}
	Point(int a, int b) : x(a), y(b) {}
	//void init() {} //// <- 원래는 생성자에서 중복되는 애를 이런식의 함수로 만들어서 처리했었다
};

int main()
{
	Point p;

	cout << p.x << endl;
	cout << p.y << endl;
}