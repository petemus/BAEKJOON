// 스택의 활용 > 2.좋은 단어(3986번)
// 스택의 맨 위에 있는 요소와 들어갈려는 요소가 같으면 pop 아니면 push
// stack이 비지 않았으면 좋은 단어가 아님.

// [c++]
// stl에서 스택과 큐는 clear() 함수를 제공하지 않는다.

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
		// stack에 삽입하면서 검사
		for (int j = 0; j < str.size(); j++) {
			if (word.empty()) word.push(str[j]);
			else {
				tmp = word.top();
				// 같으면 pop
				if (tmp == str[j]) word.pop();
				// 같지 않으면 push
				else word.push(str[j]);
			}
		}

		if (!word.empty()) {
			// 스택이 비지 않았으면 나쁜 단어
			// stack이 빌때까지 비워줌
			while (!word.empty()) word.pop();
		}
		else goodWord++;
	}

	cout << goodWord;

}