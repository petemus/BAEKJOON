// Recursion > 5.종이의 개수(1780번)

// 3^7 = 2187

#include <iostream>
#include <cmath>
using namespace std;

int arr[3000][3000];
int zero = 0, one = 0, minusone = 0;

void paper(int n, int sY, int sX) {
	
	// 종료 조건
	if (n == 1) {
		if (arr[sY][sX] == 0) zero++;
		else if (arr[sY][sX] == 1) one++;
		else minusone++;
		return;
	}
	int tmp = arr[sY][sX];
	// 종이 검사
	bool isSame = true;
	for (int i = sY; i < sY + n; i++) {
		if (!isSame) break;
		for (int j = sX; j < sX + n; j++) {
			if (tmp != arr[i][j]) {
				isSame = false;
				break;
			}
		}
	}
	// 종이가 같으면 +1 증가 아니면 나누기
	if (isSame) {
		if (tmp == 0) zero++;
		else if (tmp == 1)one++;
		else minusone++;
	}
	else {
		int tmp = n / 3;
		int dirX[] = { 0, tmp, tmp * 2, 0, tmp, tmp * 2, 0, tmp, tmp * 2 };
		int dirY[] = { 0, 0, 0, tmp, tmp, tmp, tmp * 2, tmp * 2, tmp * 2 };
		for (int i = 0; i < 9; i++) {
			paper(tmp, sY + dirY[i], sX + dirX[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	paper(n, 0, 0);

	cout << minusone << "\n" << zero << "\n" << one;

}