// BFS > 3.�̷�Ž��(2178��)
// BFS�� ���� ������ �ּ� ��μ��ε� ���� ������ ��� ���ϴ³İ� ����
// => �ش� ����� ũ�⸸ŭ level �迭�� ���� ����

#include <iostream>
#include <queue>
using namespace std;

int BFS(bool**& picture,int n, int m) {

	// direct �迭 
	int dirX[4] = { -1, 1, 0, 0 };
	int dirY[4] = { 0, 0, -1, 1 };
	//q, isVisited �迭
	queue<pair<int, int>> q;
	bool** isVisited = new bool* [n];
	int** level = new int* [n];

	// �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		isVisited[i] = new bool[m];
		level[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			isVisited[i][j] = 0;
			level[i][j] = 0;
		}
	}

	q.push(make_pair(0, 0));
	isVisited[0][0] = 1;
	level[0][0] = 1;
	int cnt = 1;

	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		// ������ �迭 ť�� �־��ֱ�
		for (int k = 0; k < 4; k++) {
			tmpX = tmp.first + dirX[k];
			tmpY = tmp.second + dirY[k];
			if (tmpX != -1 && tmpX != n && tmpY != -1 && tmpY != m) {
				if (picture[tmpX][tmpY] && !isVisited[tmpX][tmpY]) {
					q.push(make_pair(tmpX, tmpY));
					isVisited[tmpX][tmpY] = 1;
					level[tmpX][tmpY] = level[tmp.first][tmp.second] + 1;
					cnt++;
				}
			}
		}
		picture[tmp.first][tmp.second] = 0;
		q.pop();
	}
	return level[n-1][m-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	// �迭
	bool** maze = new bool*[n];
	// �̷� �����
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		maze[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			maze[i][j] = (tmp[j] - '0');
		}
	}

	cout << BFS(maze, n, m);


}