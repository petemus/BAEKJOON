// Graph Search > �� �μ��� �̵��ϱ�(2206��)
// ��� �μ��� ���� -> ��� �μ��� �湮�� �׳� �湮 ���� => isVisited�� �ΰ� �����

// Error> �޸� �ʰ� -> isVisited Ȯ�� �� ������ ����
// Error> ���� ���� ������� bisVisited������ Ȯ���ϱ� ����


// checkPoint
// 1) ���� �μ��� �湮�ߴ��� ü���ϴ� �Ͱ� ���� �μ��� �ʰ� �湮�ߴ����� ���� üũ�������
// 2) ���� �ν������� Ȯ���� �� �ִ� ������ �ʿ��� -> �� ������ �̵��� ��ΰ� ������ �־���ϹǷ�
//    Q�� �ִ� ��Ұ� ������ �־����. -> ���� ���� ������ �ϳ��� ���� �ʿ� 
// 3) ���� �ƴҶ��� ���̽��� �� ��������� -> �����ؼ� ���� �ʿ� 


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

		// ���� ���� 
		if(now.first.y == n -1 && now.first.x == m - 1) return now.second;

		for (int i = 0; i < 4; i++)
		{
			int nX = now.first.x + dirX[i];
			int nY = now.first.y + dirY[i];

			if (nX >= 0 && nX < m && nY >= 0 && nY < n)
			{
				// ���̸�, �� ���� �ʾ����� push 
				// but, next�� �椷������ �ʾҾ�� �� 
				if (map[nY][nX] == '1' && !now.first.isBlock && !bisVisited[nY][nX])
				{
					q.push({Pos(nY, nX, true), now.second + 1});
					bisVisited[nY][nX] = true;
					
				}
				// �� �ƴϸ�, �� push (but �湮 ���� �ʾƾ��� !isVisited)
				// > now�� blockisVisited �� ���̸� blockisVisited �� ���� 
				// > �׷��� ������ isVisited �� ����
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