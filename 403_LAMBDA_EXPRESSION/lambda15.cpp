
int main()
{
	int(*f)(int, int) = [](int a, int b) 
	{
		return a + b; 
	};

	//// 람다가 함수 포인터로 암시적 형변환 가능하다는 것은?
	//// 그 안에 변환 연산자가 있다는 뜻이다. 
	/* 기본 형식
	class ClosureType
	{
	public:
		int operator()( int a, int b ) const
		{
			return a + b;
		}

		static int method ( int a, int b )
		{
			return a + b;
		}

		typedef int ( *F )( int, int );

		//// 함수 포인터로의 변환 연산자
		operator F()
		{
			return &ClosureType::method;
		}
	};
	*/

	int v = 0;

	// capture 구문을 사용하면
	// 함수포인터로 암시적 변환 될수 없다.
	int(*f1)(int, int) = [v](int a, int b)			////  <- 이게 문제가 되는 이유, 아래 참조
	{
		return a + b + v;
	};


	/* 캡쳐가 추가된다면?
	class ClosureType
	{
		int v; <- 추가
	public:
	int operator()( int a, int b ) const
	{
	return a + b + v; <-이거 가능
	}

	static int method ( int a, int b )
	{
	return a + b + v ; <- 이거 불가능, Class의 static 멤버 함수는 멤버 변수에 접근할 수 없기 때문에
	}

	typedef int ( *F )( int, int );

	//// 함수 포인터로의 변환 연산자
	operator F()
	{
	return &ClosureType::method;
	}
	};
	*/
}
