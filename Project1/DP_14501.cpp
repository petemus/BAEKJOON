// 3.���(14501) => O
// overlapping subproblem, optimal substrutcture ->  N�Ͽ����� �ִ� ������ N-1�Ͽ����� �ִ� ���� + �ڱ� �ڽ�
// ?? �ʹ� ����ó���� ���� �ߴµ� �̷��� Ǫ�� �� ������?


#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// ���� �迭 vector ����
	vector<pair<int, int>> cal;
	int calNote[16] = {};

	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		cal.push_back({ t, p });
		calNote[i] = p;
	}

	// �Ѱ��� �� -> �̶� �ִ� �ϼ� ���� ������ ���� ó�� �������
	// �Ѱ��� ���ʿ� �ִ� �����̶� ��

	int maxPay = 0;

	for (int i = 0; i < n; i++)
	{
		// ���� ��¥�� �ִ� ��¥�� �ʰ����� �ʴ��� �� 
		if ((i + cal[i].first) > n) continue;
		// ���ʿ� �ִ� ��¥���̶� �� ��
		for (int j = i - 1; j >= 0; j--)
		{
			// ���ʿ� �ִ� ��¥���� ���� ��¥�� �ʰ����� �ʴ��� �˻�
			if ((j + cal[j].first) > i) continue;
			// �� �ʰ��ϸ� ���� ��Ʈ ���� ��
			if ((calNote[j] + cal[i].second) > calNote[i]) calNote[i] = calNote[j] + cal[i].second;
		}

		// maxPay �� ����
		if (maxPay < calNote[i]) maxPay = calNote[i];
	}

	cout << maxPay;


}