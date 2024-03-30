// Backtracking > 12.N과 M (6)(15655번)
// 수열 직접 입력 받기 + (2) 번 문제 (오름차순)

#include <iostream>
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
	int d = dept + 1;
	for (int i = index + 1; i < n; i++) {
		Backtracking(i, d);
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