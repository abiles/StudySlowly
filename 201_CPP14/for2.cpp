#include <iostream>
#include <list>
using namespace std;

//// 내가 만든 type으로 ranged_for 하기
struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;

	int* begin (  ) { return &( x ); } //// class 처음 위치 주소
	int* end (  ) { return &( z ) + 1; } //// 마지막 위치 + 1 주소
};

//// 멤버 함수로 하거나 전역함수로 하거나  선택가능, 보통 멤버 함수로 많이 함ㄴ
//// int* begin ( Point3D& p3 ) { return &( p3.x ); } //// class 처음 위치 주소
//// int* end ( Point3D& p3 ) { return &( p3.z ) +1; } //// 마지막 위치 + 1 주소

//// 이렇게 하면 x,y,z를 차례대로 찍게 됨
//// 이런걸 많이 쓰려나, 잘 쓰면 좋을지도
//// 보통 begin, end를 멤버함수로 만들어서 많이 씀


int main()
{
	Point3D p3;
	//// 내가 만든 type도 ranged_for로 이용할 수 있을까아?
	for (auto& n : p3)  // begin(p3)
		cout << n << endl;
}


/*
int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };


//	for (auto& n : s) 
//		cout << n << endl;

//// 위의 for 문은 아래 형태로 컴파일러가 바꿉니다.
//// ranged_for의 원리 : begin()/end()를 사용해 얻어진 반복자를 통해서 요소에 접근하는 것
	for ( auto p = begin(s); p != end(s); ++p )
	{
		auto& n = *p;

		cout << n << endl;
	}

}

*/
