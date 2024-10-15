// DP > 2*n 타일링 2 (11727번)
// 풀이 시간 : 15m (2*n타일링이랑 거의 같음 규칙만 찾으면 됨 + memo 하는 거 잊지 말자)

// 점화식 : [i] = [i -1] + [i -2] * 2
// [i-1] 에는 가로 1개 추가이고 [i-2] 에는 세로 두개랑 직사각형 한개 추가 가능 

#include <iostream>
#include <memory.h>

#define MOD 10007

using namespace std;

int memo[1001];

int Recur(int i)
{
	// memo가 되어 있으면 패스
	if(memo[i] != -1) return memo[i];

	return memo[i] = (Recur(i - 1) + Recur(i - 2) * 2) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	memset(memo, -1, (n + 1) * sizeof(int));

	// 초기값 세팅
	memo[1] = 1;
	memo[2] = 3;



	cout << Recur(n) % MOD;

}