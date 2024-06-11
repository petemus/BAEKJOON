#include <iostream>

using namespace std;

int main() {
	int N, F;

	cin >> N;
	cin >> F;

	int num = N / 100 * 100;

	for (int i = num; i < num + 100; i++) {
		if (i % F == 0) {
			if (i % 100 < 10) {
				cout << '0' << i % 100;
			} else
				cout << i % 100;
			break;
		}
	}

}