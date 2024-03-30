// 정렬 > 9. 단어 정렬
// 중복되는 값은 vector에 넣지 않는 게 핵심.
// -- 기수 정렬 --
// 같은 자리수일 때만 사용.
// 뒷자리수부터 시작해서 첫쨰자리 순서로 정렬

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else  return a.length() < b.length(); // size()도 가능
}

// 문자열에서는 length() 가 실제로의 문자열 길이를 의미
// size()는 string 객체가 메모리에서 실제 사용하고 있는 크기
// 결과적으로 같은 값이 나오는 것 같은데... 무슨 차이인지 정확히 모르겠음
// vector에서는 size() 가 원소 개수를 의미하고
// capacity()는 vector의 type들을 담을 수 있는 메모리가 할당되어 있는 공간의 용량

int main() {

	int n;
	cin >> n;

	vector<string> arr;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		// find 함수는 해당 문자열이 없으면 arr.end()를 반환
		if (find(arr.begin(), arr.end(), str) == arr.end())
			arr.push_back(str);
	}
	// 일반적으로 문자열 정렬은 사전순
	sort(arr.begin(), arr.end(), compare); 


	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << '\n';
	}

}