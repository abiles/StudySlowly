#include <iostream>
#include <functional>

using namespace std;

void foo ( int& a ) { a=30; }	//// ������ ���ڸ� ����

template<typename F, typename T>
void chronometry ( F f, T arg )	//// ������ ���ڸ� �ް� ,ref�� ����ϸ� ������ �ް� ������
{
	f ( arg );
}


/*
1. reference_wrapper
- ������ �����ϰ� �����ϴ� Ŭ���� ���ø�
- ������ ��ȯ ������ ������
- �̵������� ����, png ���� Ȯ��

2. ref, cref
- reference_wrapper�� �����ϴ� helper �Լ�
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
	xreference_wrapper<int> ref ( n );	// �ּҺ���

	int& r	=	ref; // ref.operator int&();

	
	//// 1. ���纻�� ����� ���� �����ϱ� �ּҸ� �����Ѵ�
	chronometry ( &foo, &n );
	//// 2. �ּҰ� �Ѿ �� ������ �Ͻ��� ����ȯ �ȴٸ� ���ϴ°� ���� �� �ִ�.
	xreference_wrapper<int> r2 ( n );
	chronometry ( &foo, r2 );
	chronometry ( &foo, xreference_wrapper<int>(n) );
	chronometry ( &foo, xref ( n ) );
	






}