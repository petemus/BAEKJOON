//  > ���� �ִܰŸ�(14940��)
// Ǯ�� �ð� : 40m (�ݷ� �����ϰ� ����!)

// BFS
// ��ǥ ������������ BFS ������ �ɵ� 
// Point1> �ݷ� ���� -> �� �� ���� ��ġ�� 0���� �������� ��..! bfs�϶� �ϸ� �Ϻδ� �ȵ� => �� �������� ����� ��. 


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> dis;

void BFS(int gX, int gY)
{
	
	// ���� �迭
	int dirX[4] = {0, 0, 1, -1};
	int dirY[4] = {1, -1, 0, 0};
	// �湮 üũ �迭 
	vector<vector<bool>> isVisitied(n, vector<bool>(m, false));

	// ť
	queue<pair<int,int>> q;

	// �ʱⰪ
	q.push({gX, gY});
	isVisitied[gY][gX] = true;
	dis[gY][gX] = 0;

	// BFS
	while (!q.empty())
	{
		pair<int,int> nowPos = q.front();
		q.pop();

		// 4���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int nextX = nowPos.first + dirX[i];
			int nextY = nowPos.second + dirY[i];

			// �� ��ġ �� �� �ִ��� üũ
			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
			{
				// �湮���� �ʾ����� �� �� �־��ֱ� 
				if (!isVisitied[nextY][nextX])
				{
					// �� �� ���� ���̸� 0 ����
					if (map[nextY][nextX] == 1)
					{
						// �Ÿ� �־��ֱ� + ť�� �־��ֱ� + �湮 üũ
						dis[nextY][nextX] = dis[nowPos.second][nowPos.first] + 1;
						q.push({ nextX, nextY });
						isVisitied[nextY][nextX] = true;
					}

				}
			}
		}

	}


}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> n >> m;

	// �迭 �ʱ�ȭ
	map.resize(n, vector<int>(m, 0));
	dis.resize(n, vector<int>(m, -1));

	int gX = 0, gY = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int v;
			cin >> v;

			map[i][j] = v;

			if (v == 2)
			{
				// �� �ε��� ����
				gY = i;
				gX = j;
			}
			
		}
	}

	// BFS�� �Ÿ� �� üũ�� dis �迭 ���
	BFS(gX, gY);



	// output
	// ���� �� �� ���� �� 0���� ����
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] == 0)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << dis[i][j] << ' ';
			}
		}
		cout << '\n';
	}





}