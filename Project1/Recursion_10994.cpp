// Recursioin > �� ��� (10994��)

#include <iostream>
using namespace std;

char arr[397][397];

void Recursion(int n, int sY, int sX)
{
	// ���� ����
	if (n == 1)
	{
		arr[sY][sX] = '*';
		return;
	}

	// n�� ���� �־��ֱ�
	for (int i = sY; i < sY + n; i++)
	{
		arr[sY][i] = '*';
		arr[i][sX] = '*';
		arr[sY + (n - 1)][i] = '*';
		arr[i][sX + (n - 1)] = '*';
	}

	// ��� ȣ��
	Recursion(n - 4, sY + 2, sX + 2);
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �� �ʱ�ȭ
	for (int i = 0; i < 397; i++)
	{
		for (int j = 0; j < 397; j++)
		{
			arr[i][j] = ' ';
		}
	}

	int n; 
	cin >> n;

	// �� ����ȭ
	n = 4 * n - 3;

	Recursion(n, 0, 0);

	// ���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}

}