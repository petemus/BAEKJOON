// Sort2 > 10.빈도정렬(2910번)
// ?? c 변수는 왜 필요한가?

// sort() stl이 내부적으로 어떤 정렬 알고리즘을 이용하는지 모르고 그에 따라서 들어온 순서가 달라질 수도 있어서 그런듯


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
			// 중복되지 않으면
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