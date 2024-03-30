// Backtracking > 17.N�� M (11)(15665��)
// ���� �Է� + �ߺ� ��� ����(but �ߺ� ���� ����) + ���� �� �ߺ� ���� ����
// �ߺ��� �����ϸ� prev �� �ᵵ ��

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
	int prev = 0;
	for (int i = 0; i < n; i++) {
		// + prev ���̶� ������ pass
		if (prev != arr[i]) {
			Backtracking(i, d);
		}
		prev = arr[i];
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