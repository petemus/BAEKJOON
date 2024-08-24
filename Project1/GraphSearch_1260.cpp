// GraphSearch, BFS, DFS > DFS�� BFS(1260��)
// Ǯ�� �ð� : 30
// �� �׷����� BFS, DFS�� Ž���ϴ� ����(���� ��ȣ�� ���� �ͺ��� �湮)

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
		// ����Ǿ� �ִ� vertex ã��
		for (int i = 1; i <= n; i++)
		{	
			// ����Ǿ� �ְ� �湮 �������� Ž��
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

	// �Է�
	cin >> n >> m >> startV;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}

	// DFS, BFS Ž��
	DFS(startV);
	cout << endl;
	BFS(startV);

}