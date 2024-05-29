// Backtracking, BrouteForce, Simulation > ������ (14502��)
// Ǯ�� �ð� : 1 h 10m
// ���� ��ġ ������ ����� ���� 64C3�̶�� �� -> ����ؼ� Backracking 

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
// ���̷��� spread�� ����� �������� spread
// ����� �������� safeZone üũ����� �� 
int spreadVirus()
{
	int cpylab[8][8];
	copy(&lab[0][0], &lab[0][0] + 64, &cpylab[0][0]);

	bool isVisited[8][8] = { false, };
	queue<pair<int, int>> virus;
	int dirX[] = {0, 0, 1, -1};
	int dirY[] = { 1, -1, 0, 0 };

	// ���̷��� ã�� ť�� �־���
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

	// ���̷��� �ѷ���
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
					// �湮���� �ʾҰ� �� ���̸� spread
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
	// ���� ���� -> 3�� �� �� ���ﶧ
	if (wallCnt == 3)
	{
		// ���̷��� ������ + safezone üũ
		int safeZone = spreadVirus();
		// �ִ� ũ�� Ȯ�� 
		if (safeZone > maxSafeZone) maxSafeZone = safeZone;
		return;
	}

	// Backtracking
	// �θ��� ������ �ε������� ����� �� -> �ߺ����� �ʵ���
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

			// �� �����̸� backracking
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

	// �Է�
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

	// ���
	cout << maxSafeZone;

}