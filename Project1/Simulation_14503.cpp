// Simulation > 로봇 청소기 (14503번)
// 풀이 시간 : 40 m
// 최소 이런 것을 찾는 게 아니라 걍 구현하는 거임

#include <iostream>
using namespace std;

int n, m;
char cells[50][50] = { 0, };
// index = 0 북, 동, 남, 서
int dirX[] = { 0, 1, 0, -1 };
int dirY[] = { -1, 0, 1, 0 };

// r, c의 네 방향 중에 더러운 곳이 있는지(청소할 수 있는지) 확인
bool isDirty(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		int nowX, nowY;
		nowX = c + dirX[i];
		nowY = r + dirY[i];
		if (nowX >= 0 && nowX < m && nowY >= 0 && nowY < n)
		{
			if (cells[nowY][nowX] == '0') return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int robotR, robotC, robotD;
	cin >> robotR >> robotC >> robotD;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> cells[i][j];
		}
	}


	// 작동이 멈출때까지 반복
	// 현재 칸 청소되지 않으면 청소
	// 빈칸 없으면 ->
	// 있으면 -> 
	bool isShoutdown = false;

	int cleanCells = 0;
	while (!isShoutdown)
	{	
		// 현재 칸 청소 되지 않으면 청소
		if (cells[robotR][robotC] == '0') {
			cells[robotR][robotC] = '.';
			cleanCells++;
		}

		int nextX, nextY;
		if (isDirty(robotR, robotC))
		{
			// 빈칸 있으면
			// 반시계로 90도 회전
			// 앞으 칸이 0이면 전진
			if (robotD == 0) robotD = 3;
			else robotD -= 1;
			nextX = robotC + dirX[robotD];
			nextY = robotR + dirY[robotD];
			// 움직일 수 있는지 index 체크
			if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
			{
				if (cells[nextY][nextX] == '0')
				{
					robotC = nextX;
					robotR = nextY;
				}
			}
		}
		else
		{
			// 빈칸 없으면 바라보는 방향을 유지한채 후진
			// 후진은 현재 dir에서 + 2 한 다음 % 4
			int backDir = (robotD + 2) % 4;
			nextX = robotC + dirX[backDir];
			nextY = robotR + dirY[backDir];
			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
			{
				// 후진 가능하면 백
				if (cells[nextY][nextX] != '1')
				{
					robotC = nextX;
					robotR = nextY;
				}
				else isShoutdown = true;
			}
		}
	}

	cout << cleanCells;

}