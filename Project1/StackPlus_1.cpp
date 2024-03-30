// 스택의 활용 > 1.균형잡힌 세상(4949번)
// 한 줄 단위로 입력 받아서 괄호만 stack에 저장. 
// 괄호가 대칭이 맞으면 올바른 문장

// [c++]
// endl -> 개행 문자이면서도 입력 버퍼를 지우는? 역할을 한다.

// ? 나는 getline(cin, str, '.') 하면 안됨
// .을 넣게 되면 중간에 . 이 들어오면 그 전까지만 입력이 들어오고
// 종료 조건을 확인할 수 가 없음

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
				// 짝이 아니면 unbalance
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
		// 스택이 비어있지 않으면 unbalance
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