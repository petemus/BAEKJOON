// BFS  > 16.불!(4179번)
// 방법2) 빌딩 주위를 E로 한번 더 감싸서 풀기
// + 벡터를 따로 만들어서 불을 레벨 
// 방법3) 불을 먼저 다 퍼트리고 그 시간을 저장하고 지훈이가 이동하면서
// 불의 시간과 비교하면서 탈출

// [c++]
// 배열 동적할당을 해줄려면 벡터쓰는 게 낫다
// 또한, 2차원 배열도 vector<vector<int>> 

// 반례
// 1. 큐가 비어있을 경우
// 2. 시작 위치에 탈출할 수 있는 경우

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
	// 불 > 지훈이 순서
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
					if (maze[tmpX][tmpY] != '#' && maze[tmpX][tmpY] != 'F') {
						maze[tmpX][tmpY] = 'F';
						fire.push(room(tmpX, tmpY, tmp->lev + 1));
					}
				}
				//
				fire.pop();
				if (fire.empty()) break;
				tmp = &(fire.front());  // 만약 큐가 비어있으면
			}
		}
		

		// 지훈이
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
					maze[tmpX][tmpY] = 'J';
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

	cin >> r >> c;


	// 입력
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> maze[i][j];
		}
	}

	// J, F 큐에 넣어줌
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (maze[i][j] == 'J') q.push(room(i, j, 0));
			if (maze[i][j] == 'F') fire.push(room(i, j, 0));
		}
	}

	// 결과
	int result = solve();
	if (result == -1) cout << "IMPOSSIBLE";
	else cout << result;



}