// DP > 2*n Ÿ�ϸ� 2 (11727��)
// Ǯ�� �ð� : 15m (2*nŸ�ϸ��̶� ���� ���� ��Ģ�� ã���� �� + memo �ϴ� �� ���� ����)

// ��ȭ�� : [i] = [i -1] + [i -2] * 2
// [i-1] ���� ���� 1�� �߰��̰� [i-2] ���� ���� �ΰ��� ���簢�� �Ѱ� �߰� ���� 

#include <iostream>
#include <memory.h>

#define MOD 10007

using namespace std;

int memo[1001];

int Recur(int i)
{
	// memo�� �Ǿ� ������ �н�
	if(memo[i] != -1) return memo[i];

	return memo[i] = (Recur(i - 1) + Recur(i - 2) * 2) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	memset(memo, -1, (n + 1) * sizeof(int));

	// �ʱⰪ ����
	memo[1] = 1;
	memo[2] = 3;



	cout << Recur(n) % MOD;

}