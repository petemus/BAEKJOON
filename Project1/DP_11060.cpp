// DP, BFS > 점프 점프 (11060번)
// 풀이 시간 : 40m -> 예외 발생할 수 있는 거를 찾는게 오래 걸림...

// !가장 오른쪽 끝으로 갈 수 없는 경우 -1 출력
// !도달하지 못한 칸과 0번 이동을 구분해줘야 함


// 예외!!) 도달하지 못했는데 점프 판단을 할 수 있음....

// 풀이 2) BFS(최소 경로이므로 적절)
// 최소 경로를 찾는거므로 가능
// maximun 100 * 1000 = 10만이므로 가능할듯


#include <iostream>	
#include <algorithm>	// min, max 
#include <cstring> // memset
using namespace std;

// 최소 점프 수가 저장되는 배열
int memo[1001];
// 미로 배열
int maze[1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> maze[i];
	}

	// dp
	// 초기화, size : 크기 * 바이트
	memset(memo, -1, sizeof(maze));
	memo[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		// @@@@ 방문하지 않은 곳이면 pass 해야함
		if(memo[i] < 0) continue;

		for (int j = 1; j <= maze[i]; ++j)
		{
			// 배열 크기 체크
			if(i + j >= n) break;

			// 방문했으면 최소값 비교
			if (memo[i + j] >= 0)
				memo[i + j] = min(memo[i + j], memo[i] + 1);
			else 
				// 방문 안했으면 바로 값 넣어줌 
				memo[i + j] = memo[i] + 1;
		}
	}


	// output
	if(memo[n - 1] == 0 && n != 1) cout << -1;
	else cout << memo[n - 1];


}