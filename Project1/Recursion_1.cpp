// Recursion > 1.곱셈(1629번)
// 제곱을 하게되면 그 수가 매우 커지게 되서 자료형 크기를 크게 해줘야함
// 시간 복잡도 문제인가?
// 곱한 값이 너무 커지니까 c를 나눠야하는데 아마 mod 때문인 것 같은데

// * (mod n) 개념
// a = b (mod n) 은 a랑 b가 n으로 나눴을 때 나머지가 같다는 뜻
// * mod 연산(모듈러 연산) => % 랑 같음
// * mod 연산 특징
// > mod 연산 분배 법칙 성립 ( 덧셈, 뺄셈, 곱셈 모두 성립)
// -> ( A +- B) mod N = ( A mod N +- B mod N ) mod N
// -> ( A * B) mod N = ( A mod N * B mod N ) mod N


// 반례
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