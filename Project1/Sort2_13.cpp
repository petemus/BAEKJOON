// Sort2 > 13.국영수(10825번)

// 연산자 오버로딩~~

#include <iostream>	
#include <vector>	
#include <algorithm>
using namespace std;

int kor[100000];
int eng[100000];
int math[100000];

bool compare(pair<string, int> a, pair<string, int> b) {
	if (kor[a.second] == kor[b.second]) {
		if (eng[a.second] == eng[b.second]) {
			if (math[a.second] == math[b.second]) {
				// 사전순
				return a.first < b.first;
			}
			else return math[a.second] > math[b.second];
		}
		else return eng[a.second] < eng[b.second];
	}
	else return kor[a.second] > kor[b.second];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<string, int>> student;

	string name;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> name >> a >> b >> c;
		student.push_back({ name, i });
		kor[i] = a;
		eng[i] = b;
		math[i] = c;
	}

	sort(student.begin(), student.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << student[i].first << "\n";
	}

}