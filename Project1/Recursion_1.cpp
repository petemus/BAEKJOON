// Recursion > 1.����(1629��)
// ������ �ϰԵǸ� �� ���� �ſ� Ŀ���� �Ǽ� �ڷ��� ũ�⸦ ũ�� �������
// �ð� ���⵵ �����ΰ�?
// ���� ���� �ʹ� Ŀ���ϱ� c�� �������ϴµ� �Ƹ� mod ������ �� ������

// * (mod n) ����
// a = b (mod n) �� a�� b�� n���� ������ �� �������� ���ٴ� ��
// * mod ����(��ⷯ ����) => % �� ����
// * mod ���� Ư¡
// > mod ���� �й� ��Ģ ���� ( ����, ����, ���� ��� ����)
// -> ( A +- B) mod N = ( A mod N +- B mod N ) mod N
// -> ( A * B) mod N = ( A mod N * B mod N ) mod N


// �ݷ�
// 99999 99999 100000
// >> 99999

#include <iostream>
using namespace std;

long long recursion(long long a, long long b, long long c) {
	if (b == 1) return a % c;
	long long tmp = recursion(a, b / 2, c) % c;

	if (b % 2 == 0) return (tmp * tmp) % c;
	else return ((( tmp * tmp) % c ) * ( a % c )) % c; 

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long  a, b, c;

	cin >> a >> b >> c;

	cout << recursion(a, b, c);


}