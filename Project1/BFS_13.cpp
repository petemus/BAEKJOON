// BFS > 13.상범 빌딩(6593번)
// 변수명을 통일하라~~~~~~~~~~~~~~
// 변수 선언 반복문 안에다가 해도 상관없대~~~~~~~~~
// 열을 x로 행을 y로~~~~~~~~~~~~~~~~~


#include <iostream>
#include <queue>
using namespace std;

int l, r, c;
char build[30][30][30];

struct box {
	int l, r, c, lev;
	box(int i, int j, int k, int le) : l(i), r(j), c(k), lev(le) {}
};

int BFS(int i, int j, int k) {

	queue<box> q;
	int dirX[6] = { 0, 0, -1, 1, 0, 0 };
	int dirY[6] = { 1, -1, 0, 0, 0, 0 };
	int dirZ[6] = { 0, 0,  0, 0, 1, -1 };

	q.push(box(i, j, k, 0));

	box* tmp;
	int tmpX, tmpY, tmpZ;
	while (!q.empty()) {
		tmp = &(q.front());
		for (int i = 0; i < 6; i++) {
			tmpX = tmp->r + dirX[i];
			tmpY = tmp->c + dirY[i];
			tmpZ = tmp->l + dirZ[i];
			if (tmpX < 0 || tmpX >= r || tmpY < 0 || tmpY >= c || tmpZ < 0 || tmpZ >= l) continue;
			if (build[tmpZ][tmpX][tmpY] == '.') {
				q.push(box(tmpZ, tmpX, tmpY, tmp->lev + 1));
				build[tmpZ][tmpX][tmpY] = '-';
			}
			else if (build[tmpZ][tmpX][tmpY] == 'E') return tmp->lev + 1;
		}
		q.pop();
	}
	// 찾지못하면 -1 반환
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 빌딩

	cin >> l >> r >> c;

	string s;
	int result;
	queue<int> results;

	while (1) {

		if (l == 0 && r == 0 && c == 0) break;

		// 빌딩 입력
		for (int k = 0; k < l; k++) {
			for (int i = 0; i < r; i++) {
				cin >> s;
				for (int j = 0; j < c; j++) {
					build[k][i][j] = s[j];
				}
			}
			//cin >> tmp;
		}

		// BFS
		for (int k = 0; k < l; k++) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (build[k][i][j] == 'S') {
						result = BFS(k, i, j);
						results.push(result);
					}
				}
			}
		}

		//for (int k = 0; k < l; k++) {
		//	for (int i = 0; i < r; i++) {
		//		for (int j = 0; j < c; j++) {
		//			cout << build[k][i][j] << " ";
		//		}
		//		cout << "\n";
		//	}
		//	cout << "\n";
		//}

		// 결과 출력
		//if (result == -1) cout << "Trapped!\n";
		//else cout << "Escaped in " << result <<  " minute(s).\n";

		cin >> l >> r >> c;
	}

	int tmp;
	while (!results.empty()) {
		tmp = results.front();
		if (tmp == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << tmp << " minute(s).\n";
		results.pop();
	}


}
