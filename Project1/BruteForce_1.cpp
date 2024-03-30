#include <iostream>
using namespace std;

void bubble_sort(int *arr, int size) {
	int tmp = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				// swap
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main() {

	int n = 0, m = 0;
	cin >> n >> m;
	
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int maxSum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] >= maxSum) {
					maxSum = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}

	cout << maxSum;
	
}