// DP > 1로 만들기(1463번)
// 3으로 나누는 연산과 2로 나누는 연산중 겹치는 부분(overlapping problem)이 발생한다
// 6으로 나누어 떨어지는 부분이 겹침 -> DP

// 최적 부분 구조(Optimal Substructure), 겹치는 부분 문제 (Overlapping subproblem)


#include <iostream>
#include <memory.h>
using namespace std;

// index가 1이 될때의 최소 연산수 
int memo[1000001];

// Top-Down 재귀
int Recur(int i)
{
	// 이미 방문한 곳이면 return
	if(memo[i] != -1) return memo[i];

	int m = Recur(i - 1);

	if(i % 2 == 0) m = min(m, Recur(i / 2));
	if(i % 3 == 0) m = min(m, Recur(i / 3));

	// 최솟값 찾은 후 대입
	return memo[i] = m + 1;

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	
	cin >> n;

	// 바이트 단위로 초기화 해주는 놈
	memset(memo, -1, 1000001 * sizeof(int));

	memo[1] = 0;
	Recur(n);



	// Bottom-up 방식
	//for (int i = 2; i <= n; i++)
	//{
	//	int m = memo[i - 1];
	//	if (i % 2 == 0) m = min(m, memo[i / 2]);
	//	if (i % 3 == 0) m = min(m, memo[i / 3]);

	//	memo[i] = m + 1;
	//}

	cout << memo[n];

}