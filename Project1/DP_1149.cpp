// Dynamic Programing > RGB �Ÿ� (1149��)
// ���� �߸� ���� �̽� -> ���� ��� i ��°�� i-1 ��°�� ������ �޶�� ��. or i������ i + 1���� ������ �޶�� ��

// -------------------------------------------------
// std::min() std::max() : �ּ�, �ִ� �����ִ� �Լ� 
// #include <algorithm> / min_element(first, last), max_element(first, last) : first���� last ������ �ִ� �ּ� iterator�� ��ȯ
// -------------------------------------------------


#include <iostream>
#include <vector>
#include <algorithm>	// min_element(), max_element()  
using namespace std;

enum Color
{
	RED = 0,
	GREEN,
	BLUE
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int red[1000];
	int green[1000];
	int blue[1000];

	// �Է�
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> red[i] >> green[i] >> blue[i];
	}


	// memo i�� r, g, b�϶��� �ּڰ� ����
	int memo[1000][3];

	memo[0][RED] = red[0]; memo[0][BLUE] = blue[0]; memo[0][GREEN] = green[0];

	for (int i = 1; i < n; i++)
	{
		memo[i][RED] = min(memo[i-1][GREEN], memo[i-1][BLUE]) + red[i];
		memo[i][GREEN] = min(memo[i - 1][RED], memo[i - 1][BLUE]) + green[i];
		memo[i][BLUE] = min(memo[i - 1][GREEN], memo[i - 1][RED]) + blue[i];
	}

	cout << *min_element(memo[n - 1], memo[n - 1] + 3);

}