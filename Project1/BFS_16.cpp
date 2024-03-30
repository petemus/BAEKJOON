// BFS  > 16.��!(4179��)
// ���2) ���� ������ E�� �ѹ� �� ���μ� Ǯ��
// + ���͸� ���� ���� ���� ���� 
// ���3) ���� ���� �� ��Ʈ���� �� �ð��� �����ϰ� �����̰� �̵��ϸ鼭
// ���� �ð��� ���ϸ鼭 Ż��

// [c++]
// �迭 �����Ҵ��� ���ٷ��� ���;��� �� ����
// ����, 2���� �迭�� vector<vector<int>> 

// �ݷ�
// 1. ť�� ������� ���
// 2. ���� ��ġ�� Ż���� �� �ִ� ���

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
	// ���� ������ Ž��
	// �� > ������ ����
	room* tmp;
	int nowLev;
	int tmpX, tmpY;
	int dirX[] = { 0, 0, 1, -1 };
	int dirY[] = { 1, -1, 0, 0 };
	while (!q.empty()) {
		// �� ����
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
				tmp = &(fire.front());  // ���� ť�� ���������
			}
		}
		

		// ������
		tmp = &(q.front());
		// ���� ��ġ ����
		if (tmp->r == 0 || tmp->c == 0 || tmp->c == c - 1 || tmp->r == r - 1) {
			// ����
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
						// ����
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


	// �Է�
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> maze[i][j];
		}
	}

	// J, F ť�� �־���
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (maze[i][j] == 'J') q.push(room(i, j, 0));
			if (maze[i][j] == 'F') fire.push(room(i, j, 0));
		}
	}

	// ���
	int result = solve();
	if (result == -1) cout << "IMPOSSIBLE";
	else cout << result;



}