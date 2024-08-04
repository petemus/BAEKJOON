// Backtracking > 치킨 배달 (15686번)
// 매번 집과 치킨집 사이의 거리를 계산 하는 게 아니라 처음 한번 저장하자

#include <iostream>
#include <vector>	
using namespace std;

int n, m;
int minChicken = 10000;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int chickenDis[100][13];		// 집 index와 chicken index 사이의 거리

bool isVilsted[50][50] = { 0, };

int minDis(int r, int c) {
	int min = 100;
	for (int i = 0; i < chicken.size(); i++) {
		int tmpr = chicken[i].first;
		int tmpc = chicken[i].second;
		if (isVilsted[tmpr][tmpc]) {
			int dis = abs(r - tmpr) + abs(c - tmpc);
			if (min > dis) min = dis;
		}
	}
	return min;
}

void Backtracking(int lev, int select) {
	// 종료 조건
	if (lev == m) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			sum += minDis(house[i].first, house[i].second);
		}
		if (minChicken > sum) {
			minChicken = sum;
		}
		return;
	}

	// 내가 선택한 치킨집의 옆부터 계산해야함 -> 그래야 중복 없음 -> 시간 초과 없음
	for (int i = select + 1; i < chicken.size(); i++) {
		int tmpr = chicken[i].first;
		int tmpc = chicken[i].second;
		if (!isVilsted[tmpr][tmpc]) {
			isVilsted[tmpr][tmpc] = true;
			Backtracking(lev + 1, i);
			isVilsted[tmpr][tmpc] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cin >> village[i][j];
			cin >> tmp;
			if (tmp == 1) house.push_back({ i,j });
			if (tmp == 2) chicken.push_back({ i,j });
		}
	}



	Backtracking(0, -1);

	cout << minChicken;

}