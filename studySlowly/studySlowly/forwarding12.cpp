#include <iostream>
#include <type_traits>
using namespace std;

class Data
{
public:
	Data () {}
	~Data () {}

	Data ( const Data& t )
	{
		cout << "Copy" << endl;
	}

	Data (  Data&& t ) noexcept
	{
		cout << "Move" << endl;
	}

	Data& operator= ( const Data& t )
	{
		cout << "Copy=" << endl;
		return *this;
	}

	Data& operator=( Data&& t ) noexcept
	{
		cout << "Move=" << endl;
		return *this;
	}
};

class Test
{
	Data data;
public:
	void setData ( const Data& d ) { data=d; } //// 이건 rvalue 인자여도 copy 불리죠

	void setData ( const Data& d ) { data=move ( d ); }	//// 이렇게 해도 copy, 상수객체는 move 될 수 없기 때문에
};


class Test2
{
	//// 1. move setter와 copy setter를 별도로 제공
	//// 장점, 오버헤드가 없다
	//// 단점, 함수를 2개 제공해야한다
	Data data;
public:
	//// lvalue용
	void setData ( const Data& d ) { data=d; } 

	//// rvalue용
	void setData (  Data&& d ) { data=move ( d ); }
};

class Test3
{
	//// 2. call by value를 사용하는 방법
	//// 장점, 함수 1개
	//// 단점, 약간의 오버헤드(move 1회)
	Data data;
public:
	
	//// call by value
	void setData (  Data d ) { data=d; }
	// lvalue시 Copy생성, move대입		//// move 한번의 오버헤드
	// rvalue시 Move생성, move대입		//// move 한번의 오버헤드
};


class Test4
{
	//// 3. forwarding ref를 사용하는 방법
	//// 장점, 오버헤드가 없고 하나의 함수 템플릿만 제공하면 된다.
	//// 단점, 템플릿이니까 side effect 고려, 이 예제에서 생각해보면 Data가 아닌 타입도 setData로 들어오다가 오류가 날수 있다
	Data data;
public:

	template <typename T> void setData ( T&& a )
	{
		//data=a;	//// 항상 copy
		//data = move(a); //// 항상 move

		data	=	std::forward<T>(a);		//// 전단계를 확인해서 전달해달라~
	}


};

int main ()
{
	Test test;

	Data d;
	test.setData ( d );					//// 실행 후에도 d  사용 가능
	test.setData ( move ( d ) );		//// 실행 후에는 d  사용 불가
}