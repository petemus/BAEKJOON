// 집합과 맵 > 5. 숫자 카드 2

// base는 문제 1과 비슷하지만 중복이 허용된다는 점이 다르다..
// 기본 set -> 중복 허용 X
// multiset -> 중복 허용
// sol1> multiset 사용 => 시간 초과 남
// sol12> map을 사용해서 value에 몇번 중복되는지를 저장
// 뇌피셜 :: count()의 연산 속도가 느린듯. why???


#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	//multiset<int> cards;
	map<int, int> mapCards;
	int tmp;
	map<int, int>::iterator iter;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		//cards.insert(tmp);
		// map 은 []로 접근이 가능해서 find() 함수 안 써도 될듯.
		// mapCards[tmp]++; 해도 가능.
		iter = mapCards.find(tmp);
		if (iter != mapCards.end()) {
			// 중복 되면 
			mapCards[tmp] = (iter->second + 1 );
		}
		else {
			// 중복 되지 않으면
			mapCards.insert(make_pair(tmp, 1));
		}
	}

	int m;
	cin >> m;
	// map 은 []로 접근이 가능해서 find() 함수 안 써도 될듯.
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		//cout << cards.count(tmp) << " ";
		iter = mapCards.find(tmp);
		if (iter != mapCards.end()) {
			cout << iter->second << " ";
		}
		else {
			cout << "0 ";
		}
	}
	

}