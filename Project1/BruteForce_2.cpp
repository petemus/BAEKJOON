// ������
#include <iostream>
#include <cmath>
using namespace std;

// 2 ��° ���
// ���� -> ���ڿ� -> ���ڷ� ��ȯ�ؼ�
// ���ڿ��� ���ڷ� �ɰ��� �ϳ��� ����.

// 3 ��° ���
// 10���� ���� �������� ���� �̿�
int sumOfDigits(int n) {
	int i = 0;
	int sum = 0;
	while (true) {
		if (n >= pow(10, i)) {
			i++;
		}
		else break;
	}
	for (int j = i - 1; j >= 0; j--) {
		sum += (n / (int)pow(10, j));
		n -= (n /(int)pow(10, j)) * (int)pow(10, j) ;
	}
	return sum;
}

int main() {
	
	int n = 0;
	cin >> n;
	int result = 0;

	// �Է¹��� n ���� ���� �� ��� �˻�
	for (int i = 0; i < n; i++) {
		if (n == (i + sumOfDigits(i))) {
			result = i;
			break;
		}
	}
	cout << result;

}