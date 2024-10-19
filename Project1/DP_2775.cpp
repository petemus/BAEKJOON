// DP > �γ�ȸ���� ���׾� (2775��)


#include <iostream>
#include <memory.h>
using namespace std;

// �ִ� 14�� 14ȣ
long long memo[15][15];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;

	// memo �ʱⰪ
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
				// j - 1���� �� + �ڱ� �Ʒ����� ȣ�� ���ϸ� ��
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