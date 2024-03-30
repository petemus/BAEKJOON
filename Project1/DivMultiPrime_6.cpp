// ���, ����� �Ҽ� 2 > 6.�Ҽ� ���ϱ�
// '�����佺�׳׽��� ü' �̿�
// m������ �Ҽ��� ���Ѵ��� n �Ʒ��� ����

// �迭 �ѹ��� �ʱ�ȭ ��� => std::fill_n(arr, size, value) 

// �����佺�׳׽��� ü�� �̿��ҷ��� n��ŭ�� ���� ������ �ʿ��ϴ� 
// 1> �Ҽ��� �����ϴ� vector�� ���� n ~ m ��ŭ�� �����ϰ� �Ұ��ϴ� ���
// 2> 100������ �迭�� ���� index�� �� ��Ұ� ��, ����, �Ҽ��� �ƴϸ� false��

// @@ 1�� �Ҽ��� �ƴϿ��� Ʋ�ȴ� ^__^

#include <iostream>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	bool nums[1000001];

	fill_n(nums, 1000001, true);

	for (int i = 2; i <= m; i++) {
		if (nums[i]) {
			// �Ҽ��̸�
			int j = 2;
			while (i * j <= m) {
				nums[i * j] = false;
				j++;
			}
		}
	}

	for (int i = n; i <= m; i++) {
		if (nums[i]) {
			if (i == 1) continue;
			cout << i << "\n";
		}
	}


}