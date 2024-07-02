// Priority Queue > ����� ���ؿ� (1655��) -> X
// Ǯ�� �ð� :
// 1) ���ö����� �����ؼ� ��� �� ��� -> �ð� ���⵵ O(n^2logn) ���� ���ͼ� �ð� �ʰ����� 
// 2) �켱 ���� ť ��� -> (?) ����� ��� ����? => queue�� size�� �����ؼ� ������ pop (X) => pop�ع��� ���� ���� �Ұ�
// 3) ������ŭ pop�ϰ� �ٽ� �־��� -> �ð� �ʰ� �ϱ�ä���


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		// �� �ֱ�
		int n;
		cin >> n;
		pq.push(n);

		int popNum = i / 2;
		vector<int> pops;
		// popNum��ŭ pop���ְ� top ���
		// pop�� �͵��� vector�� �ӽ������� �����ϰ� ���߿� �ٽ� �־���
		for (int j = 0; j < popNum; j++)
		{
			int top = pq.top();
			pops.push_back(top);
			pq.pop();
		}
		cout << pq.top() << '\n';
		for (int j = 0; j < pops.size(); j++)
		{
			pq.push(pops[j]);
		}
	}

}

