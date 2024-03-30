// BFS > 9.안전 영역(2468번)
// BFS를 최소 크기에서 최대 크기만큼 돌리면 될듯

#include <iostream>
#include <queue>
using namespace std;

int iceberg[100][100]; // 배열
int n; // 배열 크기

void BFS(bool isVisted[][100], int i, int j, int t) {

	int dirX[] = { 0, 0, -1, 1 };
	int dirY[] = { 1, -1, 0, 0 };
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmp.first + dirX[i];
			tmpY = tmp.second + dirY[i];
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= n) continue;
			if (!isVisted[tmpX][tmpY] && iceberg[tmpX][tmpY] > t) {
				q.push(make_pair(tmpX, tmpY));
				isVisted[tmpX][tmpY] = 1;
			}
		}
		q.pop();
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int tmp;
	// 입력
	int max = 1, min = 100; // 높이는 1이상 100이하이므로
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			iceberg[i][j] = tmp;
			if (tmp > max) max = tmp;
			if (tmp < min) min = tmp;
		}
	}

	// min ~ max 만큼 반복
	int safeMax = 1;
	int safearea = 0;
	bool isVisted[100][100] = { 0, };
	for (int t = min; t < max; t++) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!isVisted[i][j] && iceberg[i][j] > t) {
					// BFS
					safearea++;
					isVisted[i][j] = 1;
					BFS(isVisted, i, j, t);
				}
			}
		}
		// 최대 영역이 갱신되면 바꿔줌
		if (safearea > safeMax) safeMax = safearea;
		// 값 초기화
		safearea = 0;
		fill_n(&isVisted[0][0], 100 * 100, 0);
	}

	cout << safeMax;

}