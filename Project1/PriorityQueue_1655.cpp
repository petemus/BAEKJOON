// Priority Queue > 가운데를 말해요 (1655번) -> X
// 풀이 시간 :
// 1) 들어올때마다 정렬해서 가운데 값 출력 -> 시간 복잡도 O(n^2logn) 정도 나와서 시간 초과날듯 
// 2) 우선 순위 큐 사용 -> (?) 가운데에 어떻게 접근? => queue의 size를 생각해서 정닥히 pop (X) => pop해버린 값에 접근 불가
// 3) 개수만큼 pop하고 다시 넣어줌 -> 시간 초과 니기ㅓㄹㄹ


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		// 수 넣기
		int n;
		cin >> n;
		pq.push(n);

		int popNum = i / 2;
		vector<int> pops;
		// popNum만큼 pop해주고 top 출력
		// pop한 것들은 vector에 임시적으로 저장하고 나중에 다시 넣어줌
		for (int j = 0; j < popNum; j++)
		{
			int top = pq.top();
			pops.push_back(top);
			pq.pop();
		}
		cout << pq.top() << '\n';
		for (int j = 0; j < pops.size(); j++)
		{
			pq.push(pops[j]);
		}
	}

}

