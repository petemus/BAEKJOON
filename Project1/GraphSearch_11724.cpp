// �׷��� Ž��, DPS, BFS > ���� ����� ����(11724��)
// Ǯ�� �ð� : 30m... ���� ����...


#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool graph[1001][1001] = {false,};
bool isVisited[1001]= {false,};


void DFS(int node)
{
	// �ش� ��� �湮
	for (int i = 1; i <= n; ++i)
	{
		// �湮���� �ʾҾ��� ����Ǿ� ������ �湮
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

	// �׷���, ������ ���� ���� ����
	// �湮 üũ �迭 �ʿ� (N�� ������ŭ)
	// ��� ��� �湮���� �ʾ����� �湮(DFS)

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	// ��� ��� �湮 -> DFS
	int connect = 0;
	for (int i = 1; i <= n; ++i)
	{
		// �湮���� �ʾ����� �湮
		if (!isVisited[i])
		{
			isVisited[i] = true;
			++connect;
			DFS(i);
		}
	}

	cout << connect;

}