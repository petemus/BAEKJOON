// 4.ž(2493��) ������ ���� �̿� ���ϰ� �迭�� Ǯ��
// => �ð� �ʰ�

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// tower ������ ���� ������ �ƴ� �迭�� ����
	int* tower = new int[n];
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		tower[i] = tmp;
	}

	int* result = new int[n];
	// �ڿ������� ã��
	int comp = 0;
	bool isFind = false;
	for (int i = n - 1; i >= 0; i--) {
		comp = tower[i];
		for (int j = i - 1; j >= 0; j--) {
			if (tower[j] >= tower[i]) {  // ? ž ����⵵ ���� �� �ְ���
				// �۽� ����
				result[i] = j;
				isFind = true;
				break;
			}
		}
		if (!isFind) {
			// �߰��� ���ϸ� 0�� ����
			result[i] = 0;
		}
		isFind = false;
	}

	
	for (int i = 0; i < n; i++) {
		tmp = result[i];
		if (tmp != 0) cout << ++tmp << " ";
		else cout << tmp << " ";
	}

}