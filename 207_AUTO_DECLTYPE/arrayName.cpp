/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	//// ���𹮿��� ������ �̸��� ���� ������ Type�� �ȴ�
	int n;		//// ���� �̸� : n, Ÿ�� : int, 
	
	int* p = &n;
	
	double d; //// ���� �̸� d, Ÿ�� : double

	int x[ 3 ]={ 1,2,3 }; //// ���� �̸� x, Ÿ�� : int [3]

	//// �迭 x�� �ּ�
	//// ? p1 = &x;
	int(* p1)[ 3 ]=&x; ////[]�� ������ ������ ���Ƽ� ��ȣ�� ����ߵ�
	//// �̰� �迭�� �ּҴ�

	int* p = x; //// �̰Ŵ� �׷� �����ϱ�?

	///////////// part2

	int n1=10;
	int n2=n1; //// ��� ������ �ڽŰ� ������ Ÿ���� ������ �ʱ�ȭ �� �� �ִ�.

	int x1[ 3 ]={ 1,2,3 };
	int x2[ 3 ]=x1; //// error, �迭�� �޸𸮸� ���� ����ϱ� ������ �ڽŰ� ������ Ÿ���� �迭�� ���簡 �ȵ�

	int* p2=x1; // �迭�� �̸��� ù��° '���'�� �ּҷ� �Ͻ��� ����ȯ �ȴ�.

	//// �迭�� �ּҴ� ���� �迭�� ����� �ּҴ� �����ϱ�?

	int x3[ 3 ]={ 1,2,3 };
	int ( *p3 )[ 3 ]=&x3; //// �迭�� �ּ�

	int *p4=x; //// �迭�� �̸��� �迭�� ù��° ����� �ּҷ� �Ͻ��� ����ȯ�� ǥ��

	//// p3�� p4�� ����Ű�� �ּҴ� �Ȱ���
	//// �׷��� p3+1 != p4+1 �̴�.
	////  �ֳ��ϸ� �ּ� + 1�ϸ� �ڽ��� ũ�⸸ŭ Ŀ���µ� ������ ����Ű�� �ִ°� �迭�� �迭�� ��ҷ� �ٸ��� ������!

	//// p3�� �迭�� �ּ� *p3 = �迭�� ����
	( *p3 )[ 0 ]=10;

	//// p4�� ����� �ּ� (int*)
	*p2=10;
}