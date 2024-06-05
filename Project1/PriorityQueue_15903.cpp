// Priority Queue > ī�� ��ü ���� (15903��)
// Ǯ�� �ð� : 10m 
// �ּҰ��� ���ϴ� ���̱� ������ ������������ �����ʿ� 
// ! �յ��� ���� �ſ� Ŀ�� �� �����Ƿ� x,y, point �� �ڷ����� longlong�̾�� ��

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		pq.push(input);
	}

	// ��� 2�� ������ �� �ٽ� �־��ֱ�
	for (int i = 0; i < m; i++)
	{
		long long x, y;
		x = pq.top(); pq.pop();
		y = pq.top(); pq.pop();
		pq.push(x + y);
		pq.push(x + y);
	}

	// ���� ���
	long long point = 0;
	while (!pq.empty())
	{
		point += pq.top();
		pq.pop();
	}

	cout << point;
}