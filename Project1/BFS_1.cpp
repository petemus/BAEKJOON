// BFS > 1.유기농 배추(1012번)

#include <iostream>
#include <queue>
using namespace std;

void BFS(bool (&field)[50][50], pair<int, int> idx, int n, int m) {
	// bfs에 쓰일 큐
	queue<pair<int, int>> q;
	bool isVisited[50][50] = { 0, };
	q.push(idx);
	isVisited[idx.first][idx.second] = 1;

	int i, j;
	pair<int, int> tmp;

	while (!q.empty()) {
		tmp = q.front();
		// 인접한 애들 큐에 넣어줌 .. 이게 맞나
		if (tmp.second != m - 1 && field[tmp.first][tmp.second + 1]) {
			if (!isVisited[tmp.first][tmp.second + 1]) {
				q.push(make_pair(tmp.first, tmp.second + 1));
				isVisited[tmp.first][tmp.second + 1] = 1;
			}
		}
		if (tmp.second != 0 && field[tmp.first][tmp.second - 1]) {
			if (!isVisited[tmp.first][tmp.second - 1]) {
				q.push(make_pair(tmp.first, tmp.second - 1));
				isVisited[tmp.first][tmp.second - 1] = 1;
			}
		}
		if (tmp.first != n - 1 && field[tmp.first + 1][tmp.second]) {
			if (!isVisited[tmp.first + 1][tmp.second]) {
				q.push(make_pair(tmp.first + 1, tmp.second));
				isVisited[tmp.first + 1][tmp.second] = 1;
			}
		}
		if (tmp.first != 0 && field[tmp.first - 1][tmp.second]) {
			if (!isVisited[tmp.first - 1][tmp.second]) {
				q.push(make_pair(tmp.first - 1, tmp.second));
				isVisited[tmp.first - 1][tmp.second] = 1;
			}
		}
		// field 수정후 pop
		field[tmp.first][tmp.second] = 0;
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	int m, n, k;
	int i, j;

	int wormCount = 0;
	//bool** field = new bool*[50];
	//for (int i = 0; i < 50; i++) field[i] = new bool[50];
	bool field[50][50] = { 0, };

	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		// 밭 배열 생성 & 초기화
		//field = new bool*[n];
		//for (int a = 0; a < n; a++) field[a] = new bool[m];

		//for(int a = 0; a < n; a++) memset(field, false, sizeof(field));
		//fill_n(&field[0][0], n * m, 0);
		//fill(&field[0][0], &field[n - 1][m], 0);
		
		// 배추 심기
		while (k--) {
			// j가 x 즉 열 i 가 행 y
			cin >> j >> i;
			field[i][j] = 1;
		}
		// 밭 전체 탐색하면서 흰지렁이 탐색
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j]) {
					wormCount++;
					//BFS
					BFS(field, make_pair(i, j), n, m);
				}
			}
		}
		cout << wormCount << "\n";
		wormCount = 0;
	}

}