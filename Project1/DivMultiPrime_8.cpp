// ��� ����� �Ҽ� 2 > 8.������ ��Ƽ��
// �������� ���� : 2���� ū ¦���� �� �Ҽ��� ������ ��Ÿ�� �� �ִ�. (�������� ������ �̷������ ����)

// sol1> 2~n/2 ��ŭ �Ҽ��� ������ �̷���� ���� ����. -> �ð� �ʰ�
// sol2> �Է¹��� n������ ���� ū ���� ���� �� �� ����ŭ �Ҽ��� ���� (�����佺�׳׽��� ü �̿�)


#include <iostream>
#include <cmath>
using namespace std;

//bool isPrime(int n) {
//	int end = sqrt(n) + 1;
//	for (int i = 2; i <= end; i++) {
//		if (n % i == 0) {
//			// 1���� ������ �������� �Ҽ��� �ƴ�
//			return false;
//		}
//	}
//	return true;
//}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// �Է�
	int* testcase = new int[n];
	int big = 0, tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		testcase[i] = tmp;
		if (tmp > big) big = tmp;
	}


	// �Ҽ�
	bool primes[1000001];
	fill_n(primes, 1000001, true);

	// big ��ŭ�� �Ҽ� ����
	for (int i = 2; i <= big; i++) {
		if (primes[i]) {
			int k = 2;
			while (i * k <= big) {
				primes[i * k] = false;
				k++;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		tmp = testcase[i];
		for (int j = 2; j <= tmp / 2; j++) {
			if (primes[j] && primes[tmp - j]) cnt++;
		}
		cout << cnt << "\n";
		cnt = 0;
	}


	// sol1> 
	//int tmp = 0;
	//int count = 0;
	//for (int i = 0; i < n; i++) {
	//	cin >> tmp;
	//	for (int j = 2; j <= tmp / 2; j++) {  // �Ҽ��� 1�� �������� �ʴ°ǰ�?
	//		if (isPrime(j) && isPrime(tmp - j)) {
	//			// �� ���� �Ҽ��� �� 
	//			count++;
	//		}
	//	}
	//	cout << count << "\n";
	//	count = 0;
	//}


}