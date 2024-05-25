// Backtracking, ���Ʈ ���� > ������(1107)
// (1) Backtracking > �ڸ��� ��� ��Ʈ��ŷ
// 1. �ڸ� ���� �Ѿ�� ���� ���� ���� -> ���ڸ����� �߰�
// 2. 00100 �ڸ������ push�� �ϸ� ���� �߻� -> ���߿� �������൵
// (2) ���Ʈ ���� > �� ���� ������ backtracking


#include <iostream>
#include <math.h>
#include <string>
using namespace std;

bool breakNum[10] = { false, };
int minPush;
int now = 100;

bool isPossible(int num)
{
	string s = to_string(num);

	bool isPossible = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (breakNum[s[i] - '0']) isPossible = false;
	}

	return isPossible;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{9
		int tmp; 
		cin >> tmp;
		breakNum[tmp] = true;
	}

	// bruteForce 
	minPush = abs(n - now);

	for (int i = 0; i < 1000000; i++)
	{
		if (isPossible(i))
		{
			// push �� ��� ����
			// 1) ��ư ���� ��
			// 2) ������ ��
			int push = to_string(i).size();
			push += abs(n - i);
			// �ּҰ� ��
			if (minPush > push) minPush = push;
		}
	}

	// ���
	cout << minPush;

}