// Priority Queue > 카드 합체 놀이 (15903번)
// 풀이 시간 : 10m 
// 최소값을 구하는 것이기 때문에 오름차순으로 정렬필요 
// ! 합들의 값이 매우 커질 수 있으므로 x,y, point 의 자료형이 longlong이어야 함

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		pq.push(input);
	}

	// 요소 2개 꺼내고 값 다시 넣어주기
	for (int i = 0; i < m; i++)
	{
		long long x, y;
		x = pq.top(); pq.pop();
		y = pq.top(); pq.pop();
		pq.push(x + y);
		pq.push(x + y);
	}

	// 점수 계산
	long long point = 0;
	while (!pq.empty())
	{
		point += pq.top();
		pq.pop();
	}

	cout << point;
}