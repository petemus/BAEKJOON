// ���, ����� �Ҽ� 2 > 1.�ּ� �����
// �ִ� ������� ���ؼ� �ּ� ������� ���� �� ����.

#include <iostream>
using namespace std;

int lcm(int a, int b) {
	int gcd = 0;
	for (int i = (a < b) ? a : b; i > 0; i--) {
		if ((a % i == 0) && (b % i == 0)) {
			gcd = i;
			break;
		}
	}
	int lcm = 0;
	lcm = (a / gcd) * (b / gcd) * gcd;
	return lcm;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int a, b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}

}