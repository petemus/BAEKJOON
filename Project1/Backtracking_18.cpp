// Backtracking > 18.N과 M (12)(15666번)
// 직접 입력 + 중복 허용 안함(but 중복 숫자 들어옴) + 같은 수 중복 선택 가능 + 오름차순


// ! 중복 제거 알고리즘
// 정렬
// unique() 함수를 이용하면 중복 되는 부분만 뒤로 보내짐
// eraseㅎ() 함수로 그 위치에서 맨뒤까지 지우면 중복 제거

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
	int prev = 0;
	for (int i = index; i < n; i++) {
		// + prev 값이랑 같으면 pass
		if (prev != arr[i]) {
			Backtracking(i, d);
		}
		prev = arr[i];
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