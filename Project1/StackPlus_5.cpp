// 스택의 활용 > 5.괄호의 값(2504번)

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
				// 잘못된 문자열
				pth.push(str[i]);
				break;
			}

			tmp = pth.top();
			if (tmp == '(') {
				pth.pop();
				pth.push('2');
			}
			else if (isdigit(tmp)) {
				// 그 값이 숫자이면
				x += tmp - '0';
				pth.pop();
				while (!pth.empty()) {
					tmp = pth.top();
					if (tmp == '(') {
						pth.pop();
						// push 할 때 문자로 형변환
						pth.push((2 * x) + '0');
						break;
					}
					else if (isdigit(tmp)) {
						x += tmp - '0';
						pth.pop();
					}
					else break; // 그렇지 않으면 잘못된 괄호열
				}
				x = 0;
			}
			else break; // 나머지는 잘못된 괄호열
		}
		else if (str[i] == ']') {
			if (pth.empty()) {
				// 잘못된 문자열
				pth.push(str[i]);
				break;
			}

			tmp = pth.top();
			if (tmp == '[') {
				pth.pop();
				pth.push('3');
			}
			else if (isdigit(tmp)) {
				// 그 값이 숫자이면
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
					else break; // 그렇지 않으면 잘못된 괄호열
				}
				x = 0;
			}
			else break; // 나머지는 잘못된 괄호열
		}
		else pth.push(str[i]);
	}

	//pth.push('2');
	//pth.push('0');
	// 스택이 숫자로 이루어져 있지 않으면 잘못
	while (!pth.empty()) {
		tmp = pth.top();
		cout << "tmp : " << tmp << "\n";
		if (isdigit(tmp)) {
			// 숫자이면 그 값을 count에 더함
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