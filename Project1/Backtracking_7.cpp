// Backtracking > 7.N과 M(1)(15649번)
// 여기는 또 순서가 있는 수열임

// 핵심은 어떻게 arr 를 관리할지 -> 매개변수에 배열을 넘겨주는데 복사로 넘겨주기
// ?? 배열을 복사로 넘겨주는 게 불가능한가? 전에 됐던 것 같은데...
// 그냥 arr중에 path의 없는 값만 넣어주기

#include <iostream>
#include <vector>
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

	// @@ 배열 어떻게 
	//입력
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	// backtracking
	for (int i = 0; i < n; i++) {
		Backtracking(i, 1);
	}


}