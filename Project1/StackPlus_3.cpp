// ������ Ȱ�� > 3.��ȣ(9012��)
// ) ��ȣ�� ���� ���� Ȯ���ؾ� ��.

#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	cin >> n;

	stack<char> pth;
	string str;
	bool isVps = true;
	char tmp;

	for (int i = 0; i < n; i++) {
		cin >> str;
		// stack�� �����ϸ鼭 �˻�
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ')') {
				if (pth.size() == 0) {
					// ���ÿ� ���� ������
					pth.push(str[j]);
					break;
				}
				tmp = pth.top();
				if (tmp == '(') pth.pop();
			}
			else pth.push(str[j]);
		}

		if (!pth.empty()) {
			// ������ ���� �ʾ����� ���� �ܾ�
			// stack�� �������� �����
			isVps = false;
			while (!pth.empty()) pth.pop();
		}

		if (isVps) cout << "YES\n";
		else cout << "NO\n";
		// �ʱ�ȭ
		isVps = true;
	}
}