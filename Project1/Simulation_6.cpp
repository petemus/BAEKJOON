// Simulation > 6.톱니바퀴(14891번)
#include <iostream>
#include <queue>
#include <cmath> // pow();
using namespace std;

int wheel[4][8];

// 시계방향 회전
void rotateRight(int k) {
	int last = wheel[k][7];
	for (int i = 7; i > 0; i--) {
		wheel[k][i] = wheel[k][i - 1];
	}
	wheel[k][0] = last;
}

// 반시계 방향 회전
void rotateLeft(int k) {
	int first = wheel[k][0];
	for (int i = 0; i < 7; i++) {
		wheel[k][i] = wheel[k][i + 1];
	}
	wheel[k][7] = first;
}

// 회전 확인 
void Rotate(int w, int d) {

	queue<pair<int, int>> q;
	q.push({ w, d });
	// 회전 해야할 바퀴 확인
	// 오른쪽 바퀴들 확인
	int dir = d; // 1이 시계 방향 -1이 반시계
	for (int i = w; i < 3; i++) {
		if (wheel[i][2] != wheel[i + 1][6]) {
			// 반대 방향으로 회전
			dir *= -1;
			q.push({ i + 1, dir });
		}
		else break;
	}
	// 왼쪽 바퀴 확인
	dir = d;
	for (int i = w; i > 0; i--) {
		if (wheel[i][6] != wheel[i - 1][2]) {
			// 반대 방향으로 회전
			dir *= -1;
			q.push({ i - 1, dir });
		}
		else break;
	}

	// 바퀴 회전
	pair<int, int> tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		if (tmp.second == -1) rotateLeft(tmp.first);
		else rotateRight(tmp.first);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// 입력
	string tmp;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		for (int j = 0; j < 8; j++) {
			wheel[i][j] = tmp[j] - '0';
		}
	}

	// 회전
	int k;
	cin >> k;

	int w, d;
	for (int i = 0; i < k; i++) {
		cin >> w >> d;
		// 바퀴 회전
		Rotate(w - 1, d);
	}

	// 점수 계산
	int point = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1) point += pow(2,i);
	}

	cout << point;

}
