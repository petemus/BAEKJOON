// 정렬 > 10. 나이순 정렬
// 사용자 정의 compare() 함수를 만드는 게 핵심인건가
// pair의 first는 나이 second는 입력값이 들어온 순서
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	// 나이가 같으면
	if (a.first == b.first) {
		return a < b;
	}
	else return a.first < b.first;
}

int main() {
	
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	string* name = new string[n];
	int age;
	for (int i = 0; i < n; i++) {
		cin >> age >> name[i];
		vec.push_back({ age, i });
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << vec[i].first << ' ' << name[vec[i].second] << '\n';
	}

}