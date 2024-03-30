// Simulation > 3.2048 (Easy)(12100번)
// backtracking, brute force
// 상하좌우를 5개의 경우 수 중에 가장 큰 블록 출력 

// ! 합쳐진 블록은 다시 합쳐질 수 없다는 것이 중요

#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> block;
int path[5] = { 0, };
int maxBlock = 0;
int n;

void moveUp(vector<vector<int>>& cpyBlock) {
	bool isBuilt[20][20] = {0,};
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cpyBlock[i][j] > 0) {
				// block 이면 위에 탐색
				for (int k = i; k > 0; k--) {
					if (cpyBlock[k - 1][j] == cpyBlock[k][j] && !isBuilt[k - 1][j]) {
						// 같은 블록이고 만들어진 블록이 아니면 합치기
						cpyBlock[k - 1][j] += cpyBlock[k ][j];
						isBuilt[k - 1][j] = true;
						cpyBlock[k][j] = 0;
						break;
					}
					if (cpyBlock[k - 1][j] == 0) {
						// 블록이 없으면 이동
						cpyBlock[k - 1][j] += cpyBlock[k][j];
						cpyBlock[k][j] = 0;
					}
					else break; // 블록이 있으면 break;
				}
			}
		}
	}
}

void moveDown(vector<vector<int>>& cpyBlock) {
	bool isBuilt[20][20] = { 0, };
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (cpyBlock[i][j] > 0) {
				// block 이면 아래 탐색
				for (int k = i; k < n - 1; k++) {
					if (cpyBlock[k + 1][j] == cpyBlock[k][j] && !isBuilt[k + 1][j]) {
						// 같은 블록이고 만들어진 블록이 아니면 합치기
						cpyBlock[k + 1][j] += cpyBlock[k][j];
						isBuilt[k + 1][j] = true;
						cpyBlock[k][j] = 0;
						break;
					}
					if (cpyBlock[k + 1][j] == 0) {
						// 블록이 없으면 이동
						cpyBlock[k + 1][j] += cpyBlock[k][j];
						cpyBlock[k][j] = 0;
					}
					else break; // 블록이 있으면 break;
				}
			}
		}
	}
}

void moveLeft(vector<vector<int>>& cpyBlock) {
	bool isBuilt[20][20] = { 0, };
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (cpyBlock[i][j] > 0) {
				// block 이면 왼쪽 탐색
				for (int k = j; k > 0; k--) {
					if (cpyBlock[i][k - 1] == cpyBlock[i][k] && !isBuilt[i][k - 1]) {
						// 같은 블록이고 만들어진 블록이 아니면 합치기
						cpyBlock[i][k - 1] += cpyBlock[i][k];
						isBuilt[i][k - 1] = true;
						cpyBlock[i][k] = 0;
						break;
					}
					if (cpyBlock[i][k - 1] == 0) {
						// 블록이 없으면 이동
						cpyBlock[i][k - 1] += cpyBlock[i][k];
						cpyBlock[i][k] = 0;
					}
					else break; // 블록이 있으면 break;
				}
			}
		}
	}
}

void moveRight(vector<vector<int>>& cpyBlock) {
	bool isBuilt[20][20] = { 0, };
	for (int j = n - 2; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			if (cpyBlock[i][j] > 0) {
				// block 이면 오른쪽 탐색
				for (int k = j; k < n - 1; k++) {
					if (cpyBlock[i][k + 1] == cpyBlock[i][k] && !isBuilt[i][k + 1]) {
						// 같은 블록이고 만들어진 블록이 아니면 합치기
						cpyBlock[i][k + 1] += cpyBlock[i][k];
						isBuilt[i][k + 1] = true;
						cpyBlock[i][k] = 0;
						break;
					}
					if (cpyBlock[i][k + 1] == 0) {
						// 블록이 없으면 이동
						cpyBlock[i][k + 1] += cpyBlock[i][k];
						cpyBlock[i][k] = 0;
					}
					else break; // 블록이 있으면 break;
				}
			}
		}
	}
}

// 1: 상  2: 하  3: 좌  4: 우
void move(int dir, vector<vector<int>>& cpyBlock) {
	switch (dir)
	{
	case 1:
		moveUp(cpyBlock);
		break;
	case 2:
		moveDown(cpyBlock);
		break;
	case 3:
		moveLeft(cpyBlock);
		break;
	case 4:
		moveRight(cpyBlock);
		break;
	default:
		break;
	}
}


int checkMax(vector<vector<int>> cpyblock) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cpyblock[i][j] > max) max = cpyblock[i][j];
		}
	}
	return max;
}

void Backtracking(int lev) {
	if (lev == 5) {
		vector<vector<int>> copyBlock(block);
		// 경로에 따라 이동
		for (int i = 0; i < 5; i++) {
			move(path[i], copyBlock);
		}
		// 최대 검사
		int max = checkMax(copyBlock);
		if (max > maxBlock) {
			maxBlock = max;
		}
		return;
	}

	// 경로 저장
	for (int i = 0; i < 4; i++) {
		path[lev] = i + 1;
		Backtracking(lev + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<int> v;
	int tmp;
	for (int i = 0; i < n; i++) {
		block.push_back(v);
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			block[i].push_back(tmp);
		}
	}

	Backtracking(0);

	cout << maxBlock;
}
