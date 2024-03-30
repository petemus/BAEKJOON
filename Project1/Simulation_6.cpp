// Simulation > 6.��Ϲ���(14891��)
#include <iostream>
#include <queue>
#include <cmath> // pow();
using namespace std;

int wheel[4][8];

// �ð���� ȸ��
void rotateRight(int k) {
	int last = wheel[k][7];
	for (int i = 7; i > 0; i--) {
		wheel[k][i] = wheel[k][i - 1];
	}
	wheel[k][0] = last;
}

// �ݽð� ���� ȸ��
void rotateLeft(int k) {
	int first = wheel[k][0];
	for (int i = 0; i < 7; i++) {
		wheel[k][i] = wheel[k][i + 1];
	}
	wheel[k][7] = first;
}

// ȸ�� Ȯ�� 
void Rotate(int w, int d) {

	queue<pair<int, int>> q;
	q.push({ w, d });
	// ȸ�� �ؾ��� ���� Ȯ��
	// ������ ������ Ȯ��
	int dir = d; // 1�� �ð� ���� -1�� �ݽð�
	for (int i = w; i < 3; i++) {
		if (wheel[i][2] != wheel[i + 1][6]) {
			// �ݴ� �������� ȸ��
			dir *= -1;
			q.push({ i + 1, dir });
		}
		else break;
	}
	// ���� ���� Ȯ��
	dir = d;
	for (int i = w; i > 0; i--) {
		if (wheel[i][6] != wheel[i - 1][2]) {
			// �ݴ� �������� ȸ��
			dir *= -1;
			q.push({ i - 1, dir });
		}
		else break;
	}

	// ���� ȸ��
	pair<int, int> tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		if (tmp.second == -1) rotateLeft(tmp.first);
		else rotateRight(tmp.first);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// �Է�
	string tmp;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		for (int j = 0; j < 8; j++) {
			wheel[i][j] = tmp[j] - '0';
		}
	}

	// ȸ��
	int k;
	cin >> k;

	int w, d;
	for (int i = 0; i < k; i++) {
		cin >> w >> d;
		// ���� ȸ��
		Rotate(w - 1, d);
	}

	// ���� ���
	int point = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1) point += pow(2,i);
	}

	cout << point;

}
