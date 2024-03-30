// 1�� : ��� 1��� 

// ���հ� �� > 1. ���� ī��
// Set(����) : key �� ������ �ڷ� ����(���ĵ�), �ߺ���� X, ���� �����̳�
// Map(��) : key�� value �� �� ������ ������ �ڷᱸ��, ���� �����̳�,



// sol1. M���� �������� N���� ī��� �񱳿��� ���� ī�� ã�� => O(n*m)
// sol2. �����̿��ϱ� (���� �ǵ�)

#include <iostream>
#include <set>
using namespace std;

int main() {

	int n;
	set<int> cards;

	// ī�� �Է� �ޱ�
	cin >> n;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cards.insert(tmp);
	}

	int m;
	cin >> m;
	int* comp = new int[m]; // ���� �Ҵ�
	for (int i = 0; i < m; i++) {
		cin >> comp[i];
	}

	//for (set<int>::iterator iter = cards.begin(); iter != cards.end(); iter++) {
	//	cout << *iter << " ";
	//}

	//��
	for (int i = 0; i < m; i++) {
		if (cards.find(comp[i]) != cards.end()) {
			// �߰��ϸ�
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
	}

}
