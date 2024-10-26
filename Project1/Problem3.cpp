// 3> 미니 카트라이더
// # DP
// 이것도 DP문제 -> 1차선인 경우 2차선인 경우
// 풀이 시간: 1시간... 구현하는데 생각보다 오래 걸림
// > 최대값 최소값일때 저장되는 값을 뭘로할지가 중요


#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAXINDEX 100001
// 각각 1번씩 이동한다고 가정하면 최대 10만
#define MAXMOVE 200000

// 1차선인 경우 2차선인 경우 3차선인 경우 나눠서 저장
// [차선][인덱스(시간?)] = 최소 이동 횟수
int memo[3][MAXINDEX];


int minimumMovement(vector<int>& obstacles)
{

	// memo 초기값 저장 -> 시작 위치 2번 라인
	memo[1][0] = 0; 
	memo[2][0] = MAXMOVE; memo[0][0] = MAXMOVE;

	int n = obstacles.size();

	for (int i = 1; i <= obstacles.size(); i++)
	{

		memo[0][i] = MAXMOVE;
		memo[1][i] = MAXMOVE;
		memo[2][i] = MAXMOVE;
		 

		if (memo[0][i - 1] < MAXMOVE)
		{	
			// 장애물 있는 곳이 아니면 저장
			if(obstacles[i - 1] != 1) memo[0][i] = min(memo[0][i - 1], memo[0][i]);
			if(obstacles[i - 1] != 2) memo[1][i] = min(memo[0][i - 1] + 1, memo[1][i]);
			if(obstacles[i - 1] != 3) memo[2][i] = min(memo[0][i - 1] + 1, memo[2][i]);
		}
		if (memo[1][i - 1] < MAXMOVE)
		{
			if(obstacles[i - 1] != 1) memo[0][i] = min(memo[1][i - 1] + 1, memo[0][i]);
			if(obstacles[i - 1] != 2) memo[1][i] = min(memo[1][i - 1], memo[1][i]);
			if(obstacles[i - 1] != 3) memo[2][i] = min(memo[1][i - 1] + 1, memo[2][i]);
		}
		if (memo[2][i - 1] < MAXMOVE)
		{
			if(obstacles[i - 1] != 1) memo[0][i] = min(memo[2][i - 1] + 1, memo[0][i]);
			if(obstacles[i - 1] != 2) memo[1][i] = min(memo[2][i - 1] + 1, memo[1][i]);
			if(obstacles[i - 1] != 3) memo[2][i] = min(memo[2][i - 1], memo[2][i]);
		}
	}

	return min({memo[0][n], memo[1][n], memo[2][n]});
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> obstacles = {3, 2, 3, 1, 2, 2};


	cout << minimumMovement(obstacles);

}
