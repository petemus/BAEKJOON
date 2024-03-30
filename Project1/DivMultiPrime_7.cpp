// 약수 배수와 소수 2 > 7.베르트랑 공준
// [베르트랑 공준] : 임의의 자연수 n에 대하여 n 보다 크고 2n 보다 작거나 같은 소수는 적어도 하나 존재

// sol1> 문제 6번 풀이 응용 -> 에라토스테네스의 체 이용

#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;

	bool nums[300000];
	fill_n(nums, 300000, true);

	int tmp = 0;
	int count = 0;
	cin >> tmp;
	while (tmp != 0) {
		for (int i = 2; i < 2 * tmp; i++) {
			if (nums[i]) {
				// 소수이면
				int j = 2;
				while (i * j <= 2 * tmp) {
					nums[i * j] = false;
					j++;
				}
			}
		}
		for (int i = tmp + 1; i <= 2 * tmp; i++) {
			if (nums[i]) {
				count++;
			}
		}
		cout << count << "\n";
		count = 0;
		cin >> tmp;
	};

	
}