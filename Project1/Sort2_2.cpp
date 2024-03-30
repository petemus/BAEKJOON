// Sort2 > 2. 수 정렬하기2(2751번) // algorithms으로 문제 품
// 삽입, 선택, 버블, 힙, 머지(머지가 제일 시간이 적음), 퀵 정렬
// 힙 정렬 -> O(nlongn)
// n의 개수가 10만이 넘을 수가 있어서 시간 복잡도가 n^2인 알고리즘으로 풀 수 없음 -> 힙
// !! 힙으로는 시간 초과남..


#include <iostream>
using namespace std;

int n;
int* arr;


void heapify(int n) {
	// root 빼고 전체 반복
	for (int i = 1; i < n; i++) {
		int child = i;
		do {
			int parent = (child - 1) / 2;
			if (arr[parent] < arr[child]) {
				int tmp = arr[parent];
				arr[parent] = arr[child];
				arr[child] = tmp;
			}
			child = parent;
		} while (child != 0);
	}
}

// 부모와 자식 교환
void change_RootChild(int n) {
	int tmp = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = tmp;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	heapify(n);
	for (int i = n; i > 0; i--) {
		change_RootChild(i);
		heapify(i - 1);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}
