// BFS > 3.미로탐색(2178번)
// BFS는 현재 레벨이 최소 경로수인데 현제 레벨을 어떻게 구하는냐가 문제
// => 해당 행렬의 크기만큼 level 배열을 만들어서 구현

#include <iostream>
#include <queue>
using namespace std;

int BFS(bool**& picture,int n, int m) {

	// direct 배열 
	int dirX[4] = { -1, 1, 0, 0 };
	int dirY[4] = { 0, 0, -1, 1 };
	//q, isVisited 배열
	queue<pair<int, int>> q;
	bool** isVisited = new bool* [n];
	int** level = new int* [n];

	// 초기화
	for (int i = 0; i < n; i++) {
		isVisited[i] = new bool[m];
		level[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			isVisited[i][j] = 0;
			level[i][j] = 0;
		}
	}

	q.push(make_pair(0, 0));
	isVisited[0][0] = 1;
	level[0][0] = 1;
	int cnt = 1;

	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		// 인접한 배열 큐에 넣어주기
		for (int k = 0; k < 4; k++) {
			tmpX = tmp.first + dirX[k];
			tmpY = tmp.second + dirY[k];
			if (tmpX != -1 && tmpX != n && tmpY != -1 && tmpY != m) {
				if (picture[tmpX][tmpY] && !isVisited[tmpX][tmpY]) {
					q.push(make_pair(tmpX, tmpY));
					isVisited[tmpX][tmpY] = 1;
					level[tmpX][tmpY] = level[tmp.first][tmp.second] + 1;
					cnt++;
				}
			}
		}
		picture[tmp.first][tmp.second] = 0;
		q.pop();
	}
	return level[n-1][m-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	// 배열
	bool** maze = new bool*[n];
	// 미로 만들기
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		maze[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			maze[i][j] = (tmp[j] - '0');
		}
	}

	cout << BFS(maze, n, m);


}