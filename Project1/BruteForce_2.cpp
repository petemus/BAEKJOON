// 분해합
#include <iostream>
#include <cmath>
using namespace std;

// 2 번째 방법
// 숫자 -> 문자열 -> 숫자로 변환해서
// 문자열을 문자로 쪼개서 하나씩 저장.

// 3 번째 방법
// 10으로 나눈 나머지와 몫을 이용
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

	// 입력받은 n 보다 작은 수 모두 검색
	for (int i = 0; i < n; i++) {
		if (n == (i + sumOfDigits(i))) {
			result = i;
			break;
		}
	}
	cout << result;

}