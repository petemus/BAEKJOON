// Simulation > 아기 상어 (16236번)
// 풀이 시간 : 2h
// BFS 사용하여 최단 거리 이동하면서 푸는 구현 문제
// (-) 거리가 가까운 물고기가 여러마리일때 우선순위 물고기를 찾아줘야 함

#include <iostream>
#include <queue>
using namespace std;

struct Position
{
	int x;
	int y;
	Position(int y, int x)
	{
		this->x = x;
		this->y = y;
	}
	Position() {}
};

int n;		
int space[20][20];
int sharkSize = 2;
int eatFish = 0;
Position sharkPos;

int fishNum[7] = { 0, };		// 물고기 크기에 따른 개수

// 상, 좌, 우, 하
int dirX[] = {0, -1, 1, 0};
int dirY[] = { -1, 0, 0, 1 };

//BFS
// 물고기를 찾는 데 걸린 시간 반환 
// 물고기 못찾으면 -1 반환 
int FindFish()
{
	// 위치 , 이동 시간 
	queue<pair<Position, int>> q;
	bool isVisited[20][20] = { false, };

	q.push({ sharkPos, 0 });
	isVisited[sharkPos.y][sharkPos.x] = true;

	// 큐가 비면 물고기를 못 먹음
	int shortX, shortY;
	int shortSec = 400;
	bool isFind = false;
	while (!q.empty())
	{
		pair<Position, int> nMove = q.front();
		q.pop();

		// 이동할 수 있는 곳들 push
		// 자기 size보다 작아야 함
		// 물고기 자기 크기 만큼 먹으면 크기 업
		for (int i = 0; i < 4; i++)
		{
			int nX = nMove.first.x + dirX[i];
			int nY = nMove.first.y + dirY[i];
			// 이동할 수 있는 방향인지 확인
			if (nX >= 0 && nX < n && nY >= 0 && nY < n)
			{
				// 방문한 공간인지 체크
				if (isVisited[nY][nX]) continue;

				// 빈 공간이거나 같은 크기의 물고기면 경로 Push
				if (space[nY][nX] == 0 || sharkSize == space[nY][nX])
				{
					q.push({ Position(nY, nX), nMove.second + 1 });
					isVisited[nY][nX] = true;
				}
				else if (sharkSize > space[nY][nX])
				{
					// 거리가 같을 때 우선순위 찾아줌 
					if (isFind && nMove.second == shortSec)
					{
						if (shortY > nY)
						{
							shortX = nX;
							shortY = nY;
						}
						else if (shortY == nY)
						{
							if (shortX > nX)
							{
								shortX = nX;
								shortY = nY;
							}
						}
						continue;
					}
					else if (isFind && nMove.second > shortSec) break;
					
					// 최단 거리에 있는 물고기를 처음 발견할때 
					shortX = nX;
					shortY = nY;
					shortSec = nMove.second;
					isFind = true;
					continue;
				}
				// 상어보다 크면 pass
				else continue;
			}
		}

	}

	if (isFind)
	{
		// 먹기
		eatFish++;
		// 크기 업뎃 
		if (eatFish == sharkSize)
		{
			++sharkSize;
			eatFish = 0;
		}
		// 상어보다 작으면 먹기
		// 먹을 수 있는 물고기가 여러 마리인지 체크
		// 여러 마리 중에 Y 가 가장 작고 X가 가장 작은 놈으로 먹기 
		// 상어 업뎃
		space[sharkPos.y][sharkPos.x] = 0;
		space[shortY][shortX] = 9;
		sharkPos.x = shortX;
		sharkPos.y = shortY;
		return shortSec + 1;
	}
	else return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			space[i][j] = tmp;
			// fish 개수 증가
			if(tmp > 0 && tmp < 7)	fishNum[tmp]++;

			if (space[i][j] == 9) sharkPos = Position(i, j);
		}
	}

	// 먹을 수 있을 물고기가 없을때까지 실행
	// 큰 물고기에 의해 막혀있으면 못 먹음 
	// -> BFS로 계속 몰고기 잡아먹으러 감
	// -> 물고기 못 찾으면 break;

	int eatTime = 0;
	while (true)
	{
		// 먹으러 감
		int sec = FindFish();

		if (sec < 0) break;
		else eatTime += sec;

	}

	cout << eatTime;

}