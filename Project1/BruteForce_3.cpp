// 수학은 비대면 강의입니다.
#include <iostream>
using namespace std;

int main() {

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	// x 구하는 식   - (ce - fb)/(bd - ea)
	// y 구하는 식 (cd - fa) / (bd - ea)

	int bunmo = 0;
	bunmo = (b * d) - (e * a);
	int x, y;
	x =  - (c * e - f * b) / bunmo;
	y = (c * d - f * a) / bunmo;
	cout << x << ' ' << y;

}