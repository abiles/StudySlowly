#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void printv(T v)
{
	//// if  (is_pointer<T>::value)	 이것과는 뭐가 다를까
	//// if문은 실행시간 메커니즘이다
	//// 비록 if( is_pointer<int>::value)가 if(false) 라고 컴파일 시간에 돼도
	//// 컴파일러 입장에서는 그 런타임에 바뀔수 있을지도 모른다고 생각
	//// 그래서 cout << v << " : " << *v << endl; 컴파일 하려고 하는데
	//// v가 포인터가 아닐수도 있다고 생각하기 때문에 *v에서 오류냄

	//// static_if, 이부분은 컴파일 시간에 확정이라고 알려주는 keyword
	//// if constexpr ( v== 10 ) 이런건 안되겠죠? v가 컴파일 시간에 확정이 안되기 때문에
	if constexpr (is_pointer<T>::value)	
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}