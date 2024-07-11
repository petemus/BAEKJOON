// Brute Force > 용감한 용사 진수 (14718번)
// 풀이 시간 : 1h 10m
// 결론 : 어떻게 BruteForce를 할지 잘 정해야함 

// k개의 적들의 스탯의 최댓값을 더한 값이 최소 스탯 포인트 
// Brtue Force -> 100 * 100 * 100 만큼 연산 100만 => power, speed. intel 따로 순차로 저장한후 확인
// Backtracking => 시간 초과

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	// 정렬 불필요여서 vector로 또 나눌 필요 없음 
	vector<int> pow;
	vector<int> speed;
	vector<int> intel;
	int enemy[100][3];
	for (int i = 0; i < n; i++)
	{
		int p, s, k;
		cin >> p >> s >> k;
		pow.push_back(p); speed.push_back(s); intel.push_back(k);
		enemy[i][0] = p; enemy[i][1] = s; enemy[i][2] = k;
	}
	// 오름차순으로 정렬 -> 어차피 전체 탐색이여서 정렬 불필요 ㅎㅋ
	sort(pow.begin(), pow.end());
	sort(speed.begin(), speed.end());
	sort(intel.begin(), intel.end());

	int jPow = 0, jSpeed = 0, jIntel = 0;
	int minStateSum = 3000000;
	for (int i = 0; i < n; i++)
	{
		jPow = pow[i];
		for (int j = 0; j < n; j++)
		{
			jSpeed = speed[j];
			for (int m = 0; m < n; m++)
			{
				jIntel = intel[m];
				int win = 0;
				for (int l = 0; l < n; l++)
				{
					if (jPow >= enemy[l][0] && jSpeed >= enemy[l][1] && jIntel >= enemy[l][2]) ++win;
				}
				if (win >= k)
				{
					int stateSum = jPow + jSpeed + jIntel;
					if (stateSum < minStateSum) minStateSum = stateSum;
				}
			}
		}
	}

	cout << minStateSum;
}