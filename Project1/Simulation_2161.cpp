// simulation > ī��1 (2161��)
// Ǯ�� �ð� : 6m
// ������ ���� �ڷ� �����ϴ� ������ ���� -> queue

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	queue<int> cards;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cards.push(i + 1);
	}

	// ī�� �Ѱ� ���������� �ݺ�
	while (true)
	{
		// �� �� ī�� ����
		if (cards.size() == 1) break;
		else
		{
			cout << cards.front() << ' ';
			cards.pop();
		}


		// ī�� �ڷ� ����
		if (cards.size() == 1) break;
		else
		{
			int t = cards.front(); cards.pop();
			cards.push(t);
		}
	}

	// ������ ī�� ���
	cout << cards.front();
}