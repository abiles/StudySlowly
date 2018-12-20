#include <iostream>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0;

	//// 캡쳐된 지역변수를을 변경하려고 했기 때문에
	//auto f1 = [v1, v2]() { v1 = 10; v2 = 20;};// error 
	
	// mutable lambda : () 연산자 함수를 비상수 함수로 
	//// 자동으로 const 써주는 부분을 뺐다는 얘기
	//// operator()() const -> operator()()
	auto f1 = [v1, v2]() mutable { v1 = 10; v2 = 20; };

	f1(); // 람다 표현식 실행..

	cout << v1 << endl; // 0	//// 람다에서 복사본을 수정했기 때문에 원본은 바뀐게 없다.
	cout << v2 << endl; // 0

}