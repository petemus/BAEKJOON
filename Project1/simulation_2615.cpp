// simulation, brute Force > 오목(2615번)
// 풀이 시간  : 3~40m
// 현재 인덱스 이후의 방향으로만 확인하면 됨
// 6개 넘어가면 실패임 무조건 5개임을 확인해야함 

#include <iostream>
using namespace std;

int board[20][20];
// 가장 왼쪽의 바둑알을 출력해야해서 왼 아래 대각이 아니라 오 위 대각을 해야함
// 탐색 방향 오른쪽, 오른 위 대각, 아래, 오른 아래 대각
int dirX[] = { 1, 1, 0, 1 };
int dirY[] = { 0, -1, 1, 1 };

int searchWin(int y, int x)
{
	// 4개의 방향으로 탐색
	// win 발견하면 발견한 바둑돌 return
	// 없으면 0반환
	int winColor = board[y][x];
	for (int i = 0; i < 4; i++)
	{
		int nowX = x, nowY = y;

		// 반대가 같지 않은지 확인
		if (board[nowY - dirY[i]][nowX - dirX[i]] == winColor) continue;

		for (int j = 0; j < 5; j++)
		{
			nowX = nowX + dirX[i];
			nowY = nowY + dirY[i];

			if (board[nowY][nowX] != winColor)
			{
				// 발견
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


	// 전체 탐색
	bool isFinish = false;
	int winColor = 0;
	int winY = 0, winX = 0;
	for (int i = 0; i < 19; i++)
	{
		if (isFinish) break;

		for (int j = 0; j < 19; j++)
		{
			// 오목이 있으면 탐색
			if (board[i][j] != 0)
			{
				winColor = searchWin(i, j);
				// 발견하면 break
				if (winColor != 0)
				{
					isFinish = true;
					winY = i; winX = j;
					break;
				}
			}
		}
	}

	// 출력
	cout << winColor << '\n';
	if (winColor) cout << winY + 1 << ' ' << winX + 1;
}
