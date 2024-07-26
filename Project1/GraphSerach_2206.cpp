// Graph Search > 벽 부수고 이동하기(2206번)
// 블록 부수기 가능 -> 블록 부수고 방문과 그냥 방문 구분 => isVisited를 두개 만들기

// Error> 메모리 초과 -> isVisited 확인 잘 안해준 문제
// Error> 벽을 뚫은 경로인지 bisVisited만으로 확인하기 힘듬


// checkPoint
// 1) 벽을 부수고 방문했는지 체그하는 것과 벽을 부수지 않고 방문했는지를 따로 체크해줘야함
// 2) 벽을 부쉈는지를 확인할 수 있는 변수가 필요함 -> 그 변수는 이동할 경로가 가지고 있어야하므로
//    Q에 넣는 요소가 가지고 있어야함. -> 여러 개의 변수를 하나로 관리 필요 
// 3) 벽이 아닐때의 케이스를 잘 나눠줘야함 -> 복잡해서 주의 필요 


#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[1000][1000];

bool isVisited[1000][1000] = { false, };
bool bisVisited[1000][1000] = { false, };
int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {1, -1, 0, 0};

struct Pos
{
	int x;
	int y;
	bool isBlock = false;
	Pos(int y, int x, bool isBlock)
	{
		this->x = x;
		this->y = y;
		this->isBlock = isBlock;
	}
	Pos(){}
};



int BFS(int y, int x)
{

	queue<pair<Pos,int>> q;

	q.push({Pos(y, x, false), 1});
	isVisited[y][x] = true;

	while (!q.empty())
	{
		pair<Pos, int> now = q.front();
		q.pop();

		// 종료 조건 
		if(now.first.y == n -1 && now.first.x == m - 1) return now.second;

		for (int i = 0; i < 4; i++)
		{
			int nX = now.first.x + dirX[i];
			int nY = now.first.y + dirY[i];

			if (nX >= 0 && nX < m && nY >= 0 && nY < n)
			{
				// 벽이면, 벽 깨지 않았을때 push 
				// but, next가 방ㅇ문하지 않았어야 함 
				if (map[nY][nX] == '1' && !now.first.isBlock && !bisVisited[nY][nX])
				{
					q.push({Pos(nY, nX, true), now.second + 1});
					bisVisited[nY][nX] = true;
					
				}
				// 벽 아니면, 걍 push (but 방문 하지 않아야함 !isVisited)
				// > now의 blockisVisited 가 참이면 blockisVisited 참 설정 
				// > 그렇지 않으면 isVisited 참 설정
				else if(map[nY][nX] == '0')	
				{
					if (now.first.isBlock && !bisVisited[nY][nX])
					{
						q.push({ Pos(nY, nX, now.first.isBlock), now.second + 1 });
						bisVisited[nY][nX] = true;

					}
					else  if(!now.first.isBlock && !isVisited[nY][nX])
					{
						q.push({ Pos(nY, nX, now.first.isBlock), now.second + 1 });
						isVisited[nY][nX] = true;
					}
				}

			}
		}

	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}

	cout << BFS(0, 0);
}