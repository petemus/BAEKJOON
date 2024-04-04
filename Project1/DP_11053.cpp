// 2. 가장 긴 증가하는 수열(11053) => O

// 풀이 1) n^2 방법 : 현재 수의 왼쪽주에 자기보다 작은 애를 저장
// 왼쪽에 있는 수들과 현재 내 왼쪽에 있는 최소값들과 비교후에 큰 것만 저장


#include <iostream>
using namespace std;

int number[1001] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	int count;
	cin >> count;
	int* arr = new int[count];
	for (int i = 0; i < count; i++) {
		int val;
		cin >> val;
		arr[i] = val;
	}

	int max = 0;
	for (int i = 1; i < count; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				if ((number[arr[j]] + 1) > number[arr[i]])
					number[arr[i]] = number[arr[j]] + 1;
			}
		}
		if (number[arr[i]] > max) max = number[arr[i]];
	}

	cout << max + 1;

}