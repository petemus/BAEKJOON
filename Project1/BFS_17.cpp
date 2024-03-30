// BFS > 17.불(5427번)

#include <iostream>
#include <queue>
using namespace std;

struct room {
	int r, c, lev;
	room(int i, int j, int l) : r(i), c(j), lev(l) {}
};

int r, c;
char maze[1000][1000];
queue<room> q;
queue<room> fire;


int solve() {

	// BFS
	// 레벨 단위로 탐색
	room* tmp;
	int nowLev;
	int tmpX, tmpY;
	int dirX[] = { 0, 0, 1, -1 };
	int dirY[] = { 1, -1, 0, 0 };
	while (!q.empty()) {
		// 불 먼저
		if (!fire.empty()) {
			tmp = &(fire.front());
			nowLev = tmp->lev;
			while (!fire.empty()) {
				if (tmp->lev > nowLev) break;
				for (int i = 0; i < 4; i++) {
					tmpX = tmp->r + dirX[i];
					tmpY = tmp->c + dirY[i];
					if (tmpX < 0 || tmpX >= r || tmpY < 0 || tmpY >= c) continue;
					if (maze[tmpX][tmpY] != '#' && maze[tmpX][tmpY] != '*') {
						maze[tmpX][tmpY] = '*';
						fire.push(room(tmpX, tmpY, tmp->lev + 1));
					}
				}
				//
				fire.pop();
				if (fire.empty()) break;
				tmp = &(fire.front());  // 만약 큐가 비어있으면
			}
		}


		// 상근이
		tmp = &(q.front());
		// 현재 위치 예외
		if (tmp->r == 0 || tmp->c == 0 || tmp->c == c - 1 || tmp->r == r - 1) {
			// 정답
			return tmp->lev + 1;
		}
		nowLev = tmp->lev;
		while (!q.empty()) {
			if (tmp->lev > nowLev) break;
			for (int i = 0; i < 4; i++) {
				tmpX = tmp->r + dirX[i];
				tmpY = tmp->c + dirY[i];
				if (tmpX < 0 || tmpX >= r || tmpY < 0 || tmpY >= c) continue;
				if (maze[tmpX][tmpY] == '.') {
					if (tmpX == 0 || tmpY == 0 || tmpY == c - 1 || tmpX == r - 1) {
						// 정답
						return tmp->lev + 2;
					}
					maze[tmpX][tmpY] = '@';
					q.push(room(tmpX, tmpY, tmp->lev + 1));
				}
			}
			//
			q.pop();
			if (q.empty()) break;
			tmp = &(q.front());
		}

	}

	return -1;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	queue<int> results;
	int result;

	while (t--) {
		cin >> c >> r;
		// 입력
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> maze[i][j];
			}
		}

		// 상근이 불 큐에 넣어줌
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (maze[i][j] == '@') q.push(room(i, j, 0));
				if (maze[i][j] == '*') fire.push(room(i, j, 0));
			}
		}
		result = solve();
		results.push(result);
		// fire, q 의 내용 초기화 해줘야 함.
		while (!q.empty()) q.pop();
		while (!fire.empty()) fire.pop();
	}


	// 결과
	while (!results.empty())
	{
		result = results.front();
		if (result == -1) cout << "IMPOSSIBLE\n";
		else cout << result << "\n";
		results.pop();
	}
	
	



}