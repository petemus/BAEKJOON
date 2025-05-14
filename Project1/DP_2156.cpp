// DP > 포도주 시식(2156번)
// 풀이 시간 : 30m (틀린 이유 찾느라 좀 걸림 

// 문제) 포도주를 연속으로 3잔 못마심 + 최대로 많은 양의 포도주 마심 => dp

// ! 점화식 조건 놓치지 않도록 잘 세워야 함!!!!!


#include <iostream>
#include <algorithm> // max(), min(), max({}) 
using namespace std;

// 와인값 저장 
int wines[10002];

// 1번 마신 거 저장
int drink1[10002];
// 2번 마신 거 저장 
int drink2[10002];
// 안 마신 거 저장 
int ndrink[10002];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> wines[i];
	}

	// 초기화
	drink1[1] = wines[1];
	drink2[1] = 0;
	ndrink[1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		// 마시지 않은 와인은 이전 것 값들 중에 최대로 비교 
		// @@@@ 논리적 오류에 빠지지 않도록 점화식 잘 세워야 할듯 
		ndrink[i] = max(ndrink[i - 1], max(drink1[i - 1], drink2[i - 1]));
		// 1번 마신 와인은 마시지 않은 와인 중에 선택
		drink1[i] = ndrink[i - 1] + wines[i];
		// 2번 마신 와인은 이전에 한번 마신 와인에 더해줌
		drink2[i] = drink1[i - 1] + wines[i];
	}

	// 많이 마신 와인 값 선택
	//cout << max({ndrink[n], drink1[n], drink2[n]});
	cout << max(max(ndrink[n], drink1[n]), drink2[n]);

}