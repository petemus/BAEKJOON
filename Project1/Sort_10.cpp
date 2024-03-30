// ���� > 10. ���̼� ����
// ����� ���� compare() �Լ��� ����� �� �ٽ��ΰǰ�
// pair�� first�� ���� second�� �Է°��� ���� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	// ���̰� ������
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