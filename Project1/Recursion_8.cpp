// Recursion > 8.�� ��� - 10(2447��)

// 3^7 = 2187 => N�� �ִ밪�� 2187

// ĭ�� 9ĭ���� ����
// ĥ  ĥ  ĥ
// ĥ ��ĥ ĥ
// ĥ  ĥ  ĥ
// �迭�� �����ϰ� �Ŀ� ���
// ��ĥ ���� ó������ ' '�� �ʱ�ȭ ���൵ ��

#include <iostream>
using namespace std;

char arr[2187][2187];

void star(int n, int sY, int sX) {
	// ���� ����
	if (n == 1) {
		arr[sY][sX] = '*';
		return;
	}

	// ������
	int tmp = n / 3;
	int dirX[] = { 0, tmp, tmp * 2, 0, tmp, tmp * 2, 0, tmp, tmp * 2 };
	int dirY[] = { 0, 0, 0, tmp, tmp, tmp, tmp * 2, tmp * 2, tmp * 2 };
	for (int i = 0; i < 9; i++) {
		// �ǳ� ���
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
	// ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

}