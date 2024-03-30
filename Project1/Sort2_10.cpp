// Sort2 > 10.������(2910��)
// ?? c ������ �� �ʿ��Ѱ�?

// sort() stl�� ���������� � ���� �˰����� �̿��ϴ��� �𸣰� �׿� ���� ���� ������ �޶��� ���� �־ �׷���


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arrCnt;


bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return false;
	}
	else return a.second > b.second;
}

int find(int k) {

	for (int i = 0; i < arrCnt.size(); i++) {
		if (arrCnt[i].first == k) {
			return i;
		}
	}
	return	-1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c;
	

	cin >> n >> c;
	
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		int k = find(tmp);
		if (k == -1) {
			// �ߺ����� ������
			arrCnt.push_back({ tmp, 1 });
		}
		else {
			arrCnt[k].second += 1;
		}
	}

	sort(arrCnt.begin(), arrCnt.end(), compare);

	int cnt;
	for (int i = 0; i < arrCnt.size(); i++) {
		cnt = arrCnt[i].second;
		for (int j = 0; j < cnt; j++) {
			cout << arrCnt[i].first << " ";
		}
	}



}