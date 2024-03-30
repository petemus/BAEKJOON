// ������ Ȱ�� > 1.�������� ����(4949��)
// �� �� ������ �Է� �޾Ƽ� ��ȣ�� stack�� ����. 
// ��ȣ�� ��Ī�� ������ �ùٸ� ����

// [c++]
// endl -> ���� �����̸鼭�� �Է� ���۸� �����? ������ �Ѵ�.

// ? ���� getline(cin, str, '.') �ϸ� �ȵ�
// .�� �ְ� �Ǹ� �߰��� . �� ������ �� �������� �Է��� ������
// ���� ������ Ȯ���� �� �� ����

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	string str;
	//cin.ignore();

	char tmp;
	stack<char> pth;
	//bool isBalance = true;

	getline(cin, str);
	while (str[0] != '.') {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') pth.push(str[i]);
			else if (str[i] == ')') {
				if (pth.empty()) {
					pth.push(str[i]);
					break;
				}
				tmp = pth.top();
				if (tmp == '(') pth.pop();
				// ¦�� �ƴϸ� unbalance
				else break;
			}
			else if (str[i] == ']') {
				if (pth.empty()) {
					pth.push(str[i]);
					break;
				}
				tmp = pth.top();
				if (tmp == '[') pth.pop();
				else break;
			}
		}
		// ������ ������� ������ unbalance
		if (pth.empty()) cout << "yes\n";
		else {
			cout << "no\n";
			while (!pth.empty()) {
				pth.pop();
			}
		}
		getline(cin, str);
	} 



}