// Brute Force > ���� �ѹ�(4673��)

#include <iostream>
using namespace std;

int constructNum(int n)
{
	int result = n;
	do
	{
		result += n % 10;
		n = n / 10;
	} while (n != 0);

	return result;
}

bool isSelfNum(int n)
{
	for (int i = 1; i <= n; i++)
	{
		// i�� n�� ���������� Ȯ��
		if (constructNum(i) == n) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 10^4�̰� ���� for���̴ϱ� 10^8 = 1000�� => 1�� �ȿ� ����
	int n = 10000;

	// �� �� üũ
	for (int i = 1; i <= n; i++)
	{
		if (isSelfNum(i)) cout << i << '\n';
	}

}