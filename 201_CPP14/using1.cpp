


//typedef int DWORD;
//typedef void(*FP)(int);

using DWORD = int;
using FP = void(*)(int);

//// using�� �� ��������?
template<typename T> struct Point
{
	T x, y;
};

typedef Point Pixel; // ??? error //// Point�� �̹� ��������� �ƴϾ��� ������(����� ���ø� �����̱� ������)

template<typename T>
using Pixel=Point<T>;

//// using vs typedef
/*
typedef : Ÿ�Կ� ���ؼ��� ��Ī�� ���� �� �ִ�
using     : Ÿ�� �� �ƴ϶� ���÷��� ���� ��Ī�� ���� �� �ִ�, template alias

using ���� �⺻���
using id = type-id;

template<template-parameter-list>
using id = type-id;
*/

int main()
{
	DWORD n; // int
	FP    p; // void(*p)(int)

	Point<int> p1;
	Pixel<int> p2; // Point<int> p2
	//// �� �� Pixel �̶�� �׳� �� ���� ���� �翬��. ��򰡿��� T�� ������� �ϴϱ�
}
