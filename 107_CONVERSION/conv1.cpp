/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// ��ȯ ������ : ��ü�� �ٸ� Ÿ������ ��ȯ�Ҷ� ȣ��ȴ�.
	// Ư¡ : ���� Ÿ���� ǥ������ �ʴ´�. //// �̹� �Լ� �̸��� �����ϰ� �ִٰ� �Ǵ��ϱ� ������
	operator int()
	{
		return x;
	}
};

int main()
{
	int			n = 3;
	double		d = n; // �Ͻ��� ����ȯ �߻�. //// ǥ�� Ÿ�Գ����� �Ͻ��� ����ȯ ����

	Point p1(1, 2);
	n = p1;		// p1.operator int() //// <-- ��ȯ�����ڸ� �����Ϸ��� ȣ���ϴ� ���

	cout << n << endl; // 1
}
















