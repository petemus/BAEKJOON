// BFS > 10.토마토(7576번)

// 첫번쨰 방법 > 하루 단위로 배열 전체 for 문 돌려줌 => 시간 초과...
// 그냥 순서대로 큐에 넣으면 제대로 작동함..

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int box[1000][1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	//입력
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			box[i][j] = tmp;
		}
	}


	// 1을 발견한 모든 것들을 큐에 넣어주고 BFS
	// 큐가 비었는데도 안 익은 토마토가 남아있으면 -1 출력
	queue<pair<int, int>> q;
	//dir
	int dirX[] = { 0, 0, -1, 1 };
	int dirY[] = { 1, -1, 0, 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	pair<int, int> tmpq;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmpq = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmpq.first + dirX[i];
			tmpY = tmpq.second + dirY[i];
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= m) continue;
			if (box[tmpX][tmpY] == 0) {
				box[tmpX][tmpY] = box[tmpq.first][tmpq.second] + 1;
				q.push(make_pair(tmpX, tmpY));
			}
		}
		q.pop();
	}

	int leastDay = 0;
	bool isriped = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				isriped = 0;
				break;
			}
			if (box[i][j] > leastDay) leastDay = box[i][j];
		}
	}

	if (isriped) cout << leastDay - 1;
	else cout << -1;


	//cout << "\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << box[i][j] << " ";
	//	}
	//	cout << "\n";
	//}



}