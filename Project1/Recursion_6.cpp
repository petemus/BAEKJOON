// Recursion > 6.������ �����(2630��)

// 5�� ������ ���� �Ȱ�

#include <iostream>
#include <cmath>
using namespace std;


int arr[128][128];
int blue = 0, white = 0;

void cut(int n, int sY, int sX) {

	// ���� ����
	if (n == 1) {
		if (arr[sY][sX] == 0) white++;
		else blue++;
		return;
	}

	int tmp = arr[sY][sX];
	// ���� �˻�
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
	// ���̰� ������ +1 ���� �ƴϸ� ������
	if (isSame) {
		if (tmp == 0) white++;
		else blue++;
	}
	else {
		int tmp = n / 2;
		int dirX[] = { 0, tmp, 0, tmp};
		int dirY[] = { 0, 0, tmp, tmp};
		for (int i = 0; i < 4; i++) {
			cut(tmp, sY + dirY[i], sX + dirX[i]);
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

	cut(n, 0, 0);

	cout << white << "\n" << blue << "\n";

}