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
void goo(char* p) { cout << "goo" << endl; }		// 3


struct xnullptr_t
{
	//operator void*() { return 0; }
	//operator char*() { return 0; }

	//// ��� Ÿ�Կ� ���ؼ� ��ȯ ���갡 �ʿ� �ϱ� ������  ���ø����� ����� �ش�.
	template<typename T>
	operator T*() { return 0; }
};

xnullptr_t xnullptr; // ������ 0

// C++ 11: nullptr
int main()
{
//	foo(0);				 // 1
//	foo(xnullptr);	 // 2. xnullptr_t => void* ���� �Ͻ��� ��ȯ �ʿ� 
							 //// ��ȯ ������ operator void*() �ʿ�
							 //     xnullptr.operator void*()
//	goo(xnullptr);  // 3 goo
							//// ��ȯ ������ operator char*() �ʿ�

	int n = 0;
	
	double* p1 = xnullptr;
	//// xnullptr.operator T *() <- 1
	//// xnullptr.operator double *() <- 2

	double* p2 = nullptr; // C++11 �� ������ 0
						  
	std::nullptr_t a = nullptr;

	int* p = a;
}



































