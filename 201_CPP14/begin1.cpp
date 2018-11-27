#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

// �����̳��� ��� ��Ҹ� ����ϴ� �Լ�.
template<typename T> void show(T& c)
{
	//// �̷� ������ �ȸ���� ������ �Ϲ� �迭�� �ޱ� ���ؼ��̴�. 
	//// std::begin���� �ϸ� �Ϲ� �迭������ �ݺ��ڸ� ���� �� �ִ�
//	auto p1 = c.begin();  //// �����̳��� ��� �Լ� �� ����ϰ� �ֱ� ������ �Ϲ� �迭(raw array)������ ������ ��
//	auto p2 = c.end();

	auto p1 = begin(c); //// std::begin ���°� �ٽ��̴�
	auto p2 = end(c);

	while (p1 != p2)
	{
		cout << *p1 << endl;
		++p1;
	}
}

int main()
{
	list<int> c = { 1,2,3 };
	//vector<int> c = { 1,2,3 };
	
	show(c);

	int x[3] = { 1,2, 3 };

	show(x);

}