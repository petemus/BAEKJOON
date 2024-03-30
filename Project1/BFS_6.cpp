// BFS > 6.���� ���ϱ�(2538��)

// �迭�� �������� �����ϸ� fill(), fill_n() �Լ��� �ʱ�ȭ�� �ȵ�...
// memset�� �� ������ �ʱ�ȭ��������� ����...

// �簢������ ������ ä��
// �����̸� ��ü Ž���ϸ鼭 �� ������ BFS ��.
// ��������� �����ؼ� �������� ����ؾ���.


// ? �̷��� ������ �迭�� ������ ���� ������ �ٸ� ��� �򰥸� ��� �ؾ��ϳ�.

#include <iostream>
#include <queue>
#include <list>
using namespace std;

int BFS(bool field[][100], int sX, int sY, int m, int n) {

	queue<pair<int, int>> q;
	bool isVisited[100][100] = { 0, };
	int dirX[] = { 0, 0, 1, -1 };
	int dirY[] = { 1, -1, 0, 0 };

	q.push(make_pair(sX, sY));
	isVisited[sX][sY] = 1;

	pair<int, int> tmp;
	int tmpX, tmpY;
	int cnt = 1;
	while (!q.empty()) {
		tmp = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmp.first + dirX[i];
			tmpY = tmp.second + dirY[i];
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n) continue;
			// �湮���� �ʾҰ� field�� 0�̸�
			if (!field[tmpX][tmpY] && !isVisited[tmpX][tmpY]) {
				q.push(make_pair(tmpX, tmpY));
				isVisited[tmpX][tmpY] = 1;
				cnt++;
			}
		}
		// pop
		field[tmp.first][tmp.second] = 1;
		q.pop();
	}
	return cnt;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, k;
	// m�� x n�� y
	cin >> m >> n >> k;

	bool field[100][100] = { 0, };

	// field�� �簢�� ĥ���ֱ�
	int leftX, leftY, rX, rY;
	int tmpX, tmpY;
	while (k--) {
		cin >> leftX >> leftY >> rX >> rY;
		for (int i = leftX; i <= rX -1; i++) {
			for (int j = leftY; j <= rY -1; j++) {
				field[j][i] = 1;
			}
		}
	}

	//cout << "\n";
	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << field[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	// BFS Ž��
	int areaCnt = 0;
	list<int> size;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// �׸�ĭ�� ��������� BFS 
			if (!field[i][j]) {
				//cout << "field i , j : " << i << " " << j << "\n";
				areaCnt++;
				size.push_back(BFS(field, i, j, m, n));
			}
		}
	}

	cout << areaCnt << "\n";
	size.sort();
	// ��ü�� �Ѱ��� ���� ������ ���簡 �Ǽ� �����ɸ� �� ����
	// -> �����ڸ� �ٿ������.
	for (list<int>::iterator it = size.begin(); it != size.end(); it++) {
		cout << (*it) << " ";
	}




}