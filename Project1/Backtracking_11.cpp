// Backtracking > 11.N과 M (5)(15654번)
// 수열 직접 입력 받음 + N과 M(1) 번 문제

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int path[8] = { 0, };
int* arr;

void Backtracking(int index, int dept) {
	path[dept - 1] = arr[index];
	if (dept == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	// 재귀 호출
	// path에 있는 애들은 제외
	bool isDup = false;
	int d = dept + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < dept; j++) {
			if (arr[i] == path[j]) isDup = true;
		}
		if (!isDup) {
			Backtracking(i, d);
		}
		isDup = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	//입력
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// arr 정렬
	sort(arr, arr + n);

	// backtracking
	for (int i = 0; i < n; i++) {
		Backtracking(i, 1);
	}


}