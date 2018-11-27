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

//// ���⼭ ���Ӱ� ����
/*
decltype( c.begin () ) begin ( C& c )
�� ���ϰ��� �տ��ٰ� ���� ���ϴ°�?
������ c�� (C& c )���� ����Ǵµ� decltype( c.begin () �� �̺��� �տ���
c�� ����Ϸ��� �Ѵ� �׷��� ����������
-> decltype(c.begin()) ��°� ���� return type�� ���ϰ� �ϴ� ��!
�Ϳ�
������ ��ȯ Ÿ��
*/


// arr version
//// �迭 ������ ����� �ʿ��ϱ�
template<typename T, std::size_t N>
constexpr T* begin(T(&arr)[N])  //// <- TŸ�� arr�� ���� �򰥸���
{
	return arr; //// �迭�̴ϱ� ���� �ּ� ����
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