#include <iostream>
#include <type_traits>
using namespace std;

struct Point
{
	int x, y;

	Point() {} // ����ڰ� ������ ����.

	//Point() = default; // �����Ϸ��� ����. //// �� ����ϰ� �Ȱ��� �������

	//// ���� ���̰� �������?
	//// 1. trivial Ȯ�ν� default �Լ� �� ���� trivial �ϴ�

//	Point(const Point& ) = default; //// ���� ������ default �Լ�
//	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p1{};  //// {}�� �ָ��϶�, ��ü �ʱ�ȭ ���ǿ��� �ٽ� Ȯ��


	cout << p1.x << endl;
	// default ������ - 0 ����
	 // ����ڰ� ���� - garbage  �� ����

	cout << is_trivially_constructible<Point>::value	 << endl;
}
