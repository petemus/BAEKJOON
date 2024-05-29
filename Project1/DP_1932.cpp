// DP  > 정수 삼각형 (1932번)
// 풀이 시간 : 30 m
// 위 레벨의 부모로부터 받는 것들 중 최대 고르면 됨

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int n;
	vector<vector<int>> tree;
	// memo > 지금 경로 순의 합
	vector<vector<int>> memo;


	// 입력
	// memo 초기화
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		vector<int> m;
		for (int j = 0; j < i + 1; j++)
		{
			int t;
			cin >> t;
			tmp.push_back(t);
			m.push_back(0);
		}
		tree.push_back(tmp);
		memo.push_back(m);
	}

	// DP
	memo[0] = tree[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j - 1 < 0) memo[i][j] = memo[i - 1][j] + tree[i][j];
			else if (j >= i) memo[i][j] = memo[i - 1][j - 1] + tree[i][j];
			// 그렇지 않으면 두 값중 큰 거 대입
			else memo[i][j] = max(memo[i - 1][j - 1], memo[i - 1][j]) + tree[i][j];
		}
	}

	// 맨 마지막 배열 중 최대값 출력
	cout << *max_element(memo[n - 1].begin(), memo[n - 1].end());
	





}