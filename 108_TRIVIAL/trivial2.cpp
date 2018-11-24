#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void copy_type(T* dst, T* arc, int sz)
{
	//// T가 멤버 변수로 포인터를 가지고 있다면 그냥 memcopy를 했을 때 포인터가 얕은 복사가 된다
	//// 따라서 복사생성자에서 해당 멤버 변수를 깊은 복사 할수 있도록 작업을 해놓았을 것이다라고 가정한다
	//// 이 후 복사 생성자가 trivial 이면(하는 일이 없으면) 그냥 memcpy를 하고
	//// 복사 생성자가 defaul가 아니면 복사생성자를 부르도록 하는 코드가 아래 내용이다

	if (is_trivially_copyable<T>::value)
	{
		cout << "복사 생성자가 trivial" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "복사 생성자가 trivial 하지 않은 경우" << endl;
		while (sz--)
		{
			new(dst) T(*src);  //// dst 위치에 src의 값을 통해서 복사생성자를 부르는
			++dst, ++src;
		}
	}
}


//// 안드로이드 프레임 워크에서는 Trivial할 때와 하지 않을 때를 분리한다
//// enalbe_if<B, C> 는 B 조건이 참일 때 C라는 타입을 꺼내주는 방식, default C는 void이다
//// 아마 컴파일러는 템플릿을 선택할 때 enable_if 첫번째 조건문이 만족하지 않는애는 선택하지 않겠지
template<typename T> 
typename enable_if< is_trivially_copyable<T>::value::type > 
copy_type ( T* dst, T* arc, int sz )
{
		cout << "복사 생성자가 trivial" << endl;
		memcpy ( dst, src, sizeof ( T )*sz );
}

template<typename T>
typename enable_if< !is_trivially_copyable<T>::value::type > 
copy_type ( T* dst, T* arc, int sz )
{
		cout << "복사 생성자가 trivial 하지 않은 경우" << endl;
		while ( sz-- )
		{
			new( dst ) T ( *src );  
			++dst, ++src;
		}
}

int main ()
{
	char s1[ 10 ]="hello";
	char s2[ 10 ]={ 0, };

	copy_type ( s1, s2, 10 ); //// 모든 타입의 배열을 복사하는 함수
}