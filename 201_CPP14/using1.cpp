


//typedef int DWORD;
//typedef void(*FP)(int);

using DWORD = int;
using FP = void(*)(int);

//// using은 왜 나왔을까?
template<typename T> struct Point
{
	T x, y;
};

typedef Point Pixel; // ??? error //// Point는 이미 만들어진게 아니었기 때문에(현재는 템플릿 형태이기 때문에)

template<typename T>
using Pixel=Point<T>;

//// using vs typedef
/*
typedef : 타입에 대해서만 별칭을 만들 수 있다
using     : 타입 뿐 아니라 템플렛에 대한 별칭도 만들 수 있다, template alias

using 문법 기본모양
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
	//// 쓸 때 Pixel 이라고 그냥 쓸 수는 없지 당연히. 어딘가에서 T는 정해줘야 하니까
}
