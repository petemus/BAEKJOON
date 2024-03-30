// BFS > 18.����(2573��)
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int iceberg[300][300];
bool isVisited[300][300] = { 0, };
int dirX[] = { 0, 0, 1, -1 };
int dirY[] = { 1, -1, 0, 0};

void DFS(int x, int y) {
	isVisited[x][y] = 1;
	int tmpX, tmpY;
	for (int i = 0; i < 4; i++) {
		tmpX = x + dirX[i];
		tmpY = y + dirY[i];
		if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= m) continue;
		if (!isVisited[tmpX][tmpY] && iceberg[tmpX][tmpY] > 0) {
			DFS(tmpX, tmpY);
		}
	}
}

void BFS(int i, int j) {

	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	isVisited[i][j] = 1;

	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmp.first + dirX[i];
			tmpY = tmp.second + dirY[i];
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= m) continue;
			if (!isVisited[tmpX][tmpY] && iceberg[tmpX][tmpY] > 0) {
				isVisited[tmpX][tmpY] = 1;
				q.push(make_pair(tmpX, tmpY));
			}
		}
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	// �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> iceberg[i][j];
		}
	}


	//BFS�� ���� üũ
	int area = 0, year = 0;
	int tmpX, tmpY;
	bool isFaield = false;

	while (!isFaield) {

		// BFS�� ���� ���ϱ�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!isVisited[i][j] && iceberg[i][j] > 0) {
					//BFS(i, j);
					DFS(i, j);
					area++;
				}
			}
		}
		// area üũ
		if (area > 1) {
			break;
		}
		else if (area == 0) {
			isFaield = true;
		}
		else {
			// ���� �پ��� -> �̷��� �ϸ� ���� �ٲ�� �͵� �ݿ��Ǽ� ��
			fill(&isVisited[0][0], &isVisited[299][300], 0);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (!isVisited[i][j] && iceberg[i][j] > 0) {
						isVisited[i][j] = 1;
						for (int k = 0; k < 4; k++) {
							tmpX = i + dirX[k];
							tmpY = j + dirY[k];
							//cout << "tmpX, Y: " << tmpX << " " << tmpY << "\n";
							if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= m) continue;
							if (!isVisited[tmpX][tmpY] && iceberg[tmpX][tmpY] == 0 && iceberg[i][j] > 0) iceberg[i][j]--;
						}
					}
				}
			}
			year++;
		}
		// �ʱ�ȭ (isVisited �ʱ�ȭ, area �ʱ�ȭ)
		fill(&isVisited[0][0], &isVisited[299][300], 0);
		area = 0;

		//cout << "\n";
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << iceberg[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}
	
	if (area > 1) cout << year;
	else cout << 0;
	

}


