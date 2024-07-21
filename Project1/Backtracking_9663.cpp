// Backtracking > N-Queen(9663��)

#include <iostream>
using namespace std;
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
int n;
int queens[15];
int possible = 0;


void Backtracking(int index, int dept) {

	// queen �α�
	queens[dept - 1] = index;
	// dept�� n - 1�̸� possible
	// ���� ����
	if (dept == n) {
		possible++;
		return;
	}

	// ��� ȣ��
	// ��ġ�� �ʴ� ���� queen �α�
	bool isCrash = false;
	int gap = 0;
	for (int i = 0; i < n; i++) {
		// �ش� ���� �浹�ϴ��� �˻�
		for (int j = 0; j < dept; j++) {
			// ���� ������
			if (queens[j] == i) isCrash = true;
			// �밢������
			gap = dept - j;
			if (queens[j] == i + gap || queens[j] == i - gap) isCrash = true;
		}
		// ��� ȣ��
		if(!isCrash) Backtracking(i, dept + 1);
		isCrash = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// algorithm
	// �Է� �ޱ�
	// n ���� ����ŭ backtracking 
	// ��ġ�� �ʴ� ���� q �α�-> ��� ȣ��

	cin >> n;

	for (int i = 0; i < n; i++) {
		Backtracking(i, 1);
	}

	cout << possible;

}