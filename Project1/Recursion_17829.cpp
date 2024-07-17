// Recursion > 222-Ǯ�� (17829��)
// Ǯ�� �ð� : 7 35

// ! �迭 �ε��� ���� �߿� 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1024][1024] = {};
int dirX[4] = { 0, 1, 0, 1 };
int dirY[4] = { 0, 0, 1, 1 };

void divide(int n, int r, int c)
{
	// ���� ����
	if (n == 2)
	{
		// 4���� ���߿� �ι�° ū�� ������
		vector<int> sorted;
		for (int i = 0; i < 4; i++)
		{
			int tmpX = c + dirX[i];
			int tmpY = r + dirY[i];
			sorted.push_back(arr[tmpY][tmpX]);
		}
		sort(sorted.begin(), sorted.end());
		// �� ���� 
		arr[r / 2][c / 2] = sorted[2];
		return;
	}

	divide(n / 2, r, c);
	divide(n / 2, r, c + (n / 2));
	divide(n / 2, r + (n / 2), c);
	divide(n / 2, r + (n / 2), c + (n / 2));
}

int pooling(int n, int r, int c)
{
	// ���� ����
	if (n == 1) return arr[0][0];

	// 2��ŭ ������
	divide(n, 0, 0);

	// ���� �� �ٽ� pooling
	return pooling(n / 2, 0, 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << pooling(n, 0, 0);
}