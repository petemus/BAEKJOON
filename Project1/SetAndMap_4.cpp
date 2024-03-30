// 집합과 맵 > 4.나는야 포켓몬 마스터 이다솜 ㅋ

// [c++/stl]
// auto 변수 타입 > 대입하는 값에 따라 자동으로 타입이 정해짐
// 입출력 시간 단축 방법 ->
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

// sol> 포켓몬 도감을 map으로 만들기 (이름) / 번호(1부터 시작) , 정렬이 안되고 들어온 순서로 저장 -> unordered_map
// 숫자(value)가 들어오면 이름(key)가 출력되고 이름이 들어오면 숫자가 출력되어야 함
// value로 key를 찾을 경우 맵의 전부를 순회해야하므로 비효율적인데 다른 방법이 없을까..?
// -> value 로 key 를 찾을려면 전부 순회해야해서 시간 초과남 O(n^2)면 시간초과 나는 듯.
// => 인덱스로 찾을 배열을 따로 만들거나 

// 문자열을 숫자로 변환하는 방법
// >> 1. isdigit() 함수 사용해서 순회하면서 문자열이 문자인지 확인
// >> 2. atoi() 함수 사용 -> atoi() 함수는 매개변수로 const char * 타입이 들어감 ( 그래서 string을 char pointer로 넘겨주기 위해서 string::c_str() 함수를 사용해야함)
// 숫자일 경우 -> 숫자 반환 / 문자일 경우 -> 0 반환 (주의: 숫자 0일 경우도 0을 반환)
// >> 3. stoi() 함수 사용 -> atoi() 함수와 달리 string을 인자로 인식
// but, stoi() 함수는 인자가 숫자로 변환이 불가능할 때 예외처리가 이러남...
// >> 4. 문자열의 첫번째 문자만 확인해도 됨 (포켓몬 이름에는 숫자가 들어가지 않으므로..) => isdigit() 함수 사용 가능


#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	unordered_map<string, int> dic;
	string* indexDic = new string[n];
	
	//입력
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		dic.insert(make_pair(tmp, i + 1));
		indexDic[i] = tmp;
	}

	string* inputs = new string[m];
	unordered_map<string, int>::iterator iter;
	for (int i = 0; i < m; i++) {
		cin >> inputs[i];
	}


	// 출력
	for (int i = 0; i < m; i++) {
		if (atoi(inputs[i].c_str())) {
			// 정수이면 value를 통해 key 찾기
			
			// 1. 전체 순회
			//for (iter = dic.begin(); iter != dic.end(); iter++) {
			//	if (atoi(inputs[i].c_str()) == iter->second) {
			//		cout << iter->first << "\n";
			//		break; // value 가 중복되지 않으므로 break 해도 됨.
			//	}
			//}
			
			// 2. 인덱스 배열 따로 만들기
			cout << indexDic[atoi(inputs[i].c_str()) - 1] << "\n";
		}
		else {
			// 문자열이면
			iter = dic.find(inputs[i]);
			cout << iter->second << "\n";
		}
	}

}