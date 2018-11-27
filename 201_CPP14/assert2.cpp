#include <iostream>
#include <mutex>
using namespace std;

//// static_assert의 활용
/*
함수 안에 만들수도, 밖에 만들수도 있다
함수 또는 클래스 템플릿을 만들 때 type_trait를 사용해서 T가 가져야 하는 조건을 static_assert로 조사하는 코드가 널리 사용됨
static_assert를 잘 활용하면 가독성 높은 에러 메시지를 만들 수 있다
*/


#pragma pack(1)
struct PACKET
{
	char cmd;
	int  data;
};
static_assert(
	sizeof(PACKET) == sizeof(char) + sizeof(int),
	"error, unexpected padding !");

//// struct가 5바이트로 만들어지면 효율이 떨어져서 패딩을 하게 되는데
//// 패킷을 전달할 때 괜한 패딩값을 보내고 싶지 않기 때문에 static_assert로 쓸데 없는 패딩이 생기는지 확인
//// 결국 이 패딩을 없애는 법을 알아야겠지용? #pragma pack(1) 하면 1바이트 단위로 패딩하기 때문에 static_assert 문제가 안생김


template<typename T> void Swap(T& a, T& b)
{
	// T가 가져야하는 조건을 조사
	static_assert(is_copy_constructible<T>::value,
		"error. T is not copyable");
	
	T tmp = a; //// 이 부분에서 복사 생성자가 필요하기 때문에 앞서 검사를 함
	a = b; //// 이것 때문에 복사 대입도 조사 해야 한다는데1
	b = tmp;
}

int main()
{
	mutex m1; //// mutex는 복사 생성자를 지원하지 않음
	mutex m2;
	Swap(m1, m2);
}