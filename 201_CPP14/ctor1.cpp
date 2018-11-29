#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	
	//Point()				: x(0), y(0) {} //// <- �⺻ ����

	Point() : Point(0,0) //// <- C++11�� ���Ӱ� �߰��� �ϳ��� �����ڿ��� �ٸ� �����ڸ� �θ��� ���
									//// ���� ������, delegate constructor
	{
		// �ٸ� �����ڸ� ȣ���Ҽ� ������ ? //// ���� 2���޴� Point���� �ϴ� �۾��� ���� �� ����� �����ϱ�
		//Point(0, 0);	// �ӽð�ü�� �����ϴ� ǥ��. <- �����ڿ��� �ٸ� �����ڸ� �ҷ����� ǥ���� �ƴϴ�

		//new(this) Point(0, 0); //// ���ſ� ���� placement new ���

	}
	Point(int a, int b) : x(a), y(b) {}
	//void init() {} //// <- ������ �����ڿ��� �ߺ��Ǵ� �ָ� �̷����� �Լ��� ���� ó���߾���
};

int main()
{
	Point p;

	cout << p.x << endl;
	cout << p.y << endl;
}