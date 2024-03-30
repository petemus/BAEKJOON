// 약수, 배수와 소수 2 > 4.가로수
// @@!! 가로수 사이 크기들의 최대 공약수가 가로수를 최대로 심을 수 있는 거리
#include <iostream>
using namespace std;

// 최대 공약수 구하기
int GCD(int a, int b) {
	int gcd = 0;
	for (int i = (a < b) ? a : b; i > 0; i--) {
		if ((a % i == 0) && (b % i == 0)) {
			// 최대 공약수 
			gcd = i;
			return gcd;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	
	int* gap = new int[n - 1];
	int a = 0, b = 0;
	cin >> a >> b;
	gap[0] = b - a;
	a = b;
	int gcd = gap[0];
	for (int i = 1; i < n - 1; i++) {
		cin >> b;
		gap[i] = b - a;
		a = b;
		gcd = GCD(gap[i], gcd);
	}

	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		count += (gap[i] / gcd - 1);
	}

	cout << count;

	//for (int i = 0; i < n - 1; i++) {
	//	cout << gap[i] << " ";
	//}
	//cout << "\n" << gcd;


}