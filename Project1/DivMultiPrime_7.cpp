// ��� ����� �Ҽ� 2 > 7.����Ʈ�� ����
// [����Ʈ�� ����] : ������ �ڿ��� n�� ���Ͽ� n ���� ũ�� 2n ���� �۰ų� ���� �Ҽ��� ��� �ϳ� ����

// sol1> ���� 6�� Ǯ�� ���� -> �����佺�׳׽��� ü �̿�

#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;

	bool nums[300000];
	fill_n(nums, 300000, true);

	int tmp = 0;
	int count = 0;
	cin >> tmp;
	while (tmp != 0) {
		for (int i = 2; i < 2 * tmp; i++) {
			if (nums[i]) {
				// �Ҽ��̸�
				int j = 2;
				while (i * j <= 2 * tmp) {
					nums[i * j] = false;
					j++;
				}
			}
		}
		for (int i = tmp + 1; i <= 2 * tmp; i++) {
			if (nums[i]) {
				count++;
			}
		}
		cout << count << "\n";
		count = 0;
		cin >> tmp;
	};

	
}