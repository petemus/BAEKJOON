// simulation > 달팽이(1913번)
// 풀이 시간 :
// 걍 규칙 찾아서 구현하는 문제

#include <iostream>
using namespace std;

int snail[1000][1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, find;
	// 상, 우, 하, 좌 순서
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
				// 범위 벗어나면 종료
				if (y < 0 || y >= n || x < 0 || x >= n) isFinish = true;
				else
				{
					// 숫자 넣어줌
					snail[y][x] = ++num;
				}
			}
			// 방향 바꿔주기
			dirIdx = (dirIdx + 1) % 4;
		}
		++move;
		
	}

	// 출력
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