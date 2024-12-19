// Backtracking, 외판원 순회 문제 (Traveling Salesman problem : TSP) > 외판원 순회 2 (10971번)
// 다익스트라는 자기 자신으로 돌아오지 않음 
// 풀이 시간 : 35m

// n의 범위가 25을 넘어가지 않으면 Backtracking, 완탐으로 가능하긴 함

#include <iostream>
using namespace std;

// 시작 도시
int startCitiy = 0;
// 도시 수
int n;
// 최소 cost
int minCost = 10000000;

int cities[11][11] = {0,};
int isVisited[11] = {false,};


void Backtracking(int citiy, int depth, int sumCost)
{
	// 종료 조건
	if (depth == n)
	{
		// 모든 도시를 다 돌았을 경우
		// 다시 돌아갈 수 있는지 확임
		if (cities[citiy][startCitiy] > 0)
		{
			// 돌아갈 수 있으면 확인
			sumCost += cities[citiy][startCitiy];
			if(sumCost < minCost) minCost = sumCost;
		}
		return;
	}

	// 이동할 수 있는 곳 찾기 -> 순회
	for (int i = 0; i < n; ++i)
	{
		// 0이 아니면 이동 가능 
		// 방문 했으면 방문하면 안됨.
		if (cities[citiy][i] > 0 && !isVisited[i])
		{
			isVisited[i] = true;
			Backtracking(i, depth + 1, sumCost + cities[citiy][i]);
			isVisited[i] = false;
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 입력
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cities[i][j];
		}
	}

	// 모든 도시에서 각각 순회
	for (int i = 0; i < n; i++)
	{
		startCitiy = i;
		isVisited[i] = true;
		Backtracking(i, 1, 0);
		isVisited[i] = false;
	}
	
	// 최소 비용 출력
	cout << minCost;


}