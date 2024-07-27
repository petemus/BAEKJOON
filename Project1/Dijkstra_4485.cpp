// X Dijkstra > ��� �� ���� �ְ� ������? (4485��)
// Ǯ�� �ð� : 12 27
// rule
// 1) (0,0) -> (n-1,n-1) �� �̵� => �Ʒ� ���������θ� �̵� ���� => X
// 2) �ּ� ���� �ݾ��� ��? => ���Ǹ� �����ϴ� ���̺� �ʿ� 
// !! �ּҷ� �̵��ϴ� �� ���Ǹ� �ּҷ� ���� �� �ְ� �����ϴ� �� �ƴ� 

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
			// �Ʒ� �̵� ������ �̵� Ȯ�� �� �־��ֱ�
			int nY = now.first + dirY[i];
			int nX = now.second + dirX[i];
			if (nY >= 0 && nY < n && nX >= 0 && nX < n)
			{
				// ó�� �湮�ϸ� rupee���ؼ� �����ְ� ť�� �־��ְ�
				// �ι�° �湮�ϸ� �ּ� ���� �� ���ؼ� �־���
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

	cout << '\n' << "�հ� ���� : " << '\n';
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

		// ���� �Է�
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) cin >> rupee[i][j];
		}

		// Search 
		cout << "Problem " << tc << ": " << BFS(0, 0) << '\n';

	}


}