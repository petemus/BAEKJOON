// Simulation > �Ʊ� ��� (16236��)
// Ǯ�� �ð� : 2h
// BFS ����Ͽ� �ִ� �Ÿ� �̵��ϸ鼭 Ǫ�� ���� ����
// (-) �Ÿ��� ����� ����Ⱑ ���������϶� �켱���� ����⸦ ã����� ��

#include <iostream>
#include <queue>
using namespace std;

struct Position
{
	int x;
	int y;
	Position(int y, int x)
	{
		this->x = x;
		this->y = y;
	}
	Position() {}
};

int n;		
int space[20][20];
int sharkSize = 2;
int eatFish = 0;
Position sharkPos;

int fishNum[7] = { 0, };		// ����� ũ�⿡ ���� ����

// ��, ��, ��, ��
int dirX[] = {0, -1, 1, 0};
int dirY[] = { -1, 0, 0, 1 };

//BFS
// ����⸦ ã�� �� �ɸ� �ð� ��ȯ 
// ����� ��ã���� -1 ��ȯ 
int FindFish()
{
	// ��ġ , �̵� �ð� 
	queue<pair<Position, int>> q;
	bool isVisited[20][20] = { false, };

	q.push({ sharkPos, 0 });
	isVisited[sharkPos.y][sharkPos.x] = true;

	// ť�� ��� ����⸦ �� ����
	int shortX, shortY;
	int shortSec = 400;
	bool isFind = false;
	while (!q.empty())
	{
		pair<Position, int> nMove = q.front();
		q.pop();

		// �̵��� �� �ִ� ���� push
		// �ڱ� size���� �۾ƾ� ��
		// ����� �ڱ� ũ�� ��ŭ ������ ũ�� ��
		for (int i = 0; i < 4; i++)
		{
			int nX = nMove.first.x + dirX[i];
			int nY = nMove.first.y + dirY[i];
			// �̵��� �� �ִ� �������� Ȯ��
			if (nX >= 0 && nX < n && nY >= 0 && nY < n)
			{
				// �湮�� �������� üũ
				if (isVisited[nY][nX]) continue;

				// �� �����̰ų� ���� ũ���� ������ ��� Push
				if (space[nY][nX] == 0 || sharkSize == space[nY][nX])
				{
					q.push({ Position(nY, nX), nMove.second + 1 });
					isVisited[nY][nX] = true;
				}
				else if (sharkSize > space[nY][nX])
				{
					// �Ÿ��� ���� �� �켱���� ã���� 
					if (isFind && nMove.second == shortSec)
					{
						if (shortY > nY)
						{
							shortX = nX;
							shortY = nY;
						}
						else if (shortY == nY)
						{
							if (shortX > nX)
							{
								shortX = nX;
								shortY = nY;
							}
						}
						continue;
					}
					else if (isFind && nMove.second > shortSec) break;
					
					// �ִ� �Ÿ��� �ִ� ����⸦ ó�� �߰��Ҷ� 
					shortX = nX;
					shortY = nY;
					shortSec = nMove.second;
					isFind = true;
					continue;
				}
				// ���� ũ�� pass
				else continue;
			}
		}

	}

	if (isFind)
	{
		// �Ա�
		eatFish++;
		// ũ�� ���� 
		if (eatFish == sharkSize)
		{
			++sharkSize;
			eatFish = 0;
		}
		// ���� ������ �Ա�
		// ���� �� �ִ� ����Ⱑ ���� �������� üũ
		// ���� ���� �߿� Y �� ���� �۰� X�� ���� ���� ������ �Ա� 
		// ��� ����
		space[sharkPos.y][sharkPos.x] = 0;
		space[shortY][shortX] = 9;
		sharkPos.x = shortX;
		sharkPos.y = shortY;
		return shortSec + 1;
	}
	else return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �Է�
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			space[i][j] = tmp;
			// fish ���� ����
			if(tmp > 0 && tmp < 7)	fishNum[tmp]++;

			if (space[i][j] == 9) sharkPos = Position(i, j);
		}
	}

	// ���� �� ���� ����Ⱑ ���������� ����
	// ū ����⿡ ���� ���������� �� ���� 
	// -> BFS�� ��� ����� ��Ƹ����� ��
	// -> ����� �� ã���� break;

	int eatTime = 0;
	while (true)
	{
		// ������ ��
		int sec = FindFish();

		if (sec < 0) break;
		else eatTime += sec;

	}

	cout << eatTime;

}