/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Test
{
public:
	Test() {}
	~Test() {}
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t)      { cout << "Move" << endl; }

	Test& operator=(const Test& t) { return *this; } // ���� ���Կ�����, �����δ� �׳� ���������
	Test& operator=(Test&& t)			{ return *this; } // move ���Կ�����, �����δ� �׳� ���������
};

int main()
{
	Test t1;
	Test t2 = t1;	// �ʱ�ȭ. ���� ������!!
	t2 = t1;			// ����.    ���� ������!!

	t2 = move(t1); //// move�� ����


}











