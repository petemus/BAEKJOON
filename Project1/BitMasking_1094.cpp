// BitMasking, ����  > ����� (1094��)

// 1 : 01
// 2 : 10
// 4 : 100
// 8 : 1000
// 16: 10000
// 32: 100000
// 64: 1000000
// x ���� 1,.. 64�� ���ڷ� �����Ͽ� ���� �� ���� -> ex) 32 + 8 + 2 = 42
// ! ���� ���� �ߺ��� �� ����
// ������ x���� �������� �� �ڸ����� �������� �Ǿ� ���� -> �� �ڸ� ���� ������  ���ϸ� �� 


#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;

	// 64 �ڸ����� ������
	int cnt = 0;
	for (int i = 0; i < 8; ++i)
	{
		if (x & (1 << i))
		{
			// �ڸ� �������� üũ
			++cnt;
		}
	}

	cout << cnt;


}