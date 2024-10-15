// DP > ������(1912��)
// Ǯ�� �ð� : 30

#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

// index�� �����ϴ� �ִ� ������
int memo[100001] = {0,};

vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> memo[i];
	}


	// dp
	int Max = memo[1];

	for (int i = 2; i <= n; i++)
	{
		memo[i] = max(memo[i - 1] + memo[i], memo[i]);

		//cout << memo[i] << endl;

		if(memo[i] > Max) Max = memo[i];
	}
	
	cout << Max;

}
