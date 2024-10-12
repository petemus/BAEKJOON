// ���ͽ�Ʈ�� > ��Ƽ(1238��)
// ������ �ִ� �׷���


#include <iostream>
#include <queue>
using namespace std;

// Time�� �ִ밪�� 100�ε� �꺸�� Ŭ �� ����...
#define INF 2147483647

// n :���� ��(�����), m : ���� ��(�ܹ���), T(���), X ��������
int n, m, x;

// ���� �׷���
// 2���� �迭�� vector�� ���� �ð� �ξ� ���� 
// vector�� ����� -> first : ���, second : idx
//int graph[1001][1001] = {0,};
vector<pair<int,int>> graph[1001];

// ������ �ִܰ��
int minDis[1001] = { 0, };


// ���ͽ�Ʈ��
// start���� end������ �ִ� �Ÿ� ��ȯ 
int Dijkstra(int start, int end)
{
	// �켱���� ť
	// first : ���, second : ���� ���
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// �湮 üũ �迭 -> �� ���� Ž���Ҷ� ���� �ٸ��� ����ؾ���
	bool isVisitied[1001] = { false, };

	// distance �迭
	// start���� index�� ���� �ִ� ���
	int dis[1001] = { 0, };
	fill(dis, dis + n + 1, INF);


	// ù��° ��� �־��ֱ� 
	pq.push({0, start});
	dis[start] = 0;


	// while�� �ݺ�  
	while (!pq.empty())
	{
		// ���� ���� ��� �������� �湮
		pair<int, int> v = pq.top();
		pq.pop();
		int vCost = v.first;
		int vIdx = v.second;

		// �湮�� ���̸� pass
		if (isVisitied[vIdx]) continue;

		isVisitied[vIdx] = true;

		// distance ������Ʈ 
		for (pair<int, int> next : graph[vIdx])
		{
			int nIdx = next.second; int nCost = next.first;
			if (vCost + nCost < dis[nIdx])
			{
				dis[nIdx] = nCost + vCost;
				pq.push({dis[nIdx], nIdx});
			}
		}
		//for (int i = 1; i <= n; i++)
		//{
		//	// �̾��� ���� �ʰ� �̹� �湮������ pass
		//	if (graph[vIdx][i] >= INF || vIdx == i) continue;
		//	// ���� �� ���� ��� ã���� ����
		//	if (vCost + graph[vIdx][i] < dis[i])
		//	{
		//		dis[i] = vCost + graph[vIdx][i];
		//		pq.push({ dis[i], i });
		//	}
		//}
	}

	// �ּҰ� ��ȯ 
	return dis[end];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// �Է�
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		// �ܹ����̱⶧���� �ѹ��� �־���
		graph[s].push_back({c, e});
	}

	// graph ������ �� INF�� ��� �ʱ�ȭ
	// �׳� vector�� {���, idx} �������� �־��ָ� �������� �ʱ�ȭ ���ص� ��
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= n; j++)
	//	{
	//		if (i == j) continue;
	//		if (graph[i][j] == 0) graph[i][j] = INF;
	//	}
	//}


	// ���ͽ�Ʈ��
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;

		int goback = Dijkstra(i, x) + Dijkstra(x, i);

		if(goback >= max) max = goback;

	}

	cout << max;


}