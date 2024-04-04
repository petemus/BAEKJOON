// 1. 파도반 수열(9461)
// ?? 정삼각형이 어떠 모양으로 늘어나는지 이해가 안감
// sol1) 수열을 보고 규칙을 찾아서 풀기 -> dp 사용
// a4 = a1 + a2 , a5 = a2 + a3, a6 = a3 + a4 => a(n) = a(n-2) + a(n-3)

// sol2) 피보나치 수열과 비슷해서 피보나치 수열 푸는 방법으로 풀 수 있을 듯

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	long long triangle[151] = { 0, 1, 1, 1, };
	for (int i = 4; i < 151; i++)
	{
		triangle[i] = triangle[i - 2] + triangle[i - 3];
	}


	// n이 들어올 때마다 triangle의 값을 구해주면 낭비(저장도 할 수 있으니까)
	// sol1) 150까지의 triangle을 다 구하고 입력값 들어오면 출력 -> 사용
	// -> n의 값이 커질수록 triagnel의 값이 급수적으로 증가해서 int로 표현 불가한듯
	// sol2) 구한 값을 저장하고 그 값보다 큰 값이 들어오면 그때 계산

	int n;
	while (testCase--)
	{
		cin >> n;
		cout << triangle[n] << '\n';
	}


}