// 집합과 맵 > 3.회사에 있는 사람

// [c++ or stl]
// :: (범위 지정 연산자) -> 식별자를 구분하는 데 사용 / 범위::식별자
// 맵은 배열 같은 문법을 허용하는 듯 ex> map[key] = value; (set은 당연하게도 불가능)
// map : key 값을 기준으로 정렬되어 있음 / 이진 탐색 트리로 구현하고 value를 찾는게
// unordered_map 보다 오래걸림 O(n)
// unordered_map : 정렬되어 있지 않은 컨테이너 / hash table 로 구현하고 value를 찾는 시간이 적게 걸림 O(1)
// @@@@@@@ 문제는 끝까지 잘 읽어 보자! ^^


// sol> 출퇴근 로그 맵을 만듬
// key 값이 이미 존재할 경우 값을 덮어씌우도록 짜야할듯
// 정렬된 상태에서 출력하면 안됨
// map에 들어온 순서대로 해야할듯.

// sol2> 출퇴근 set을 만들어서 퇴근하면 그 key를 지우도록. 그래서 최종 set에는 
// 출근한 사람만 남아 있음.


#include <iostream>
#include <map>
using namespace std;

int main() {

	int n;
	cin >> n;
	// map의 기본은 오름차순
	// greater<string> 추가시 내림차순 정렬
	map<string, string, greater<string>> log; 
	string key, value;
	for (int i = 0; i < n; i++) {
		cin >> key >> value;
		// 중복 확인
		if (log.count(key)) {
			// 중복 되면 value 수정
			// 혹은 지우고 다시 삽입 가능
			log[key] = value;			
		}
		else {
			log.insert(make_pair(key, value));
		}
	}

	// 전채 탐색하면서 value 값이 enter면 그 key 출력
	map<string, string>::iterator iter;
	for (iter = log.begin(); iter != log.end(); iter++) {
		if ((iter->second).compare("enter") == 0) {
			// compare() 함수는 둘이 같으면 -> 0 / 다르면 -> -1 을 리턴한다.
			cout << iter->first << "\n";
		}

	}

	
}