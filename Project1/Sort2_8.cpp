// Sort2 > 8.역원소(5648번)
// 입력값 < 10^12 -> 1000억 => long long


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> num;
	int n;

	cin >> n;

	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		long long k = 1;
		long long n = 0;
		bool isZero = true;
		for (int j = 0; j < tmp.size(); j++) {
			if (isdigit(tmp[j])) {
				// 숫자이면
				long long digit = tmp[j] - '0';
				if (digit == 0 && isZero) {
					continue;
				}
				n += digit * k;
				k *= 10;
				isZero = false;
			}
		}
		num.push_back(n);
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < n; i++) {
		cout << num[i] << '\n';
	}


}