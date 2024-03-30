// 집합과 맵 > 6.듣보잡
// 두 집합의 교집합의 원소 개수와 원소들을 구하는 문제

// 교집합을 어떻게 구할 것인가?
// @1. 한 집합의 모든 원소들을 돌면서 다른 집합에 이 원소가 있!는지 확인 -> O(n)
// 2. 알고리즘 이용 vector의 교집합 연산해주는 함수 set_difference()

#include <iostream>
#include <set>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	
	set<string> set1;

	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		set1.insert(tmp);
	}

	int count = 0;
	set<string> inter;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (set1.count(tmp)) {
			// 1개 이상이면 
			inter.insert(tmp);
			count++;
		}
	}

	// 출력
	cout << count << "\n";
	set<string>::iterator iter;
	for (iter = inter.begin(); iter != inter.end(); iter++) {
		cout << *iter << "\n";
	}
}