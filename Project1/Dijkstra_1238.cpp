// 다익스트라 > 파티(1238번)
// 방향이 있는 그래프


#include <iostream>
#include <queue>
using namespace std;

// Time의 최대값이 100인데 얘보다 클 수 있음...
#define INF 2147483647

// n :마을 수(사람수), m : 간선 수(단방향), T(비용), X 도착지점
int n, m, x;

// 마을 그래프
// 2차원 배열을 vector로 만들어도 시간 훨씬 단축 
// vector로 만들기 -> first : 비용, second : idx
//int graph[1001][1001] = {0,};
vector<pair<int,int>> graph[1001];

// 마을별 최단경로
int minDis[1001] = { 0, };


// 다익스트라
// start에서 end까지의 최단 거리 반환 
int Dijkstra(int start, int end)
{
	// 우선순위 큐
	// first : 비용, second : 연결 노드
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// 방문 체크 배열 -> 각 마을 탐색할때 마다 다르게 사용해야함
	bool isVisitied[1001] = { false, };

	// distance 배열
	// start에서 index로 갈때 최단 비용
	int dis[1001] = { 0, };
	fill(dis, dis + n + 1, INF);


	// 첫번째 요소 넣어주기 
	pq.push({0, start});
	dis[start] = 0;


	// while문 반복  
	while (!pq.empty())
	{
		// 가장 작은 요소 꺼내오고 방문
		pair<int, int> v = pq.top();
		pq.pop();
		int vCost = v.first;
		int vIdx = v.second;

		// 방문한 곳이면 pass
		if (isVisitied[vIdx]) continue;

		isVisitied[vIdx] = true;

		// distance 업데이트 
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
		//	// 이어져 있지 않고 이미 방문했으면 pass
		//	if (graph[vIdx][i] >= INF || vIdx == i) continue;
		//	// 만약 더 작은 경로 찾으면 업뎃
		//	if (vCost + graph[vIdx][i] < dis[i])
		//	{
		//		dis[i] = vCost + graph[vIdx][i];
		//		pq.push({ dis[i], i });
		//	}
		//}
	}

	// 최소값 반환 
	return dis[end];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// 입력
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		// 단방향이기때문에 한번만 넣어줌
		graph[s].push_back({c, e});
	}

	// graph 나머지 값 INF로 모두 초기화
	// 그냥 vector에 {비용, idx} 형식으로 넣어주면 무한으로 초기화 안해도 됨
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= n; j++)
	//	{
	//		if (i == j) continue;
	//		if (graph[i][j] == 0) graph[i][j] = INF;
	//	}
	//}


	// 다익스트라
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;

		int goback = Dijkstra(i, x) + Dijkstra(x, i);

		if(goback >= max) max = goback;

	}

	cout << max;


}