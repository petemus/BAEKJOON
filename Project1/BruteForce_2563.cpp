// Brute Force > 색종이 (2563번)
// 풀이 시간 :
// 1) 겹치는 것들 고안해서 빼주기 -> 불가능
// 2) 도화지 전부 검사 

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// 100 * 100 도화지만큼 검사
	// 종이들의 크기만큼 저장하고 
	// 마지막에 모두 세주기

	bool picture[100][100] = { false, };
	for (int i = 0; i < n; i++)
	{
		int r, c;
		cin >> r >> c;
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				picture[r - 1 + j][c - 1 + k] = true;
			}
		}
	}

	// 마지막에 세주기
	int area = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (picture[i][j]) ++area;
		}
	}

	cout << area;
}