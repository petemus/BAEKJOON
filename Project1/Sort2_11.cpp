// Sort2 > 11.나이순 정렬(10814번)품
//등록된 순서를 저장해야할듯

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) return false;
	else return a.first < b.first;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;
	vector<pair<int, string>> arr;


	int age;
	string name;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		arr.push_back({ age, name });
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}



}