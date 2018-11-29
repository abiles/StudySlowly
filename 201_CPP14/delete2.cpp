//// 함수를 삭제하는 다양한 경우
template<typename T> void goo(T a)
{
}

//void goo(double) = delete;

class Mutex
{
public:

	Mutex(const Mutex&) = delete;
	void operator=(const Mutex&) = delete;	//// 문법, 복사가 안되면 대입도 안되게 해야 됨

//// 예전에 복사 생성자 막는 방식, 문법이 아니라 테크닉
//private:
//	Mutex(const Mutex&);
};

int main()
{
	//// 1. 일반 함수가 템플릿 함수보다 먼저 불리기 때문에 void goo(double) = delete; 가 있으면 이 밑에서 오류남
	goo(3.4);


	//// 2. Mutex는 복사 생성자를 사용할 수 없음. 
	Mutex m1;
	Mutex m2 = m1; // 복사 생성자.
}