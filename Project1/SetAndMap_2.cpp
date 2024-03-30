// 집합과 맵 > 2.문자열 집합

// sol1. 브루트 포스
// sol2. 집합 사용 (string 타입)

#include <iostream>
#include <set>
using namespace std;

int main() {

	int n, m;
	cin >> n;
	cin >> m;
	
	// 집합
	set<string> s;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		s.insert(tmp);
	}
	// 비교할 배열 
	string* comp = new string[m];
	for (int i = 0; i < m; i++) {
		cin >> comp[i];
	}

	int result = 0;


	// 아래 for 문 위에 for문과 합칠 수 있을 듯
	for (int i = 0; i < m; i++) {
		if (s.find(comp[i]) != s.end()) {
			// 값을 찾으면
			result++;
		}
	}

	cout << result;
}