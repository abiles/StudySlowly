/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

class Test
{
	int value;
public:
	//// Test ( int n ) : value ( n ) {} ���� �� ����ε� �Ͻ��� '����ȯ'�� �������ؼ� �Ʒ�ó�� ���
	//// explicit ���̸� '����'�� ���� ����� �� ������ '��ȯ'�� ���� ����� �� ���� �ȴ�.
	explicit Test(int n) : value(n) {}
};

int main()
{
	// �Ʒ� 2���� �������� ?
	
	Test t1(5);  //// ���ڰ� �Ѱ��� ������ ȣ��
					   //// direct initialization ( ��ȣ�� �̿��ؼ� �ʱ�ȭ �ϴ� ���)

	Test t2 = 5;  //// 1. ��ȯ �����ڸ� ����ؼ� 5�� ������ Test�� �ӽð�ü ���� ( ������ ù��°)
					     //// 2. �ӽð�ü�� ���� �����ڸ� ����ؼ� t2�� ���� (������ �ι�°)
						 //// �� �� ���� ���ļ� �ϰ� �ߴ����� �𸣰ڳ�, �ᱹ �޸� �������� Test��� ��ü�� �ϳ� ��Ƴ��� �ٷ� �ϴ��� 2�� ��Ƽ� �־��ִ����� �����ΰ�?
					     //// copy initialization ( = �� �̿��ؼ� �ʱ�ȭ �ϴ� ���)
}
