// Sort2 > 12.���̻� �迭(11656��)

// substr() �Լ� �̿��ؼ��� Ǯ �� ����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	cin >> str;

	vector<string> arr;

	char* tmp;
	for (int i = 0; i < str.size(); i++) {
		tmp = new char[str.size() + 1 - i];
		for (int j = i; j < str.size(); j++) {
			tmp[j - i] = str[j];
		}
		tmp[str.size() - i] = '\0';
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "\n";
	}
}