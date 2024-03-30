// 덱 > 3.AC(5430번)
// idea>
// 물리적으로 뒤집을 수도 있지만 덱을 사용하면 뒤집으면 뒤에서 버리고 뒤집지 않으면 앞에서 버리면 된다
// 따라서 물리적으로 뒤집지 않고 flag 같은 것을 이용해서 뒤집는지 안 뒤집는지 표시해서
// 그에 따라 pop을 달리 한다.
// ! 배열을 입력받는 게 어려울 것 같다.
// @@ 오류찾을 때 엣지케이스부터 찾아야함.!

// [c++]
// c++에서 문자열 자르기>
// - ssstream::istringstream 과 std::getline() 함수 이용하기 -> 문자열 구분자가 1개일 때 유용
// - strtok() 함수 이용하기 -> 문자열 구분자가 2개 이상일 경우 유용하지만 형변환이 많이 필요함

// @@ 문자열에서 배열을 추출할 때 쪼개는 함수를 이용하는 것 보다
// @@ 규칙을 찾아서 입력 받는 게 더 좋은 듯

#include <iostream>
#include <deque>
#include <cstring>
#include <string>
using namespace std;

void printArr(deque<int> dq, bool isReverse) {
	cout << "[";
	if (isReverse) {
		for (int i = dq.size() - 1; i >= 0; i--) {
			cout << dq[i];
			if (i != 0) cout << ",";
		}
	}
	else {
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[i];
			if (i != dq.size() - 1 ) cout << ",";
		}
	}
	cout << "]\n";
}

void makeArr(string arr, deque<int>& dq) {
	// string 을 문자 배열로 전환할 때 그 크기보다 1이 더 커야 한다.
	// 널문자를 포함해야하므로
	char* charr = new char[arr.size() + 1];
	strcpy_s(charr, arr.size() + 1, arr.c_str());
	// 백준에서는 strcpy_s는 컴파일 에러남. strcpy()를 써야하는듯

	char* leftstr = NULL;
	char* ptr = strtok_s(charr, "[,]", &leftstr);
	// 백준에서는 strtok_s() 함수는 컴파일 에러. strtok_r()을 써야하는 듯

	string tmp;
	while (ptr != NULL) {
		tmp = string(ptr);
		dq.push_back(stoi(tmp));
		ptr = strtok_s(NULL, "[,]", &leftstr);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	// 변수들
	string cmd;
	int n; // 배열 크기
	string arr;
	deque<int> dq;
	bool isReverse = false;
	bool isError = false;

	for (int i = 0; i < t; i++) {
		cin >> cmd >> n >> arr;
		// arr 문자열을 쪼개서 덱에 저장.
		makeArr(arr, dq);
		// 명령어 실행
		for (int j = 0; j < cmd.size(); j++) {
			if (cmd[j] == 'R') {
				isReverse = !isReverse;
			}
			else if (cmd[j] == 'D') {
				if (dq.size() == 0) {
					// 비어 있으면 error후 반복문 탈출
					cout << "error\n";
					isError = true;
					break;
				}
				else {
					// 뒤로 pop
					if (isReverse) dq.pop_back();
					// 앞으로 pop
					else dq.pop_front();
				}
			}
		}
		// 남은 배열 출력
		if(!isError) printArr(dq, isReverse);
		// 변수들 초기화
		isReverse = false;
		dq.clear();
		isError = false;
	}
}