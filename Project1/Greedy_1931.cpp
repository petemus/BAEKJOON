#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 회의실
vector<pair<int, int>> lectures;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	int n;
	cin >> n;

	int startTime, endTime;
	for (int i = 0; i < n; i++) {
		cin >> startTime >> endTime;
		lectures.push_back({ startTime, endTime });
	}

	// 끝나는 시간이 작은 대로 정렬
	sort(lectures.begin(), lectures.end(), compare);

	// 끝나는 시간이 빠른 데로 배정
	endTime = 0;
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (lectures[i].second >= endTime && lectures[i].first >= endTime) {
			result++;
			endTime = lectures[i].second;
		}
	}

	cout << result;

}