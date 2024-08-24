// GraphSearch, BFS, DFS > DFS와 BFS(1260번)
// 풀이 시간 : 30
// 걍 그래프를 BFS, DFS로 탐색하는 문제(정점 번호가 작은 것부터 방문)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, startV;
bool graph[1001][1001] = { false, };
bool isVisited[1001] = { false, };

void BFS(int sV)
{
	bool isVisited[1001] = {false,};
	queue<int> q;

	q.push(sV);
	isVisited[sV] = true;

	while (!q.empty())
	{
		int vertex = q.front();
		cout << vertex << ' ';
		q.pop();
		// 연결되어 있는 vertex 찾기
		for (int i = 1; i <= n; i++)
		{	
			// 연결되어 있고 방문 안했으면 탐색
			if (graph[vertex][i] && !isVisited[i])
			{
				q.push(i);
				isVisited[i] = true;
			}
		}
	}
}

void DFS(int vertex)
{
	isVisited[vertex] = true;
	cout << vertex << ' ';

	for (int i = 1; i <= n; i++)
	{
		if (graph[vertex][i] && !isVisited[i])
		{
			DFS(i);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> n >> m >> startV;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}

	// DFS, BFS 탐색
	DFS(startV);
	cout << endl;
	BFS(startV);

}