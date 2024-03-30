// Sort2 > 1. �� �����ϱ�(2750��) // heap���� ���� �ѹ� ǰ
// ����, ����, ����, ��, �պ�, �� ����
// ���� ����

#include <iostream>
using namespace std;

int n;
int arr[1000];

void bubble_sort() {
	int tmp;
	
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n - j; i++) {
			if (arr[i] > arr[i + 1]) {
				// ��ȯ
				tmp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = tmp;
			}
		}
	}

	// �Ϲ� ���� ���� ����
	//for (int i = n - 1; i > 0; i--) {
	//	for (int j = 0; j < i; j++) {
	//		if (arr[j] > arr[j + 1]) {
	//			// ��ȯ
	//			tmp = arr[j + 1];
	//			arr[j + 1] = arr[j];
	//			arr[j] = tmp;
	//		}
	//	}
	//}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bubble_sort();
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}
