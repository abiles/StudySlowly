/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

//// protected constructor
//// �ڽ��� ��ü�� ���� �� ������( �߻����� ����), �Ļ�Ŭ������ ��ü�� ���� �� �ְ� �Ѵ�. ( �������̽� �������̷���?)
//// animal�� ���ǿ� ���ݾ�, �̷� ������ ������ �������°ǰ�, ����, ���Ǹ� �����´ٴ� �����ΰ� ����
//// ����� �߻� Ŭ���� �����ɷ� ����������� protected �����ڸ� ����Ҽ� �ִ�
//// ���� ���� �ҽ����� �ֻ��� Ŭ������ �����ڴ� protected�� ����

class Animal
{
protected:   //// <-- �� �κ��� public �� ���� protected �� ���� �� �˾ƾߵ�
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() : Animal() {}
};

int main()
{
	// ������ ������ ��� ��� ������.
	Animal a; // error.
	Dog    d; // ok..
}