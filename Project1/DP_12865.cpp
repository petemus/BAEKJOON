// DP > ����� �賶(12865��)
// Ǯ�� �ð� :
//

// 1) Backtracking  -> �ð� �ʰ�
// 2) DP -> ���� ���ذ� �ȵ�

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
	// weight�� ���� �ִ� value ����
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
	//	// n ��ŭ �ݺ� => �̷��� �ϸ� �ߺ��ؼ� ���õ� �� ����...
	//	for (int j = 0; j < n; ++j)
	//	{	
	//		// ��ġ�� �ʰ� ���ݺ��� Ŀ�� �� 
	//		if (weights[j] <= i && weights[j] > (i / 2))
	//		{
	//			// weight�� ���� memo ���Ժ��� ũ�� ���� memo�� ���� ������
	//			int prevW = i - weights[j];
	//			if (memo[prevW] >= 0)
	//			{
	//				// �� ���� ������ ���� �־�� ���ؼ� ������ 
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

