// Dynameic programing > 피보나치 함수 (1003번)
// 풀이 시간 : 15m

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
	// 피보나치의 결과값이 저장되는 게 아니라 호출된 횟수가 저장됨
	int memo0[41] = { 0, };		// 0이 호출된 수
	int memo1[41] = { 0, };		// 1이 호출된 수

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