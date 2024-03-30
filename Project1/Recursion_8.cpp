// Recursion > 8.별 찍기 - 10(2447번)

// 3^7 = 2187 => N의 최대값은 2187

// 칸을 9칸으로 나눔
// 칠  칠  칠
// 칠 안칠 칠
// 칠  칠  칠
// 배열에 저장하고 후에 출력
// 안칠 말고 처음부터 ' '로 초기화 해줘도 됨

#include <iostream>
using namespace std;

char arr[2187][2187];

void star(int n, int sY, int sX) {
	// 종료 조건
	if (n == 1) {
		arr[sY][sX] = '*';
		return;
	}

	// 나누기
	int tmp = n / 3;
	int dirX[] = { 0, tmp, tmp * 2, 0, tmp, tmp * 2, 0, tmp, tmp * 2 };
	int dirY[] = { 0, 0, 0, tmp, tmp, tmp, tmp * 2, tmp * 2, tmp * 2 };
	for (int i = 0; i < 9; i++) {
		// 건너 띄기
		if (i == 4) {
			for (int k = sY + dirY[i]; k < sY + dirY[i] + tmp; k++) {
				for (int l = sX + dirX[i]; l < sX + dirX[i] + tmp; l++) {
					arr[k][l] = ' ';
				}
			}
		}
		else star(tmp, sY + dirY[i], sX + dirX[i]);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	star(n, 0, 0);
	// 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

}