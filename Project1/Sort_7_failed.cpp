// 정렬 > 7. 좌표 정렬하기
// 좌표 값 저장하기 위해 2차원 배열 사용할려고 했는데
// 복잡해서 1차원 배열로 저장 -> 같은 함수를 호출 불가능해서 복잡
#include <iostream>
using namespace std;

// bubble_sort 커스텀
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
	// 2차원 배열 동적 생성
	int* arrX = new int[n];
	int* arrY = new int[n];
	// 입력값 대입
	for(int i = 0; i < n; i++){
		cin >> arrX[i] >> arrY[i];
	}
	// x 우선 정렬, x 값이 다음 값과 같으면 비교후 변경
	// 버블 정렬
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << arrX[i] << ' ' << arrY[i];
		cout << '\n';
	}
	// x 1차 정렬
	bubble_sort(arrX, arrY, 0, 5);
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << arrX[i] << ' ' << arrY[i];
		cout << '\n';
	}
	// y 정렬
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