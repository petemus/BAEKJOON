// Sort2 > 3.수 정렬하기 3(10989번)
// 일반적으로 하면 메모리 초과남
// 중복 여러개를 다 저장하면 메모리 초과남
// => 전에 ㄱㅁㄱ씨가 알려준 방법

#include <iostream>
using namespace std;

int arr[10001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp]++;
	}
	// 출력
	for (int i = 1; i < 10001; i++) {
		tmp = arr[i];
		for (int j = 0; j < tmp; j++) {
			cout << i << "\n";
		}
	}

}