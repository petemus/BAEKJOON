// Backtracking > 11.N�� M (5)(15654��)
// ���� ���� �Է� ���� + N�� M(1) �� ����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int path[8] = { 0, };
int* arr;

void Backtracking(int index, int dept) {
	path[dept - 1] = arr[index];
	if (dept == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	// ��� ȣ��
	// path�� �ִ� �ֵ��� ����
	bool isDup = false;
	int d = dept + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < dept; j++) {
			if (arr[i] == path[j]) isDup = true;
		}
		if (!isDup) {
			Backtracking(i, d);
		}
		isDup = false;
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
	for (int i = 0; i < n; i++) {
		Backtracking(i, 1);
	}


}