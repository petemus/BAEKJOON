// Tree, BFS, DFS > Ʈ���� �θ� ã�� (11725��)
// Ǯ�� �ð� : 12 40 

// point 1> ���� �θ����� �� -> �ϴ� �� ������ ���� -> 1���� �����ؼ� �湮 üũ�� �ϸ鼭 Backtracking 
//		!���� > ��� ã�������� Backtracking ���ָ� �ϵ� -> DFS�� ��ü ������ ���߿� ��� BFS ���� But pair�� ������� 
//		? �־��� ��� 10�� * 10�� �� ������ ������? => �ƴ� ������ ���� n-1, �θ� �ڽ� �ߺ��ؼ� ���ϱ� 2(n-1)����

#include <iostream>
#include <vector>	
#include <queue>
using namespace std;

// ��� ��
int n;
// �� ������ ����Ǿ� �ִ� �͵� 
vector<vector<int>> node;
// ����� �θ� ���� 
vector<int> childParent;

// BFS
// ��� �ڽ��� �θ� ��� �־��� 
void BFS()
{
	
	vector<bool> isVisited(n + 2, false);
	queue<int> q;

	//�ʱⰪ
	q.push(1);
	isVisited[1] = true;

	while (!q.empty())
	{
		int parent = q.front();
		q.pop();

		for (int i = 0; i < node[parent].size(); ++i)
		{
			//�湮���� ���� ��� �ڽ� Ž��
			int child = node[parent][i];
			if (!isVisited[child])
			{
				childParent[child] = parent;
				q.push(child);
				isVisited[child] = true;
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
	cin >> n;
	
	node.resize(n + 2);
	childParent.resize(n + 2);

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		// �� ��忡 �־��ֱ� 
		node[a].push_back(b);
		node[b].push_back(a);
	}

	// BFS�� ��� ����� �θ� ã���ֱ�
	BFS();

	// 2�� ������ ���������� ���
	for (int i = 2; i <= n; ++i)
	{
		cout << childParent[i] << '\n';
	}

}