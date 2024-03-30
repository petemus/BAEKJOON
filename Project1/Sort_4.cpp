// 정렬> 4. 수 정렬하기
#include <iostream>
using namespace std;

// 1. heap 상태 만들어 주기 최대 힙
//		> 자식 노드를 전체적으로 돌아
//		> 부모 노드 보다 크면 교환 ( 루트 노드에 닿을 떄까지 반복)
// 2. 맨 끝 노드와 루트 노드 교환 => 내림차순으로 정렬


void heapify(int* arr, int n) {
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
void change_RootChild(int* arr, int n) {
	int tmp = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = tmp;
}

int main() {

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	// ios::sync_with_stdio(false), cin.tie(nullptr) : 빠른 입출력

	heapify(arr, n);

	for (int i = n; i > 0; i--) {
		change_RootChild(arr, i);
		heapify(arr, i - 1);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}