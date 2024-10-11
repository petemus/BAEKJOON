// ���ͽ�Ʈ�� > ��Ƽ(1238��)
// ������ �ִ� �׷���


#include <iostream>
#include <queue>
using namespace std;

// Time�� �ִ밪�� 100�̹Ƿ� 
#define INF 101;

// n :���� ��(�����), m : ���� ��(�ܹ���), T(���), X ��������
int n, m, x;


// ���� �׷���
int graph[1001][1001] = {0, };

int minDis[1001] = {0,};




// ���ͽ�Ʈ��
void Dijkstra(int start, int end)
{
	// �켱���� ť
	// first : ���, second : ���� ���
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

	// �湮 üũ �迭 -> �� ���� Ž���Ҷ� ���� �ٸ��� ����ؾ���
	bool isVisitied[1001] = { false, };

	// distance �迭
	// start���� index�� ���� �ִ� ���
	int dis[1001] = {0, };


	// ù��° ��� �־��ֱ� 
	isVisitied[start] = true;
	for (int i = 1; i <= n; i++)
	{
		if(start == i) continue;

		dis[i] = graph[start][i];
		pq.push({ dis[i], i});
	}

	// while�� �ݺ�  
	while (!pq.empty())
	{
		// �湮�� ���̸� �н�
		// ���� ���� ��� �������� �湮
		pair<int,int> v = pq.top(); 
		pq.pop();
		int vCost = v.first;
		int vIdx = v.second;

		// �湮�� ���̸� pass
		if (isVisitied[vIdx]) continue;

		isVisitied[vIdx] = true;


		// distance ������Ʈ 
		for (int i = 1; i <= n; i++)
		{
			// �̾��� ���� ������ pass
			if(graph[vIdx][i] >= 101 && graph[vIdx][i] == 0) continue;
			
			// ���� �� ���� ��� ã���� ����
			if (vCost + graph[vIdx][i] < dis[vIdx])
			{
				dis[vIdx] = vCost + graph[vIdx][i];
				pq.push({ dis[vIdx], i});
			}
		}
	}


	// �ּҰ� ����
	minDis[start] = dis[x];

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
		graph[s][e] = c;
	}

	// graph ������ �� INF�� ��� �ʱ�ȭ
	// ���߿� stl���� �����ϴ� �Լ� ��� ����.
	//fill_n(&graph[0][0], &graph[1001][1001], 101);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{	
			if(i == j) continue;
			if(graph[i][j] == 0) graph[i][j] = INF;
		}
	}



	// ���ͽ�Ʈ��
	for (int i = 1; i <= n; i++)
	{
		Dijkstra(i, x);
		Dijkstra(x, i);
	}


	// ���ͽ�Ʈ�� �Լ��� �� ������ ���� dis�迭�� x���� ��� ���� �ּ��� ���� ���
	// 100 * 10000 * 2
	int min = 2000000;
	for (int i = 1; i < n; i++)
	{
		if(minDis[i] <= min) min = minDis[i];
	}
	// ���
	cout << min;

}