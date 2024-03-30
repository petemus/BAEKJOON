// Simulation > 4.치킨 배달(15686번)
// 
// (1) 백트랙킹(사실강 걍 dfs) -> 시간초과 니기럴ㄹ
// -> 반복문 거의 제거해서 했는데도 시간초과..
// ?? 언제 시간초과가 나는거지 => 치킨집을 안뽑음~~~

// 재귀호출 할 때 방문 표시해야하고 재귀 나오면 방문 해제 해야함
// (2) 치킨집 한 개씩 제거 -> 제거 규칙이 명확하지 않음..


#include <iostream>
#include <vector>	
using namespace std;

int n, m;
int minChicken = 10000;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

bool isVilsted[50][50] = { 0, };

int minDis(int r, int c) {
	// 치킨집과의 거리 계산후 최솟값 반환
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

void Backtracking(int lev) {
	// 종료 조건
	if (lev == m) {
		// 치킨 거리 최솟값 계산
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			sum += minDis(house[i].first, house[i].second);
		}
		if (minChicken > sum) {
			minChicken = sum;
		}
		return;
	}

	// Backtracking
	for (int i = 0; i < chicken.size(); i++) {
		int tmpr = chicken[i].first;
		int tmpc = chicken[i].second;
		if (!isVilsted[tmpr][tmpc]) {
			isVilsted[tmpr][tmpc] = true;
			Backtracking(lev + 1);
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
			cin >> tmp;
			if (tmp == 1) house.push_back({ i,j });
			if (tmp == 2) chicken.push_back({ i,j });
		}
	}

	Backtracking(0);

	cout << minChicken;

}