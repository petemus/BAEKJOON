// DP > ���� ��� �� (10844��)
// Ǯ�� �ð� : 30m (���� ũ�� ���� -> MOD ����)

// ��ģ���� ����� ���� -> �� �ڸ��� ���� 0~9�� ������ �ִ� ���� ����
// => 0~9������ ���� ��� �� ������ �� 0~9������ �ְ� 0�̶�9 �ƴϸ� + �翷���� +1
// 0�̶� 9�̸� �� �Ʒ��� + 1
// ! ũ�� ���� -> ���Ҷ����� mod + long long


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

	// �ʱⰪ
	for (int i = 1; i < 10; i++)
	{
		memo[1][i] = 1;
	}

	for (int i = 2; i <= 100; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// ������ 0���� �ƴϸ� �翷���� ���� ���ϱ�
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