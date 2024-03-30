// Backtracking > 6.소문난 칠공주(1941번)
// 이게 dfs 로 하는 건가?

#include <iostream>
#include<queue>
using namespace std;

queue<pair<int, int>> ppath;
char seats[5][5];
bool isVisited[5][5] = { 0, };
int path[7][2];
int dirR[] = { 0, 0, 1, -1 };
int dirC[] = { 1, -1, 0, 0 };
int princess7 = 0;

void Backtracking(int rindex, int cindex, int dept, int sCnt) {

	//경로 쓰기
	path[dept - 1][0] = rindex;
	path[dept - 1][1] = cindex;
	ppath.push(make_pair(rindex, cindex));

	//종료 조건
	if (dept == 7) {
		cout << "성공\n";
		princess7++;
		return;
	}

	// 재귀 호출
	int tmpR, tmpC;
	pair<int, int> tmp;
	bool isDuplicate = false;

	tmp = ppath.front();
	for (int i = 0; i < 4; i++) {
		tmpR = tmp.first + dirR[i];
		tmpC = tmp.second + dirC[i];
		
		cout << "tR tC : " << tmpR << " " << tmpC << '\n';

		if (tmpR < 0 || tmpR > 4 || tmpC < 0 || tmpC > 4) continue;
		if (isVisited[tmpR][tmpC]) continue;
		// path에 있는 곳인지 확인
		isDuplicate = false;
		for (int j = 0; j < dept; j++) {
			cout << "path " << path[j][0] << " " << path[j][1] << "\n";
			if (path[j][0] == tmpR && path[j][1] == tmpC) {
				cout << "겹침\n";
				isDuplicate = true;
			}
		}
		cout << "\n";
		if (isDuplicate) continue;

		ppath.push(make_pair(tmpR, tmpC));


		// 재귀 호출 하는 조건
		if (seats[tmpR][tmpC] == 'S') {
			if ((7 - dept) > (3 - sCnt)) {
				cout << "솜 : tmpR tmpC " << tmpR << " " << tmpC << "\n";
				Backtracking(tmpR, tmpC, dept + 1, sCnt + 1);
				isVisited[tmpR][tmpC] = 1;
			}
		}
		else {
			if ((7 - dept) > (4 - sCnt)) {
				cout << "tmpR tmpC " << tmpR << " " << tmpC << "\n";
				Backtracking(tmpR, tmpC, dept + 1, sCnt);
			}
		}
	}




}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// algorithm
	
	// 입력
	// 이번에는 또 겁나 잘들어옴
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> seats[i][j];
		}
	}

	// Backtracking
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (seats[i][j] == 'S') {
				cout << "R: " << i << " C: " << j << "\n";
				isVisited[i][j] = 1;
				Backtracking(i, j, 1, 1);
			}
		}
	}

	cout << princess7;

	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		cout << seats[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

}