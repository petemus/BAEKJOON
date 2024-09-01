// Brute Force > 편의점2 (14400번)
// x모음에서 최소랑 y 모음에서 최소이면 됨
// 즉 x랑 y랑 따로 하면 됨 -> 독립 시행 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> posX(n);
	vector<int> posY(n);

	for (int i = 0; i < n; i++)
	{
		int y, x;
		cin >> x >> y;
		posX[i] = x;
		posY[i] = y;
	}

	// x,y 각각 따로 정렬
	sort(posX.begin(), posX.end());
	sort(posY.begin(), posY.end());

	int midX = 0, midY = 0;
	midX = n / 2;
	midY = n / 2;

	long long sumX = 0, sumY = 0;
	for (int i = 0; i < n; i++)
	{
		sumX += abs(posX[midX] - posX[i]);
		sumY += abs(posY[midY]- posY[i]);
	}

	cout << sumX + sumY;

	
}