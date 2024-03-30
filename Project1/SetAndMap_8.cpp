// 집합과 맵 > 8. 서로 다른 부분 문자열의 개수
// 처음에는 부분 집합의 개수를 구하는 문제와 관련이 있나했는데 아닌듯
// @@ 문제를 잘 읽자 ^^

// string::substr(a, b) : a는 시작 인덱스, b 는 문자열 길이


// sol1> 문자열을 1~문자열의 크기만큼 자른 것들을 집합에 집어넣음
// 집합은 중복 허용을 안하기 때문에 그 집합의 크기가 서로 다른 문자열의 개수가 됨.


#include <iostream>
#include <set>
using namespace std;

int main() {

	// 문자열의 크기는 널 문자 포함 X
	string str; 
	cin >> str;

	set<string> substrs;
	string tmp;
	for (int i = 0; i < str.size(); i++) {
		for (int j = 1; j <= str.size() - i; j++) {
			tmp = str.substr(i, j);
			//cout << tmp << "\n";
			substrs.insert(tmp);
		}
	}

	cout << substrs.size();
}