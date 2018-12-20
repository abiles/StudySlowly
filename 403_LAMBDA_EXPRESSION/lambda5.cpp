/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <functional>
using namespace std;

int main()
{
	//// ���� ǥ���� ��� ���
	//// 1. auto
	auto f1 = [](int a, int b) { return a + b; };

	//// 2. �Լ� ������ Ÿ������ �Ͻ��� ��ȯ -> ������ �ڿ��� ���캼����
	int(*f2)(int, int) = 
			  [](int a, int b) { return a + b; };

	//f2 = [](int a, int b) { return a - b; };

	//// 3. stl fucntion
	function<int(int, int)> f3 =
		[](int a, int b) { return a + b; };


	f1(1, 2); // inline ġȯ ����.			//// �Լ� ��ü�̱� ������
	f2(1, 2); // inline ġȯ�� ��ƴ�	//// �ٸ� �Լ��� �߰��� ���� ���� ���� �ִ� �����̱� ������
	f3(1, 2); // inline ġȯ�� ��ƴ�	//// �ֵ� �ٸ� �Լ��� �߰��� ���� ���� �� �ִ�

}

