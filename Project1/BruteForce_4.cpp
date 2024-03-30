// ü���� �ٽ� ĥ�ϱ�
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

	// 1. ü���� �ٽ� ĥ�ϴ� ������ ������ �迭�� ����
	// 2. 8*8 ��ŭ �迭�� �ִ� ���� �����ͼ� ���� ���� �� ���

	int n, m;
	cin >> n >> m;
	// 2���� �迭 ���� ����
	char** board = new char*[n];
	// ��ȭ�� ���� �������� �迭 ����
	bool** change_b = new bool* [n];
	bool** change_w = new bool* [n];
	for (int i = 0; i < n; i++) {
		board[i] = new char[m];
		change_b[i] = new bool[m];
		change_w[i] = new bool[m];
	}
	// �迭�� �� �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			change_b[i][j] = false;
			change_w[i][j] = false;
		}
	}

	// ��ȭ�Ǵ� �� �ֱ�
	// black board, white ���� �Ѵ� �ֱ�
	// 2. next ��� ������ ���� ���簪�� next �񱳸� ���ؼ�
	// �ٲ��(�ٸ���) count++
	// 8*8 �迭�� �̾Ƴ��� ���̵��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// white board
			// ���� ¦���� WBWB...
			// ���� Ȧ���� BWBW...
			// Black board
			// ���� ¦���̸� BWBW..
			// ���� Ȧ���̸� WBWB.. 
			if (i % 2 == 0) {
				// white : ���� ¦���� W
				if (j % 2 == 0) {
					if (board[i][j] == 'B') change_w[i][j] = true;
					if (board[i][j] == 'W') change_b[i][j] = true;
				}
				// white : ���� Ȧ���̸� B
				else {
					if(board[i][j] == 'W') change_w[i][j] = true;
					if (board[i][j] == 'B') change_b[i][j] = true;
				}
			}
			else {
				// white : ���� ¦���� B
				if (j % 2 == 0) {
					if (board[i][j] == 'W') change_w[i][j] = true;
					if (board[i][j] == 'B') change_b[i][j] = true;
				}
				// white : ���� Ȧ���̸� W
				else {
					if (board[i][j] == 'B') change_w[i][j] = true;
					if (board[i][j] == 'W') change_b[i][j] = true;
				}
			}
		}
	}
	// ĥ�ؾ� �ϴ� �ּڰ� 
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