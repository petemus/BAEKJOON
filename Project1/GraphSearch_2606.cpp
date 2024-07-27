// Graph Search > ���̷��� (2606��)
// Ǯ�� �ð�

#include <iostream>
#include <queue>
using namespace std;

int n;		// ��ǻ�� ��
bool graph[101][101] = { false, };

int virusCom = 0;
bool isVisited[101] = { false, };

int BFS(int a)
{
	isVisited[a] = true;
	queue<int> q;
	q.push(a);
	
	int virus = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (!isVisited[i] && graph[now][i])
			{
				// �湮���� �ʾҰ� ����Ǿ� ������ push
				++virus;
				isVisited[i] = true;
				q.push(i);
			}
		}
	}

	return virus;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int d;		// ����Ǿ� �ִ� ���� ��
	cin >> d;

	for (int i = 0; i < d; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}

	// 1�� ���� BFS
	cout << BFS(1);
}