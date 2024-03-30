// Sort2 > 6.�ø��� ��ȣ(1431��)
// 1.���ڿ� ���̰� ª�� ������ ����
// 2.���� ���̸� > ���ڰ� ���� ������ ����
// 3.���� ������ ���� 

// �̷��� Ư�� ��찡 ���� ��쿡�� �Ϲ����� �˰��� (����, ����, ����, ��, ���� ���� ������ ����ϳ�?)

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
				// ���ڶ�� ������
				cnta += a[i] - '0';
			}
			if (isdigit(b[i])) {
				cntb += b[i] - '0';
			}
		}
		// ũ�Ⱑ ������ ������
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