// 2. ���� �� �����ϴ� ����(11053)

// Ǯ�� 1) n^2 ��� : ���� ���� �����ֿ� �ڱ⺸�� ���� �ָ� ����
// ���ʿ� �ִ� ����� ���� �� ���ʿ� �ִ� �ּҰ���� ���Ŀ� ū �͸� ����


#include <iostream>
using namespace std;

int number[1001] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	int* arr = new int[count];
	// �Է�
	for (int i = 0; i < count; i++) {
		int val;
		cin >> val;
		arr[i] = val;
	}

	int max = 0;

	for (int i = 1; i < count; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				if ((number[arr[j]] + 1) > number[arr[i]])
					number[arr[i]] = number[arr[j]] + 1;
			}
		}
		if (number[arr[i]] > max) max = number[arr[i]];
	}

	cout << max + 1;

}