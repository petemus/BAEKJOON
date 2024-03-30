// ���, ����� �Ҽ� 2 > 5.���� �Ҽ�
// �Ҽ��� ���ϴ� ����� �˾ƾ���

// �Ҽ��� ���ϴ� �˰��� ���� ã�ƺ�
// 1> n�� �Ҽ����� �Ǻ��ϱ� ���� n�� 2~n-1�� ��� �� �߿� �ϳ��� ������ �������� �Ҽ��� �ƴ� => O(n)
// 2> ����� �������� ���̷� ��Ī���̱� ������ ������ ������ �Ǻ��ϸ� �ȴ�. ��Ʈ n������ Ȯ���ϸ� ��
// 3> '�����佺�׳׽��� ü' : n ������ ���� �߿��� �Ҽ��� ������ ���� ��(���� ���� �Ҽ��� ���� ��) ���
// -> i�� ����� �����Ѵ�(i�� �ǵ��� ����) �̰Ÿ� ��� �ݺ� => O(n*log(logn))
 
// 2> => Ʋ��.... why..?
// ����Ʈ�� ���� ���� => Ʋ��...
// �ڷ����� ����?
// 10���� �Ѿ�� ��°��� ����� �ȳ���. => �ڷ��� �ٲپ �ذ��ߴµ��� Ʋ������ ����
// ^^ �̰͵� 1 �����ؼ� Ʋ�� ^^^^^^^^^^^^^^^^^^^^^^^^^ ��


#include <iostream>
#include <cmath> // sqrt()
using namespace std;

bool isPrime(unsigned int n) {
	unsigned int end = sqrt(n);
	for (unsigned int i = 2; i <= end; i++) {
		if (n % i == 0) {
			// 1���� ������ �������� �Ҽ��� �ƴ�
			return false;
		}
	}
	return true;
}

long long int nextPrime(long long int n) {
	while (n <= 2 * n) { // n�� ��� �����ؼ� �ǹ� ���� 
		if (isPrime(n) && n > 1) {
			return n;
		}
		n++;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned int n; 
	cin >> n;

	long long int tmp = 0;
	for (unsigned int i = 0; i < n; i++) {
		cin >> tmp;
		cout << nextPrime(tmp) << "\n";
	}

	//cout << nextPrime(2300000000);

}