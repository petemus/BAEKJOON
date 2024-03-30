// Backtracking > 3.암호 만들기(1759번)
// 서로 다른 문자들 + 오름차순
// 핵심 : 최소 모음 1 + 자음 2
// -> 방법 1: dept가 4일 때 해당 pw 가  모음 1 + 자음 2로 이루어져있는지 검사
// -> 방법 2: Backtracking 함수 호출할 때마다 모음 개수 자음 개수 검사해주기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> alpha;
char pw[15];

void Backtracking(int index, int dept) {
	pw[dept - 1] = alpha[index];
	// 종료 조건
	if (dept == l) {
		// 모음 1 자음 2인지 검사
		int vowelCnt = 0;
		for (int i = 0; i < l; i++) {
			if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u') vowelCnt++;
		}
		if (vowelCnt < 1 || vowelCnt >(l - 2)) return;
		// 출력
		for (int i = 0; i < l; i++) {
			cout << pw[i];
		}
		cout << "\n";
		return;
	}

	// 재귀 호출
	int d = dept + 1;
	for (int i = index + 1; i < c; i++) {
		Backtracking(i, d);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// algorithm
	// 입력 받기
	// 문자들 정렬
	// backtracking

	// 입력
	cin >> l >> c;
	char tmp;
	for (int i = 0; i < c; i++) {
		cin >> tmp;
		alpha.push_back(tmp);
	}
	// 정렬
	sort(alpha.begin(), alpha.end());

	// Backtracking
	for (int i = 0; i < c; i++) {
		Backtracking(i, 1);
	}
}