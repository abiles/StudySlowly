// ������
//// �ڽ��� +1�ϰ� ���� �����δ� ���� ���� ���;� ��
//// �������� temp�� ������ retrun �Ҽ� ���� ������ �� return�� �ؾ���
int operator++(int& n, int )
{
	int temp = n;
	n = n + 1;
	return temp;
}
// ������
int& operator++(int& n)
{
	n = n + 1;
	return n;
}
int main()
{
	int n = 3;
	n++; // operator++(n, int)
	++n; // operator++(n)

	++(++n); //// ���࿡ ���� retrun ���� �� ������ �����غ���
					//// ���� ������ retrun �� �� �ۿ� ����

	n++ = 10; // error, �ӽð�ü�� ������ ���� ����.
	++n = 10; // ok
}