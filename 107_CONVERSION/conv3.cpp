/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;
//// 변환 연산자의 장점

// RAII : Resource Acquision Is Initialization
//// 생성자에서 할당 소멸자에서 해제, 나중에 더 자세히 배움
class OFile
{
	FILE* file;
public:
	OFile(const char* filename, const char* mode = "wt")
	{
		file = fopen(filename, mode);
	}
	~OFile() {	fclose(file);	}

	operator FILE*() { return file; }
	//// 평소의 나였다면 Getter를 만들었을 것 같긴 하네
	//// 예전에 C를 만들었던거를 C++로 돌릴 때 사용했으니 옛날 오픈소스에는 이런게 많이 남아 있다
};

int main()
{
	OFile f("a.txt");

	// C 함수를 사용해서 화일 작업
	fputs("hello", f); //// 기본적으로 여기서 넘어가는 f는 파일포인터이지 OFile이 아니다
							    //// 이게 되게 하려면 OFile이 파일 포인터로 암시적 변환이 되어야 한다.
	fprintf(f, "n = %d", 10);	// OFile => FILE* 로 암시적 변환되면 가능.
							// f.operator FILE*()
	
	String s1 = "hello";
	char s2[10];

	strcpy(s2, s1); // String => const char* 암시적 변환..
	//// operator const char*() 라는 변환 연산자를 제공했겠지
}









/*
int main()
{
	FILE* f = fopen("a.txt", "wt");

	fputs("hello", f);

	if (....)
		return false;

	//fclose(f);
}
*/















