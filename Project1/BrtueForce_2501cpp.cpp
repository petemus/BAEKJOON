// Brute Force > 약수 구하기 (2501번)
// 풀이 시간 : 5m
// 시간 복잡도 : O(n) -> N이 10,000이하니까 최대 연산수 10,000 -> 완탐 가능 


#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;


	// n을 하나씩 나눠보면서 그게 k번째로 작은지 확인
	int index = 0;
	for (int i = 1; i <= n; ++i)
	{
		// 약수 체크
		if (n % i == 0)
		{
			// 순서 체크
			++index;
			if (index == k)
			{
				// k 번쨰로 작은 약수 출력
				cout << i;
			}
		}
	}

	// 해당하는 수가 없으면 0 출력
	if (index < k)
	{
		cout << 0;
	}

}