// Simulation > 1.����(15683��)
// 1�� ���� ī�޶� -> 4���� �̵� ����
// 2�� -> 2���� �̵� ����
// 3�� -> 4����
// 4�� -> 4����
// 5�� -> �̵� ����

// 1) ��� ���� ī�޶� ���� �������鼭 �ּڰ� ��� -> �ð��� �����ɸ� �� ����
// 2) ��üŽ���� �ϸ鼭 cctv ������ ���� �����鼭 �ּڰ� ���� -> ���ܰ� ���� �� => ���Ф�

// ���⸸ �����ϰ� �������� ������ִ� �� �߿�

#include <iostream>
#include <vector>
using namespace std;

int n, m; // n�� ���� (��) m�� ���� (��)
int office[8][8];


void cctv1(int y, int x) {
	int max = 0;

	// 4�������� �˻�
	int dirY[] = { 0, 0, 1, -1};
	int dirX[] = { 1, -1, 0, 0 };
	

	// 4���� �߿� ���� ���� �� -1���� �ٲٱ�
	int tmpX, tmpY;
	int tmp = 0;
	int mdir = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 8; j++) {
			tmpX = x + (dirX[i] * j);
			tmpY = y + (dirY[i] * j);
			// ���� ����ġ�ų� �Ѿ�� break
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) tmp++;
		}
		// max �˻�
		// ũ�� �� �����ֱ�
		if (max < tmp) {
			max = tmp;
			mdir = i;
		}
		tmp = 0;
	}

	// �� �����ֱ�
	for (int j = 1; j < 8; j++) {
		tmpX = x + (dirX[mdir] * j);
		tmpY = y + (dirY[mdir] * j);
		// ���� ����ġ�ų� �Ѿ�� break
		if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
		if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
	}
}

void cctv2(int y, int x) {
	int max = 0;

	// 4�������� �˻�
	int dirY[] = { 1, 0 };
	int dirX[] = { 0, 1 };


	// 2���� �߿� ���� ���� �� -1���� �ٲٱ�
	int tmpX, tmpY;
	int tmp = 0;
	int mdir = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 8; j++) {
			tmpX = x + (dirX[i] * j);
			tmpY = y + (dirY[i] * j);
			// ���� ����ġ�ų� �Ѿ�� break
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) tmp++;
		}
		for (int j = 1; j < 8; j++) {
			tmpX = x - (dirX[i] * j);
			tmpY = y - (dirY[i] * j);
			// ���� ����ġ�ų� �Ѿ�� break
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) tmp++;
		}
		// max �˻�
		// ũ�� �� �����ֱ�
		if (max < tmp) {
			max = tmp;
			mdir = i;
		}
		tmp = 0;
	}

	// �� �����ֱ�
	for (int j = 1; j < 8; j++) {
		tmpX = x + (dirX[mdir] * j);
		tmpY = y + (dirY[mdir] * j);;
		// ���� ����ġ�ų� �Ѿ�� break
		if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
		if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
	}
	for (int j = 1; j < 8; j++) {
		tmpX = x - (dirX[mdir] * j);
		tmpY = y - (dirY[mdir] * j);;
		// ���� ����ġ�ų� �Ѿ�� break
		if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
		if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
	}
}



void cctv3(int y, int x) {
	
	int max = 0;
	// 4�������� �˻�
	int dirY[] = { -1, 1, 1, -1 };
	int dirX[] = { 1, 1, -1, -1 };


	// 4���� �߿� ���� ���� �� -1���� �ٲٱ�
	int tmpX, tmpY;
	int tmp = 0;
	int mdir = 0;
	for (int i = 0; i < 4; i++) {
		// x ����
		for (int j = 1; j < 8; j++) {
			tmpX = x + (dirX[i] * j);
			tmpY = y;
			// ���� ����ġ�ų� �Ѿ�� break
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) tmp++;
		}
		// y ����
		for (int j = 1; j < 8; j++) {
			tmpX = x;
			tmpY = y + (dirY[i] * j);
			// ���� ����ġ�ų� �Ѿ�� break
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) tmp++;
		}
		// max �˻�
		// ũ�� �� �����ֱ�
		if (max < tmp) {
			max = tmp;
			mdir = i;
		}
		tmp = 0;
	}

	// �� �����ֱ�
	for (int j = 1; j < 8; j++) {
		tmpX = x + (dirX[mdir] * j);
		tmpY = y;
		// ���� ����ġ�ų� �Ѿ�� break
		if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
		if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
	}
	for (int j = 1; j < 8; j++) {
		tmpX = x;
		tmpY = y + (dirY[mdir] * j);
		// ���� ����ġ�ų� �Ѿ�� break
		if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
		if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
	}
}

void cctv4(int y, int x) {
	int max = 0;

	// 4�������� �˻�
	int dirY[] = { -1, 1, 0, 0 };
	int dirX[] = { 0, 0, -1, 1 };

	int tmpX, tmpY;
	int mdir = 0;
	int tmp = 0;
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 1; j < 8; j++) {
				tmpX = x + (j * dirX[(k + i) % 4]);
				tmpY = y + (j * dirY[(k + i) % 4]);
				if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
				if (office[tmpY][tmpX] == 0) tmp++;
			}
		}

		if (max < tmp) {
			max = tmp;
			mdir = k;
		}
		tmp = 0;
	}
	

	// �� �����ֱ�
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 8; j++) {
			tmpX = x + (j * dirX[(mdir + i) % 4]);
			tmpY = y + (j * dirY[(mdir + i) % 4]);
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
		}
	}
}

void cctv5(int y, int x) {

	int dirY[] = { -1, 1, 0, 0 };
	int dirX[] = { 0, 0, -1, 1 };
	int tmpX, tmpY;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 8; j++) {
			tmpX = x + (j * dirX[i]);
			tmpY = y + (j * dirY[i]);
			if (tmpX < 0 || tmpX >= m || tmpY < 0 || tmpY >= n || office[tmpY][tmpX] == 6) break;
			if (office[tmpY][tmpX] == 0) office[tmpY][tmpX] = -1;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	


	cin >> n >> m;

	// �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> office[i][j];
		}
	}

	// ��ü Ž��
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		// cctv�̸� 
	//		if (office[i][j] >= 1 && office[i][j] <= 5) {
	//			switch (office[i][j])
	//			{
	//			case 1:
	//				cctv1(i, j);
	//				break;
	//			case 2:
	//				cctv2(i, j);
	//				break;
	//			case 3:
	//				cctv3(i, j);
	//				break;
	//			case 4:
	//				cctv4(i, j);
	//				break;
	//			case 5:
	//				cctv5(i, j);
	//				break;
	//			default:
	//				break;
	//			}
	//		}
	//	}
	//}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cctv�̸� 
			if (office[i][j] == 5) cctv5(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cctv�̸� 
			if (office[i][j] == 4) cctv4(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cctv�̸� 
			if (office[i][j] == 3) cctv3(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cctv�̸� 
			if (office[i][j] == 2) cctv2(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cctv�̸� 
			if (office[i][j] == 1) cctv1(i, j);
		}
	}

	
	//cout << "\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << office[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	// ��ü Ȯ��
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (office[i][j] == 0) result++;
		}
	}
	cout << result;

}