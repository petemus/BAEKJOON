// 집합과 맵 > 7.대칭 차집합
// 대칭 차집합의 개수를 구하는 문제
// 집합 A, B가 있을 때 (A - B) + (B - A) 가 대칭 차집합.

// sol1> B와 A의 교집합의 개수를 구하고 B와 A의 원소 개수를 더한 다음 2*(교집합)을 빼줌
// @@@@ 중요 => A + B - 2(A n B) 
// sol2> setA를 만들고 setB에 대한 원소가 들어올 때,
// A에 있는 원소가 들어오는 경우 제거하고 A에 없는 원소가 들어오면 추가
// => setA를 진짜 대칭 차집합의 set으로 만들 수 있음.

#include <iostream>
#include <set>
using namespace std;

int main() {


	int n, m;
	cin >> n >> m;

	set<int> setA;
	set<int> setB;
	int count = 0;

	//A 입력 받음
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		setA.insert(tmp);
	}
	// B 입력 받음 + A와 겹치는 갯수 확인
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		setB.insert(tmp);
		if (setA.count(tmp)) {
			// count() 말고 find() 함수 쓰면 최적화 가능
			// tmp가 A에 있으면
			count++;
		}
	}
	int result = 0;
	// 결과 계산
	result = setA.size() + setB.size() - 2 * count;
	cout << result;

}