#include <iostream>
using namespace std;

void foo(int n)
{
	cout << "foo(int)" << endl;
}

//void foo(double); // 선언만
//// 암시적 형변환 일어났을 때 오류가 발생하도록
//// 이렇게하면 문제가 있을 때 컴파일 에러가 아니라 링크에러

//void foo(double) = delete; //// <- 이 함수를 삭제해 주세요 (함수삭제)
//// 컴파일 타임에 삭제된 함수를 사용하게 되면 에러가 발생한다

int main()
{
	foo(3.4); // foo(double) //// <- double이 int로 형변환이 가능하니까 foo(int)가 불린다(암시적 형변환)
}