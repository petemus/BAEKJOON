// DP > 쉬운 계단 수 (10844번)
// 풀이 시간 : 30m (값의 크기 조심 -> MOD 연산)

// 이친수랑 비슷한 느낌 -> 각 자리수 마다 0~9를 가지고 있는 수를 저장
// => 0~9까지의 수가 계단 수 증가시 각 0~9까지가 있고 0이랑9 아니면 + 양옆으로 +1
// 0이랑 9이면 앞 아래로 + 1
// ! 크기 조심 -> 더할때마다 mod + long long


#include <iostream>
#include <memory.h>
using namespace std;

#define MOD 1000000000

long long memo[101][10] = {0,};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	//memset(memo, -1, 101 * 10 * sizeof(int));

	// 초기값
	for (int i = 1; i < 10; i++)
	{
		memo[1][i] = 1;
	}

	for (int i = 2; i <= 100; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// 개수가 0개가 아니면 양옆으로 개수 더하기
			if (memo[i - 1][j] > 0)
			{
				if(j == 0) memo[i][j + 1] += memo[i - 1][j] % MOD;
				else if(j == 9) memo[i][j - 1] += memo[i - 1][j] % MOD;
				else
				{
					memo[i][j + 1] += memo[i - 1][j] % MOD;
					memo[i][j - 1] += memo[i - 1][j] % MOD;
				}
			}

		}
	}

	// TEST
	//for (int k = 1; k <= 100; k++)
	//{
	//	long long sum = 0;;
	//	for (int i = 0; i < 10; i++)
	//	{
	//		sum += (memo[k][i] % MOD);
	//	}
	//	cout << sum % MOD;
	//	cout << "\n";
	//}
	

	long long sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += (memo[n][i] % MOD);
	}
	cout << sum % MOD;
}