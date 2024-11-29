// 그래프 탐색, DPS, BFS > 연결 요소의 개수(11724번)
// 풀이 시간 : 30m... 감을 잃음...


#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool graph[1001][1001] = {false,};
bool isVisited[1001]= {false,};


void DFS(int node)
{
	// 해당 노드 방문
	for (int i = 1; i <= n; ++i)
	{
		// 방문하지 않았었고 연결되어 있으면 방문
		if (!isVisited[i] && graph[node][i])
		{
			isVisited[i] = true;
			DFS(i);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 그래프, 간선에 대한 정보 저장
	// 방문 체크 배열 필요 (N의 개수만큼)
	// 모든 노드 방문하지 않았으면 방문(DFS)

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	// 모든 노드 방문 -> DFS
	int connect = 0;
	for (int i = 1; i <= n; ++i)
	{
		// 방문하지 않았으면 방문
		if (!isVisited[i])
		{
			isVisited[i] = true;
			++connect;
			DFS(i);
		}
	}

	cout << connect;

}