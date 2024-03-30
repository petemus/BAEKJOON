// 약수, 배수와 소수 2 > 5.다음 소수
// 소수를 구하는 방법을 알아야함

// 소수를 구하는 알고리즘에 대해 찾아봄
// 1> n이 소수인지 판별하기 위해 n을 2~n-1의 모든 수 중에 하나라도 나누어 떨어지면 소수가 아님 => O(n)
// 2> 약수는 제곱근을 사이로 대칭적이기 때문에 제곱근 까지만 판별하면 된다. 루트 n까지만 확인하면 됨
// 3> '에라토스테네스의 체' : n 까지의 수들 중에서 소수인 값들을 구할 때(여러 개의 소수를 구할 때) 사용
// -> i의 배수를 제거한다(i는 건들지 않음) 이거를 계속 반복 => O(n*log(logn))
 
// 2> => 틀림.... why..?
// 베르트랑 공준 적용 => 틀림...
// 자료형의 문제?
// 10억이 넘어가면 출력값이 제대로 안나옴. => 자료형 바꾸어서 해결했는데도 틀림으로 나옴
// ^^ 이것도 1 포함해서 틀림 ^^^^^^^^^^^^^^^^^^^^^^^^^ ㅎ


#include <iostream>
#include <cmath> // sqrt()
using namespace std;

bool isPrime(unsigned int n) {
	unsigned int end = sqrt(n);
	for (unsigned int i = 2; i <= end; i++) {
		if (n % i == 0) {
			// 1개라도 나누어 떨어지면 소수가 아님
			return false;
		}
	}
	return true;
}

long long int nextPrime(long long int n) {
	while (n <= 2 * n) { // n이 계속 증가해서 의미 없음 
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