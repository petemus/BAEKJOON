// ���, ����� �Ҽ� 2 > 3.�м� ��

// @ sol1> �ϴ� �� �м��� ���� �и� ���ؼ� ���� �� ���� �и�� ������ gcd�� ������ gcd�� �и� ���ڿ� ������
// ���м� �ϼ� -> ���� ��
// ?? sol2> �� �м��� �и��� lcm�� ���ϰ� �и� lcm�� ���� ��� ���ڵ��� ���ϸ� �ϼ� -> Ʋ�Ƚ��ϴ� ��
// => ���� ���� ����� �� �� ����. �� �����Ф�

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

// �ּ� ����� �����ֱ�
int LCM(int a, int b) {
	// �ִ� ����� ���ϱ�
	int gcd = GCD(a, b);
	// �ּ� ����� �����ֱ�
	int lcm = 0;
	lcm = (a / gcd) * (b / gcd) * gcd; // => a * b / gcd;
	return lcm;
}

int main() {

	int a_deno, a_num, b_deno, b_num;
	cin >> a_num >> a_deno;
	cin >> b_num >> b_deno;

	int c_deno, c_num;

	//int lcm = LCM(a_deno, b_deno);
	//c_deno = lcm;
	//c_num = (lcm / a_deno * a_num) + (lcm / b_deno * b_num);

	//cout << c_num << " " << c_deno;

	c_deno = a_deno * b_deno;
	c_num = a_num * b_deno + b_num * a_deno;
	int gcd = GCD(c_num, c_deno);
	c_deno /= gcd;
	c_num /= gcd;
	cout << c_num << " " << c_deno;
}