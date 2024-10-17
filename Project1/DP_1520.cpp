// DP > 내리막 길(1520번)
// ! 최단 높이가 아니라 높이가 더 낮은 지점으로 가는 경우의 수 
// 백트랙킹으로 가능 -> but, 시간 제한으로 인해서 dp로 풀어야할 것 같음
// 오른쪽으부터 어떻게 와야하나 
// 도대체 완전히 겹치는 부분이 어디지 -> !!더 큰 곳만 방문하는 게 포인트 => 그러면 두 개의 노드 사이의 이동방향은 하나

#include <iostream>
#include <memory.h>
using namespace std;

int n, m;
// (0, 0) -> (i, j)로 갈 수 있는 경로 수 
int memo[500][500] = {0,};
int map[500][500] = {0,};

// direction 배열 (위로는 못감)
int dirX[4] = { 0, -1, 1, 0};
int dirY[4] = { -1, 0, 0, 1 };

int DP(int y, int x)
{
	// 종료 조건
	if (memo[y][x] != -1)
	{
		// memo가 되어져 있으면 return
		return memo[y][x];
	}


	int sum = 0;
	for (int k = 0; k < 4; k++)
	{
		int prevY = y + dirY[k];
		int prevX = x + dirX[k];

		// 인덱스 범위 넘어가면 pass
		if (prevY < 0 || prevY >= n || prevX < 0 || prevX >= m) continue;

		// 나보다 크면 방문
		if (map[prevY][prevX] > map[y][x])
		{
			sum += DP(prevY, prevX);;
		}
	}
	return memo[y][x] = sum;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// Input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	// memo 초기화
	memset(memo, -1, 500 * 500 * sizeof(int));

	// memo 초기값
	memo[0][0] = 1;
	int result = DP(n - 1, m - 1);

	cout << result;
	
	

}