// 후위형
//// 자신을 +1하고 리턴 값으로는 이전 값이 나와야 함
//// 지역변수 temp를 참조로 retrun 할수 없기 때문에 값 return을 해야함
int operator++(int& n, int )
{
	int temp = n;
	n = n + 1;
	return temp;
}
// 전위형
int& operator++(int& n)
{
	n = n + 1;
	return n;
}
int main()
{
	int n = 3;
	n++; // operator++(n, int)
	++n; // operator++(n)

	++(++n); //// 만약에 값을 retrun 했을 때 문제를 생각해보자
					//// 역시 참조를 retrun 할 수 밖에 없어

	n++ = 10; // error, 임시객체에 대입할 수는 없지.
	++n = 10; // ok
}