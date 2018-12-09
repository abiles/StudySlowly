/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : temp3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};
// temp5.cpp
//// �Լ����� ���� �����ϸ� �ӽð�ü�� �����ȴ�.

Point foo()
{
	Point pt(1, 1);		// 2. ������
	return pt;				// return Point(pt) �ӽð�ü ����, pt�� {} ����� �ı��Ǳ� ������ ���⼭ �ӽð�ü�� ���纻 ����� ������
								// 3. ���� ������ ( pt -> �ӽð�ü�� ����)
}	

Point foo2()
{
	// �ӽð�ü�� ����� ����
	// RVO ( Return Value Optimization )
	return Point ( 1, 1 );	// 2. ������
										// ���� ������ ����� �۾� X
}

int main()
{
	Point ret(0, 0);	// 1. ������
	ret = foo();			// 4. �ӽ� ��ü�� ���Կ����� ���ؼ� ret�� 
								// 5. �ӽ� ��ü �Ҹ�

	Point ret2 ( 1, 1 );	// 1. ������
	ret2 = foo2();			//  4, 5 ����

	//// ������ foo ó�� ����ص� �����Ϸ��� �˾Ƽ� RVO�� ����ȭ ���� �̸� NRVO(Named...)��� ��
	//// ����ũ�μ���Ʈ���� NRVO ����ϰ� ������ /O2 �ɼ� �ָ� ��

	cout << endl;

}

