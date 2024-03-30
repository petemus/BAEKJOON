// BFS > 5.����Ʈ�� �̵�(7562��)

#include <iostream>
#include <queue>
using namespace std;

int BFS(int sX, int sY, int eX, int eY, int m)
{
	queue<pair<int, int>> q;
	bool isVisited[300][300] = { 0, };
	int level[300][300] = { 0, };
	//direct
	int dirX[8] = { -2, -2, -1, 1, 2, 2, -1, 1 };
	int dirY[8] = { -1, 1, 2, 2, -1, 1, -2, -2 };

	q.push(make_pair(sX, sY));
	isVisited[sX][sY] = 1;
	level[sX][sY] = 0;

	pair<int, int> tmp;
	int nextX, nextY;
	while (!q.empty()) {
		tmp = q.front();
		// ���� ����
		if (tmp.first == eX && tmp.second == eY) return level[tmp.first][tmp.second];
		// ���� �迭 �־��ֱ�
		for (int i = 0; i < 8; i++) {
			nextX = tmp.first + dirX[i];
			nextY = tmp.second + dirY[i];
			// ũ�Ⱑ �� ������ continue
			if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= m) continue;
			// �湮�������� �־��ֱ�
			if (!isVisited[nextX][nextY]) {
				q.push(make_pair(nextX, nextY));
				isVisited[nextX][nextY] = 1;
				level[nextX][nextY] = level[tmp.first][tmp.second] + 1;
				//cout << "nextX, next Y : " << nextX << " " << nextY << " level[nX][]: " << level[nextX][nextY] << "\n";
			}
		}
		// pop
		q.pop();
	}


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int l;
	int startX, startY;
	int endX, endY;
	while (t--) {
		cin >> l;
		cin >> startX >> startY;
		cin >> endX >> endY;
		cout << BFS(startX, startY, endX, endY, l) << "\n";
	}

}