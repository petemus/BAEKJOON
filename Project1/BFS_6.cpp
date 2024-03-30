// BFS > 6.영역 구하기(2538번)

// 배열을 동적으로 생성하면 fill(), fill_n() 함수로 초기화가 안됨...
// memset을 행 단위로 초기화해줘야지만 가능...

// 사각형들을 모눈종이 채움
// 모눈종이를 전체 탐색하면서 빈 공간을 BFS 함.
// 결과값들을 저장해서 마지막에 출력해야함.


// ? 이렇게 실제로 배열의 순서와 문제 순서가 다를 경우 헷갈림 어떻게 해야하나.

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
			// 방문하지 않았고 field가 0이면
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
	// m이 x n이 y
	cin >> m >> n >> k;

	bool field[100][100] = { 0, };

	// field에 사각형 칠해주기
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

	// BFS 탐색
	int areaCnt = 0;
	list<int> size;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 네모칸이 비어있으면 BFS 
			if (!field[i][j]) {
				//cout << "field i , j : " << i << " " << j << "\n";
				areaCnt++;
				size.push_back(BFS(field, i, j, m, n));
			}
		}
	}

	cout << areaCnt << "\n";
	size.sort();
	// 객체를 넘겨줄 때는 일일이 복사가 되서 오래걸릴 수 있음
	// -> 참조자를 붙여줘야함.
	for (list<int>::iterator it = size.begin(); it != size.end(); it++) {
		cout << (*it) << " ";
	}




}