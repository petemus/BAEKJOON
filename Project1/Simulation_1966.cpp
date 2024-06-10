// simulation > 프린터 큐(1966번)
// 풀이 시간 : 
// 중요도에 따라 인쇄해야 함 
// 자료구조 사용 -> 큐, stack 는 iterator 없음 / 배열 -> 모든 요소 다 옮겨줘야 함
// => deque
// ?? 컨테이너를 매개변수로 넣어주면 어떻게 되나??

#include <iostream>
#include <deque>
using namespace std;

bool isBigger(deque<pair<int, int>> dq)
{
	// 맨 앞의 요소보다 큰 요소가 없는지 확인
	deque<pair<int, int>>::iterator iter = dq.begin();
	int frontImport = (*iter).second;
	while (iter != dq.end())
	{
		int comp = (*iter).second;
		if (frontImport < (*iter).second) return false;
		++iter;
	}
	return true;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	int n, m;

	cin >> testcase;

	while (testcase--)
	{
		// 입력
		cin >> n >> m;
		deque<pair<int,int>> dq;	// index, 중요도
		for (int i = 0; i < n; i++)
		{
			int e;
			cin >> e;
			dq.push_back({i, e});
		}

		// 중요도에 따른 출력
		// 중요도가 큰 놈들이 없고 내가 찾는 인덱스면 출력
		int num = 0;
		while (true)
		{
			if (isBigger(dq))
			{
				// 인쇄
				num++;
				if (dq.front().first == m)
				{
					cout << num << '\n';
					break;
				}
				else dq.pop_front();
			}
			else
			{
				// 문서 뒤에다가 배치
				pair<int, int> front = dq.front(); dq.pop_front();
				dq.push_back(front);
			}
		}

	}

}