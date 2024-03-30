// 정렬 > 6. 소트 인사이드
// 가변 배열을 만드는 게 핵심인 걸까
// counting sort 알고리즘 사용하면 좋음 -> 수의 범위가 적을 때 사용하면 좋음
// 수가 클 때는 메모리 사용량이 많아짐
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// vector 도 값에 의한 호출로 전달.
void heapify(vector<int> &arr, int n) {
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
void change_RootChild(vector<int> arr, int n) {
	int tmp = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = tmp;
}

int main() {

	vector<int> v;

	int n;
	cin >> n;
	while (n != 0) {
		int tmp = n % 10;
		v.push_back(tmp);
		n = n / 10;
	}

	heapify(v, v.size());

	for (int i = v.size(); i > 0; i--) {
		// 교환
		int tmp = v[v.size() - 1];
		v[v.size() - 1] = v[0];
		v[0] = tmp;
		//
		cout << v.back();
		v.pop_back();
		// 
		heapify(v, v.size());
	}



	

}