
int main()
{
	int(*f)(int, int) = [](int a, int b) 
	{
		return a + b; 
	};

	//// ���ٰ� �Լ� �����ͷ� �Ͻ��� ����ȯ �����ϴٴ� ����?
	//// �� �ȿ� ��ȯ �����ڰ� �ִٴ� ���̴�. 
	/* �⺻ ����
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

		//// �Լ� �����ͷ��� ��ȯ ������
		operator F()
		{
			return &ClosureType::method;
		}
	};
	*/

	int v = 0;

	// capture ������ ����ϸ�
	// �Լ������ͷ� �Ͻ��� ��ȯ �ɼ� ����.
	int(*f1)(int, int) = [v](int a, int b)			////  <- �̰� ������ �Ǵ� ����, �Ʒ� ����
	{
		return a + b + v;
	};


	/* ĸ�İ� �߰��ȴٸ�?
	class ClosureType
	{
		int v; <- �߰�
	public:
	int operator()( int a, int b ) const
	{
	return a + b + v; <-�̰� ����
	}

	static int method ( int a, int b )
	{
	return a + b + v ; <- �̰� �Ұ���, Class�� static ��� �Լ��� ��� ������ ������ �� ���� ������
	}

	typedef int ( *F )( int, int );

	//// �Լ� �����ͷ��� ��ȯ ������
	operator F()
	{
	return &ClosureType::method;
	}
	};
	*/
}
