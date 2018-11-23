/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct stream_buf
{
	stream_buf(size_t sz) 
	{ 
		cout << "stream_buf" << endl; 
	}
};
struct stream
{
	stream(stream_buf& buf) 
	{
		cout << "stream : using stream_buf" << endl; 
	}
};

// 버퍼를 가지고 있는 stream
//// ( 스트림이랑 버퍼를 따로 가지고 있으면 불편하니까 안에 가지고 있게 한다)
struct mystream : public stream
{
	stream_buf buf;
public:
	mystream(int sz) : buf(sz), stream(buf) {} //// <- 내가 코드상으로 초기화 리스트에 어떻게 써도 결국에는 기반 클래스가 먼저 생성자를 부르기 때문에 buf가 생성자를 부르기 전에 가져다 쓰려고 하니까 버그남
};


int main()
{
//	stream_buf buf(1024);
//	stream st(buf);

	mystream mst(1024);
}