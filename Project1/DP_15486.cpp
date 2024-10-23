// DP > 퇴사2 (15486번)
// 풀이 시간 : @, 시뮬레이션 하기 쉽지 않음...

// 빨리 끝나는 상담을 우선적으로 하게 되면 상담을 많이 할 수 있음 -> But, pay가 있기에 달라질 수 있음 
// N이 150만이여서 이중 포문 못씀 -> 우선 순위 큐...?

// Top-down?


#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

#define MEMOSIZE 1500001


int n;
// first : EndDay, second : cost
vector<pair<int,int>> schedul;
// index 날짜일때 최대 금액
int memo[MEMOSIZE];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;

	schedul.push_back({0,0});
	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;
		schedul.push_back({i + t - 1, p});
	}

	memset(memo, 0, sizeof(int)* MEMOSIZE);

	// i까지의 최대값
	int M = 0;
	for (int i = 1; i <= n; i++)
	{

		// 이전 날짜에서의 최대값과 비교해서 넣어주기
		memo[i] = max(M, memo[i]);

		// EndDay가 i보다 작거나 같으면 현재 씌어져 있는 값과 비교하여 넣기
		int iEndDay = schedul[i].first;
		if (iEndDay == i)
		{
			// 이전 값 가져온 거면(자기 날짜 포함 안되어 있으니까) 더해주고
			// 원래 있던 값이면(자기 날짜 포함) M에다가 현재 스케쥴 더해줌
			if (M == memo[i]) memo[i] += schedul[i].second;
			else memo[i] = max(M + schedul[i].second, memo[i]);
		}
		else if(iEndDay < MEMOSIZE)
		{
			// EndDay가 크면 그 날짜의 값과 비교해서 넣어줌
			// 이때도 memo에 있는 값이 자기자신을 포함했는지 비교
			memo[iEndDay] = max(memo[iEndDay], M + schedul[i].second);
		}

		// M 업뎃
		M = max(M, memo[i]);
	}

	cout << memo[n];


	//DP(n);


}

