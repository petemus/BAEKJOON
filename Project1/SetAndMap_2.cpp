// ���հ� �� > 2.���ڿ� ����

// sol1. ���Ʈ ����
// sol2. ���� ��� (string Ÿ��)

#include <iostream>
#include <set>
using namespace std;

int main() {

	int n, m;
	cin >> n;
	cin >> m;
	
	// ����
	set<string> s;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		s.insert(tmp);
	}
	// ���� �迭 
	string* comp = new string[m];
	for (int i = 0; i < m; i++) {
		cin >> comp[i];
	}

	int result = 0;


	// �Ʒ� for �� ���� for���� ��ĥ �� ���� ��
	for (int i = 0; i < m; i++) {
		if (s.find(comp[i]) != s.end()) {
			// ���� ã����
			result++;
		}
	}

	cout << result;
}