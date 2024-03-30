// 약수, 배수와 소수 2 > 2.최소 공배수 2
// 변수 크기에 대한 조건이 붙음. 
// 그 외에는 1번 문제와 차이를 모르겠음

// [유클리드 호제법]을 이용하는 듯.
// 호제법 : 두 수를 상대방 수에 나누어서 원하는 수를 얻는 방법
// @@ 변수 선언 long long int로 안 하면 오류 
// 근데 int의 범위가 +- 20억 정도인데 지금 제한되 있는 값으로 충분히 들어가는데 왜 그럼?
// = > 최소 공배수는 1억보다 크게 나와서

#include <iostream>
using namespace std;

// 유클리드 호제법으로 gcd 구하기
// 1. 재귀 호출 2. 반복문 사용 을 통해 구할 수 있음
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