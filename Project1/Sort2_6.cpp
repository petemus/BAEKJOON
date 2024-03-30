// Sort2 > 6.시리얼 번호(1431번)
// 1.문자열 길이가 짧은 순으로 정렬
// 2.같은 길이면 > 숫자가 작은 순으로 정렬
// 3.사전 순으로 정렬 

// 이렇게 특수 경우가 많은 경우에도 일반적인 알고리즘 (선택, 삽입, 버블, 퀵, 머지 등의 정렬을 사용하나?)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b) {
	int sizea = a.size();
	int sizeb = b.size();

	if (sizea == sizeb) {
		int cnta = 0, cntb = 0;
		for (int i = 0; i < sizea; i++) {
			if (isdigit(a[i])) {
				// 숫자라면 세워줌
				cnta += a[i] - '0';
			}
			if (isdigit(b[i])) {
				cntb += b[i] - '0';
			}
		}
		// 크기가 같으면 사전순
		if (cnta == cntb) return a < b;
		else return cnta < cntb;
	}
	else {
		return sizea < sizeb;
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<string> dic;

	cin >> n;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		dic.push_back(tmp);
	}
	sort(dic.begin(), dic.end(), compare);

	for (int i = 0; i < dic.size(); i++) {
		cout << dic[i] << '\n';
	}

}