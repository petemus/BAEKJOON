// Dynamic Programing > RGB �Ÿ� (1149��)
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

	// �Է�
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


	// ���
	cout << minCost;
}