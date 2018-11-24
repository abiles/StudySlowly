#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void copy_type(T* dst, T* arc, int sz)
{
	//// T�� ��� ������ �����͸� ������ �ִٸ� �׳� memcopy�� ���� �� �����Ͱ� ���� ���簡 �ȴ�
	//// ���� ��������ڿ��� �ش� ��� ������ ���� ���� �Ҽ� �ֵ��� �۾��� �س����� ���̴ٶ�� �����Ѵ�
	//// �� �� ���� �����ڰ� trivial �̸�(�ϴ� ���� ������) �׳� memcpy�� �ϰ�
	//// ���� �����ڰ� defaul�� �ƴϸ� ��������ڸ� �θ����� �ϴ� �ڵ尡 �Ʒ� �����̴�

	if (is_trivially_copyable<T>::value)
	{
		cout << "���� �����ڰ� trivial" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "���� �����ڰ� trivial ���� ���� ���" << endl;
		while (sz--)
		{
			new(dst) T(*src);  //// dst ��ġ�� src�� ���� ���ؼ� ��������ڸ� �θ���
			++dst, ++src;
		}
	}
}


//// �ȵ���̵� ������ ��ũ������ Trivial�� ���� ���� ���� ���� �и��Ѵ�
//// enalbe_if<B, C> �� B ������ ���� �� C��� Ÿ���� �����ִ� ���, default C�� void�̴�
//// �Ƹ� �����Ϸ��� ���ø��� ������ �� enable_if ù��° ���ǹ��� �������� �ʴ¾ִ� �������� �ʰ���
template<typename T> 
typename enable_if< is_trivially_copyable<T>::value::type > 
copy_type ( T* dst, T* arc, int sz )
{
		cout << "���� �����ڰ� trivial" << endl;
		memcpy ( dst, src, sizeof ( T )*sz );
}

template<typename T>
typename enable_if< !is_trivially_copyable<T>::value::type > 
copy_type ( T* dst, T* arc, int sz )
{
		cout << "���� �����ڰ� trivial ���� ���� ���" << endl;
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

	copy_type ( s1, s2, 10 ); //// ��� Ÿ���� �迭�� �����ϴ� �Լ�
}