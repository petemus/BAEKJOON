// DP  > ���� �ﰢ�� (1932��)
// Ǯ�� �ð� : 30 m
// �� ������ �θ�κ��� �޴� �͵� �� �ִ� ���� ��

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
	vector<vector<int>> tree;
	// memo > ���� ��� ���� ��
	vector<vector<int>> memo;


	// �Է�
	// memo �ʱ�ȭ
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		vector<int> m;
		for (int j = 0; j < i + 1; j++)
		{
			int t;
			cin >> t;
			tmp.push_back(t);
			m.push_back(0);
		}
		tree.push_back(tmp);
		memo.push_back(m);
	}

	// DP
	memo[0] = tree[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j - 1 < 0) memo[i][j] = memo[i - 1][j] + tree[i][j];
			else if (j >= i) memo[i][j] = memo[i - 1][j - 1] + tree[i][j];
			// �׷��� ������ �� ���� ū �� ����
			else memo[i][j] = max(memo[i - 1][j - 1], memo[i - 1][j]) + tree[i][j];
		}
	}

	// �� ������ �迭 �� �ִ밪 ���
	cout << *max_element(memo[n - 1].begin(), memo[n - 1].end());
	





}