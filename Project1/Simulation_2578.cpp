// Simulation > 빙고 (2578번)
// 풀이 시간 : 20m

#include <iostream>
using namespace std;

int board[5][5];
bool isCheck[5][5] = { false, };

void checkBoard(int n)
{
	// n 값을 가지는 board check
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
	// 가로, 세로, 대각선 빙고 개수 확인
	int bingo = 0;

	for (int i = 0; i < 5; i++)
	{
		// 모두 불렸으면 bingo + 1
		if (isCheck[i][0] && isCheck[i][1] && isCheck[i][2] && isCheck[i][3] && isCheck[i][4]) ++bingo;
		if (isCheck[0][i] && isCheck[1][i] && isCheck[2][i] && isCheck[3][i] && isCheck[4][i]) ++bingo;
	}
	// 대각선 계산 
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
	

	// 빙고 부름
	int result = 0;
	for (int i = 0; i < 25; i++)
	{
		int n;
		cin >> n;
		checkBoard(n);

		// 빙고 확인
		if (!result)
		{
			int v = countBingo();
			if (3 <= v) result = i + 1;
		}
	}

	cout << result;

}