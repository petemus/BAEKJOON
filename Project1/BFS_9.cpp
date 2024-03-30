// BFS > 9.���� ����(2468��)
// BFS�� �ּ� ũ�⿡�� �ִ� ũ�⸸ŭ ������ �ɵ�

#include <iostream>
#include <queue>
using namespace std;

int iceberg[100][100]; // �迭
int n; // �迭 ũ��

void BFS(bool isVisted[][100], int i, int j, int t) {

	int dirX[] = { 0, 0, -1, 1 };
	int dirY[] = { 1, -1, 0, 0 };
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmp.first + dirX[i];
			tmpY = tmp.second + dirY[i];
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= n) continue;
			if (!isVisted[tmpX][tmpY] && iceberg[tmpX][tmpY] > t) {
				q.push(make_pair(tmpX, tmpY));
				isVisted[tmpX][tmpY] = 1;
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

	int tmp;
	// �Է�
	int max = 1, min = 100; // ���̴� 1�̻� 100�����̹Ƿ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			iceberg[i][j] = tmp;
			if (tmp > max) max = tmp;
			if (tmp < min) min = tmp;
		}
	}

	// min ~ max ��ŭ �ݺ�
	int safeMax = 1;
	int safearea = 0;
	bool isVisted[100][100] = { 0, };
	for (int t = min; t < max; t++) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!isVisted[i][j] && iceberg[i][j] > t) {
					// BFS
					safearea++;
					isVisted[i][j] = 1;
					BFS(isVisted, i, j, t);
				}
			}
		}
		// �ִ� ������ ���ŵǸ� �ٲ���
		if (safearea > safeMax) safeMax = safearea;
		// �� �ʱ�ȭ
		safearea = 0;
		fill_n(&isVisted[0][0], 100 * 100, 0);
	}

	cout << safeMax;

}