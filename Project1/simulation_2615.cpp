// simulation, brute Force > ����(2615��)
// Ǯ�� �ð�  : 3~40m
// ���� �ε��� ������ �������θ� Ȯ���ϸ� ��
// 6�� �Ѿ�� ������ ������ 5������ Ȯ���ؾ��� 

#include <iostream>
using namespace std;

int board[20][20];
// ���� ������ �ٵϾ��� ����ؾ��ؼ� �� �Ʒ� �밢�� �ƴ϶� �� �� �밢�� �ؾ���
// Ž�� ���� ������, ���� �� �밢, �Ʒ�, ���� �Ʒ� �밢
int dirX[] = { 1, 1, 0, 1 };
int dirY[] = { 0, -1, 1, 1 };

int searchWin(int y, int x)
{
	// 4���� �������� Ž��
	// win �߰��ϸ� �߰��� �ٵϵ� return
	// ������ 0��ȯ
	int winColor = board[y][x];
	for (int i = 0; i < 4; i++)
	{
		int nowX = x, nowY = y;

		// �ݴ밡 ���� ������ Ȯ��
		if (board[nowY - dirY[i]][nowX - dirX[i]] == winColor) continue;

		for (int j = 0; j < 5; j++)
		{
			nowX = nowX + dirX[i];
			nowY = nowY + dirY[i];

			if (board[nowY][nowX] != winColor)
			{
				// �߰�
				if (j == 4) return winColor;
				else break;
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cin >> board[i][j];
		}
	}


	// ��ü Ž��
	bool isFinish = false;
	int winColor = 0;
	int winY = 0, winX = 0;
	for (int i = 0; i < 19; i++)
	{
		if (isFinish) break;

		for (int j = 0; j < 19; j++)
		{
			// ������ ������ Ž��
			if (board[i][j] != 0)
			{
				winColor = searchWin(i, j);
				// �߰��ϸ� break
				if (winColor != 0)
				{
					isFinish = true;
					winY = i; winX = j;
					break;
				}
			}
		}
	}

	// ���
	cout << winColor << '\n';
	if (winColor) cout << winY + 1 << ' ' << winX + 1;
}
