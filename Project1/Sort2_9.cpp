// Sort2 > �ܾ� ����(1181��)ǰ
// �ߺ��� �ܾ� �����ؾ���

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	int sizea = a.size();
	int sizeb = b.size();
	if (sizea == sizeb) return a < b;
	else return sizea < sizeb;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<string> words;

	cin >> n;

	string tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		words.push_back(tmp);
	}

	sort(words.begin(), words.end(), compare);

	// �ߺ� ���� -> ����
	vector<string>::iterator prev = words.begin();
	int k = 0;
	for (vector<string>::iterator it = words.begin() + 1 ; it != words.end(); it++) {
		if ((*prev).compare(*it) == 0) {
			// ���� ���ڿ��� ���� ���ڿ��̸� ���� ���ڿ� ����
			words.erase(it);
			it = prev + 1;
			cout << "���� ���ڿ� : " << *prev  << " " << *it << '\n';
			continue;
		}
		prev = it;
	}

	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << "\n";
	}
}