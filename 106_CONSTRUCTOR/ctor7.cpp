/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor7.cpp
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

// 버퍼만 관리하는 클래스
struct buf_manager
{
protected:  //// <- 파생클래스만 사용할 수 있도록 protected 를 해주고
	stream_buf buf;
public:
	buf_manager(size_t sz) : buf(sz) {}
};

struct mystream : public buf_manager, public stream   //// <- 순서 있게 상속하면 먼저 버퍼를 만들어서 초기화하고 나중에 stream을 초기화 할 때 buf를 가져다 쓰는 방식이 됨
{
public:
	mystream(size_t sz) : buf_manager(sz), stream(buf) {}
};


int main()
{
	mystream mst(1024);
}