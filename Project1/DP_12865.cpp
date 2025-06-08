// DP > 평범한 배낭(12865번)
// 풀이 시간 :
//

// 1) Backtracking  -> 시간 초과
// 2) DP -> 아직 이해가 안됨

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;

	// Input
	cin >> n >> k;

	vector<int> weights(n + 2, 0);
	vector<int> values(n + 2, 0);

	// memorization
	// weight에 따른 최대 value 저장
	vector<int> memo(100002, -1);
	vector<vector<int>> dp(n + 2, vector<int>(100002, 0));

	for (int i = 1; i <= n; i++)
	{
		cin >> weights[i] >> values[i];
	}


	// DP
	//memo[0] = 0;
	//for (int i = 1; i <= k; ++i)
	//{
	//	// n 만큼 반복 => 이렇게 하면 중복해서 선택될 수 있음...
	//	for (int j = 0; j < n; ++j)
	//	{	
	//		// 겹치지 않게 절반보다 커야 함 
	//		if (weights[j] <= i && weights[j] > (i / 2))
	//		{
	//			// weight가 현재 memo 무게보다 크면 이전 memo에 값과 더해줌
	//			int prevW = i - weights[j];
	//			if (memo[prevW] >= 0)
	//			{
	//				// 그 이전 무게의 값이 있어야 비교해서 더해줌 
	//				memo[i] = max(memo[prevW] + values[j], memo[i]);
	//			}
	//		}
	//	}
	//}


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j >= weights[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
			}
			else dp[i][j] = dp[i -1][j];
		}
	}

	cout << dp[n][k];



}

