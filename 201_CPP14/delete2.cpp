//// �Լ��� �����ϴ� �پ��� ���
template<typename T> void goo(T a)
{
}

//void goo(double) = delete;

class Mutex
{
public:

	Mutex(const Mutex&) = delete;
	void operator=(const Mutex&) = delete;	//// ����, ���簡 �ȵǸ� ���Ե� �ȵǰ� �ؾ� ��

//// ������ ���� ������ ���� ���, ������ �ƴ϶� ��ũ��
//private:
//	Mutex(const Mutex&);
};

int main()
{
	//// 1. �Ϲ� �Լ��� ���ø� �Լ����� ���� �Ҹ��� ������ void goo(double) = delete; �� ������ �� �ؿ��� ������
	goo(3.4);


	//// 2. Mutex�� ���� �����ڸ� ����� �� ����. 
	Mutex m1;
	Mutex m2 = m1; // ���� ������.
}