// Brute Force > ������2 (14400��)

#include <iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	pair<int,int> pos[100000];

	for (int i = 0; i < n; i++)
	{
		int y, x;
		cin >> x >> y;
		pos[i] = {x, y};
	}

	cout << "���";
}