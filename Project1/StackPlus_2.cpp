// ������ Ȱ�� > 2.���� �ܾ�(3986��)
// ������ �� ���� �ִ� ��ҿ� ������ ��Ұ� ������ pop �ƴϸ� push
// stack�� ���� �ʾ����� ���� �ܾ �ƴ�.

// [c++]
// stl���� ���ð� ť�� clear() �Լ��� �������� �ʴ´�.

#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	cin >> n;

	stack<char> word;
	string str;
	int goodWord = 0;
	char tmp;

	for (int i = 0; i < n; i++) {
		cin >> str;
		// stack�� �����ϸ鼭 �˻�
		for (int j = 0; j < str.size(); j++) {
			if (word.empty()) word.push(str[j]);
			else {
				tmp = word.top();
				// ������ pop
				if (tmp == str[j]) word.pop();
				// ���� ������ push
				else word.push(str[j]);
			}
		}

		if (!word.empty()) {
			// ������ ���� �ʾ����� ���� �ܾ�
			// stack�� �������� �����
			while (!word.empty()) word.pop();
		}
		else goodWord++;
	}

	cout << goodWord;

}