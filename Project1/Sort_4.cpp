// ����> 4. �� �����ϱ�
#include <iostream>
using namespace std;

// 1. heap ���� ����� �ֱ� �ִ� ��
//		> �ڽ� ��带 ��ü������ ����
//		> �θ� ��� ���� ũ�� ��ȯ ( ��Ʈ ��忡 ���� ������ �ݺ�)
// 2. �� �� ���� ��Ʈ ��� ��ȯ => ������������ ����


void heapify(int* arr, int n) {
	// root ���� ��ü �ݺ�
	for (int i = 1; i < n; i++) {
		int child = i;
		do {
			int parent = (child - 1) / 2;
			if (arr[parent] < arr[child]) {
				int tmp = arr[parent];
				arr[parent] = arr[child];
				arr[child] = tmp;
			}
			child = parent;
		} while (child != 0);
	}
}

// �θ�� �ڽ� ��ȯ
void change_RootChild(int* arr, int n) {
	int tmp = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = tmp;
}

int main() {

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	// ios::sync_with_stdio(false), cin.tie(nullptr) : ���� �����

	heapify(arr, n);

	for (int i = n; i > 0; i--) {
		change_RootChild(arr, i);
		heapify(arr, i - 1);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}