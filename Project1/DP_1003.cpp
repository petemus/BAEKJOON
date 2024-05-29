// Dynameic programing > �Ǻ���ġ �Լ� (1003��)
// Ǯ�� �ð� : 15m

#include <iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	// Memorization
	// �Ǻ���ġ�� ������� ����Ǵ� �� �ƴ϶� ȣ��� Ƚ���� �����
	int memo0[41] = { 0, };		// 0�� ȣ��� ��
	int memo1[41] = { 0, };		// 1�� ȣ��� ��

	while (t--)
	{
		int n;

		cin >> n;

		for (int i = 0; i <= n; i++)
		{
			if (i == 0) memo0[i] = 1;
			else if (i == 1) memo1[i] = 1;
			else
			{
				memo0[i] = memo0[i - 1] + memo0[i - 2];
				memo1[i] = memo1[i - 1] + memo1[i - 2];
			}
		}

		cout << memo0[n] << " " << memo1[n] << "\n";
	}

}