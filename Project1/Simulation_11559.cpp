// Simulation, BFS > Puyo Puyo(11559번)
// 터질때마다 필드의 위치가 변경되는데 이게 핵심인듯

//  터지는 개수를 각각 세서 틀렸음

#include <iostream>
#include <queue>
using namespace std;

char field[12][6];
bool isVisited[12][6] = { 0, };
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

int BFS(int x, int y) {

	queue<pair<int, int>> q;

	q.push({ x,y });
	isVisited[x][y] = true;

	//검사
	int cnt = 1;
	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmp.first + dirX[i];
			tmpY = tmp.second + dirY[i];
			if (tmpX < 0 || tmpX >= 12 || tmpY < 0 || tmpY >= 6) continue;
			if (!isVisited[tmpX][tmpY] && field[tmp.first][tmp.second] == field[tmpX][tmpY]) {
				cnt++;
				q.push({ tmpX, tmpY });
				isVisited[tmpX][tmpY] = true;
			}
		}
		q.pop();
	}

	return cnt;
}

void Bomb(int x, int y) {
	// x, y와 연결된 애들 . 으로 바꿔줌
	queue<pair<int, int>> q;

	q.push({ x,y });
	char right = field[x][y];
	field[x][y] = '.';

	//검사
	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmp.first + dirX[i];
			tmpY = tmp.second + dirY[i];
			if (tmpX < 0 || tmpX >= 12 || tmpY < 0 || tmpY >= 6) continue;
			if (field[tmpX][tmpY] == right) {
				field[tmpX][tmpY] = '.';
				q.push({ tmpX, tmpY });
			}
		}
		q.pop();
	}
}

void arrange() {
	// 문자의 밑의 요소가 .이면 .이 아닐때까지 이동
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			// 뿌요이면
			if (field[i][j] != '.') {
				int k = i;
				while (k < 12) {
					if (field[k + 1][j] == '.') {
						field[k + 1][j] = field[k][j];
						field[k][j] = '.';
					}
					k++;
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// 입력
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> field[i][j];
		}
	}

	// 턴 반복
	bool isBombed = false;
	// 연쇄 카운트 
	int bombCnt = 0;

	//arrange();
	while (true) {
		// 터지기 확인
		for (int i = 11; i >= 0; i--) {
			// Bomb
			for (int j = 0; j < 6; j++) {
				if (!isVisited[i][j] && field[i][j] != '.') {
					int cnt = BFS(i, j);
					if (cnt > 3) {
						// bombed
						Bomb(i, j);
						isBombed = true;
						break;
					}
				}
			}
		}
		// 폭탄이 터지지 않으면 종료
		if (!isBombed) break;
		else bombCnt++;
		// 필드 정리 -> 중력 작용 
		arrange();
		// 변수 초기화
		isBombed = false;
		fill(isVisited[0], isVisited[12], 0);
	}

	cout << bombCnt;
}
