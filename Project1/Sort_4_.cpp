// ���� > 4. �� �����ϱ� 2
// �����Լ� ��� ver
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int tmp = 0;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}
}