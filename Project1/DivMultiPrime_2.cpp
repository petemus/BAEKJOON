// ���, ����� �Ҽ� 2 > 2.�ּ� ����� 2
// ���� ũ�⿡ ���� ������ ����. 
// �� �ܿ��� 1�� ������ ���̸� �𸣰���

// [��Ŭ���� ȣ����]�� �̿��ϴ� ��.
// ȣ���� : �� ���� ���� ���� ����� ���ϴ� ���� ��� ���
// @@ ���� ���� long long int�� �� �ϸ� ���� 
// �ٵ� int�� ������ +- 20�� �����ε� ���� ���ѵ� �ִ� ������ ����� ���µ� �� �׷�?
// = > �ּ� ������� 1�ﺸ�� ũ�� ���ͼ�

#include <iostream>
using namespace std;

// ��Ŭ���� ȣ�������� gcd ���ϱ�
// 1. ��� ȣ�� 2. �ݺ��� ��� �� ���� ���� �� ����
int GCD(long long int a, long long int b) {
	long long int big = a > b ? a : b;
	long long int small = a > b ? b : a;
	long long int tmp = 0;
	while (small != 0) {
		tmp = big % small;
		big = small;
		small = tmp;
	}
	return big;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long int a, b;
	cin >> a >> b;
	long long int gcd = GCD(a, b);
	long long int lcm = a * b / gcd;
	cout << lcm;

}