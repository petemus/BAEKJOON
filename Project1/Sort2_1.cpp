// Sort2 > 1. 수 정렬하기(2750번) // heap으로 문제 한번 품
// 삽입, 선택, 버블, 힙, 합병, 퀵 정렬
// 버블 정렬

#include <iostream>
using namespace std;

int n;
int arr[1000];

void bubble_sort() {
	int tmp;
	
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n - j; i++) {
			if (arr[i] > arr[i + 1]) {
				// 교환
				tmp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = tmp;
			}
		}
	}

	// 일반 적인 버블 정렬
	//for (int i = n - 1; i > 0; i--) {
	//	for (int j = 0; j < i; j++) {
	//		if (arr[j] > arr[j + 1]) {
	//			// 교환
	//			tmp = arr[j + 1];
	//			arr[j + 1] = arr[j];
	//			arr[j] = tmp;
	//		}
	//	}
	//}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bubble_sort();
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}
