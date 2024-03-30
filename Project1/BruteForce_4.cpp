// 체스판 다시 칠하기
#include <iostream>
using namespace std;

int changeNum(bool** changeBoard, int n, int m, int k, int l) {
	int sum = 0;
	for (int i = k; i < k + 8; i++) {
		for (int j = l; j < l + 8; j++) {
			if (changeBoard[i][j] == true) sum++;
		}
	}
	return sum;
}

int main() {

	// 1. 체스판 다시 칠하는 정보를 이차원 배열에 저장
	// 2. 8*8 만큼 배열에 있는 수를 가져와서 가장 작은 값 출력

	int n, m;
	cin >> n >> m;
	// 2차원 배열 동적 생성
	char** board = new char*[n];
	// 변화된 값을 저장해줄 배열 생성
	bool** change_b = new bool* [n];
	bool** change_w = new bool* [n];
	for (int i = 0; i < n; i++) {
		board[i] = new char[m];
		change_b[i] = new bool[m];
		change_w[i] = new bool[m];
	}
	// 배열에 값 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			change_b[i][j] = false;
			change_w[i][j] = false;
		}
	}

	// 변화되는 값 넣기
	// black board, white 보드 둘다 넣기
	// 2. next 라는 변수를 만들어서 현재값과 next 비교를 통해서
	// 바뀌면(다르면) count++
	// 8*8 배열을 뽑아내는 아이디어
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// white board
			// 행이 짝수면 WBWB...
			// 행이 홀수면 BWBW...
			// Black board
			// 행이 짝수이면 BWBW..
			// 행이 홀수이면 WBWB.. 
			if (i % 2 == 0) {
				// white : 열이 짝수면 W
				if (j % 2 == 0) {
					if (board[i][j] == 'B') change_w[i][j] = true;
					if (board[i][j] == 'W') change_b[i][j] = true;
				}
				// white : 열이 홀수이면 B
				else {
					if(board[i][j] == 'W') change_w[i][j] = true;
					if (board[i][j] == 'B') change_b[i][j] = true;
				}
			}
			else {
				// white : 열이 짝수면 B
				if (j % 2 == 0) {
					if (board[i][j] == 'W') change_w[i][j] = true;
					if (board[i][j] == 'B') change_b[i][j] = true;
				}
				// white : 열이 홀수이면 W
				else {
					if (board[i][j] == 'B') change_w[i][j] = true;
					if (board[i][j] == 'W') change_b[i][j] = true;
				}
			}
		}
	}
	// 칠해야 하는 최솟값 
	int paintMin = n * m;
	int num = 0;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			num = changeNum(change_b, n, m, i, j);
			if (num < paintMin) paintMin = num;
			num = changeNum(change_w, n, m, i, j);
			if (num < paintMin) paintMin = num;
		}
	}

	cout << paintMin;

}