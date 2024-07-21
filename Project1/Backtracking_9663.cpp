// Backtracking > N-Queen(9663번)

#include <iostream>
using namespace std;
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
int n;
int queens[15];
int possible = 0;


void Backtracking(int index, int dept) {

	// queen 두기
	queens[dept - 1] = index;
	// dept가 n - 1이면 possible
	// 종료 조건
	if (dept == n) {
		possible++;
		return;
	}

	// 재귀 호출
	// 겹치지 않는 곳에 queen 두기
	bool isCrash = false;
	int gap = 0;
	for (int i = 0; i < n; i++) {
		// 해당 열이 충돌하는지 검사
		for (int j = 0; j < dept; j++) {
			// 같은 열인지
			if (queens[j] == i) isCrash = true;
			// 대각선인지
			gap = dept - j;
			if (queens[j] == i + gap || queens[j] == i - gap) isCrash = true;
		}
		// 재귀 호출
		if(!isCrash) Backtracking(i, dept + 1);
		isCrash = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// algorithm
	// 입력 받기
	// n 개의 열만큼 backtracking 
	// 겹치지 않는 곳에 q 두기-> 재귀 호출

	cin >> n;

	for (int i = 0; i < n; i++) {
		Backtracking(i, 1);
	}

	cout << possible;

}