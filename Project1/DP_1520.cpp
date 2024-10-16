// DP > 내리막 길(1520번)
// ! 최단 높이가 아니라 높이가 더 낮은 지점으로 가는 경우의 수 
// 백트랙킹으로 가능 -> but, 시간 제한으로 인해서 dp로 풀어야할 것 같음
// 오른쪽으부터 어떻게 와야하나 
// 도대체 완전히 겹치는 부분이 어디지

#include <iostream>
#include <memory.h>
using namespace std;

int n, m;
// (0, 0) -> (i, j)로 갈 수 있는 경로 수 
int memo[500][500] = {0,};
int map[500][500] = {0,};

// direction 배열 (위로는 못감)
int dirX[3] = { 0, -1, 1};
int dirY[3] = { -1, 0, 0 };

int DP(int y, int x)
{
	// 종료 조건
	if (memo[y][x] != -1)
	{
		// memo가 되어져 있으면 return
		return memo[y][x];
	}


	int sum = 0;
	for (int k = 0; k < 3; k++)
	{
		int prevY = y + dirY[k];
		int prevX = x + dirX[k];

		// 인덱스 범위 넘어가면 pass
		if (prevY < 0 || prevY >= n || prevX < 0 || prevX >= m) continue;

		memo[prevY][prevX] = DP(prevY, prevX);
		sum += memo[prevY][prevX];
	}
	return sum;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 모든 (i, j)에서 상하 좌우로 다 간다고 했을때 최소인 것만 저장해나가기

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
	DP(n, m);
	
	// 모든 (i, j) dp
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		//아래 오, 왼 위치에 갈 수있는 경로 수가 있고 내가 더 작으면 경로 수에 더하기
	//		// 방문한 적 없으면 pass
	//		if(memo[i][j] == -1) memo[i][j] = 0;

	//		for (int k = 0; k < 3; k++)
	//		{
	//			int nextY = i + dirY[k];
	//			int nextX = j + dirX[k];

	//			// 인덱스 범위 확인
	//			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

	//			// 다음이 더 작으면 경로 수 넣어주기
	//			if (map[i][j] > map[nextY][nextX])
	//			{
	//				if (memo[nextY][nextX] == -1)
	//				{
	//					// 다음 경로가 방문한 적 없으면 덮어쓰기
	//					memo[nextY][nextX] = memo[i][j];
	//				}
	//				else
	//				{
	//					// 방문 했었으면 더해주기
	//					memo[nextY][nextX] += memo[i][j];
	//				}
	//			}

	//		}
	//	}
	//}

	cout << memo[n - 1][m - 1];

}