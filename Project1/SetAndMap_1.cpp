// 1초 : 계산 1억번 

// 집합과 맵 > 1. 숫자 카드
// Set(집합) : key 만 가지는 자료 구조(정렬됨), 중복허용 X, 연관 컨테이너
// Map(맵) : key와 value 를 한 쌍으로 가지는 자료구조, 연관 컨테이너,



// sol1. M개의 정수들을 N개의 카드와 비교에서 같은 카드 찾기 => O(n*m)
// sol2. 집합이용하기 (출제 의도)

#include <iostream>
#include <set>
using namespace std;

int main() {

	int n;
	set<int> cards;

	// 카드 입력 받기
	cin >> n;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cards.insert(tmp);
	}

	int m;
	cin >> m;
	int* comp = new int[m]; // 동적 할당
	for (int i = 0; i < m; i++) {
		cin >> comp[i];
	}

	//for (set<int>::iterator iter = cards.begin(); iter != cards.end(); iter++) {
	//	cout << *iter << " ";
	//}

	//비교
	for (int i = 0; i < m; i++) {
		if (cards.find(comp[i]) != cards.end()) {
			// 발견하면
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
	}

}
