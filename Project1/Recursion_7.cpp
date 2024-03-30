// Recursion > 7.쿼드트리(1992번)

// 5, 6번이랑 비슷

#include <iostream>
#include <cmath>
using namespace std;

int arr[64][64];

void QuardTree(int n, int sY, int sX) {
	// 종료 조건
	if (n == 1) {
		cout << arr[sY][sX];
		return;
	}

	// 검사
	int tmp = arr[sY][sX];
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
	// 같으면 출력 틀리면 나누기
	if (isSame) cout << tmp;
	else {
		int tmp = n / 2;
		int dirX[] = {0, tmp, 0, tmp};
		int dirY[] = { 0, 0, tmp, tmp};
		cout << "(";
		for (int i = 0; i < 4; i++) {
			QuardTree(tmp, sY + dirY[i], sX + dirX[i]);
		}
		cout << ")";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// 어쩔때는 그냥 int형으로 받아도 되고 어쩔 때는 안되고 뭐징...
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; j++){
			arr[i][j] = tmp[j] - '0';
		}
	}

	QuardTree(n, 0, 0);


}