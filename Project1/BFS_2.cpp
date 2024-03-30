// BFS > 2.그림(1926번)
// picture을 동적 배열에서 정적 배열로 바꿨는데 메모리 초과 해소... why..?

#include <iostream>
#include <queue>
using namespace std;

// bool** &picture 
int BFS(bool picture[][500], int i, int j, int n, int m) {

	// direct 배열 
	int dirX[4] = { -1, 1, 0, 0 };
	int dirY[4] = { 0, 0, -1, 1 };
	//q, isVisited 배열
	queue<pair<int, int>> q;
	//bool** isVisited = new bool*[n];
	//for (int i = 0; i < n; i++) isVisited[i] = new bool[m];
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) isVisited[i][j] = 0;
	//}
	bool isVisited[500][500] = { 0, };

	q.push(make_pair(i, j));
	isVisited[i][j] = 1;
	int cnt = 1;

	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		// 인접한 배열 큐에 넣어주기
		for (int k = 0; k < 4; k++) {
			tmpX = tmp.first + dirX[k];
			tmpY = tmp.second + dirY[k];
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= m) continue;
			if (picture[tmpX][tmpY] && !isVisited[tmpX][tmpY]) {
				q.push(make_pair(tmpX, tmpY));
				isVisited[tmpX][tmpY] = 1;
				cnt++;
			}
		}
		picture[tmp.first][tmp.second] = 0;
		q.pop();
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	//배열 만들기
	//bool** picture = new bool* [n];
	//for (int i = 0; i < n; i++) picture[i] = new bool[m];
	bool picture[500][500];

	// 그림 입력 받기
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			picture[i][j] = tmp;
		}
	}

	int sizeM = 0;
	int pictureCnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (picture[i][j]) {
				// 그림 발견하면 bfs
				pictureCnt++;
				tmp = BFS(picture, i, j, n, m);
				if (tmp > sizeM) sizeM = tmp;
			}
		}
	}

	cout << pictureCnt << "\n" << sizeM;

}