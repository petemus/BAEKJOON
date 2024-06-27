// Brute Force > 아이폰 9s (5883번)
// 풀이 시간 :
// 1) Brute Force : 1000 * 100만 -> 최대 10억(초과)
// 2) Brute Force (n * n)만큼 탐색 1000 * 1000 -> 100만
// + 사람을 선택하지 않는 경우는 없는듯

#include <iostream> 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// Brute Force 
	// 순서대로 하나씩 선택하고 해당 숫자 무시하고 가장 길이가 긴 연속 구간 체크
	// arr[i]가 선택한 용량
	// 가장 길이가 긴 연속 구간 체크
	int maxLen = 0;
	for (int i = 0; i < n; i++)
	{
		int len = 0;
		int nowVal = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == arr[i]) continue;

			if (nowVal == arr[j]) ++len;
			else
			{
				// 다른 숫자가 나오면 최대 길이랑 비교 + 초기화
				if (len > maxLen) maxLen = len;
				nowVal = arr[j];
				len = 1;
			}
		}

		// 다른 숫자가 나오지 않고 끝나면 최대값 확인 못해주므로 마지막으로 한번 더 체크
		if (len > maxLen) maxLen = len;
	}


	cout << maxLen;
}