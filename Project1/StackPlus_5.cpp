// ������ Ȱ�� > 5.��ȣ�� ��(2504��)

#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string str;
	cin >> str;

	int pthCount = 0;
	stack<char> pth;

	char tmp;
	int x = 0;


	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			if (pth.empty()) {
				// �߸��� ���ڿ�
				pth.push(str[i]);
				break;
			}

			tmp = pth.top();
			if (tmp == '(') {
				pth.pop();
				pth.push('2');
			}
			else if (isdigit(tmp)) {
				// �� ���� �����̸�
				x += tmp - '0';
				pth.pop();
				while (!pth.empty()) {
					tmp = pth.top();
					if (tmp == '(') {
						pth.pop();
						// push �� �� ���ڷ� ����ȯ
						pth.push((2 * x) + '0');
						break;
					}
					else if (isdigit(tmp)) {
						x += tmp - '0';
						pth.pop();
					}
					else break; // �׷��� ������ �߸��� ��ȣ��
				}
				x = 0;
			}
			else break; // �������� �߸��� ��ȣ��
		}
		else if (str[i] == ']') {
			if (pth.empty()) {
				// �߸��� ���ڿ�
				pth.push(str[i]);
				break;
			}

			tmp = pth.top();
			if (tmp == '[') {
				pth.pop();
				pth.push('3');
			}
			else if (isdigit(tmp)) {
				// �� ���� �����̸�
				x += tmp - '0';
				pth.pop();
				while (!pth.empty()) {
					tmp = pth.top();
					if (tmp == '[') {
						pth.pop();
						pth.push((3 * x) + '0');
						break;
					}
					else if (isdigit(tmp)) {
						x += tmp - '0';
						pth.pop();
					}
					else break; // �׷��� ������ �߸��� ��ȣ��
				}
				x = 0;
			}
			else break; // �������� �߸��� ��ȣ��
		}
		else pth.push(str[i]);
	}

	//pth.push('2');
	//pth.push('0');
	// ������ ���ڷ� �̷���� ���� ������ �߸�
	while (!pth.empty()) {
		tmp = pth.top();
		cout << "tmp : " << tmp << "\n";
		if (isdigit(tmp)) {
			// �����̸� �� ���� count�� ����
			pthCount += (tmp - '0');
			pth.pop();
		}
		else {
			pthCount = 0;
			break;
		}
	}

	cout << pthCount;

	


}