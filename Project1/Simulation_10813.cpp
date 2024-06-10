 // simulation > 공 바꾸기 (10813번)


#include <iostream>
#define SWAP(x, y) { int tmp = x; x = y; y = tmp; }
using namespace std;

int n, m;
int basket[105];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		basket[i] = i + 1;
	}

	// swap
	for (int i = 0; i < m; i++)
	{
		int indexA, indexB;
		cin >> indexA >> indexB;
		SWAP(basket[indexA -1], basket[indexB - 1]);
	}

	// 출력
	for (int i = 0; i < n; i++)
	{
		cout << basket[i] << ' ';
	}
}