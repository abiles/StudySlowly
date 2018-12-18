#include <iostream>
#include <functional>

using namespace std;

void foo ( int& a ) { a=30; }	//// 참조로 인자를 받음

template<typename F, typename T>
void chronometry ( F f, T arg )	//// 값으로 인자를 받고 ,ref를 사용하면 참조로 받게 만들자
{
	f ( arg );
}


/*
1. reference_wrapper
- 참조와 유사하게 동작하는 클래스 템플릿
- 참조로 변환 가능한 포인터
- 이동가능한 참조, png 파일 확인

2. ref, cref
- reference_wrapper를 생성하는 helper 함수
*/
template<typename T> struct xreference_wrapper
{
	T* ptr;
public:
	xreference_wrapper (T& r) : ptr ( &r ) {}

	operator T&( ) { return *ptr; }
};

template<typename T>
xreference_wrapper<T> xref ( T& obj )
{
	return xreference_wrapper<T> ( ojb );
}


int main ()
{
	int n=0;

	/////////////////////////////
	xreference_wrapper<int> ref ( n );	// 주소보관

	int& r	=	ref; // ref.operator int&();

	
	//// 1. 복사본을 만들고 싶지 않으니까 주소를 전달한다
	chronometry ( &foo, &n );
	//// 2. 주소가 넘어갈 때 참조로 암시적 형변환 된다면 원하는건 만들 수 있다.
	xreference_wrapper<int> r2 ( n );
	chronometry ( &foo, r2 );
	chronometry ( &foo, xreference_wrapper<int>(n) );
	chronometry ( &foo, xref ( n ) );
	






}