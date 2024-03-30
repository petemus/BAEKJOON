// Simulation > 8.Ʈ��(13335��)

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int truck[1001] = { 0, };
	int bridge[101] = { 0, };

	int n, w, maxWeight; // 1000, 100, 1000

	// �Է�
	cin >> n >> w >> maxWeight;
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}


	int bridgeWeight = 0;
	int time = 0;
	// truck �迭�� ù���� ���Ұ� 0�϶� ���� + bridge�� Ʈ���� ���� �� -> Ʈ���� �� �ǳʸ� ����
	while (true) {
		if (truck[0] == 0 && bridgeWeight == 0) break;

		// �ٸ� �ǳʱ�
		for (int i = w - 1; i >= 0; i--) {
			if (bridge[i] != 0) {
				// Ʈ���� ������ ��ĭ�� �̵�
				if (i == w - 1) {
					// Ʈ���� �ǳ��� ������ ���� ����
					bridgeWeight -= bridge[i];
					bridge[i] = 0;
				}
				bridge[i + 1] = bridge[i];
				bridge[i] = 0;
			}
		}

		// truck ��ĭ�� �ű��
		// �� ó�� �ִ� Ʈ�� ���� ���
		if (truck[0] + bridgeWeight <= maxWeight) {
			// Ʈ���� �ǳ� �� ������ �̵�
			bridgeWeight += truck[0];
			bridge[0] = truck[0];
			truck[0] = 0;
			// Ʈ���� �̵��ϸ� ���� Ʈ���鵵 ��ĭ�� �̵�
			for (int i = 1; i < n; i++) {
				if (truck[i] != 0) {
					// Ʈ���� ������ ��ĭ�� �̵�
					truck[i - 1] = truck[i];
					truck[i] = 0;
				}
			}
		}
		

		time++;

		//cout << "Ʈ�� : ";
		//for (int i = 0; i < n; i++) {
		//	cout << truck[i] << " ";
		//}
		//cout << "\n";
		//cout << "�ٸ� : ";
		//for (int i = 0; i < w; i++) {
		//	cout << bridge[i] << " ";
		//}
		//cout << "\n";
	}

	cout << time;


}