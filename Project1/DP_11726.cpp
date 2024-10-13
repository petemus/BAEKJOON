// DP > 2*N Ÿ�ϸ� (11726��)


#include <iostream>
#include <memory.h>
using namespace std;


// [i] = [i - 1] + [i -2]
// ��ĭ �þ�� �� �� �ִ� ��� �� ���η� �Ѱ� ����� �Ͱ� ���η� 2�� ����� ��
// ���η� �� ���� [i -1]�� �� ���� ����� ���ϱ� [i-1]�� ������ ����
// ���η� 2�� ����� �Ŵ� [i-2]�� ���� 2�� ����� �Ͱ� ���Ƽ� [i-2]�� ���� 

// ! 10007�� �����ٴ� ���� �ٽ� -> memo�� ���� �ſ� Ŀ���ٴ� �� 
// modulo ���� -> �� ���� ( (A+B) mod c == (A mod c + B mod C) mod c (���� ����, �� ���� ��������)

// index���϶� ���簢�� ü��� ��
long long memo[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	memset(memo, -1, 1001  * sizeof(long long));

	// �ʱⰪ
	memo[1] = 1; memo[2] = 2;

	// Bottom-Up
	for (int i = 3; i <= n; i++)
	{
		memo[i] = (memo[i -1] + memo[i - 2]) % 10007;
	}

	cout << memo[n] % 10007;

}