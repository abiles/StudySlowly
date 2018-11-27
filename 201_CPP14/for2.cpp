#include <iostream>
#include <list>
using namespace std;

//// ���� ���� type���� ranged_for �ϱ�
struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;

	int* begin (  ) { return &( x ); } //// class ó�� ��ġ �ּ�
	int* end (  ) { return &( z ) + 1; } //// ������ ��ġ + 1 �ּ�
};

//// ��� �Լ��� �ϰų� �����Լ��� �ϰų�  ���ð���, ���� ��� �Լ��� ���� �Ԥ�
//// int* begin ( Point3D& p3 ) { return &( p3.x ); } //// class ó�� ��ġ �ּ�
//// int* end ( Point3D& p3 ) { return &( p3.z ) +1; } //// ������ ��ġ + 1 �ּ�

//// �̷��� �ϸ� x,y,z�� ���ʴ�� ��� ��
//// �̷��� ���� ������, �� ���� ��������
//// ���� begin, end�� ����Լ��� ���� ���� ��


int main()
{
	Point3D p3;
	//// ���� ���� type�� ranged_for�� �̿��� �� �������?
	for (auto& n : p3)  // begin(p3)
		cout << n << endl;
}


/*
int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };


//	for (auto& n : s) 
//		cout << n << endl;

//// ���� for ���� �Ʒ� ���·� �����Ϸ��� �ٲߴϴ�.
//// ranged_for�� ���� : begin()/end()�� ����� ����� �ݺ��ڸ� ���ؼ� ��ҿ� �����ϴ� ��
	for ( auto p = begin(s); p != end(s); ++p )
	{
		auto& n = *p;

		cout << n << endl;
	}

}

*/
