// Priority Queue > 카드 정렬하기 (1715번)
// 풀이 시간 : 10m
// 작은 수끼리 더하고 더하면 되지 않나 -> !합한 수도 다시 정렬 되어야 함 => 걍 우선순위 큐 사용하면 쉬움

#include <iostream>	
#include <queue>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// 중단점 걸어두고 pq 내부를 확인해보면 정렬되어 있지 않을 때가 있음을 확인할 수 있음 
	// why...
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		int cards;
		cin >> cards;
		pq.push(cards);
	}

	int result = 0;
	while (pq.size() > 1)
	{
		int comp1 = pq.top(); pq.pop();
		int comp2 = pq.top(); pq.pop();

		result += comp1 + comp2;
		pq.push(comp1 + comp2);
	}

	cout << result;
}