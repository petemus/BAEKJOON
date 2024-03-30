// 약수 배수와 소수2 > 9.창문 닫기

// sol1> 에라토스테네스의 체로 소수 구한 것 처럼 풀어보기 => 메모리 초과
// sol2> 각 수의 약수 개수 : on, off의 개수 -> 약수의 개수가 짝수이면 on 홀수이면 off => 시간 초과
// > 시간 초과를 줄이기 위한 방법 -> 약수의 개수가 홀수인 수는 수의 제곱근이 양수일 때임. => 시간 초과 ^^
// >> i * i < tmp 인 i를 구하는 방법으로 바꾸기 => 성공 ^^

#include <iostream>
#include <cmath>
using namespace std;

//int countDivisor(int k) {
//	int end = sqrt(k);
//	int cnt = 2;
//	for (int i = 2; i <= end; i++) {
//		if (k % i == 0) {
//			// 약수
//			if (i * i == k) cnt++;
//			else cnt += 2;
//		}
//	}
//	return cnt;
//}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int cntOn = 0;
	int i = 1;
	while (i * i <= n) {
		cntOn++;
		i++;
	}

	cout << cntOn;


	// sol1>
	//bool* windows = new bool[n + 1];
	//for (int i = 0; i <= n; i++) windows[i] = false;
	//vector<bool> windows;
	//for (int i = 0; i <= n; i++) windows.push_back(false);
	//// 열어 주기
	//for (int i = 1; i < n + 1; i++) {
	//	for (int j = 1; j * i <= n; j++) {
	//		windows[i * j] = !windows[i * j];
	//	}
	//}
	//int cnt = 0;
	//for (int i = 1; i <= n; i++) {
	//	if (windows[i]) cnt++;
	//}
	//cout << cnt;

}