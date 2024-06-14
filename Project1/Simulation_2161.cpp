// simulation > 카드1 (2161번)
// 풀이 시간 : 6m
// 앞으로 빼고 뒤로 삽입하는 연산이 많음 -> queue

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	queue<int> cards;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cards.push(i + 1);
	}

	// 카드 한개 남을때까지 반복
	while (true)
	{
		// 맨 위 카드 버림
		if (cards.size() == 1) break;
		else
		{
			cout << cards.front() << ' ';
			cards.pop();
		}


		// 카드 뒤로 삽입
		if (cards.size() == 1) break;
		else
		{
			int t = cards.front(); cards.pop();
			cards.push(t);
		}
	}

	// 마지막 카드 출력
	cout << cards.front();
}