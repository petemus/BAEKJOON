// ���, ����� �Ҽ� 2 > 4.���μ�
// @@!! ���μ� ���� ũ����� �ִ� ������� ���μ��� �ִ�� ���� �� �ִ� �Ÿ�
#include <iostream>
using namespace std;

// �ִ� ����� ���ϱ�
int GCD(int a, int b) {
	int gcd = 0;
	for (int i = (a < b) ? a : b; i > 0; i--) {
		if ((a % i == 0) && (b % i == 0)) {
			// �ִ� ����� 
			gcd = i;
			return gcd;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	
	int* gap = new int[n - 1];
	int a = 0, b = 0;
	cin >> a >> b;
	gap[0] = b - a;
	a = b;
	int gcd = gap[0];
	for (int i = 1; i < n - 1; i++) {
		cin >> b;
		gap[i] = b - a;
		a = b;
		gcd = GCD(gap[i], gcd);
	}

	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		count += (gap[i] / gcd - 1);
	}

	cout << count;

	//for (int i = 0; i < n - 1; i++) {
	//	cout << gap[i] << " ";
	//}
	//cout << "\n" << gcd;


}