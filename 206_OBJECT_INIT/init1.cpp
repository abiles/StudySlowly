/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//// ���� �ʱ�ȭ ������ ������

int main()
{
	// 1. 
	//// ��ü(����)�� ������ ���� �ʱ�ȭ ����� �ٸ���
	int n1 = 0;
	int n2(0);
	int ar[3] = { 1,2,3 };
	Point p = { 1,2 };		// ����ü
	complex c(1, 2);		// Ŭ����

	// 2.
	//// Ŭ������ ����� �ִ� �迭�� �ʱ�ȭ �� �� ����
	class Test
	{
		int x[10];
	};

	// 3. 
	//// ���� �޸� �Ҵ����� ������� �迭�� �ʱ�ȭ �� �� ����
	int* p = new int[3];

	// 4.
	//// STL�� �����̳ʸ� �ʱ�ȭ�ϴ� ���� ����� ����
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(1);
}






