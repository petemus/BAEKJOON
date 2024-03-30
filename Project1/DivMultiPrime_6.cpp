// 약수, 배수와 소수 2 > 6.소수 구하기
// '에라토스테네스의 체' 이용
// m까지의 소수를 구한다음 n 아래는 제거

// 배열 한번에 초기화 방법 => std::fill_n(arr, size, value) 

// 에라토스테네스의 체를 이용할려면 n만큼의 저장 공간이 필요하다 
// 1> 소수를 저장하는 vector를 만들어서 n ~ m 만큼을 저장하고 소거하는 방식
// 2> 100만개의 배열을 만들어서 index가 수 요소가 참, 거짓, 소수가 아니면 false로

// @@ 1이 소수가 아니여서 틀렸다 ^__^

#include <iostream>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	bool nums[1000001];

	fill_n(nums, 1000001, true);

	for (int i = 2; i <= m; i++) {
		if (nums[i]) {
			// 소수이면
			int j = 2;
			while (i * j <= m) {
				nums[i * j] = false;
				j++;
			}
		}
	}

	for (int i = n; i <= m; i++) {
		if (nums[i]) {
			if (i == 1) continue;
			cout << i << "\n";
		}
	}


}