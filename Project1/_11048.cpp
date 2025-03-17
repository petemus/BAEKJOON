// DP > �̵��ϱ� (11048��)
// Ǯ�� �ð� : 25m


// (1,1) -> (n, m)���� �̵��� �� ������ �� �ִ� �ִ� ���� ���� -> ���ͽ�Ʈ��?, dp, ��Ž(��Ʈ��ŷ)
// ��Ž �� �뷫 3^1000���� �Ұ����� �� -> dp?
// !Top-down, Bottom-Up �� �� ������ �� 

// point 1 > (r, c)������ �ִ� = Max( (r, c-1), (r-1, c), (r-1, c-1) ) 
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

	// *vector �ʱ�ȭ 
	vector<vector<int>> maze(n, vector<int>(m, -1));
	// Memorization�� �迭
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

	// �ʱⰪ
	memo[0][0] = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			// (r-1, c), (r, c-1), (r-1, c-1) ���� �Ѵ��� üũ
			if (i >= 1) memo[i][j] = max(memo[i][j], memo[i - 1][j]);

			if (j >= 1) memo[i][j] = max(memo[i][j], memo[i][j - 1]);

			if(i >= 1 && j >= 1) memo[i][j] = max(memo[i][j], memo[i - 1][j - 1]);


			// �ڱ� ��ġ ������ �־���
			memo[i][j] += maze[i][j];
		}
	}


	// output
	cout << memo[n - 1][m - 1];


}