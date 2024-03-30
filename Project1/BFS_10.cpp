// BFS > 10.�丶��(7576��)

// ù���� ��� > �Ϸ� ������ �迭 ��ü for �� ������ => �ð� �ʰ�...
// �׳� ������� ť�� ������ ����� �۵���..

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int box[1000][1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	//�Է�
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			box[i][j] = tmp;
		}
	}


	// 1�� �߰��� ��� �͵��� ť�� �־��ְ� BFS
	// ť�� ����µ��� �� ���� �丶�䰡 ���������� -1 ���
	queue<pair<int, int>> q;
	//dir
	int dirX[] = { 0, 0, -1, 1 };
	int dirY[] = { 1, -1, 0, 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	pair<int, int> tmpq;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmpq = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmpq.first + dirX[i];
			tmpY = tmpq.second + dirY[i];
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= m) continue;
			if (box[tmpX][tmpY] == 0) {
				box[tmpX][tmpY] = box[tmpq.first][tmpq.second] + 1;
				q.push(make_pair(tmpX, tmpY));
			}
		}
		q.pop();
	}

	int leastDay = 0;
	bool isriped = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				isriped = 0;
				break;
			}
			if (box[i][j] > leastDay) leastDay = box[i][j];
		}
	}

	if (isriped) cout << leastDay - 1;
	else cout << -1;


	//cout << "\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << box[i][j] << " ";
	//	}
	//	cout << "\n";
	//}



}