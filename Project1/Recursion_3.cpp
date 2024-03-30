// Recursion > 3.Z(1074번)

// # 시간 초과 문제 -> 전체 탐색을 하지말고 r,c가 있는 부분만 탐색하자

#include <iostream>
#include <cmath>
using namespace std;

int visit = -1;
int r, c;

void search(int n, int startR, int startC) {
	// n = 1이면 (sR, sC), (sR, sC+1), (sR + 1, sC), (sR + 1, sC + 1) 순으로 방문
	if (n == 0) {
		visit++;
		cout << visit;
	}
	else {
		int plus = pow(2, n - 1);
		if(r < startR + plus && c < startC + plus){
			search(n - 1, startR, startC);
		}
		else if (r < startR + plus && c >= startC + plus) {
			visit += pow(4, n -1);
			search(n - 1, startR, startC + plus);
		}
		else if (r >= startR + plus && c < startC + plus) {
			visit += pow(4, n - 1) * 2;
			search(n - 1, startR + plus, startC);
		}
		else {
			visit += pow(4, n - 1) * 3;
			search(n - 1, startR + plus, startC + plus);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n >> r >> c;

	search(n, 0, 0);
	


}