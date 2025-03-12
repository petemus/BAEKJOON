// DP > 01타일 (1904번)
// 풀이 시간 : 15 m



// 모든 가짓수 출력 -> 완탐, dp -> n의 크기 큼 -> 보통 dp => 이전 것들에서 다음 것들이 나오는지 체크해줘야할듯 
// point1> 출력 조건 -> 15746을 나눈 나머지 => 전체적으로 더할때 계속 나눠주면서 더해줘야듯
// point2> 규칙 찾기 -> [n] = [n-1] + [n-2]
//			n-2 개일때 00 붙여주기 , n-1개일때 1붙여주기 => 점화식 완성 


#include <iostream>
#include <vector>
using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<int> memo;
	int n;
	cin >> n;


	memo.resize(n + 1, -1);

	memo[0] = 1;
	memo[1] = 1;

	// memorization
	// [n] = [n-1] + [n-2]
	for (int i = 2; i <= n; ++i)
	{
		memo[i] = (memo[i - 1] + memo[i - 2]) % 15746;
	}

	cout << memo[n];


}