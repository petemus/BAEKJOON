// 구현, 백트랙킹  > 테트로미노(14500번)
// 풀이 시간 : 40 ~ 50m


// point1> 5가지의 테트로미노의 규칙을 잘 보면 4개로 이어져 있는 모든 경로가 5개의 테트로미노로 표현 가능
//			-> bfs로 이어져있는 부분만 찾아서 완탐하면 됨
// point2> 탐색할때 4개면 그만해야 하므로 재귀가 적당할듯
// point3> 간과 ->  ㅗ, ㅜ, ㅓ, ㅏ 같은 모양은 일반적으로 4방향 탐색과 좀 다름
//			=> 경우의 수가 하나므로 저 모양만 체크 해줌 



#include <iostream>
#include <vector>
using namespace std;


int n, m;
vector<vector<int>> papers;

// 방향 배열 
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};
// 방문 체크 배열
vector<vector<bool>> isVisited;

// 칸의 최대 합
int maxSum = 0; 

void Backtracking(int x, int y, int cellNum, int sum)
{
	
	// 종료 조건 
	if (cellNum >= 4)
	{
		// 최대값 비교
		if(sum > maxSum) maxSum = sum;
		return;
	}


	// 탐색
	for (int i = 0; i < 4; ++i)
	{
		int nextX, nextY;
		nextX = x + dirX[i];
		nextY = y + dirY[i];

		if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;

		if (!isVisited[nextY][nextX])
		{
			// 방문하지 않았으면 방문
			isVisited[nextY][nextX] = true;
			Backtracking(nextX, nextY, cellNum + 1, sum + papers[nextY][nextX]);
			isVisited[nextY][nextX] = false;
		}
	}
	

}


void CheckSpecialCase(int x, int y)
{

	for (int i = 0; i < 4; ++i)
	{
		int index = i;
		int sum = papers[y][x];

		for (int j = 0; j < 3; ++j)
		{
			index = (index + j) % 4;
			
			int nY = y + dirY[index];
			int nX = x + dirX[index];

			if(nY < 0 || nY >= n || nX < 0 || nX >= m) break;

			sum += papers[nY][nX];
		}

		if(sum > maxSum) maxSum = sum;

	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// *input*
	cin >> n >> m;
	// resize
	papers.resize(n, vector<int>(m, 0));
	isVisited.resize(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> papers[i][j];
		}
	}


	// 모든 경우에서 그래프 탐색 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			// 배열 값 초기화
			for (int k = 0; k < n; ++k) fill_n(isVisited[k].begin(), m, false);

			// 일반 탐색
			isVisited[i][j] = true;
			Backtracking(j, i, 1, papers[i][j]);
			// 특수 케이스 탐색 
			CheckSpecialCase(j, i);
		}
	}


	// Output
	cout << maxSum;


}