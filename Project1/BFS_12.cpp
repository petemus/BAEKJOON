// BFS > 12.적록색약(10026번)
// 적록색약 BFS와 일반 BFS 만들기

#include <iostream>
#include <queue>
using namespace std;

char grid[100][100];
int n;

void BFS(bool isVisited[][100], int i, int j) {

	char value = grid[i][j];
	queue<pair<int, int>> q;
	int dirX[] = {0, 0, 1, -1};
	int dirY[] = { 1, -1, 0, 0};

	q.push(make_pair(i, j));

	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmp.first + dirX[i];
			tmpY = tmp.second + dirY[i];
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= n) continue;
			if (!isVisited[tmpX][tmpY] && grid[tmpX][tmpY] == value) {
				isVisited[tmpX][tmpY] = 1;
				q.push(make_pair(tmpX, tmpY));
			}
		}
		q.pop();
	}
}

void BFSW(bool isVisited[][100], int i, int j) {

	char value = grid[i][j];
	bool isWeak;
	if (value == 'B') isWeak = 0;
	else isWeak = 1;

	queue<pair<int, int>> q;
	int dirX[] = { 0, 0, 1, -1 };
	int dirY[] = { 1, -1, 0, 0 };

	q.push(make_pair(i, j));

	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmp.first + dirX[i];
			tmpY = tmp.second + dirY[i];
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= n || isVisited[tmpX][tmpY]) continue;
			if (value == 'B') {
				if (grid[tmpX][tmpY] == 'B') {
					isVisited[tmpX][tmpY] = 1;
					q.push(make_pair(tmpX, tmpY));
				}
			}
			else {
				// 적록색맹
				if (grid[tmpX][tmpY] != 'B') {
					isVisited[tmpX][tmpY] = 1;
					q.push(make_pair(tmpX, tmpY));
				}
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
	// 입력
	char tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			grid[i][j] = tmp;
		}
	}

	bool isVisited[100][100] = { 0, };

	// 일반
	int normalArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 방문한적 없으면 bfs
			if (!isVisited[i][j]) {
				normalArea++;
				isVisited[i][j] = 1;
				BFS(isVisited, i, j);
			}
		}
	}

	// 적록색약
	int weakArea = 0;
	//fill_n(&isVisited[0][0], 100 * 100, 0);
	fill_n(&isVisited[0][0], 100 * 100, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 방문한적 없으면 bfs
			if (!isVisited[i][j]) {
				weakArea++;
				isVisited[i][j] = 1;
				BFSW(isVisited, i, j);
			}
		}
	}


	cout << normalArea << " " << weakArea;


}