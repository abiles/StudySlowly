#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

// 컨테이너의 모든 요소를 출력하는 함수.
template<typename T> void show(T& c)
{
	//// 이런 식으로 안만드는 이유는 일반 배열도 받기 위해서이다. 
	//// std::begin으로 하면 일반 배열에서도 반복자를 꺼낼 수 있다
//	auto p1 = c.begin();  //// 컨테이너의 멤버 함수 를 사용하고 있기 때문에 일반 배열(raw array)에서는 오류가 남
//	auto p2 = c.end();

	auto p1 = begin(c); //// std::begin 쓰는게 핵심이다
	auto p2 = end(c);

	while (p1 != p2)
	{
		cout << *p1 << endl;
		++p1;
	}
}

int main()
{
	list<int> c = { 1,2,3 };
	//vector<int> c = { 1,2,3 };
	
	show(c);

	int x[3] = { 1,2, 3 };

	show(x);

}