// ���հ� �� > 6.�躸��
// �� ������ �������� ���� ������ ���ҵ��� ���ϴ� ����

// �������� ��� ���� ���ΰ�?
// @1. �� ������ ��� ���ҵ��� ���鼭 �ٸ� ���տ� �� ���Ұ� ��!���� Ȯ�� -> O(n)
// 2. �˰��� �̿� vector�� ������ �������ִ� �Լ� set_difference()

#include <iostream>
#include <set>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	
	set<string> set1;

	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		set1.insert(tmp);
	}

	int count = 0;
	set<string> inter;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (set1.count(tmp)) {
			// 1�� �̻��̸� 
			inter.insert(tmp);
			count++;
		}
	}

	// ���
	cout << count << "\n";
	set<string>::iterator iter;
	for (iter = inter.begin(); iter != inter.end(); iter++) {
		cout << *iter << "\n";
	}
}