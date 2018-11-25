/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

//// 변환 연산자의 위험성, 단점

class OFile
{
	FILE* file;
public:

	//// OFile(const char* filename, const char* mode = "wt") <- 인자가 2개짜리로 보이지만 default 값이 있기 때문에 1개짜리로 사용될 수 있다
	//// 따라서 변환 생성자 기능을 할 수 있다. 생성자에 의한 암시적 형변환은 의도치 않은 결과를 보일 수 있기 때문에
	//// explicit를 붙여서 문제를 방지한다.
	// explicit 생성자 : 인자가 한개인 생성자(C++ 11이후로는 1개 이상)가 암시적 변환을
	// 허용하는 것을 막는다.
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

	//foo("hello"); // const char* => OFile 로 암시적 변환 발생.
							// 변환 생성자
							//// 변환 생성자를 통해서 hello라는 파일을 쓰기모드로 연 다음에 OFile 임시객체를 만들어서 foo 함수에 진입하겠군
							// foo(static_cast<OFile>("hello")); <- 명시적 캐스팅은 사용 가능

}


















