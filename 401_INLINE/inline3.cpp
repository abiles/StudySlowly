/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// inline3.cpp
#include "add.h"
/*
#include�� add.h�� �ִ� ������ �׳� ���� �ؿ��� ���̴�
int Add1(int a, int b);
inline int Add2(int a, int b);

���� add.h�� ���� ���Ҵٸ� �׳� ���͸� �����ؿ��� ���̴�
�׷��� Add2�� inline���� ������������� �ش� ���� �ڵ带 �����Ͻð��� �����;� �Ǵµ� ������ �� �� ����.
*/

int main()
{
	Add1(1, 2); // call (4����Ʈ�����) <-ȣ���̱� ������ �����Ͻð����� ������ ����, Add1 �ּҸ� ���߿� ��Ŀ�� ä����
	Add2(1, 2); // inline�̱� ������ ������ �ð��� �ٷ� �����;� �� = internal linkage
}
