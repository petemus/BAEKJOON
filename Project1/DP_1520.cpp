// DP > ������ ��(1520��)
// ! �ִ� ���̰� �ƴ϶� ���̰� �� ���� �������� ���� ����� �� 
// ��Ʈ��ŷ���� ���� -> but, �ð� �������� ���ؼ� dp�� Ǯ����� �� ����
// ������������ ��� �;��ϳ� 
// ����ü ������ ��ġ�� �κ��� �����

#include <iostream>
#include <memory.h>
using namespace std;

int n, m;
// (0, 0) -> (i, j)�� �� �� �ִ� ��� �� 
int memo[500][500] = {0,};
int map[500][500] = {0,};

// direction �迭 (���δ� ����)
int dirX[3] = { 0, -1, 1};
int dirY[3] = { -1, 0, 0 };

int DP(int y, int x)
{
	// ���� ����
	if (memo[y][x] != -1)
	{
		// memo�� �Ǿ��� ������ return
		return memo[y][x];
	}


	int sum = 0;
	for (int k = 0; k < 3; k++)
	{
		int prevY = y + dirY[k];
		int prevX = x + dirX[k];

		// �ε��� ���� �Ѿ�� pass
		if (prevY < 0 || prevY >= n || prevX < 0 || prevX >= m) continue;

		memo[prevY][prevX] = DP(prevY, prevX);
		sum += memo[prevY][prevX];
	}
	return sum;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ��� (i, j)���� ���� �¿�� �� ���ٰ� ������ �ּ��� �͸� �����س�����

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
	DP(n, m);
	
	// ��� (i, j) dp
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		//�Ʒ� ��, �� ��ġ�� �� ���ִ� ��� ���� �ְ� ���� �� ������ ��� ���� ���ϱ�
	//		// �湮�� �� ������ pass
	//		if(memo[i][j] == -1) memo[i][j] = 0;

	//		for (int k = 0; k < 3; k++)
	//		{
	//			int nextY = i + dirY[k];
	//			int nextX = j + dirX[k];

	//			// �ε��� ���� Ȯ��
	//			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

	//			// ������ �� ������ ��� �� �־��ֱ�
	//			if (map[i][j] > map[nextY][nextX])
	//			{
	//				if (memo[nextY][nextX] == -1)
	//				{
	//					// ���� ��ΰ� �湮�� �� ������ �����
	//					memo[nextY][nextX] = memo[i][j];
	//				}
	//				else
	//				{
	//					// �湮 �߾����� �����ֱ�
	//					memo[nextY][nextX] += memo[i][j];
	//				}
	//			}

	//		}
	//	}
	//}

	cout << memo[n - 1][m - 1];

}