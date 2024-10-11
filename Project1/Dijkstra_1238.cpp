// 다익스트라 > 파티(1238번)
// 방향이 있는 그래프


#include <iostream>
#include <queue>
using namespace std;

// Time의 최대값이 100이므로 
#define INF 101;

// n :마을 수(사람수), m : 간선 수(단방향), T(비용), X 도착지점
int n, m, x;


// 마을 그래프
int graph[1001][1001] = {0, };

int minDis[1001] = {0,};




// 다익스트라
void Dijkstra(int start, int end)
{
	// 우선순위 큐
	// first : 비용, second : 연결 노드
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

	// 방문 체크 배열 -> 각 마을 탐색할때 마다 다르게 사용해야함
	bool isVisitied[1001] = { false, };

	// distance 배열
	// start에서 index로 갈때 최단 비용
	int dis[1001] = {0, };


	// 첫번째 요소 넣어주기 
	isVisitied[start] = true;
	for (int i = 1; i <= n; i++)
	{
		if(start == i) continue;

		dis[i] = graph[start][i];
		pq.push({ dis[i], i});
	}

	// while문 반복  
	while (!pq.empty())
	{
		// 방문한 곳이면 패스
		// 가장 작은 요소 꺼내오고 방문
		pair<int,int> v = pq.top(); 
		pq.pop();
		int vCost = v.first;
		int vIdx = v.second;

		// 방문한 곳이면 pass
		if (isVisitied[vIdx]) continue;

		isVisitied[vIdx] = true;


		// distance 업데이트 
		for (int i = 1; i <= n; i++)
		{
			// 이어져 있지 않으면 pass
			if(graph[vIdx][i] >= 101 && graph[vIdx][i] == 0) continue;
			
			// 만약 더 작은 경로 찾으면 업뎃
			if (vCost + graph[vIdx][i] < dis[vIdx])
			{
				dis[vIdx] = vCost + graph[vIdx][i];
				pq.push({ dis[vIdx], i});
			}
		}
	}


	// 최소값 저장
	minDis[start] = dis[x];

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
		graph[s][e] = c;
	}

	// graph 나머지 값 INF로 모두 초기화
	// 나중에 stl에서 제공하는 함수 사용 하자.
	//fill_n(&graph[0][0], &graph[1001][1001], 101);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{	
			if(i == j) continue;
			if(graph[i][j] == 0) graph[i][j] = INF;
		}
	}



	// 다익스트라
	for (int i = 1; i <= n; i++)
	{
		Dijkstra(i, x);
		Dijkstra(x, i);
	}


	// 다익스트라 함수가 다 끝나면 가장 dis배열의 x열의 비용 값이 최소인 놈을 출력
	// 100 * 10000 * 2
	int min = 2000000;
	for (int i = 1; i < n; i++)
	{
		if(minDis[i] <= min) min = minDis[i];
	}
	// 출력
	cout << min;

}