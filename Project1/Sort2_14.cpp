// Sort2 > 14.���� ���ΰ� ���� ���ΰ�(7795��)
// brute force�� ����ϸ� �ð� ���� �ɸ�
// a, b�� ���� ����

// �̺� Ž��

#include <iostream>	
#include <vector>	
#include <algorithm>
using namespace std;


bool compare(int a, int b) {
	// ��������
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int n, m;
	int tmp;
	int cnt = 0;
	while (t--) {
		cin >> n >> m;
		vector<int> a, b;
		// �Է�
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			a.push_back(tmp);
		}
		for (int i = 0; i < m; i++) {
			cin >> tmp;
			b.push_back(tmp);
		}
		// ���� �������� �������� ����
		sort(a.begin(), a.end(), compare);
		sort(b.begin(), b.end());
		// ���� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] <= b[j]) break;
				// �� ���ϱ�
				cnt++;
			}
		}
		cout << cnt << "\n";
		// �ʱ�ȭ
		cnt = 0;
	}

}