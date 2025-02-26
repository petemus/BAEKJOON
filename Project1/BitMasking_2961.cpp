// 비트 마스킹, 백트랙킹, 완탐 > 도영이가 만든 맛있는 음식(2961번)
// ! 완탐 base는 같지만, 재귀를 사용하는 문제에서 비트 마스킹을 사용하면서 반복문으로 처리 가능
// 풀이 시간 : 40m....

// 재료 개수 최대 10 => 1023개의 경우의 수 
// 모든 경우의 수 2^N - 1(0은 안되므로) 


#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int,int>> flavors;
	for (int i = 0; i < n; ++i)
	{
		int sour, bitter;
		cin >> sour >> bitter;
		flavors.push_back({sour, bitter});
	}

	// 완탐 
	// 1 ~ 2^n -1 까지 확인 (..01 ~ (1 << n))
	// i가 들어간 쟤료들
	// 각 들어간 쟤료들 하나씩 확인하면서 계산
	int minDis = 1000000000;
	for (int i = 1; i < (1 << n); ++i)
	{
		// i에 들어간 쟤료 확인하면서 맛 구하기
		int sourSum = 1;
		int bitterSum = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				// 해당 쟤료가 있으면 맛 계산
				sourSum *= flavors[j].first;
				bitterSum += flavors[j].second;
			}
		}
		// 모든 맛 구하면 최솟값 비교
		int dis = abs(sourSum - bitterSum);
		if(dis < minDis) minDis = dis;
	}

	cout << minDis;

}