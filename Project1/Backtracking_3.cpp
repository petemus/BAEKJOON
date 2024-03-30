// Backtracking > 3.��ȣ �����(1759��)
// ���� �ٸ� ���ڵ� + ��������
// �ٽ� : �ּ� ���� 1 + ���� 2
// -> ��� 1: dept�� 4�� �� �ش� pw ��  ���� 1 + ���� 2�� �̷�����ִ��� �˻�
// -> ��� 2: Backtracking �Լ� ȣ���� ������ ���� ���� ���� ���� �˻����ֱ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> alpha;
char pw[15];

void Backtracking(int index, int dept) {
	pw[dept - 1] = alpha[index];
	// ���� ����
	if (dept == l) {
		// ���� 1 ���� 2���� �˻�
		int vowelCnt = 0;
		for (int i = 0; i < l; i++) {
			if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u') vowelCnt++;
		}
		if (vowelCnt < 1 || vowelCnt >(l - 2)) return;
		// ���
		for (int i = 0; i < l; i++) {
			cout << pw[i];
		}
		cout << "\n";
		return;
	}

	// ��� ȣ��
	int d = dept + 1;
	for (int i = index + 1; i < c; i++) {
		Backtracking(i, d);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// algorithm
	// �Է� �ޱ�
	// ���ڵ� ����
	// backtracking

	// �Է�
	cin >> l >> c;
	char tmp;
	for (int i = 0; i < c; i++) {
		cin >> tmp;
		alpha.push_back(tmp);
	}
	// ����
	sort(alpha.begin(), alpha.end());

	// Backtracking
	for (int i = 0; i < c; i++) {
		Backtracking(i, 1);
	}
}