// Backtracking, BrouteForce, Simulation > 연구소 (14502번)
// 풀이 시간 : 1 h 10m
// 벽의 배치 가능한 경우의 수가 64C3이라는 것 -> 고려해서 Backracking 

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int lab[8][8];
int maxSafeZone = 0;

int checkSafeZone(int cpyLab[][8])
{
	int safeZone = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cpyLab[i][j] == 0)	++safeZone;
		}
	}
	return safeZone;
}

// BFS
// 바이러스 spread는 복사된 공간에서 spread
// 복사된 공간에서 safeZone 체크해줘야 함 
int spreadVirus()
{
	int cpylab[8][8];
	copy(&lab[0][0], &lab[0][0] + 64, &cpylab[0][0]);

	bool isVisited[8][8] = { false, };
	queue<pair<int, int>> virus;
	int dirX[] = {0, 0, 1, -1};
	int dirY[] = { 1, -1, 0, 0 };

	// 바이러스 찾고 큐에 넣어줌
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cpylab[i][j] == 2)
			{
				virus.push({ i,j });
				isVisited[i][j] = true;
			}
		}
	}

	// 바이러스 뿌려줌
	pair<int, int> next;
	while (!virus.empty())
	{
		next = virus.front();
		virus.pop();

		int nX, nY;
		for (int i = 0; i < 4; i++)
		{
			nX = next.second + dirX[i];
			nY = next.first + dirY[i];
			if (nX >= 0 && nX < m && nY >= 0 && nY < n)
			{
				if (!isVisited[nY][nX] && cpylab[nY][nX] == 0)
				{
					// 방문하지 않았고 빈 방이면 spread
					isVisited[nY][nX] = true;
					cpylab[nY][nX] = 2;
					virus.push({ nY, nX });
				}
			}
		}
	}
	return checkSafeZone(cpylab);
}


// Backtracking
void buildWall(int wallCnt, int parenti, int parentj)
{
	// 종료 조건 -> 3개 벽 다 세울때
	if (wallCnt == 3)
	{
		// 바이러스 퍼지기 + safezone 체크
		int safeZone = spreadVirus();
		// 최대 크기 확인 
		if (safeZone > maxSafeZone) maxSafeZone = safeZone;
		return;
	}

	// Backtracking
	// 부모벽의 오른쪽 인덱스부터 세줘야 함 -> 중복되지 않도록
	bool isFirst = false;
	for (int i = parenti; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == parenti && !isFirst) 
			{
				j += parentj;
				isFirst = true;
			}

			// 빈 공간이면 backracking
			if (lab[i][j] == 0)
			{
				lab[i][j] = 1;
				buildWall(wallCnt + 1, i, j);
				lab[i][j] = 0;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> lab[i][j];
		}
	}

	// Backtracking
	buildWall(0, 0, 0);

	// 출력
	cout << maxSafeZone;

}