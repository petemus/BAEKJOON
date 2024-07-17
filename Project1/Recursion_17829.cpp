// Recursion > 222-풀링 (17829번)
// 풀이 시간 : 7 35

// ! 배열 인덱스 선정 중요 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1024][1024] = {};
int dirX[4] = { 0, 1, 0, 1 };
int dirY[4] = { 0, 0, 1, 1 };

void divide(int n, int r, int c)
{
	// 종료 조건
	if (n == 2)
	{
		// 4개의 값중에 두번째 큰값 구해줌
		vector<int> sorted;
		for (int i = 0; i < 4; i++)
		{
			int tmpX = c + dirX[i];
			int tmpY = r + dirY[i];
			sorted.push_back(arr[tmpY][tmpX]);
		}
		sort(sorted.begin(), sorted.end());
		// 값 저장 
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
	// 종료 조건
	if (n == 1) return arr[0][0];

	// 2만큼 나누기
	divide(n, 0, 0);

	// 구한 값 다시 pooling
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