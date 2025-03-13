// 구현, 완탐 > 숫자 정사각형(1051번)
// 풀이 시간 : 20m 

// point 1 > 우, 하 기준으로 찾아주면 됨 -> 나머지는 다 중복 됨 

#include <iostream>
using namespace std;


int n, m;
int square[52][52];

// (i, j)위치의 최대 square 구해줌 
int MaxSquare(int y, int x)
{
	// (i, j)에서 우, 하 기준으로 꼭짓점이 같은 최대 정사각형 찾아주기 
	
	// 더 작은 걸 찾아줘야 함
	int maxLength = (n - y) < (m - x) ? n - y : m - x;

	int area = 1;
	for (int i = 1; i < maxLength; ++i)
	{
		// 4 꼮지점 다 찾기 
		int v = square[y][x];
		if (v == square[y + i][x] && v == square[y][x + i] && v == square[y + i][x + i])
		{
			// 꼭지점이 다 같으면 그 크기 넣어줌 
			area = (i + 1) * (i + 1);
		}
	}
	
	return area;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); ++j)
		{
			square[i][j] = s[j] - '0';
		}
	}

	// Brute Force
	int maxArea = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int area = MaxSquare(i, j);
			// 크기 확인 
			if(area > maxArea) maxArea = area;
		}
	}

	// Output
	cout << maxArea;


}