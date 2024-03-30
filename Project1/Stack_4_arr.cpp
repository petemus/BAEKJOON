// 4.탑(2493번) 문제를 스택 이용 안하고 배열로 풀기
// => 시간 초과

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// tower 저장할 값을 스택이 아닌 배열에 저장
	int* tower = new int[n];
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		tower[i] = tmp;
	}

	int* result = new int[n];
	// 뒤에서부터 찾기
	int comp = 0;
	bool isFind = false;
	for (int i = n - 1; i >= 0; i--) {
		comp = tower[i];
		for (int j = i - 1; j >= 0; j--) {
			if (tower[j] >= tower[i]) {  // ? 탑 꼭대기도 받을 수 있겠지
				// 송신 가능
				result[i] = j;
				isFind = true;
				break;
			}
		}
		if (!isFind) {
			// 발견을 못하면 0을 저장
			result[i] = 0;
		}
		isFind = false;
	}

	
	for (int i = 0; i < n; i++) {
		tmp = result[i];
		if (tmp != 0) cout << ++tmp << " ";
		else cout << tmp << " ";
	}

}