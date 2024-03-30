// Backtracking > 15.N과 M (9)(15663번)
// 직접 입력 + 중복 허용 안함(but 중복 숫자 들어옴) + 순서가 있는 수열
// @ 꽤 시간 걸림

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int path[8] = { 0, }; // index 저장
int* arr;

void Backtracking(int index, int dept) {
	path[dept - 1] = index;
	if (dept == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[path[i]] << " ";
		}
		cout << "\n";
		return;
	}

	// 재귀 호출
	int d = dept + 1;
	bool isPath = false;
	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (i == index) continue;
		// path에 있는 애들은 pass
		for (int j = 0; j < dept; j++) {
			if (path[j] == i) {
				// index가 같으면 pass
				isPath = true;
				break;
			}
		}
		if (!isPath) {
			// 경로에 저장된 게 아니면 backtracking
			// + prev 값이랑 같으면 pass
			if (prev != arr[i]) {
				Backtracking(i, d);
			}
			prev = arr[i];
		}
		isPath = false;
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
	// prev 값이랑 같으면 pass
	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (prev != arr[i]) {
			Backtracking(i, 1);
		}
		prev = arr[i];
	}


}