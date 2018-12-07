/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <initializer_list>
using namespace std;

//// Initializer_list
/*
1. brace-init-list�� �ʱ�ȭ�� ����� ���۰� ��(Ȥ�� ����)�� ����Ű�� Ŭ����
2. �ݺ��ڴ� ����� ����Ų��
*/

int main()
{
	// brace-init-'list'
	// VC++ : int* first, *last, ó�� �ּ�, ������ �ּ�
	// g++  : int* first, count, ó���ּ�, ����
	initializer_list<int> s = { 1, 2, 3, 4, 5 };

	auto p = begin(s); // ����� ����Ű�� �ݺ���
	//*p = 20; // error

	cout << *p << endl;

}