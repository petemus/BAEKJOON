// DP > 부녀회장이 될테야 (2775번)


#include <iostream>
#include <memory.h>
using namespace std;

// 최대 14층 14호
long long memo[15][15];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;

	// memo 초기값
	for (int i = 1; i < 15; i++)
	{
		memo[0][i] = i;
	}

	// dp
	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			if(j == 1) memo[i][j] = memo[i - 1][j];
			else
			{
				// j - 1층의 수 + 자기 아래층의 호를 더하면 됨
				memo[i][j] = memo[i][j - 1] + memo[i - 1][j];
			}
		}
	}




	for (int i = 0; i < testcase; i++)
	{
		int k, n;
		cin >> k >> n;
		cout << memo[k][n] << '\n';
	}

}