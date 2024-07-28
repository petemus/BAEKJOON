// Graph Search > A -> B (16953��)
// Ǯ�� �ð� :
// long long���� ������� => int ���� ������ �� ������� int������ ������ ������ ���� �߸����� => ���� 

#include <iostream>
#include <queue>
using namespace std;

int BFS(int a, int b)
{
	// first -> ����� ��  second -> ����Ƚ��
	queue<pair<long, long>> q;
	q.push({a, 1});

	while (!q.empty())
	{
		pair<long, long> now = q.front();
		q.pop();

		// ���� ���� Ȯ�� 
		if (now.first == b) return now.second;

		if (now.first * 2 <= b) q.push({ now.first * 2, now.second + 1 });
		if(now.first * 10 + 1 <= b) q.push({ now.first * 10 + 1, now.second + 1 });
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	//cout << BFS(a, b);
	cout << a * 10;

}

