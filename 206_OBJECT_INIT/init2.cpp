/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int cnt = 0;

class Test
{
public:
	//	int data = 0; // member initializer

	int data = ++cnt; //// 이렇게 하고 아래에서 Test t2(3) 하면 어떤 결과가 나올까?

	Test() {}
	Test(int n) {}  //: data(n) {} //// 이런식으로 명시적으로 data(n)을 해주면 int data = ++cnt;는 작동하지 않는다
												//// data(n), 이게 없으면 작동함
};

int main()
{
	Test t1;		// data = 1		//// 여기서 ++cnt 할거고
	Test t2(3);	// data = 3		//// 여기서도 조건에 따라 ++cnt 할수도 있고 안 할수도 있고, 그 조건은 위 내용 확인

	cout << cnt << endl; // 1

	cout << t1.data << endl;
	cout << t2.data << endl;
}
