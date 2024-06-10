// simulation > ������ ť(1966��)
// Ǯ�� �ð� : 
// �߿䵵�� ���� �μ��ؾ� �� 
// �ڷᱸ�� ��� -> ť, stack �� iterator ���� / �迭 -> ��� ��� �� �Ű���� ��
// => deque
// ?? �����̳ʸ� �Ű������� �־��ָ� ��� �ǳ�??

#include <iostream>
#include <deque>
using namespace std;

bool isBigger(deque<pair<int, int>> dq)
{
	// �� ���� ��Һ��� ū ��Ұ� ������ Ȯ��
	deque<pair<int, int>>::iterator iter = dq.begin();
	int frontImport = (*iter).second;
	while (iter != dq.end())
	{
		int comp = (*iter).second;
		if (frontImport < (*iter).second) return false;
		++iter;
	}
	return true;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	int n, m;

	cin >> testcase;

	while (testcase--)
	{
		// �Է�
		cin >> n >> m;
		deque<pair<int,int>> dq;	// index, �߿䵵
		for (int i = 0; i < n; i++)
		{
			int e;
			cin >> e;
			dq.push_back({i, e});
		}

		// �߿䵵�� ���� ���
		// �߿䵵�� ū ����� ���� ���� ã�� �ε����� ���
		int num = 0;
		while (true)
		{
			if (isBigger(dq))
			{
				// �μ�
				num++;
				if (dq.front().first == m)
				{
					cout << num << '\n';
					break;
				}
				else dq.pop_front();
			}
			else
			{
				// ���� �ڿ��ٰ� ��ġ
				pair<int, int> front = dq.front(); dq.pop_front();
				dq.push_back(front);
			}
		}

	}

}