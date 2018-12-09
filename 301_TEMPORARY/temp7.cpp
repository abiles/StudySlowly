int x = 0;

int  foo() { return x; }
int& goo() { return x; }

//// 사용자 정의타입말고 표준 타입도 동일하게 적용된다는 것을 보여주기 위한 예제
int main()
{
	foo() = 10; // error
	goo() = 10; // ok
}