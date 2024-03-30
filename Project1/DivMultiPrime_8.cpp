// 약수 배수와 소수 2 > 8.골드바흐 파티션
// 골드바흐의 추측 : 2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다. (아직까지 증명이 이루어지지 않음)

// sol1> 2~n/2 만큼 소수의 합으로 이루어진 개수 구함. -> 시간 초과
// sol2> 입력받은 n개에서 가장 큰 수를 구한 후 그 수만큼 소수를 구함 (에라토스테네스의 체 이용)


#include <iostream>
#include <cmath>
using namespace std;

//bool isPrime(int n) {
//	int end = sqrt(n) + 1;
//	for (int i = 2; i <= end; i++) {
//		if (n % i == 0) {
//			// 1개라도 나누어 떨어지면 소수가 아님
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

	// 입력
	int* testcase = new int[n];
	int big = 0, tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		testcase[i] = tmp;
		if (tmp > big) big = tmp;
	}


	// 소수
	bool primes[1000001];
	fill_n(primes, 1000001, true);

	// big 만큼의 소수 구함
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
	//	for (int j = 2; j <= tmp / 2; j++) {  // 소수에 1은 포함하지 않는건가?
	//		if (isPrime(j) && isPrime(tmp - j)) {
	//			// 두 수가 소수일 떄 
	//			count++;
	//		}
	//	}
	//	cout << count << "\n";
	//	count = 0;
	//}


}