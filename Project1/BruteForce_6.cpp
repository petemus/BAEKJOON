#include <iostream>
using namespace std;

int main() {

	// ( 3 <= n <= 5000 )
	int n;
	cin >> n;

	int minBag = n; // 

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			if (n == (5 * i + 3 * j)) {
				if ((i + j) < minBag) minBag = i + j;
			}
		}
	}
	if (minBag == n) cout << -1;
	else cout << minBag;


}