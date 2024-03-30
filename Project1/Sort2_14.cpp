// Sort2 > 14.먹을 것인가 먹힐 것인가(7795번)
// brute force를 사용하면 시간 오래 걸림
// a, b를 각각 정렬

// 이분 탐색

#include <iostream>	
#include <vector>	
#include <algorithm>
using namespace std;


bool compare(int a, int b) {
	// 오름차순
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int n, m;
	int tmp;
	int cnt = 0;
	while (t--) {
		cin >> n >> m;
		vector<int> a, b;
		// 입력
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			a.push_back(tmp);
		}
		for (int i = 0; i < m; i++) {
			cin >> tmp;
			b.push_back(tmp);
		}
		// 각각 오름차순 내림차순 정렬
		sort(a.begin(), a.end(), compare);
		sort(b.begin(), b.end());
		// 개수 세기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] <= b[j]) break;
				// 쌍 더하기
				cnt++;
			}
		}
		cout << cnt << "\n";
		// 초기화
		cnt = 0;
	}

}