/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

//// �ʱ�ȭ ������ ������ �غ�
// 1. 
//// ��ü(����)�� ������ ���� �ʱ�ȭ ����� �ٸ���

// 2.
//// Ŭ������ ����� �ִ� �迭�� �ʱ�ȭ �� �� ����

// 3. 
//// ���� �޸� �Ҵ����� ������� �迭�� �ʱ�ȭ �� �� ����

// 4.
//// STL�� �����̳ʸ� �ʱ�ȭ�ϴ� ���� ����� ����

int main()
{
	// 1. 
	int n1{ 0 };
	int n2{ 0 };
	int ar[3]{ 1,2,3 };
//	Point p = { 1,2 };		// ����ü
//	complex c{ 1, 2 };		// Ŭ����

	// 2.
	class Test
	{
		int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
	};

	// 3. 
	int* p = new int[3]{ 1,2,3 };

	// 4.
	vector<int> v{ 1,2,3 };

//	for (int i = 0; i < 10; i++)
//		v.push_back(1);
}






