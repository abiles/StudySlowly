/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// inline3.cpp
#include "add.h"
/*
#include는 add.h에 있는 내용을 그냥 복사 해오는 것이다
int Add1(int a, int b);
inline int Add2(int a, int b);

만약 add.h가 위와 같았다면 그냥 저것만 복사해오는 것이다
그래서 Add2가 inline으로 만들어져있으면 해당 기계어 코드를 컴파일시간에 가져와야 되는데 가져올 수 가 없다.
*/

int main()
{
	Add1(1, 2); // call (4바이트빈공간) <-호출이기 때문에 컴파일시간에는 공간만 마련, Add1 주소를 나중에 링커가 채워줌
	Add2(1, 2); // inline이기 때문에 컴파일 시간에 바로 가져와야 함 = internal linkage
}
