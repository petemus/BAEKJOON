// Backtracking > �ҹ��� ĥ����(1941��)
// �� 25���� 7���� ���� �������� -> 25C7 = �� 48�� (��ü Ž��)
// lev = 7�϶� ĥ���� �Ἲ�� �������� Ȯ��

#include <iostream> 
#include <queue>
#include <vector>
using namespace std;

char classes[5][5];
bool isVisited[5][5] = { false, };
int possibleCnt = 0;
vector<pair<int,int>> p7;


// �Լ� ���� ����
int BFS(int r, int c);
bool isPossible();


void Backtracking(int lev, int r, int c)
{
	// ���� ����
	if (lev == 7)
	{
		// �����ϸ� ���ֱ�
		if (isPossible()) possibleCnt++;
		return;
	}

	// ���� ������ ��ġ�� �����ʺ��� ����
	for (int i = r; i < 5; i++)
	{
		int j = 0;
		if (i == r) j = c + 1;

		for (j; j < 5; j++)
		{
			// �湮���� �ʾ����� ����
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

	// �Է�
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> classes[i][j];
		}
	}


	// ��� ��ǥ���� backtracking
	Backtracking(0, 0, -1);
	
	// ���
	cout << possibleCnt;

}

int BFS(int r, int c)
{
	// �̾��� �ִ� ���� ���ֱ�
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
	// �ҹ��� ĥ���� �������� Ȯ��
	// 1. ���İ� 4�� �̻����� Ȯ��
	// 2. BFS�� 7�� �� �������ִ��� Ȯ��
	int somCnt = 0;
	for (int i = 0; i < p7.size(); i++)
	{
		if (classes[p7[i].first][p7[i].second] == 'S') somCnt++;
	}
	if (somCnt < 4) return false;

	// BFS�� �̾��� �ִ��� Ȯ��
	int cnt = BFS(p7[0].first, p7[0].second);

	if (cnt < 7) return false;
	else return true;

}