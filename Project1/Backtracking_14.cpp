// Backtracking > 14.N�� M (8)(15657��)
// ���� ���� �Է� �ޱ� + (4)�� ����

#include <iostream>
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
	int d = dept + 1;
	for (int i = index; i < n; i++) {
		Backtracking(i, d);
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