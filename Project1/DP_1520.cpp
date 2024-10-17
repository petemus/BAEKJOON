// DP > ������ ��(1520��)
// ! �ִ� ���̰� �ƴ϶� ���̰� �� ���� �������� ���� ����� �� 
// ��Ʈ��ŷ���� ���� -> but, �ð� �������� ���ؼ� dp�� Ǯ����� �� ����
// ������������ ��� �;��ϳ� 
// ����ü ������ ��ġ�� �κ��� ����� -> !!�� ū ���� �湮�ϴ� �� ����Ʈ => �׷��� �� ���� ��� ������ �̵������� �ϳ�

#include <iostream>
#include <memory.h>
using namespace std;

int n, m;
// (0, 0) -> (i, j)�� �� �� �ִ� ��� �� 
int memo[500][500] = {0,};
int map[500][500] = {0,};

// direction �迭 (���δ� ����)
int dirX[4] = { 0, -1, 1, 0};
int dirY[4] = { -1, 0, 0, 1 };

int DP(int y, int x)
{
	// ���� ����
	if (memo[y][x] != -1)
	{
		// memo�� �Ǿ��� ������ return
		return memo[y][x];
	}


	int sum = 0;
	for (int k = 0; k < 4; k++)
	{
		int prevY = y + dirY[k];
		int prevX = x + dirX[k];

		// �ε��� ���� �Ѿ�� pass
		if (prevY < 0 || prevY >= n || prevX < 0 || prevX >= m) continue;

		// ������ ũ�� �湮
		if (map[prevY][prevX] > map[y][x])
		{
			sum += DP(prevY, prevX);;
		}
	}
	return memo[y][x] = sum;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// Input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	// memo �ʱ�ȭ
	memset(memo, -1, 500 * 500 * sizeof(int));

	// memo �ʱⰪ
	memo[0][0] = 1;
	int result = DP(n - 1, m - 1);

	cout << result;
	
	

}