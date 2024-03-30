// Backtracking > 2.�ζ�(6603��)

#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> arr;
int lotto[6] = { 0, };

void Backtracking(int index, int dept) {

	lotto[dept] = arr[index];
	//���� ����
	if (dept == 5) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << "\n";
		return;
	}

	//��� ȣ��
	int cnt = dept + 1;
	for (int i = index + 1; i < k; i++) {
		Backtracking(i, cnt);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;

	int tmp = 0;
	while (k != 0) {

		// �Է�
		for (int i = 0; i < k; i++) {
			cin >> tmp;
			arr.push_back(tmp); // ���ĵ� ���·� ����
		}

		// backtracking
		for (int i = 0; i < k - 5; i++) {
			Backtracking(i, 0);
		}
		// arr �ʱ�ȭ
		arr.clear();
		cin >> k;
		cout << "\n";
	}
}