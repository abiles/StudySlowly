/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

//// ��ȯ �������� ���輺, ����

class OFile
{
	FILE* file;
public:

	//// OFile(const char* filename, const char* mode = "wt") <- ���ڰ� 2��¥���� �������� default ���� �ֱ� ������ 1��¥���� ���� �� �ִ�
	//// ���� ��ȯ ������ ����� �� �� �ִ�. �����ڿ� ���� �Ͻ��� ����ȯ�� �ǵ�ġ ���� ����� ���� �� �ֱ� ������
	//// explicit�� �ٿ��� ������ �����Ѵ�.
	// explicit ������ : ���ڰ� �Ѱ��� ������(C++ 11���ķδ� 1�� �̻�)�� �Ͻ��� ��ȯ��
	// ����ϴ� ���� ���´�.
	explicit OFile(const char* filename, const char* mode = "wt")
	{
		file = fopen(filename, mode);
	}
	~OFile() { fclose(file); }

	operator FILE*() { return file; }
};

void foo(OFile f) {}

int main()
{
	OFile f("a.txt");
	foo(f); // ok..

	//foo("hello"); // const char* => OFile �� �Ͻ��� ��ȯ �߻�.
							// ��ȯ ������
							//// ��ȯ �����ڸ� ���ؼ� hello��� ������ ������� �� ������ OFile �ӽð�ü�� ���� foo �Լ��� �����ϰڱ�
							// foo(static_cast<OFile>("hello")); <- ����� ĳ������ ��� ����

}


















