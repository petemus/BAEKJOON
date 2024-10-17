// DP > 가장 큰 증가하는 부분 순열(11055)
// start : 50


#include <iostream>
#include <memory.h>
using namespace std;

// i 보다 작은 인덱스에서 i보다 작은 놈을 찾으면 걔 + 자기 자신이 자기 최대

// 자기 자신을 포함하는 증가하는 부분 수열 합
int memo[1001];
int arr[1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}


	memset(memo, -1, sizeof(int));

	// 초기값
	memo[1] = arr[1];

	// 최대 크기 저장
	// !! 최대값 이런거 항상 상수를 넣는 거 조심...
	int m = memo[1];
	for (int i = 2; i <= n; i++)
	{
		// 현재 값보다 작은 녀석 찾아주기
		// !! 작은 녀석들 중에서 최대인 녀석에 더해주기 
		int subMax = 0;
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[i] > arr[j])
			{
				subMax = max(subMax, memo[j]);
			}
		}
		memo[i] = subMax + arr[i];

		// 최대 비교
		if(memo[i] > m) m = memo[i];
	}

	cout << m;

}