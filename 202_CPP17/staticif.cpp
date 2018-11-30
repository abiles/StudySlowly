#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void printv(T v)
{
	//// if  (is_pointer<T>::value)	 �̰Ͱ��� ���� �ٸ���
	//// if���� ����ð� ��Ŀ�����̴�
	//// ��� if( is_pointer<int>::value)�� if(false) ��� ������ �ð��� �ŵ�
	//// �����Ϸ� ���忡���� �� ��Ÿ�ӿ� �ٲ�� �������� �𸥴ٰ� ����
	//// �׷��� cout << v << " : " << *v << endl; ������ �Ϸ��� �ϴµ�
	//// v�� �����Ͱ� �ƴҼ��� �ִٰ� �����ϱ� ������ *v���� ������

	//// static_if, �̺κ��� ������ �ð��� Ȯ���̶�� �˷��ִ� keyword
	//// if constexpr ( v== 10 ) �̷��� �ȵǰ���? v�� ������ �ð��� Ȯ���� �ȵǱ� ������
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