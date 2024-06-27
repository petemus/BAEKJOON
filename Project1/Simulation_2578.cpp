// Simulation > ���� (2578��)
// Ǯ�� �ð� : 20m

#include <iostream>
using namespace std;

int board[5][5];
bool isCheck[5][5] = { false, };

void checkBoard(int n)
{
	// n ���� ������ board check
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == n) isCheck[i][j] = true;
		}
	}
}

int countBingo()
{
	// ����, ����, �밢�� ���� ���� Ȯ��
	int bingo = 0;

	for (int i = 0; i < 5; i++)
	{
		// ��� �ҷ����� bingo + 1
		if (isCheck[i][0] && isCheck[i][1] && isCheck[i][2] && isCheck[i][3] && isCheck[i][4]) ++bingo;
		if (isCheck[0][i] && isCheck[1][i] && isCheck[2][i] && isCheck[3][i] && isCheck[4][i]) ++bingo;
	}
	// �밢�� ��� 
	if (isCheck[0][0] && isCheck[1][1] && isCheck[2][2] && isCheck[3][3] && isCheck[4][4]) ++bingo;
	if (isCheck[4][0] && isCheck[3][1] && isCheck[2][2] && isCheck[1][3] && isCheck[0][4]) ++bingo;

	return bingo;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> board[i][j];
		}
	}
	

	// ���� �θ�
	int result = 0;
	for (int i = 0; i < 25; i++)
	{
		int n;
		cin >> n;
		checkBoard(n);

		// ���� Ȯ��
		if (!result)
		{
			int v = countBingo();
			if (3 <= v) result = i + 1;
		}
	}

	cout << result;

}