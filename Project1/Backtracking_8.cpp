// Backtracking > 8.N과 M (2)(15650번)
// 순서 없는 수열 문제


#include <iostream>
#include <vector>
using namespace std;

int n, m;
int path[8] = { 0, };
int arr[8];

void Backtracking(int index, int dept) {

	// -1이 아닐 때만 
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

	// @@ 배열 어떻게 
	//입력
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	// backtracking
	//Backtracking(-1, 0);
	for (int i = 0; i < n; i++) {
		Backtracking(i, 1);
	}


}