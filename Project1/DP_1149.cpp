// Dynamic Programing > RGB 거리 (1149번)
//

//

#include <iostream>
#include <vector>
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
	int minCost = 1000;
	vector<vector<int>> RGB;

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < n; j++)
		{
			int t;
			cin >> t;
			tmp.push_back(t);
		}
		RGB.push_back(tmp);
	}

	// DP
	int memo[1000];


	// 출력
	cout << minCost;
}