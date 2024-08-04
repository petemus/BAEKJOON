// Backtracking > 소문난 칠공주(1941번)
// 반 25명에서 7공주 구성 가지수는 -> 25C7 = 약 48만 (전체 탐색)
// lev = 7일때 칠공주 결성이 가능한지 확인

#include <iostream> 
#include <queue>
#include <vector>
using namespace std;

char classes[5][5];
bool isVisited[5][5] = { false, };
int possibleCnt = 0;
vector<pair<int,int>> p7;


// 함수 전방 선언
int BFS(int r, int c);
bool isPossible();


void Backtracking(int lev, int r, int c)
{
	// 종료 조건
	if (lev == 7)
	{
		// 가능하면 세주기
		if (isPossible()) possibleCnt++;
		return;
	}

	// 현재 선택한 위치의 오른쪽부터 가능
	for (int i = r; i < 5; i++)
	{
		int j = 0;
		if (i == r) j = c + 1;

		for (j; j < 5; j++)
		{
			// 방문하지 않았으면 선택
			if (!isVisited[i][j])
			{
				isVisited[i][j] = true;
				p7.push_back({ i,j });
				Backtracking(lev + 1, i, j);
				p7.pop_back();
				isVisited[i][j] = false;
			}
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> classes[i][j];
		}
	}


	// 모든 좌표에서 backtracking
	Backtracking(0, 0, -1);
	
	// 출력
	cout << possibleCnt;

}

int BFS(int r, int c)
{
	// 이어져 있는 개수 세주기
	queue<pair<int, int>> q;
	bool bfsisVisited[5][5] = { false, };
	int dirY[4] = { 0, 0, 1, -1 };
	int dirX[4] = { 1, -1, 0, 0 };

	q.push({ r, c });
	bfsisVisited[r][c] = true;

	int cnt = 1;
	while (!q.empty())
	{
		pair<int, int> tmp = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nX = tmp.first + dirY[i];
			int nY = tmp.second + dirX[i];
			if (nX >= 0 && nX < 5 && nY >= 0 && nY < 5 && !bfsisVisited[nY][nX] && isVisited[nY][nX])
			{
				q.push({ nY, nX });
				isVisited[nY][nX];
				++cnt;
			}
		}
	}

	return cnt;

}

bool isPossible()
{
	// 소문난 칠공주 가능한지 확인
	// 1. 솜파가 4명 이상인지 확인
	// 2. BFS로 7명 다 인접해있는지 확인
	int somCnt = 0;
	for (int i = 0; i < p7.size(); i++)
	{
		if (classes[p7[i].first][p7[i].second] == 'S') somCnt++;
	}
	if (somCnt < 4) return false;

	// BFS로 이어져 있는지 확인
	int cnt = BFS(p7[0].first, p7[0].second);

	if (cnt < 7) return false;
	else return true;

}