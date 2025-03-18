// DP > 이동하기 (11048번)
// 풀이 시간 : 25m


// (1,1) -> (n, m)으로 이동할 때 가져올 수 있는 최대 사탕 개수 -> 다익스트라?, dp, 완탐(백트랙킹)
// 완탐 한 대략 3^1000으로 불가능할 듯 -> dp?
// !Top-down, Bottom-Up 둘 다 가능할 듯 

// point 1 > (r, c)에서의 최대 = Max( (r, c-1), (r-1, c), (r-1, c-1) ) 
// 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	// *vector 초기화 
	vector<vector<int>> maze(n, vector<int>(m, -1));
	// Memorization할 배열
	vector<vector<int>> memo(n, vector<int>(m, -1));
	
	// *input
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> maze[i][j];
		}
	}


	// *Memorization

	// 초기값
	memo[0][0] = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			// (r-1, c), (r, c-1), (r-1, c-1) 범위 넘는지 체크
			if (i >= 1) memo[i][j] = max(memo[i][j], memo[i - 1][j]);

			if (j >= 1) memo[i][j] = max(memo[i][j], memo[i][j - 1]);

			if(i >= 1 && j >= 1) memo[i][j] = max(memo[i][j], memo[i - 1][j - 1]);


			// 자기 위치 사탕도 넣어줌
			memo[i][j] += maze[i][j];
		}
	}


	// output
	cout << memo[n - 1][m - 1];


}