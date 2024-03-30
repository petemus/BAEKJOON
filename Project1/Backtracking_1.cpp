// Backtracking > 1.�κм����� ��(1182��)
// Backtracking�� dfs�� ���̴� backtracking�� �ʿ����� ���� �κ��� ����ġ�� �ؼ� �߶󳻴� �ݸ鿡
// dfs�� ��ü Ž���� �Ѵ�.

// �Է°� vector�� ������ ����
// backtracking ( ���� ���� S ���� Ŀ���� back)

//????? ���� -> ���� ���� 1 2 3 4  /  1 3 2 4 ���?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int subseq = 0; // �κ� ������ ����
int n, s;


// �� ���������� dept�� �� ����
void Backtracking(int index, int sum, int dept) {
	sum += arr[index];
	// ���� ����
	if (sum > s && arr[index] > 0) return;  // @@@@ �� ���� �� �����ϴ� �� �߿�!!!
	else if (sum == s) {
		subseq++;
	}

	for (int i = index + 1; i < n; i++) {
		Backtracking(i, sum, dept + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	// ���� ����
	sort(arr.begin(), arr.end());
	// ���� n ��ŭ backtracking
	for (int i = 0; i < n; i++) {
		//cout << arr[i] << " ";
		Backtracking(i, 0, 1);
	}


	cout << subseq;

}