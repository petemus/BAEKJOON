// 스택의 활용 > 3.괄호(9012번)
// ) 괄호가 들어올 때만 확인해야 함.

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
		// stack에 삽입하면서 검사
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ')') {
				if (pth.size() == 0) {
					// 스택에 값이 없으면
					pth.push(str[j]);
					break;
				}
				tmp = pth.top();
				if (tmp == '(') pth.pop();
			}
			else pth.push(str[j]);
		}

		if (!pth.empty()) {
			// 스택이 비지 않았으면 나쁜 단어
			// stack이 빌때까지 비워줌
			isVps = false;
			while (!pth.empty()) pth.pop();
		}

		if (isVps) cout << "YES\n";
		else cout << "NO\n";
		// 초기화
		isVps = true;
	}
}