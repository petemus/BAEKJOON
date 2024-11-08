// 투 포인터, 누적합 > 수열(2559번)
// 풀이 시간 : 20m
// 연속적인 며칠 동안의 온도의 합이 가장 큰 값
// start, end의 index만 알고 있으면 한번 구해 주면 그 이후는 계속 그값에서 더해주고 뺴주면 된다



#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> temperature(n);
	for (int i = 0; i < n; i++)
	{
		cin >> temperature[i];
	}

	// 투 포인터 (start와 end는 같을 수 있다)
	int start = 0, end = -1;
	// 최솟값은 온도의 최소 값 * 10만
	int maxSum = 0;
	// 누적합
	int sum = 0;

	// 처음은 k만큼 더해줌
	for (int i = 0; i < k; i++)
	{
		sum += temperature[++end];
	}
	maxSum = sum;

	// n - k번 만큼 반복
	for (int i = 1; i <= n - k; i++)
	{
		// start, end 증가
		// start : 빼고 증가
		// end : 증가하고 더함
		sum -= temperature[start++];
		sum += temperature[++end];

		if(sum > maxSum) maxSum = sum;
	}


	cout << maxSum;
}
