/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int cnt = 0;

class Test
{
public:
	//	int data = 0; // member initializer

	int data = ++cnt; //// �̷��� �ϰ� �Ʒ����� Test t2(3) �ϸ� � ����� ���ñ�?

	Test() {}
	Test(int n) {}  //: data(n) {} //// �̷������� ��������� data(n)�� ���ָ� int data = ++cnt;�� �۵����� �ʴ´�
												//// data(n), �̰� ������ �۵���
};

int main()
{
	Test t1;		// data = 1		//// ���⼭ ++cnt �ҰŰ�
	Test t2(3);	// data = 3		//// ���⼭�� ���ǿ� ���� ++cnt �Ҽ��� �ְ� �� �Ҽ��� �ְ�, �� ������ �� ���� Ȯ��

	cout << cnt << endl; // 1

	cout << t1.data << endl;
	cout << t2.data << endl;
}
