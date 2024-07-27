// X Dijkstra > 녹색 옷 입은 애가 젤다지? (4485번)
// 풀이 시간 : 12 27
// rule
// 1) (0,0) -> (n-1,n-1) 로 이동 => 아래 오른쪽으로만 이동 가능 => X
// 2) 최소 잃은 금액은 얼마? => 루피를 저장하는 테이블 필요 
// !! 최소로 이동하는 게 루피를 최소로 잃을 수 있게 보장하는 게 아님 

#include <iostream>
#include <queue>
using namespace std;


int n;
int rupee[125][125] = { 0, };

int dirY[2] = { 1, 0 };
int dirX[2] = { 0, 1 };

int BFS(int y, int x)
{
	int sumRupee[125][125] = { 0, };
	bool isVisted[125][125] = { false, };
	queue<pair<int, int>> q;

	q.push({ y, x });
	isVisted[y][x] = true;
	sumRupee[y][x] = rupee[y][x];

	while(!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			// 아래 이동 오른쪽 이동 확인 후 넣어주기
			int nY = now.first + dirY[i];
			int nX = now.second + dirX[i];
			if (nY >= 0 && nY < n && nX >= 0 && nX < n)
			{
				// 처음 방문하면 rupee합해서 더해주고 큐에 넣어주고
				// 두번째 방문하면 최소 루피 수 구해서 넣어줌
				if (!isVisted[nY][nX])
				{
					isVisted[nY][nX] = true;
					sumRupee[nY][nX] = sumRupee[now.first][now.second] + rupee[nY][nX];
					q.push({ nY, nX });
				}
				else
				{
					if(sumRupee[now.first][now.second] + rupee[nY][nX] < sumRupee[nY][nX])
						sumRupee[nY][nX] = sumRupee[now.first][now.second] + rupee[nY][nX];
				}
			}

		}
	}

	cout << '\n' << "합계 루피 : " << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << sumRupee[i][j] << " ";
		}
		cout << '\n';
	}

	return sumRupee[n - 1][n - 1];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 0;
	while (true)
	{
		cin >> n;
		++tc;

		if (n == 0) break;

		// 루피 입력
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) cin >> rupee[i][j];
		}

		// Search 
		cout << "Problem " << tc << ": " << BFS(0, 0) << '\n';

	}


}