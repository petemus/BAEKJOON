// Sort2 > 2. �� �����ϱ�2(2751��) // algorithms���� ���� ǰ
// ����, ����, ����, ��, ����(������ ���� �ð��� ����), �� ����
// �� ���� -> O(nlongn)
// n�� ������ 10���� ���� ���� �־ �ð� ���⵵�� n^2�� �˰������� Ǯ �� ���� -> ��
// !! �����δ� �ð� �ʰ���..


#include <iostream>
using namespace std;

int n;
int* arr;


void heapify(int n) {
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
void change_RootChild(int n) {
	int tmp = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = tmp;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	heapify(n);
	for (int i = n; i > 0; i--) {
		change_RootChild(i);
		heapify(i - 1);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}
