// Simulation, BFS > Puyo Puyo(11559��)
// ���������� �ʵ��� ��ġ�� ����Ǵµ� �̰� �ٽ��ε�

//  ������ ������ ���� ���� Ʋ����

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

	//�˻�
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
	// x, y�� ����� �ֵ� . ���� �ٲ���
	queue<pair<int, int>> q;

	q.push({ x,y });
	char right = field[x][y];
	field[x][y] = '.';

	//�˻�
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
	// ������ ���� ��Ұ� .�̸� .�� �ƴҶ����� �̵�
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			// �ѿ��̸�
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


	// �Է�
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> field[i][j];
		}
	}

	// �� �ݺ�
	bool isBombed = false;
	// ���� ī��Ʈ 
	int bombCnt = 0;

	//arrange();
	while (true) {
		// ������ Ȯ��
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
		// ��ź�� ������ ������ ����
		if (!isBombed) break;
		else bombCnt++;
		// �ʵ� ���� -> �߷� �ۿ� 
		arrange();
		// ���� �ʱ�ȭ
		isBombed = false;
		fill(isVisited[0], isVisited[12], 0);
	}

	cout << bombCnt;
}
