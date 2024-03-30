// Backtracking > 15.N�� M (9)(15663��)
// ���� �Է� + �ߺ� ��� ����(but �ߺ� ���� ����) + ������ �ִ� ����
// @ �� �ð� �ɸ�

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int path[8] = { 0, }; // index ����
int* arr;

void Backtracking(int index, int dept) {
	path[dept - 1] = index;
	if (dept == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[path[i]] << " ";
		}
		cout << "\n";
		return;
	}

	// ��� ȣ��
	int d = dept + 1;
	bool isPath = false;
	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (i == index) continue;
		// path�� �ִ� �ֵ��� pass
		for (int j = 0; j < dept; j++) {
			if (path[j] == i) {
				// index�� ������ pass
				isPath = true;
				break;
			}
		}
		if (!isPath) {
			// ��ο� ����� �� �ƴϸ� backtracking
			// + prev ���̶� ������ pass
			if (prev != arr[i]) {
				Backtracking(i, d);
			}
			prev = arr[i];
		}
		isPath = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	//�Է�
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// arr ����
	sort(arr, arr + n);

	// backtracking
	// prev ���̶� ������ pass
	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (prev != arr[i]) {
			Backtracking(i, 1);
		}
		prev = arr[i];
	}


}