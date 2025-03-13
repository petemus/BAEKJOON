// ����, ��Ž > ���� ���簢��(1051��)
// Ǯ�� �ð� : 20m 

// point 1 > ��, �� �������� ã���ָ� �� -> �������� �� �ߺ� �� 

#include <iostream>
using namespace std;


int n, m;
int square[52][52];

// (i, j)��ġ�� �ִ� square ������ 
int MaxSquare(int y, int x)
{
	// (i, j)���� ��, �� �������� �������� ���� �ִ� ���簢�� ã���ֱ� 
	
	// �� ���� �� ã����� ��
	int maxLength = (n - y) < (m - x) ? n - y : m - x;

	int area = 1;
	for (int i = 1; i < maxLength; ++i)
	{
		// 4 ������ �� ã�� 
		int v = square[y][x];
		if (v == square[y + i][x] && v == square[y][x + i] && v == square[y + i][x + i])
		{
			// �������� �� ������ �� ũ�� �־��� 
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
			// ũ�� Ȯ�� 
			if(area > maxArea) maxArea = area;
		}
	}

	// Output
	cout << maxArea;


}