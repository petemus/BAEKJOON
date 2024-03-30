// Backtracking > 4.계란으로 계란치기(16987번)
// 종료 조건 설정 문제
// 계란 내구도 저장 문제
// 너무 많은 재귀 함수 호출 문제

#include <iostream>
#include <vector>
using namespace std;

int maxCnt = 0;
vector<pair<int, int>> eggs; // first : 내구도, second: 무게(공격력)
int n;


void Backtracking(int leftEgg, int rightEgg, int brokenEgg) {

	//cout << "eggs ";
	//for (int i = 0; i < n; i++) {
	//	cout << eggs[i].first << " ";
	//}
	//cout << '\n';

	//달걀 깨기
	//왼쪽 계란이 깨졌거나 오른쪽 계란이 깨져있으면 pass
	bool isBreak = false;
	if (eggs[leftEgg].first > 0 && eggs[rightEgg].first > 0) {
		eggs[leftEgg].first -= eggs[rightEgg].second;
		eggs[rightEgg].first -= eggs[leftEgg].second;
		//cout << "broken Egg " << eggs[leftEgg].first << " " << eggs[rightEgg].first << '\n';
		if (eggs[leftEgg].first <= 0) brokenEgg++;
		if (eggs[rightEgg].first <= 0) brokenEgg++;
		isBreak = true;
	}
	
	//종료 조건
	if (leftEgg + 1 == n) {
		if (brokenEgg > maxCnt) maxCnt = brokenEgg;
		// 계란 돌려내기
		if (isBreak) {
			eggs[leftEgg].first += eggs[rightEgg].second;
			eggs[rightEgg].first += eggs[leftEgg].second;
		}
		return;
	}

	//재귀 호출
	bool noEgg = true;
	for (int i = 0; i < n; i++) {
		if (i == leftEgg + 1) continue;
		if (eggs[i].first > 0) {
			//cout << "Backtracking " << leftEgg + 1 << " " << i << '\n';
			Backtracking(leftEgg + 1, i, brokenEgg);
			noEgg = false;
		}
	}

	if (noEgg) {
		//cout << "칠거 없음\n";
		//cout << "Backtracking " << leftEgg + 1 << " " << 0 << '\n';
		Backtracking(leftEgg + 1, 0, brokenEgg);
	}

	if (isBreak) {
		// 계란 돌려내기
		eggs[leftEgg].first += eggs[rightEgg].second;
		eggs[rightEgg].first += eggs[leftEgg].second;
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// algorithm
	// 입력
	// Backtracking

	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		eggs.push_back(make_pair(a, b));
	}

	//Backtracking
	for (int i = 1; i < n; i++) {
		//cout << i << "\n";
		//cout << "Backtracking " << 0 << " " << i << '\n';
		Backtracking(0, i, 0);
	}

	cout << maxCnt;

}