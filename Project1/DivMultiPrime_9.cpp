// ��� ����� �Ҽ�2 > 9.â�� �ݱ�

// sol1> �����佺�׳׽��� ü�� �Ҽ� ���� �� ó�� Ǯ��� => �޸� �ʰ�
// sol2> �� ���� ��� ���� : on, off�� ���� -> ����� ������ ¦���̸� on Ȧ���̸� off => �ð� �ʰ�
// > �ð� �ʰ��� ���̱� ���� ��� -> ����� ������ Ȧ���� ���� ���� �������� ����� ����. => �ð� �ʰ� ^^
// >> i * i < tmp �� i�� ���ϴ� ������� �ٲٱ� => ���� ^^

#include <iostream>
#include <cmath>
using namespace std;

//int countDivisor(int k) {
//	int end = sqrt(k);
//	int cnt = 2;
//	for (int i = 2; i <= end; i++) {
//		if (k % i == 0) {
//			// ���
//			if (i * i == k) cnt++;
//			else cnt += 2;
//		}
//	}
//	return cnt;
//}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int cntOn = 0;
	int i = 1;
	while (i * i <= n) {
		cntOn++;
		i++;
	}

	cout << cntOn;


	// sol1>
	//bool* windows = new bool[n + 1];
	//for (int i = 0; i <= n; i++) windows[i] = false;
	//vector<bool> windows;
	//for (int i = 0; i <= n; i++) windows.push_back(false);
	//// ���� �ֱ�
	//for (int i = 1; i < n + 1; i++) {
	//	for (int j = 1; j * i <= n; j++) {
	//		windows[i * j] = !windows[i * j];
	//	}
	//}
	//int cnt = 0;
	//for (int i = 1; i <= n; i++) {
	//	if (windows[i]) cnt++;
	//}
	//cout << cnt;

}