// Brute Force > ������ (2563��)
// Ǯ�� �ð� :
// 1) ��ġ�� �͵� ����ؼ� ���ֱ� -> �Ұ���
// 2) ��ȭ�� ���� �˻� 

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// 100 * 100 ��ȭ����ŭ �˻�
	// ���̵��� ũ�⸸ŭ �����ϰ� 
	// �������� ��� ���ֱ�

	bool picture[100][100] = { false, };
	for (int i = 0; i < n; i++)
	{
		int r, c;
		cin >> r >> c;
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				picture[r - 1 + j][c - 1 + k] = true;
			}
		}
	}

	// �������� ���ֱ�
	int area = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (picture[i][j]) ++area;
		}
	}

	cout << area;
}