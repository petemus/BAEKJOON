// BFS > 11.토마토(7569번)
// 첫번쨰 토마토 문제에서 box의 크기가 위로도 올라감

#include <iostream>
#include <queue>
using namespace std;

int n, m, h;
int box[100][100][100];

struct index {
	int x, y, z;
	index(int i, int j, int k) : x(i), y(j), z(k) {}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;

	//입력
	int tmp;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> tmp;
				box[i][j][k] = tmp;
			}
		}
	}


	queue<index> q;
	//dir
	int dirX[] = { 0, 0, -1, 1, 0, 0 };
	int dirY[] = { 1, -1, 0, 0, 0, 0 };
	int dirZ[] = { 0, 0,  0, 0, 1, -1 };


	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j][k] == 1) {
					q.push(index(i, j, k));
				}
			}
		}
	}
	

	int tmpX, tmpY, tmpZ;
	while (!q.empty()) {
		index tmpq = q.front();
		for (int i = 0; i < 6; i++) {
			tmpX = tmpq.x + dirX[i];
			tmpY = tmpq.y + dirY[i];
			tmpZ = tmpq.z + dirZ[i];
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= m || tmpZ < 0 || tmpZ >= h) continue;
			if (box[tmpX][tmpY][tmpZ] == 0) {
				box[tmpX][tmpY][tmpZ] = box[tmpq.x][tmpq.y][tmpq.z] + 1;
				q.push(index(tmpX, tmpY, tmpZ));
			}
		}
		q.pop();
	}

	int leastDay = 0;
	bool isriped = 1;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j][k] == 0) {
					isriped = 0;
					break;
				}
				if (box[i][j][k] > leastDay) leastDay = box[i][j][k];
			}
		}
	}
	

	if (isriped) cout << leastDay - 1;
	else cout << -1;
	
	//cout << "\n\n";
	//for (int k = 0; k < h; k++) {
	//	for (int i = 0; i < n; i++) {
	//		for (int j = 0; j < m; j++) {
	//			cout << box[i][j][k] << " ";
	//		}
	//		cout << "\n";
	//	}
	//	cout << "\n";
	//}



}