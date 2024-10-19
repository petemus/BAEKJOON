// DP > 퇴사2 (15486번)
// 풀이 시간 : 모르겠다 ㅇㅅㅇ...

// 빨리 끝나는 상담을 우선적으로 하게 되면 상담을 많이 할 수 있음 -> But, pay가 있기에 달라질 수 있음 
// N이 150만이여서 이중 포문 못씀

// Top-down?


#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

#define MEMOSIZE 1500001

int n;
// first : Time, second : pay
vector<pair<int,int>> schedul;
int memo[MEMOSIZE];

int DP(int day)
{

	if(memo[day] == -1) return memo[day];






	return memo[day];
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	schedul.push_back({0, 0});
	for (int i = 0; i < n; i++)
	{
		int t, p;
		cin >> t >> p;
		schedul.push_back({t, p});
	}

	memset(memo, -1, sizeof(int)* MEMOSIZE);

	DP(n);


}

