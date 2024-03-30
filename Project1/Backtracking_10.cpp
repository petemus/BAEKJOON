// Backtracking > 10.N과 M (4)(15652번)
// 중복 허용 + 오름 차순

#include <iostream>
using namespace std;

int n, m;
int path[8] = { 0, };
int arr[8];

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
	for (int i = index; i < n; i++) {
		Backtracking(i, d);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	//입력
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	// backtracking
	for (int i = 0; i < n; i++) {
		Backtracking(i, 1);
	}


}