/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new5.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()  { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// placement new : �����ڸ� ȣ���ϱ� ���� ���� new //// C++ ǥ��
// 
/*
void* operator new(size_t sz, void* p)
{
	return p; //// ���ڷ� ���� ������ �״�� �����ֱ�
}
*/
int main()
{
	Point p;	//// �ϴ� ������ �ѹ� �Ҹ�
	//// p.Point (); �̷������� �����ڸ� ȣ���� ���� ����.

	//new Point; // ���ڰ� 1���� operator new()ȣ��. //// �⺻ new������

	new(&p) Point; // ���ڰ� 2���� operator new()ȣ��. //// size�� �˾Ƽ� �Ѿ
					// �޸� �Ҵ��� �ƴ� �����ڸ� ȣ���ϴ� �ڵ�
	//// new(&p)�� ��� �����ؾ� �ϳ� �ϸ�
	//// 1. ���� ���� ���� 2���ڸ� operator new�� �θ���
	//// 2. �޸� �ּҸ� ���θ��� operator new �� ���ؼ� ��ȯ�ϰ� �ȴ� 
	//// 3. �� �� ��ȿ�� �ּҸ� �����ϱ� ������ �����ڸ� ȣ���ϰ� �ȴ�
	//// �ᱹ �߿��Ѱ� �����ڸ� p�� ���ؼ� �ѹ� ȣ���Ѵٴ� ���̴�. 
	p.~Point(); 
}