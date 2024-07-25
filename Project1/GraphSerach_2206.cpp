// Graph Search > �� �μ��� �̵��ϱ�(2206��)
// ��� �μ��� ���� -> ��� �μ��� �湮�� �׳� �湮 ���� => isVisited�� �ΰ� �����


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
	Pos(int y, int x)
	{
		this->x = x;
		this->y = y;
	}
	Pos();
};



int BFS(int y, int x)
{

	queue<pair<Pos,int>> q;

	q.push({Pos(y, x), 1});
	isVisited[y][x] = true;

	while (!q.empty())
	{
		pair<Pos, int> now = q.front();
		q.pop();

		// ���� ���� 
		if(now.first.y == n -1 && now.first.y == n - 1) return now.second;

		for (int i = 0; i < 4; i++)
		{
			int nX = now.first.x + dirX[i];
			int nY = now.first.y + dirY[i];

			if (nX >= 0 && nX < m && nY >= 0 && nY < n)
			{
				// ���̸�, �� ���� �ʾ����� push 
				// 
				if (map[nY][nX] == '1' && !bisVisited[now.first.y][now.first.x])
				{
				}
				
				// �� �ƴϸ�, �� push (but �湮 ���� �ʾƾ��� !isVisited)
				// > now�� blockisVisited �� ���̸� blockisVisited �� ���� 
				// > �׷��� ������ isVisited �� ����


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