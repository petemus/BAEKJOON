// Greedy > �� �߱� (2170��)
// Ǯ�� �ð� : 8 5
// ! ���� �ʿ��� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// startpoint�� ����
	// n��ŭ ���鼭 ��ġ�� ���� ���
	// ������ ���� ���

	int n;
	cin >> n;
	
	vector<pair<int, int>> points;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		points.push_back({ s, e });
	}

	sort(points.begin(), points.end(), compare);

	int len = 0;
	int start = points[0].first;
	int end = points[0].second;
	for (int i = 1; i < n; i++)
	{
		int nextS = points[i].first;
		int nextE = points[i].second;
		if (nextS >= start && nextS <= end)
		{
			if (nextE > end) end = nextE;
			else continue;
		}
		else
		{
			// ���� ������ְ� 
			// start end �ʱ�ȭ
			len += end - start;
			start = nextS;
			end = nextE;
		}
	}
	
	// ���������� ���� ���
	len += end - start;

	cout << len;
}