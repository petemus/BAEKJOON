// Simulation > 2.스티커 붙이기(18808번)
// 각 스티커별로 0 90 180 270도의 위치들을 저장
// 스티커의 가장 왼쪽, 위쪽의 칸에서 스티커의 위치를 vector에 저장후
// 그 스티거를 붙일 수 있는지(그 위치가 다 0인지 확인후 붙이기

// 벡터 리사이즈, 복사, 참조 전달 가능

#include <iostream>
using namespace std;

int n, m, s;
int notebook[40][40];

int*** sticker0;
int*** sticker90;
int*** sticker180;
int*** sticker270;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> s;
	sticker0 = new int** [s];
	sticker90 = new int** [s];
	sticker180 = new int** [s];
	sticker270 = new int** [s];
	
	// 입력
	int tmp;
	for (int k = 0; k < s; k++) {
		int r, c;
		cin >> r >> c;
		sticker0[k] = new int* [r];
		sticker90[k] = new int* [c];
		sticker180[k] = new int* [r];
		sticker270[k] = new int* [c];
		for (int i = 0; i < r; i++) {
			sticker0[k][i] = new int[c];
			sticker180[k][i] = new int[c];
		}
		for (int i = 0; i < c; i++) {
			sticker90[k][i] = new int[r];
			sticker270[k][i] = new int[r];
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> tmp;
				sticker0[k][i][j] = tmp;
				sticker180[k][r - 1 - i][c - 1 - j] = tmp;
			}
		}
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				sticker90[k][j][r - 1 - i] = tmp;
				sticker270[k][c - 1 - j][i] = tmp;
			}
		}
	}

	//int*** arr = new int**[4];
	//arr[0] = new int* [2];
	//arr[1] = new int* [5];
	//arr[2] = new int* [2];
	//arr[3] = new int* [5];
	//int r, c;
	//cin >> r >> c;
	//int tmp;
	//for (int i = 0; i < r; i++) {
	//	for (int j = 0; j < c; j++) {
	//		cin >> tmp;
	//		arr[0][i][j] = tmp;
	//		arr[1][j][r - 1 - i] = tmp;
	//		arr[2][r - 1 - i][c - 1 - j] = tmp;
	//		arr[3][c - 1 - j][i] = tmp;
	//	}
	//}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << sticker90[0][i][j] << " ";
		}
		cout << '\n';
	}

}