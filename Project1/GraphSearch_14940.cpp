//  > 쉬운 최단거리(14940번)
// 풀이 시간 : 40m (반례 신중하게 생각!)

// BFS
// 목표 지점에서부터 BFS 돌리면 될듯 
// Point1> 반례 조심 -> 갈 수 없는 위치는 0으로 출력해줘야 함..! bfs일때 하면 일부는 안들어감 => 걍 마지막에 해줘야 함. 


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> dis;

void BFS(int gX, int gY)
{
	
	// 방향 배열
	int dirX[4] = {0, 0, 1, -1};
	int dirY[4] = {1, -1, 0, 0};
	// 방문 체크 배열 
	vector<vector<bool>> isVisitied(n, vector<bool>(m, false));

	// 큐
	queue<pair<int,int>> q;

	// 초기값
	q.push({gX, gY});
	isVisitied[gY][gX] = true;
	dis[gY][gX] = 0;

	// BFS
	while (!q.empty())
	{
		pair<int,int> nowPos = q.front();
		q.pop();

		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int nextX = nowPos.first + dirX[i];
			int nextY = nowPos.second + dirY[i];

			// 그 위치 갈 수 있는지 체크
			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
			{
				// 방문하지 않았으면 그 값 넣어주기 
				if (!isVisitied[nextY][nextX])
				{
					// 갈 수 없는 곳이면 0 대입
					if (map[nextY][nextX] == 1)
					{
						// 거리 넣어주기 + 큐에 넣어주기 + 방문 체크
						dis[nextY][nextX] = dis[nowPos.second][nowPos.first] + 1;
						q.push({ nextX, nextY });
						isVisitied[nextY][nextX] = true;
					}

				}
			}
		}

	}


}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> n >> m;

	// 배열 초기화
	map.resize(n, vector<int>(m, 0));
	dis.resize(n, vector<int>(m, -1));

	int gX = 0, gY = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int v;
			cin >> v;

			map[i][j] = v;

			if (v == 2)
			{
				// 골 인덱스 저장
				gY = i;
				gX = j;
			}
			
		}
	}

	// BFS로 거리 다 체크후 dis 배열 출력
	BFS(gX, gY);



	// output
	// 원래 갈 수 없는 곳 0으로 대입
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] == 0)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << dis[i][j] << ' ';
			}
		}
		cout << '\n';
	}





}