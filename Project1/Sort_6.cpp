// ���� > 6. ��Ʈ �λ��̵�
// ���� �迭�� ����� �� �ٽ��� �ɱ�
// counting sort �˰��� ����ϸ� ���� -> ���� ������ ���� �� ����ϸ� ����
// ���� Ŭ ���� �޸� ��뷮�� ������
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// vector �� ���� ���� ȣ��� ����.
void heapify(vector<int> &arr, int n) {
	// root ���� ��ü �ݺ�
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

// �θ�� �ڽ� ��ȯ
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
		// ��ȯ
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