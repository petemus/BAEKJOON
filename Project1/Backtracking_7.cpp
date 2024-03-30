// Backtracking > 7.N�� M(1)(15649��)
// ����� �� ������ �ִ� ������

// �ٽ��� ��� arr �� �������� -> �Ű������� �迭�� �Ѱ��ִµ� ����� �Ѱ��ֱ�
// ?? �迭�� ����� �Ѱ��ִ� �� �Ұ����Ѱ�? ���� �ƴ� �� ������...
// �׳� arr�߿� path�� ���� ���� �־��ֱ�

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int path[8] = { 0, };
int arr[8];

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

	// @@ �迭 ��� 
	//�Է�
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	// backtracking
	for (int i = 0; i < n; i++) {
		Backtracking(i, 1);
	}


}