/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// aggregate initialization
// aggregate type : {} �� �ʱ�ȭ ������ �͵��� ��Ƽ� �θ��� ��. ����ü(class �ƴ�), �迭.
struct Point
{
	int x, y;
	
	void foo() {}

//	Point() {}						// 1
//	Point(int a, int b) { }	// 2

//	Point() = default;	//// default�� �����ص� aggregate�� ������

//	virtual void foo() {}  //// �����Լ� ���� ���̻� struct��� �� �� ����(class�ϱ�)
};

int main()
{
	Point p1;				// 1. ok
	Point p2 { 1,2 };	// 2. ???, �ּ����� ���� ���¿����� �̰� �����ϴ� ���ϱ�?, ���� �̰� �Ǵ� type��
							
}
