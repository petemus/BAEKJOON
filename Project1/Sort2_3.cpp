// Sort2 > 3.�� �����ϱ� 3(10989��)
// �Ϲ������� �ϸ� �޸� �ʰ���
// �ߺ� �������� �� �����ϸ� �޸� �ʰ���
// => ���� ���������� �˷��� ���

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
	// ���
	for (int i = 1; i < 10001; i++) {
		tmp = arr[i];
		for (int j = 0; j < tmp; j++) {
			cout << i << "\n";
		}
	}

}