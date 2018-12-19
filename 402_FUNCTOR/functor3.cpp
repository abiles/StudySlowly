/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <algorithm>	
#include <iostream>
using namespace std;
//// Functor�� ����

// ���̺귯�� �����ڵ��� ���
// ������ ���� ��ü �帧�ӿ���
// ����Ǿ�� �ϴ� �κ��� �и��Ѵ�. (functor �κ�)

// qsort() �Լ��� ������ ���

// '�Ϲ��Լ��� �ڽŸ��� Ÿ���� ����.'
// signature�� �����ϸ� ��� ���� Ÿ���̴�.			//// int xx(int,int) = int yy(int, int)
// so �̷� ���� �Լ��� �� cmp �ڸ��� �� �� �ִٴ� ��
void Sort(int* x, int n, bool(*cmp)(int, int))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//	if (x[i] > x[j])

			if (cmp(x[i], x[j]))		//// ���ϴ� �κ�, �Լ������͸� ���ؼ� �θ��� ������ inline ���� �ȵ�, �׷��� ���� ���ڰ�? ����
				swap(x[i], x[j]);
		}
	}
}

//// �ٸ� �Լ�, ���� Ÿ��!
inline bool cmp1(int a, int b) { return a > b; }	//// ��������, ���⼭ inline �ߴٰ� ����ɱ�? 
inline bool cmp2(int a, int b) { return a < b; }	//// ��������

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, cmp2);
}
