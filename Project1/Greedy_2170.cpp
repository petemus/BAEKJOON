// Greedy > 선 긋기 (2170번)
// 풀이 시간 : 8 5
// ! 정렬 필요함 

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

	// startpoint로 정렬
	// n만큼 돌면서 겹치는 길이 계산
	// 마지막 길이 계산

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
			// 길이 계산해주고 
			// start end 초기화
			len += end - start;
			start = nextS;
			end = nextE;
		}
	}
	
	// 마지막으로 길이 계산
	len += end - start;

	cout << len;
}