// BFS > 7.단지번호붙이기(2667번)
// 기존 문제랑 거의 비슷
#include <iostream>
#include <queue>
#include <list>
using namespace std;

int BFS(bool apts[][25], int i, int j, int n) {
	
	bool isVisited[25][25] = { 0, };
	queue<pair<int, int>> q;
	int dirX[] = { 1, -1, 0, 0 };
	int dirY[] = { 0, 0, -1, 1 };

	q.push(make_pair(i, j));
	isVisited[i][j] = 1;

	int cnt = 1;
	pair<int, int> tmp;
	int tmpX, tmpY;
	while (!q.empty()) {
		tmp = q.front();
		for (int i = 0; i < 4; i++) {
			tmpX = tmp.first + dirX[i];
			tmpY = tmp.second + dirY[i];
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= n) continue;
			if (!isVisited[tmpX][tmpY] && apts[tmpX][tmpY]) {
				apts[tmpX][tmpY] = 0;
				isVisited[tmpX][tmpY] = 1;
				q.push(make_pair(tmpX, tmpY));
				cnt++;
			}
		}
		q.pop();
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	//입력
	bool apts[25][25] = { 0, };
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) apts[i][j] = s[j] - '0';
	}

	// BFS
	int aptCnt = 0;
	list<int> li;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (apts[i][j]) {
				aptCnt++;
				li.push_back(BFS(apts, i, j, n));
			}
		}
	}

	li.sort();
	cout << aptCnt << "\n";
	for (list<int>::iterator it = li.begin(); it != li.end(); it++) {
		cout << *it << "\n";
	}

}