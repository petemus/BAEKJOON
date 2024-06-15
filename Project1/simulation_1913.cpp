// simulation > ������(1913��)
// Ǯ�� �ð� :
// �� ��Ģ ã�Ƽ� �����ϴ� ����

#include <iostream>
using namespace std;

int snail[1000][1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, find;
	// ��, ��, ��, �� ����
	int dirX[] = { 0, 1, 0, -1 };
	int dirY[] = { -1, 0, 1, 0 };

	cin >> n >> find;

	int x = n / 2, y = n / 2;

	int num = 1;
	int dirIdx = 0;
	snail[y][x] = num;
	
	bool isFinish = false;
	int move = 1;

	while (true)
	{
		if (isFinish) break;

		for (int i = 0; i < 2; i++)
		{
			for (int i = 0; i < move; i++)
			{
				x += dirX[dirIdx];
				y += dirY[dirIdx];
				// ���� ����� ����
				if (y < 0 || y >= n || x < 0 || x >= n) isFinish = true;
				else
				{
					// ���� �־���
					snail[y][x] = ++num;
				}
			}
			// ���� �ٲ��ֱ�
			dirIdx = (dirIdx + 1) % 4;
		}
		++move;
		
	}

	// ���
	int findY, findX;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << snail[i][j] << ' ';
			if (find == snail[i][j])
			{
				findX = j;
				findY = i;
			}
		}
		cout << '\n';
	}
	cout << findY + 1 << ' ' << findX + 1;
}