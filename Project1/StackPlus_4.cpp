// 스택의 활용 > 4.쇠막대기(10799번)

// @@ 다시 풀어보기


#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string str;
	cin >> str;

	stack<char> pth;
	char tmp;
	int count = 0;
	int rcount = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			// 이 문제는 비어있을 수 없음
			tmp = pth.top();
			if (tmp == '(') {
				pth.pop();
				pth.push('R');
			}
			else if (tmp == 'R') {
				rcount++;
				pth.pop();
				while (!pth.empty()) {
					tmp = pth.top();
					if (tmp == '(') {
						pth.pop();
						count += rcount + 1;
						for (int j = 0; j < rcount; j++) pth.push('R');
						break;
					}
					else if (tmp == 'R') {
						pth.pop();
						rcount++;
					}
				}
				rcount = 0;
			}
		}
		else pth.push(str[i]);
	}
	// count = 2 + 1 + 3
	// ()((()()))
	// R ( 
	// ((()))((R

	cout << count;

}