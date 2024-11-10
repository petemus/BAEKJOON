// DP, ����  > �ٸ� ���� (1010��)

#include <iostream>
#include <memory.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ���ս� mCn�� ���ϸ� ���� ���� �� ���� 
	// DP : dp[N][M] = dp[N-1][1] + dp[N-1][2] + ... + dp[N-1][M-1]


	// input 
	int t;
	cin >> t;

	long long memo[31][31];
	memset(memo, 0, 31 * 31 * sizeof(long long));

	// �ʱⰪ
	for (int i = 1; i < 30; i++)
	{
		memo[1][i] = i;
	}

	// �� ���� �� ���


	for (int i = 2; i < 30; i++)
	{
		for (int j = 1; j < 30; j++)
		{
			for (int k = 1; k < j; k++)
			{
				memo[i][j] += memo[i - 1][k];
			}
		}
	}



	while (t--)
	{
		int n, m;
		cin >> n >> m;
		cout << memo[n][m] << "\n";
	}
	

}