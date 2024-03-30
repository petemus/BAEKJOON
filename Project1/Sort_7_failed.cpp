// ���� > 7. ��ǥ �����ϱ�
// ��ǥ �� �����ϱ� ���� 2���� �迭 ����ҷ��� �ߴµ�
// �����ؼ� 1���� �迭�� ���� -> ���� �Լ��� ȣ�� �Ұ����ؼ� ����
#include <iostream>
using namespace std;

// bubble_sort Ŀ����
void bubble_sort(int* arr1, int* arr2, int start, int end) {
	int tmp = 0;
	for (int i = start; i < end - 1; i++) {
		for (int j = start; j < end - 1 - i; j++) {
			if (arr1[j] > arr1[j + 1]) {
				// swap
				tmp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = tmp;
				// 
				tmp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = tmp;
			}
		}
	}
}

int main() {

	int n;
	cin >> n;
	// 2���� �迭 ���� ����
	int* arrX = new int[n];
	int* arrY = new int[n];
	// �Է°� ����
	for(int i = 0; i < n; i++){
		cin >> arrX[i] >> arrY[i];
	}
	// x �켱 ����, x ���� ���� ���� ������ ���� ����
	// ���� ����
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << arrX[i] << ' ' << arrY[i];
		cout << '\n';
	}
	// x 1�� ����
	bubble_sort(arrX, arrY, 0, 5);
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << arrX[i] << ' ' << arrY[i];
		cout << '\n';
	}
	// y ����
	int start = 0;
	int end = 0;
	int same = 0;
	for (int i = 0; i < n; i++) {
		same = arrX[i];
		start = i;
		for (int j = 0; j < n; j++) {
			if (same == arrX[i]) {
				end++;
			}
		}
		bubble_sort(arrY, arrX, start, end + start);
		i += end - 1;
		end = 0;
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << arrX[i] << ' ' << arrY[i];
		cout << '\n';
	}

}