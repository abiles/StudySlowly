/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int n)   { cout << "int" << endl; }			// 1
void foo(void* p) { cout << "void*" << endl; }	// 2

void foo2(char* p) { cout << "foo2" << endl; }	// 3

int main()
{
	foo(0);				// �����ϱ� 1������ ��
	foo((void*)0);	// ��Ȯ�ϰ� 2������ ���� �ϴ¹�

//// �� �̰� ���� �������?
#ifdef __cplusplus
	#define NULL	0
#else
	#define NULL (void*)0
#endif
	
	foo2 ( NULL );	// void* => char* ���� �Ͻ��� ��ȯ �ʿ�.
							// C   : ok
							// C++ : �Ͻ��� ��ȯ �ȵ�. Ÿ�Կ� ���ؼ� �� �����ϰ� �ٷ�� ������. void*���� char*���� �Ͻ��� ��ȯ �ȵ�
							//// ���� C�� C++�� �����ؼ� NULL�� define ����� ��


	foo(NULL);		//// C++���� 2���� �θ��� ������ ����μ��� 1���� �Ҹ���
							//// ���� point 0 �̶�°� �ʿ��ؼ� ����� nullptr


}



















