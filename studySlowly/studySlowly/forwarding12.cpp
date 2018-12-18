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
	void setData ( const Data& d ) { data=d; } //// �̰� rvalue ���ڿ��� copy �Ҹ���

	void setData ( const Data& d ) { data=move ( d ); }	//// �̷��� �ص� copy, �����ü�� move �� �� ���� ������
};


class Test2
{
	//// 1. move setter�� copy setter�� ������ ����
	//// ����, ������尡 ����
	//// ����, �Լ��� 2�� �����ؾ��Ѵ�
	Data data;
public:
	//// lvalue��
	void setData ( const Data& d ) { data=d; } 

	//// rvalue��
	void setData (  Data&& d ) { data=move ( d ); }
};

class Test3
{
	//// 2. call by value�� ����ϴ� ���
	//// ����, �Լ� 1��
	//// ����, �ణ�� �������(move 1ȸ)
	Data data;
public:
	
	//// call by value
	void setData (  Data d ) { data=d; }
	// lvalue�� Copy����, move����		//// move �ѹ��� �������
	// rvalue�� Move����, move����		//// move �ѹ��� �������
};


class Test4
{
	//// 3. forwarding ref�� ����ϴ� ���
	//// ����, ������尡 ���� �ϳ��� �Լ� ���ø��� �����ϸ� �ȴ�.
	//// ����, ���ø��̴ϱ� side effect ���, �� �������� �����غ��� Data�� �ƴ� Ÿ�Ե� setData�� �����ٰ� ������ ���� �ִ�
	Data data;
public:

	template <typename T> void setData ( T&& a )
	{
		//data=a;	//// �׻� copy
		//data = move(a); //// �׻� move

		data	=	std::forward<T>(a);		//// ���ܰ踦 Ȯ���ؼ� �����ش޶�~
	}


};

int main ()
{
	Test test;

	Data d;
	test.setData ( d );					//// ���� �Ŀ��� d  ��� ����
	test.setData ( move ( d ) );		//// ���� �Ŀ��� d  ��� �Ұ�
}